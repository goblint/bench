/***************************************************************************
                          scan_engine.c  -  description
                             -------------------
    begin                : Mon May 26 2003
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


#include "scan_engine.h"
#include "relay.h"
#include "options.h"
#include "smtprc_error.h"
#include "utils.h"
#include "connect.h"
#include "relay_check.h"


extern struct options o;
extern struct flags f;

extern host **hosts;
extern rule **rules;

pthread_mutex_t main_thread_count_mutex; //mutex for the main thread counter

void start_scan(void) {

	struct timespec tv;
	pthread_t c_tid;
	pthread_attr_t attr;
	unsigned char flag = 0;
	unsigned char res = 0;
	int x = 0;
	int ret =0;
	size_t stack_size;
	tv.tv_sec = 0;
	tv.tv_nsec = 500000000;


	/* use if we want to start in a detached state but im not going to do this for now
	 * im going to try and join the threads instead
	 *
	 * pthread_attr_init(&attr);
	 * pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	 *
	 */

	pthread_mutex_init(&main_thread_count_mutex, NULL);

	if((ret = pthread_attr_getstacksize(&attr, &stack_size)) != 0) {
		fatal("cannot get stacksize");
	}

	debug("\n\nstack size: %d\n", stack_size);

	stack_size = (PTHREAD_STACK_MIN + 0x3000);
	ret = pthread_attr_init (&attr);

	if((ret = pthread_attr_setstacksize(&attr, stack_size)) != 0) {
		fatal("cannot setting stacksize");
	}

	if((ret = pthread_attr_getstacksize(&attr, &stack_size)) != 0) {
		fatal("cannot get stacksize");
	}

	debug("\n\nstack size: %d\n", stack_size);


	o.tid=s_malloc((o.no_hostnames + 1) * sizeof(pthread_t));

	for(x=0;x<o.no_hostnames;x++) {
		o.tid[x] = (pthread_t)0;
	}

	if(pthread_create(&c_tid, &attr, (void *)cleaner_start, NULL) != 0) {
		fatal("Unable to start cleaner thread");
		perror("aa");
	}

	for(o.cur_host=0;o.cur_host<o.no_hostnames;o.cur_host++) {
		pthread_mutex_lock(&main_thread_count_mutex);
		while(o.cur_threads>=o.number_of_threads) {
			pthread_mutex_unlock(&main_thread_count_mutex);
			debug("Sleeping cur child == %d, max child == %d\n", o.cur_threads, o.number_of_threads);
			nanosleep(&tv, NULL);
		}
		pthread_mutex_unlock(&main_thread_count_mutex);
		while((res = pthread_create(&c_tid, &attr, (void *)thread_start, (int *)o.cur_host)) != 0) {
			if(res != EAGAIN) {
				fatal("Unable to create thread - (try reducing the number of threads)\n");
			}
			if(!flag) {
				error("** Failed to create thread!!\nTrying to use sleep to compensate.... although you should run this again with a lower value for -p\n\n");
				flag++;
			}
			usleep(200000);
		}
		//printf("c_tid: %d\n", c_tid);
		debug("Created thread\n");
		pthread_mutex_lock(&main_thread_count_mutex);
		o.cur_threads++;
		pthread_mutex_unlock(&main_thread_count_mutex);
	}
	flag = 0;
	pthread_mutex_lock(&main_thread_count_mutex);
	while(o.cur_threads>0) {
		pthread_mutex_unlock(&main_thread_count_mutex);
		flag++;
		if(f.debug||f.verbose>1) {
			if(flag>1) {
				fprintf(stderr, "O.cur_childs(%d) id greater than zero...... sleepingz\n",o.cur_threads);
				flag = 0;
			}
		}
		nanosleep(&tv, NULL);
	}
	pthread_mutex_unlock(&main_thread_count_mutex);
	//pthread_attr_destroy(&attr);

	return;

}


int cleaner_start(void) {

	/*
	 * This is the cleaner thread it scans the
	 * thread exit global variable for any threads
	 * that have exited and then joins them clearing
	 * up any resources they've used.
	 *
	 */

	int x = 0;


	while(1) {
		for(x=0;x<o.no_hostnames;x++) {
			if((int)o.tid[x]) {
				if(!pthread_join(o.tid[x], NULL)) {
					pthread_mutex_lock(&main_thread_count_mutex);
					o.cur_threads--;	
					pthread_mutex_unlock(&main_thread_count_mutex);
					//printf("REAPER KILLED: %d\n", (int)o.tid[x]);
					o.tid[x] = (pthread_t)0;
				}
			}
		}
		usleep(200000);
	}


	return(0);

}

int thread_start(long cur_host) {

	int sockfd;
	int counter = 0;
	int x=0;
	int res=0;
	long ip;
	char hostnamer[MAXDATA+1];


	debug("Starting thread_start process\n");
	debug("hostname == %s o.cur_host == %d\n", hosts[cur_host]->ip_address, (int)cur_host);


	//convert ip address into0 the correct format.
	if((ip = get_ip(hosts[cur_host]->ip_address)) == -1) {
		//couldn't convert ip address... quit this thread.
		debug("Couldn't resolve ip\n");
		o.tid[cur_host] = pthread_self();
		return(int)(NULL);
	}
	//connect to port 25 on this ip address and
	//return a valid socket descriptor.

	if((sockfd = tcp_connect(ip)) != -1) {
		counter++;
		//printf("SOCKET == %u, COUNT == %d\n", sockfd, counter);
		if(f.resolve_hostnames) {
			strncpy(hostnamer, get_hostname(hosts[cur_host]->ip_address), MAXDATA);
			hostnamer[MAXDATA] = '\0';
			if(strncmp(hosts[cur_host]->ip_address, hostnamer, strlen(hosts[cur_host]->ip_address))) {
				hosts[cur_host]->hostname=s_malloc((strlen(hostnamer)+1)*sizeof(char));
				strncpy(hosts[cur_host]->hostname, hostnamer, strlen(hostnamer));
				hosts[cur_host]->hostname[strlen(hostnamer)] = '\0';
				hosts[cur_host]->resolved = 1;
			}
		}
		hosts[cur_host]->smtp_open = 1;
		hosts[cur_host]->smtp_check=s_malloc((o.no_rules + 1) * sizeof(check **));
		for(x=0;x<=o.no_rules;x++) {
			hosts[cur_host]->smtp_check[x]=s_malloc(sizeof(check));
			hosts[cur_host]->smtp_check[x]->failed = 0;
			hosts[cur_host]->smtp_check[x]->passed = 0;
			hosts[cur_host]->smtp_check[x]->error_code = 0;
		}
		//hosts[cur_host]->smtp_check[o.no_rules]->error_code = 8;
		if((res=relay_check(&sockfd, cur_host)) == -1) {
			close(sockfd);
		}
		close(sockfd);
	} else {
		//printf("Can't connect to %s\n", hosts[cur_host]->ip_address);
		close(sockfd);
	}


	o.tid[cur_host] = pthread_self();
	//printf("DIED: %d\n", o.tid[cur_host]);
	return(int)(NULL);
}

