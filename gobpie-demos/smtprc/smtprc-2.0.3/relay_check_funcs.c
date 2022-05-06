/***************************************************************************
                          relay_check_funcs.c  -  description
                             -------------------
    begin                : Wed May 28 2003
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


#include "relay_check_funcs.h"
#include "relay_check.h"
#include "relay.h"
#include "options.h"
#include "utils.h"
#include "connect.h"


extern struct options o;
extern struct flags f;

extern host **hosts;
extern rule **rules;

int write_smtp(int *sockfd, char *string, long cur_host) {

  int size = strlen(string);
	int ret = 0;

  if((ret=send(*sockfd, string, size, MSG_NOSIGNAL)) == -1) {
    if(errno == MSG_NOSIGNAL || ret != size) {
      hosts[cur_host]->fatal_error = 1;
      //free(hosts[cur_host]->smtp_check);
    } 
		else {
      hosts[cur_host]->fatal_error = 2;
      //free(hosts[cur_host]->smtp_check);
    }
    return(-1);
  }

  return(0);

}

int read_smtp(int *sockfd, char *dest, long cur_host) {

  int ret;

  if((ret=read_timeo(*sockfd, dest, MAXDATA, o.r_timeout)) == -1) {
    hosts[cur_host]->fatal_error = 3;
    //free(hosts[cur_host]->smtp_check);
    return(-1);
  }
  if(!ret) {
    hosts[cur_host]->fatal_error = 4;
    //free(hosts[cur_host]->smtp_check);
    return(-1);
  }

  return(0);

}


int check_banner(int *sockfd, long cur_host, int rule) {

  char *buf;
  int res = 0;


  buf=s_zmalloc((MAXDATA+1) * sizeof(char));

  if((res=read_smtp(sockfd, buf, cur_host)) == -1) {
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 1;
    free(buf);
    return(-1);
  }


  if(!strncmp(buf, "220", 3)) {
    hosts[cur_host]->smtp_check[rule]->r_banner=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_banner, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_banner[strlen(buf)] = '\0';
    free(buf);
    return(0);
  } else if(!strncmp(buf, "421", 3)) {
    hosts[cur_host]->fatal_error = 5;
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 2;
    hosts[cur_host]->smtp_check[rule]->r_banner=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_banner, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_banner[strlen(buf)] = '\0';
    free(buf);
    return(-1);
  } else if(!strncmp(buf, "521", 3)) {
    hosts[cur_host]->fatal_error = 5;
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 2;
    hosts[cur_host]->smtp_check[rule]->r_banner=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_banner, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_banner[strlen(buf)] = '\0';
    free(buf);
    return(-1);
  } else {
    hosts[cur_host]->fatal_error = 6;
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 2;
    hosts[cur_host]->smtp_check[rule]->r_banner=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_banner, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_banner[strlen(buf)] = '\0';
    free(buf);
    return(-1);
  }

  //Sould never reach here

  free(buf);
  return(-1);

}

int check_helo(int *sockfd, long cur_host, int rule) {

  char *buf;
  int res = 0;

  buf=s_zmalloc((MAXDATA+1) * sizeof(char));

  swap_rule(buf, rules[rule]->helo, cur_host);
  convert_rule(buf, 1);

  hosts[cur_host]->smtp_check[rule]->helo=s_malloc((strlen(buf)+1) * sizeof(char));
  strncpy(hosts[cur_host]->smtp_check[rule]->helo, buf, strlen(buf));
  hosts[cur_host]->smtp_check[rule]->helo[strlen(buf)] = '\0';

  if(write_smtp(sockfd, buf, cur_host) == -1) {
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 3;
    free(buf);
    return(-1);
  }

  memset(buf, 0x0, MAXDATA);

  if((res=read_smtp(sockfd, buf, cur_host)) == -1) {
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 4;
    free(buf);
    return(-1);
  }


  if(!strncmp(buf, "250", 3)) {
    hosts[cur_host]->smtp_check[rule]->r_helo=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_helo, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_helo[strlen(buf)] = '\0';
    free(buf);
    return(0);
  } else if(!strncmp(buf, "421", 3)) {
    hosts[cur_host]->fatal_error = 5;
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 5;
    hosts[cur_host]->smtp_check[rule]->r_helo=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_helo, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_helo[strlen(buf)] = '\0';
    free(buf);
    return(-1);
  } else {
    hosts[cur_host]->fatal_error = 6;
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 5;
    hosts[cur_host]->smtp_check[rule]->r_helo=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_helo, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_helo[strlen(buf)] = '\0';
    free(buf);
    return(-1);
  }

  free(buf);
  return(-1);

}

int check_mail_from(int *sockfd, long cur_host, int rule) {

  char *buf;
  int res = 0;

  buf=s_zmalloc((MAXDATA+1) * sizeof(char));

  swap_rule(buf, rules[rule]->mail_from, cur_host);
  convert_rule(buf, 2);

  hosts[cur_host]->smtp_check[rule]->mail_from=s_malloc((strlen(buf)+1) * sizeof(char));
  strncpy(hosts[cur_host]->smtp_check[rule]->mail_from, buf, strlen(buf));
  hosts[cur_host]->smtp_check[rule]->mail_from[strlen(buf)] = '\0';

  if(write_smtp(sockfd, buf, cur_host) == -1) {
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 6;
    free(buf);
    return(-1);
  }
  memset(buf, 0x0, MAXDATA);
  if((res=read_smtp(sockfd, buf, cur_host)) == -1) {
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 7;
    free(buf);
    return(-1);
  }

  if(!strncmp(buf, "250", 3)) {
    hosts[cur_host]->smtp_check[rule]->r_mail_from=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_mail_from, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_mail_from[strlen(buf)] = '\0';
    free(buf);
    return(0);
  } else if(buf[0] == '5' && isdigit(buf[1]) && isdigit(buf[2])) {
    hosts[cur_host]->smtp_check[rule]->passed = 3;
    hosts[cur_host]->smtp_check[rule]->r_mail_from=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_mail_from, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_mail_from[strlen(buf)] = '\0';
    free(buf);
    return(1);
  } else if(!strncmp(buf, "451", 3) || !strncmp(buf, "452", 3)) {
    hosts[cur_host]->fatal_error = 7;
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 8;
    hosts[cur_host]->smtp_check[rule]->r_mail_from=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_mail_from, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_mail_from[strlen(buf)] = '\0';
    free(buf);
    return(-1);
  } else if(!strncmp(buf, "421", 3)) {
    hosts[cur_host]->fatal_error = 5;
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 8;
    hosts[cur_host]->smtp_check[rule]->r_mail_from=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_mail_from, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_mail_from[strlen(buf)] = '\0';
    free(buf);
    return(-1);
  } else {
    hosts[cur_host]->fatal_error = 6;
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 8;
    hosts[cur_host]->smtp_check[rule]->r_mail_from=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_mail_from, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_mail_from[strlen(buf)] = '\0';
    free(buf);
    return(-1);
  }

  free(buf);
  return(-1);

}

int check_rcpt_to(int *sockfd, long cur_host, int rule) {

  char *buf;
  int res = 0;

  buf=s_zmalloc((MAXDATA+1) * sizeof(char));

  swap_rule(buf, rules[rule]->rcpt_to, cur_host);
  convert_rule(buf, 3);

  hosts[cur_host]->smtp_check[rule]->rcpt_to=s_malloc((strlen(buf)+1) * sizeof(char));
  strncpy(hosts[cur_host]->smtp_check[rule]->rcpt_to, buf, strlen(buf));
  hosts[cur_host]->smtp_check[rule]->rcpt_to[strlen(buf)] = '\0';

  debug("Check rcpt_to: sending %s", buf);

  if(write_smtp(sockfd, buf, cur_host) == -1) {
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 9;
    free(buf);
    return(-1);
  }
  memset(buf, 0x0, MAXDATA);
  if((res=read_smtp(sockfd, buf, cur_host)) == -1) {
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 10;
    free(buf);
    return(-1);
  }

  debug("Check rcpt_to: received %s", buf);

  if(!strncmp(buf, "250", 3)) {
    hosts[cur_host]->smtp_check[rule]->r_rcpt_to=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_rcpt_to, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_rcpt_to[strlen(buf)] = '\0';
    free(buf);
    return(0);
  } else if(buf[0] == '5' && isdigit(buf[1]) && isdigit(buf[2])) {
    hosts[cur_host]->smtp_check[rule]->passed = 4;
    hosts[cur_host]->smtp_check[rule]->r_rcpt_to=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_rcpt_to, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_rcpt_to[strlen(buf)] = '\0';
    free(buf);
    return(1);
  } else if(!strncmp(buf, "450", 3) || !strncmp(buf, "473", 3) || !strncmp(buf, "500", 3) || !strncmp(buf, "521", 3) || !strncmp(buf, "530", 3) || !strncmp(buf, "554", 3)) {
    hosts[cur_host]->smtp_check[rule]->passed = 4;
    hosts[cur_host]->smtp_check[rule]->r_rcpt_to=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_rcpt_to, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_rcpt_to[strlen(buf)] = '\0';
    free(buf);
    return(1);
  } else if(!strncmp(buf, "451", 3) || !strncmp(buf, "452", 3)) {
    hosts[cur_host]->fatal_error = 7;
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 11;
    hosts[cur_host]->smtp_check[rule]->r_rcpt_to=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_rcpt_to, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_rcpt_to[strlen(buf)] = '\0';
    free(buf);
    return(-1);
  } else if(!strncmp(buf, "421", 3)) {
    hosts[cur_host]->fatal_error = 5;
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 11;
    hosts[cur_host]->smtp_check[rule]->r_rcpt_to=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_rcpt_to, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_rcpt_to[strlen(buf)] = '\0';
    free(buf);
    return(-1);
  } else {
    hosts[cur_host]->fatal_error = 6;
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 11;
    hosts[cur_host]->smtp_check[rule]->r_rcpt_to=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_rcpt_to, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_rcpt_to[strlen(buf)] = '\0';
    free(buf);
    return(-1);
  }

  free(buf);
  return(-1);

}

int check_send_data_start(int *sockfd, long cur_host, int rule) {

  char *buf;
  int res = 0;

  buf=s_zmalloc((MAXDATA+1) * sizeof(char));

  if(write_smtp(sockfd, DATA, cur_host) == -1) {
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 12;
    free(buf);
    return(-1);
  }

  if((res=read_smtp(sockfd, buf, cur_host)) == -1) {
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 13;
    free(buf);
    return(-1);
  }

  if(!strncmp(buf, "354", 3)) {
    hosts[cur_host]->smtp_check[rule]->r_data_start=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_data_start, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_data_start[strlen(buf)] = '\0';
    free(buf);
    return(0);
  } else if(buf[0] == '5' && isdigit(buf[1]) && isdigit(buf[2])) {
    hosts[cur_host]->smtp_check[rule]->passed = 5;
    hosts[cur_host]->smtp_check[rule]->r_data_start=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_data_start, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_data_start[strlen(buf)] = '\0';
    free(buf);
    return(1);
  } else if(!strncmp(buf, "451", 3) || !strncmp(buf, "452", 3)) {
    hosts[cur_host]->fatal_error = 7;
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 14;
    hosts[cur_host]->smtp_check[rule]->r_data_start=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_data_start, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_data_start[strlen(buf)] = '\0';
    free(buf);
    return(-1);
  } else if(!strncmp(buf, "421", 3)) {
    hosts[cur_host]->fatal_error = 5;
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 14;
    hosts[cur_host]->smtp_check[rule]->r_data_start=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_data_start, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_data_start[strlen(buf)] = '\0';
    free(buf);
    return(-1);
  } else {
    hosts[cur_host]->fatal_error = 6;
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 14;
    hosts[cur_host]->smtp_check[rule]->r_data_start=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_data_start, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_data_start[strlen(buf)] = '\0';
    free(buf);
    return(-1);
  }

  free(buf);
  return(-1);
}

int check_send_data(int *sockfd, long cur_host, int rule) {

  char *buf;
  int res = 0;

  buf=s_zmalloc((MAXDATA+1) * sizeof(char));
  return_data(cur_host, rule, buf);

  if(write_smtp(sockfd, buf, cur_host) == -1) {
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 15;
    free(buf);
    return(-1);
  }
  memset(buf, 0x0, MAXDATA);
  if((res=read_smtp(sockfd, buf, cur_host)) == -1) {
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 16;
    free(buf);
    return(-1);
  }


  if(!strncmp(buf, "250", 3)) {
    hosts[cur_host]->smtp_check[rule]->r_data_end=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_data_end, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_data_end[strlen(buf)] = '\0';
    free(buf);
    return(0);
  } else if(!strncmp(buf, "550", 3) || !strncmp(buf, "55", 2) || !strncmp(buf, "571", 3)) {
    hosts[cur_host]->smtp_check[rule]->passed = 6;
    hosts[cur_host]->smtp_check[rule]->r_data_end=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_data_end, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_data_end[strlen(buf)] = '\0';
    free(buf);
    return(1);
  } else if(!strncmp(buf, "450", 3) || !strncmp(buf, "473", 3) || !strncmp(buf, "500", 3) || !strncmp(buf, "521", 3) || !strncmp(buf, "530", 3)) {
    hosts[cur_host]->smtp_check[rule]->passed = 6;
    hosts[cur_host]->smtp_check[rule]->r_data_end=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_data_end, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_data_end[strlen(buf)] = '\0';
    free(buf);
    return(1);
  } else if(!strncmp(buf, "451", 3) || !strncmp(buf, "452", 3)) {
    hosts[cur_host]->fatal_error = 7;
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 17;
    hosts[cur_host]->smtp_check[rule]->r_data_end=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_data_end, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_data_end[strlen(buf)] = '\0';
    free(buf);
    return(-1);
  } else if(!strncmp(buf, "421", 3)) {
    hosts[cur_host]->fatal_error = 5;
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 17;
    hosts[cur_host]->smtp_check[rule]->r_data_end=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_data_end, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_data_end[strlen(buf)] = '\0';
    free(buf);
    return(-1);
  } else {
    hosts[cur_host]->fatal_error = 6;
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 17;
    hosts[cur_host]->smtp_check[rule]->r_data_end=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_data_end, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_data_end[strlen(buf)] = '\0';
    free(buf);
    return(-1);
  }

  free(buf);
  return(-1);

}

int suspected_open_relay(long cur_host, int rule) {


  return(0);

}

int reset_smtp(int *sockfd, long cur_host, int rule) {

  char *buf;
  int res = 0;

  buf=s_zmalloc((MAXDATA+1) * sizeof(char));


  if(write_smtp(sockfd, RSET, cur_host) == -1) {
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 18;
    free(buf);
    return(-1);
  }

  if((res=read_smtp(sockfd, buf, cur_host)) == -1) {
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 19;
    free(buf);
    return(-1);
  }

  if(strncmp(buf, "250", 3)) {
    hosts[cur_host]->fatal_error = 8;
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 20;
    hosts[cur_host]->smtp_check[rule]->r_reset=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_reset, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_reset[strlen(buf)] = '\0';
    free(buf);
    return(-1);
  } else {
    hosts[cur_host]->smtp_check[rule]->r_reset=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->smtp_check[rule]->r_reset, buf, strlen(buf));
    hosts[cur_host]->smtp_check[rule]->r_reset[strlen(buf)] = '\0';
    free(buf);
    return(0);
  }


  free(buf);
  return(0);

}

int quit_smtp(int *sockfd, long cur_host, int rule) {

  char *buf;
  int res = 0;

  buf=s_zmalloc((MAXDATA+1) * sizeof(char));

  if(write_smtp(sockfd, QUIT, cur_host) == -1) {
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 21;
    free(buf);
    return(-1);
  }

  if((res=read_smtp(sockfd, buf, cur_host)) == -1) {
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 22;
    free(buf);
    return(-1);
  }

  if(strncmp(buf, "221", 3)) {
    hosts[cur_host]->fatal_error = 9;
    hosts[cur_host]->fatal = rule;
    hosts[cur_host]->smtp_check[rule]->error_code = 23;
    hosts[cur_host]->r_quit=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->r_quit, buf, strlen(buf));
    hosts[cur_host]->r_quit[strlen(buf)] = '\0';
    free(buf);
    return(-1);
  } else {
    hosts[cur_host]->r_quit=s_malloc((strlen(buf)+1) * sizeof(char));
    strncpy(hosts[cur_host]->r_quit, buf, strlen(buf));
    hosts[cur_host]->r_quit[strlen(buf)] = '\0';
    free(buf);
    return(0);
  }


  free(buf);
  return(0);

}

