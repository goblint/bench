/*
** ptester.c - a simple HTTP protocol benchmarking program.
**
** Copyright (c) 1995-1999 Peter Eriksson <pen@lysator.liu.se>
**
** Version: 1.1
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include <pthread.h>

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <syslog.h>

#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>


int debug = 0;

int repeat = 1;
int expected_bytes = 0;
#ifdef __sun__
int concurrency = 0;
#endif

char *server_host = "127.0.0.1";
char *server_port = "80";
int rcvbuf_size = 0;
int keepalive = 0;
int http_0 = 0;
int failure = 0;
int bind_local = 0;


struct sockaddr_in server_addr;

int total_nrq = 0;
int total_bytes = 0;
int total_failed = 0;
double min_tx = 0.0;
double max_tx = 0.0;

volatile int stop_flag = 0;
int test_length = 60;
pthread_mutex_t result_lock;


void xsleep(int timeout)
{
    /* There is a bug in Solaris 2.4's sleep() which causes
       it to return random garbage if interrupted by some
       signals - so we handle it by calling time() ourself */

    time_t start, now;
    int len;
    

    time(&start);
    len = timeout;
    
    while (len > 0)
    {
	sleep(len);
	time(&now);

	len = timeout - (now - start);
    }
}

int s_read(int fd, char *buf, int len)
{
    int s = 0;
    int n_read = 0;

    do
    {
	buf += s;
	errno = 0;
	while ((s = read(fd, buf, len)) < 0 && errno == EINTR)
	    errno = 0;

	if (s > 0)
	    n_read += s;
	
    } while (s > 0 && (len -= s) > 0);

    return s >= 0 ? n_read : s;
}

int s_write(int fd, char *buf, int len)
{
    int s = 0;
    int n_written = 0;

    do
    {
	buf += s;
	
	errno = 0;
	while ((s = write(fd, buf, len)) < 0 && errno == EINTR)
	    errno = 0;
	
	if (s > 0)
	    n_written += s;
    } while (s >= 0 && (len -= s) > 0);
    
    return s >= 0 ? n_written : s;
}


struct rtinfo
{
    int fd;
    int rbytes;
    char buffer[65536];
};


void *read_thread(void *data)
{
    struct rtinfo *rip = data;
    int len;


    if (debug)
	printf("read_thread(), fd=%d\n", rip->fd);

    do
    {
	len = s_read(rip->fd, rip->buffer, sizeof(rip->buffer));
	if (len < 0)
	{
	    perror("read");
	    return NULL;
	}
	
	rip->rbytes += len;
    } while (len > 0);

    if (debug)
	printf("read_thread(), rbytes=%d\n", rip->rbytes);
    
    return NULL;
}


static void *test_thread(void *misc)
{
    char *rqbuf, *cp, *url;
    void *vval;
    int status, rqlen, len, val, fd, requests, ecode;
    int bytes, rbytes, failed_requests, ki;
    double min_time, max_time, total_time, dt;
    double min_ctime, max_ctime, total_ctime, cdt;
    struct timeval start_time, stop_time, connect_time, setup_time;
    pthread_t read_tid;
    struct rtinfo *rip;
    struct sockaddr_in l_sin;

    
    
    if (debug)
	printf("test_thread(): Start\n");
    
    url = (char *) misc;
    requests = 0;
    failed_requests = 0;
    min_time = -1.0;
    max_time = 0.0;
    total_time = 0.0;
    bytes = 0;
    
    min_ctime = -1.0;
    max_ctime = 0.0;
    total_ctime = 0.0;

    rqbuf = (char *) malloc((64+strlen(url))*keepalive);
    rqbuf[0] = '\0';

    rip = malloc(sizeof(*rip));
    
    for (ki = 0; ki < keepalive; ki++)
    {
	cp = rqbuf+strlen(rqbuf);
	if (ki+1 < keepalive)
	{
	    sprintf(cp, "GET %s HTTP/1.0\r\nConnection: Keep-Alive\r\nAccept: */*\r\n\r\n", url);
	}
	else
	{
	    if (http_0)
		sprintf(cp, "GET %s\r\n", url);
	    else
		sprintf(cp, "GET %s HTTP/1.0\r\nAccept: */*\r\n\r\n", url);
	}
    }
    
    rqlen = strlen(rqbuf);


    memset(&l_sin, 0, sizeof(l_sin));
    l_sin.sin_family = AF_INET;
    l_sin.sin_addr.s_addr = INADDR_ANY;

    
    while (!stop_flag)
    {
	rbytes = 0;
	
	gettimeofday(&start_time, NULL);

	while ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0 &&
	       errno == EINTR)
	    ;
	
	if (fd < 0)
	{
	    perror("socket");
	    free(rqbuf);
	    return NULL;
	}
	
	if (rcvbuf_size > 0)
	{
	    val = rcvbuf_size;
	    setsockopt(fd, SOL_SOCKET, SO_RCVBUF, (void *) &val, sizeof(val));
	}
	
	val = 1;
	setsockopt(fd, 6, TCP_NODELAY, (void *) &val, sizeof(val));
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (void *) &val, sizeof(val));
	gettimeofday(&setup_time, NULL);

	if (bind_local)
	{
	    l_sin.sin_port = htons(30000+fd*1000+requests);
	    
	    if (bind(fd, (struct sockaddr *) &l_sin, sizeof(l_sin)) < 0)
	    {
		perror("bind");
	    }
	}
	
	while ((status = connect(fd, 
				 (struct sockaddr *) &server_addr,
				 sizeof(server_addr))) < 0 && errno == EINTR)
	    ;
	if (status < 0)
	{
	    perror("connect");
	    free(rqbuf);
	    failure = 1;
	    return NULL;
	}
	
	gettimeofday(&connect_time, NULL);

	if (debug)
	    printf("test_thread(), Connected\n");
	   
	rip->fd = fd;
	rip->rbytes = 0;
	
	ecode = pthread_create(&read_tid, 
			       NULL,
			       (void *(*)(void *)) read_thread,
			       (void *) rip);
	if (ecode)
	{
	    fprintf(stderr, "pthread_create: %s\n", strerror(errno));
	    exit(1);
	}

	len = s_write(fd, rqbuf, rqlen);
	if (len < 0)
	{
	    if (errno != EPIPE)
	    {
		perror("ptester: write");
		free(rqbuf);
		return NULL;
	    }
	}
	
	if (shutdown(fd, 1) < 0)
	{
	    perror("shutdown");
	    free(rqbuf);
	    return NULL;
	}

	if (debug)
	    printf("test_thread(), Waiting for join (fd=%d)\n", fd);
	
	ecode = pthread_join(read_tid, &vval);

	if (ecode)
	{
	    fprintf(stderr, "pthread_join: %s\n", strerror(ecode));
	    exit(1);
	}

	rbytes = rip->rbytes;
	
	if (debug)
	    printf("test_thread(), Got join (rbytes=%d)\n", rbytes);
	
	if (rbytes == 0)
	    failed_requests += keepalive;
	else if (expected_bytes > 0 && rbytes != expected_bytes)
	{
	    fprintf(stderr, "Got %d (expected %d) bytes\n",
		    rbytes, expected_bytes);
	    rbytes = 0;
	}
	
	bytes += rbytes;

	if (debug)
	    printf("test_thread(), Closing down (fd=%d)\n", fd);

	while (close(fd) < 0 && errno == EINTR)
	    ;
	
	gettimeofday(&stop_time, NULL);
	
	dt = ((double) stop_time.tv_sec +
	      (double) stop_time.tv_usec / 1000000.0)-
		  ((double) setup_time.tv_sec +
		   (double) setup_time.tv_usec / 1000000.0);
	
	if (min_time < 0)
	    min_time = dt;
	else if (dt < min_time)
	    min_time = dt;
	
	if (dt > max_time)
	    max_time = dt;
	
	total_time += dt;
	
	cdt = ((double) connect_time.tv_sec +
	       (double) connect_time.tv_usec / 1000000.0) -
		   ((double) setup_time.tv_sec +
		    (double) setup_time.tv_usec / 1000000.0);
	
	if (min_ctime < 0)
	    min_ctime = cdt;
	else if (cdt < min_ctime)
	    min_ctime = cdt;
	
	if (cdt > max_ctime)
	    max_ctime = cdt;
	
	total_ctime += cdt;
	
	requests += keepalive;
    }

    free(rqbuf);
    free(rip);
    
    pthread_mutex_lock(&result_lock);
    total_nrq += requests;
    total_bytes += bytes;
    total_failed += failed_requests;
    
    if (max_time > max_tx)
	max_tx = max_time;

    if (min_time < min_tx || min_tx == 0.0)
	min_tx = min_time;
    
    printf("%-19s %4d  %.4f %.4f %.4f  %.4f %.4f %.4f  %d\n",
	   url, requests-failed_requests,
	   
	   min_ctime / (keepalive ? (double) keepalive : 1),
	   total_ctime / (double) (requests-failed_requests),
	   max_ctime / (keepalive ? (double) keepalive : 1),
	   
	   min_time / (keepalive ? (double) keepalive : 1),
	   total_time / (double) (requests-failed_requests),
	   max_time / (keepalive ? (double) keepalive : 1),
	   
	   bytes/(requests-failed_requests));
    
    pthread_mutex_unlock(&result_lock);

    return NULL;
}





int mksockaddr_in(const char *host,
		  char *service,
		  struct sockaddr_in *sin)
{
    struct hostent *hp;

    
    memset(sin, 0, sizeof(sin));
    
    sin->sin_family = AF_INET;

    hp = gethostbyname(host);
    if (hp == NULL)
    {
	sin->sin_addr.s_addr = inet_addr(host);
	if (sin->sin_addr.s_addr == -1)
	    return -1;
    }
    else
	memcpy(&sin->sin_addr, hp->h_addr_list[0], hp->h_length);

    
    if (isdigit(service[0]))
	sin->sin_port = htons(atoi(service));
    else
    {
	struct servent *sp;
	

	sp = getservbyname(service, "tcp");
	if (sp == NULL)
	    return -1;

	sin->sin_port = sp->s_port;
    }

    return 0;

}


int help(char *argv0)
{
    printf("Usage: %s [<options>]* <url> [<url>]*\n\n", argv0);

    puts("Option  \tDefault\t\tDescription");
    puts("------- \t---------------\t-----------------------------------");
    puts("-H      \t\t\tDisplay this information");
    printf("-h<host>\t%-15s Server host to connect to\n",
	   server_host);
    printf("-p<port>\t%-15s Server port to connect to\n",
	   server_port);
    printf("-t<len> \t%-15d Test length in seconds\n",
	   test_length);
#ifdef __sun__ 
    printf("-c<num> \t%-15d Thread concurrency level if nonzero\n",
	   concurrency);
#endif

    printf("-R<num> \t%-15d Receive socket buffer size\n",
	   rcvbuf_size);
    printf("-e<num> \t%-15d Check length of reply against this if nonzero\n",
	   expected_bytes);
    printf("-r<num> \t%-15d Repeat each request this number of times\n",
	   repeat);
    printf("-k<num> \t%-15d Repeat each request inband (keepalive)\n",
	   keepalive);
    printf("-B      \t\t\tAttempt to bind the local port\n");
    return 0;
}


int main(int argc,
	 char *argv[])
{
    int i, j, t, ecode;
    void *vval;
    int n_tids = 0;
    pthread_t tid[256];
    time_t start_time, stop_time;
    

    signal(SIGPIPE, SIG_IGN);
    
    for (i = 1; i < argc && argv[i][0] == '-'; i++)
	switch (argv[i][1])
	{
	  case '?':
	  case 'H':
	    exit(help(argv[0]));
	    break;

	  case 'd':
	    debug = atoi(argv[i]+2);
	    break;
	    
	  case 'R':
	    rcvbuf_size = atoi(argv[i]+2);
	    break;
	    
	  case 't':
	    test_length = atoi(argv[i]+2);
	    break;
	    
	  case 'h':
	    server_host = argv[i]+2;
	    break;

	  case 'p':
	    server_port = argv[i]+2;
	    break;

	  case 'B':
	    bind_local = 1;
	    break;
#ifdef __sun__ 
	  case 'c':
	    concurrency = atoi(argv[i]+2);
	    break;
#endif
	  case 'e':
	    expected_bytes = atoi(argv[i]+2);
	    break;

	  case 'r':
	    repeat = atoi(argv[i]+2);
	    break;

	  case 'k':
	    keepalive = atoi(argv[i]+2);
	    break;

	  case '0':
	    http_0 = 1;
	    break;
	    
	  default:
	    fprintf(stderr, "%s: unknown switch '%s', try -H for help\n",
		    argv[0], argv[1]);
	    exit(1);
	}

    keepalive++;
    
    pthread_mutex_init(&result_lock, NULL);

    if (mksockaddr_in(server_host, server_port, &server_addr) < 0)
    {
	fprintf(stderr, "Error creating socket address\n");
	exit(1);
    }

    puts("[Ptester, version 1.1 - Copyright (c) 1999 Peter Eriksson <pen@lysator.liu.se>]\n");
    
    fprintf(stderr, "Running test: ");

    for (t = 0; t < test_length; t++)
      {
	if (t % 10)
	  putc('-', stderr);
	else
	  putc('+', stderr);
      }

    fprintf(stderr, "\rRunning test: ");

#ifdef __sun__
    if (concurrency > 0)
	thr_setconcurrency(concurrency);
#endif


    time(&start_time);
    
    for (; i < argc; i++)
    {
	for (j = 0; j < repeat; j++)
	{
	    ecode = pthread_create(&tid[n_tids],
				   NULL, 
				   (void *(*)(void *)) test_thread,
				   (void *) argv[i]);
	    if (ecode)
	    {
		fprintf(stderr, "pthread_create: %s\n", strerror(errno));
		exit(1);
	    }
	    
	    n_tids++;
	}
    }

    for (t = 0; t < test_length; t++)
    {
	xsleep(1);
	putc('>', stderr);
	fflush(stdout);
    }
    
    putc('\n', stderr);
    putc('\n', stderr);
    
    printf("%-19s %4s  %6s %6s %6s  %6s %6s %6s  %s\n",
	   "URL", 
	   "NRq",
	   "Min Ct",
	   "Avg Ct",
	   "Max Ct",
	   "Min Tx",
	   "Avg Tx",
	   "Max Tx",
	   "Bytes");

    stop_flag = 1;

    for (i = 0; i < n_tids; i++)
	pthread_join(tid[i], &vval);

    if (failure)
	exit(1);
    
    time(&stop_time);

    test_length = (int) stop_time - (int) start_time;
    
    putchar('\n');

    printf("Actual test time.. %d seconds\n", test_length);
    
    // pthread_mutex_lock(&result_lock);
    printf("Total requests.... %d (%d requests/sec)\n",
	   total_nrq,
	   total_nrq / test_length);
    
    printf("Total failed...... %d (%d requests/sec)\n",
	   total_failed,
	   total_failed / test_length);
    
    printf("Total bytes....... %d (%d bytes/sec)\n",
	   total_bytes,
	   total_bytes / test_length);
    // pthread_mutex_unlock(&result_lock);
    
    putchar('\n');
    printf("Min Tx: %.4f\n", min_tx / (keepalive ? (double) keepalive : 1));
    printf("Max Tx: %.4f\n", max_tx / (keepalive ? (double) keepalive : 1));
    
    exit(0);
}



