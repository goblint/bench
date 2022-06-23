/***************************************************************************
                          connect.c  -  description
                             -------------------
    begin                : Wed May 21 2003
    copyright            : (C) 2003 by Spencer Hardy
    email                : diceman@dircon.co.uk
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#include "connect.h"
#include "options.h"
#include "utils.h"

extern struct options o;
extern struct flags f;


//return an ip adress from hostname
long get_ip(char *host) {

	long ia;
	struct hostent *h;

	if(f.debug) {
		fprintf(stderr, "Getting IP\n");
	}


	if((ia = inet_addr(host)) == -1) {
		if((h=gethostbyname(host)) == NULL) {
			if(f.debug) {
				fprintf(stderr, "Couldn't resolv ip\n");
			}
			return(-1);
		}
		memcpy(&ia,h->h_addr,4);
	}

	if(f.debug) {
		fprintf(stderr, "Got ip ok\n");
	}

	return(ia);

}


/* Function to conect to ip address on port 25
 * it uses a timeout on creating the socket as
 * the max number of sockets could be used up
 * and it may need a child or two to exit
 *
 * it also uses a non blocking connect so that a
 * a timeout can be specefied
 */

int tcp_connect(long ipa) {

	struct sockaddr_in their_addr;
	int sockfd;
	int socket_f = 0;

START1:
	while((sockfd=socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket: ");
		exit(EXIT_FAILURE);
		if(socket_f>12) {
			fatal("Still unable to create socket after 60 secs.... Try reducing the number of threads.....");
		}
		socket_f++;
		if(f.verbose || 1) {
			error("Unable to create socket.... sleeping for 5 seconds");
		}
		sleep(5);
	}
	if(sockfd > 2000) {
		close(sockfd);
		fprintf(stderr, "Socket count exceding 2000; sleeping 5!\n");
		sleep(5);
		goto START1;
	}

	//  linger.l_onoff = 1;
	//  linger.l_linger = 0;

	//  if(setsockopt(sockfd, SOL_SOCKET, SO_LINGER, (char*) &linger, sizeof( linger)) == -1) {
	//    perror("setsockopt: ");
	//  }

	//printf("Socket: %d\n", sockfd);

	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(PORT);
	their_addr.sin_addr.s_addr = ipa;
	bzero(&(their_addr.sin_zero), 8);

	if((sockfd=connect_non_blocking(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr), o.c_timeout)) == -1) {
		if(f.verbose > 1) {
			error("! Unable to connect to host");
		}
		return(-1);
	}
	if(sockfd > 2000) {
		printf("\n\n\n\n\n\n\n\n******** in tcp_connect\n");
		sleep(10);
	}

	return(sockfd);
}

/* Non blocking connect. this is done so that
 * a timeout can be specified.
 */

int connect_non_blocking(int sockfd, const struct sockaddr *thaddr, socklen_t salen, int nsec) {

	int n;
	int flags;
	int serror;
	socklen_t len;
	fd_set rset;
	fd_set wset;
	struct timeval tval;

	if((flags=fcntl(sockfd, F_GETFL, 0)) == -1) {
		perror("Cant set flags");
		close(sockfd);
		return(-1);
	}

	if(fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) == -1) {
		perror("Cant set socket options");
		close(sockfd);
		return(-1);
	}
	serror = 0;
	if((n = connect(sockfd, thaddr, salen)) == -1) {
		if(errno != EINPROGRESS) {
			close(sockfd);
			return(-1);
		}
	}

	if(sockfd > 2000) {
		printf("\n\n\n\n\n\n******** in connect non blocking\n");
		sleep(10);
	}

	if(n == 0) {
		goto done;
	}

	FD_ZERO(&rset);
	//  FD_ZERO(&wset);
	FD_SET(sockfd, &rset);
	//  FD_SET(sockfd, &wset);
	wset = rset;
	tval.tv_sec = nsec;
	tval.tv_usec = 500000;

	if((n = select(sockfd +1, &rset, &wset, NULL, nsec ? &tval : NULL)) == 0) {
		close(sockfd);
		errno = ETIMEDOUT;
		return(-1);
	} else if(n == -1) {
		perror("Select failed\n");
		close(sockfd);
		return(-1);
	}

	//  if((res = FD_ISSET(sockfd, &rset)) || (res = FD_ISSET(sockfd, &wset))) {
	if(FD_ISSET(sockfd, &rset) || FD_ISSET(sockfd, &wset)) {
		len = sizeof(serror);
		if(getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &serror, &len) < 0) {
			close(sockfd);
			return(-1);
		}
	} else {
		error("**** Socket not set..... ");
		perror("FD_SET: ");
		close(sockfd);
		exit(-1);
	}

done:
	if(fcntl(sockfd, F_SETFL, flags) == -1) {
		perror("Can't restore the socket opts\n");
		close(sockfd);
		return(-1);
	}

	if(serror) {
		errno = serror;
		close(sockfd);
		return(-1);
	}

	//printf("connectnb - socket: %d\n", sockfd);

	return(sockfd);

}


/* function to read from a socket returning after
 * the specified timeout if no data has been read
 */


int read_timeo(int sockfd, char *string, int max, int timeo) {

	struct timeval tv;

	int numbytes = 0;

	fd_set readfds;

	tv.tv_sec = timeo;
	tv.tv_usec = 500000;


	FD_ZERO(&readfds);
	FD_SET(sockfd, &readfds);


	select(sockfd+1, &readfds, NULL, NULL, &tv);

	if(FD_ISSET(sockfd, &readfds)) {
		if((numbytes=read(sockfd, string, max)) < 1) {
			return(0);
		} else {
			string[numbytes] = '\0';
		}
	} else {
		return(-1);
	}

	return(1);

}

char *get_hostname(const char *addr) {

	struct hostent *hn;
	struct in_addr *myaddr;

	myaddr=s_malloc(sizeof(struct in_addr));
	myaddr->s_addr=inet_addr(addr);


	if((hn = gethostbyaddr((char *) myaddr, 4, AF_INET)) == NULL) {
		free(myaddr);
		return((char *)addr);
	}

	free(myaddr);
	return((char *)hn->h_name);

}


