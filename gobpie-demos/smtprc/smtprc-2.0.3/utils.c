/***************************************************************************
                          utils.c  -  description
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


#include "utils.h"
#include "relay.h"
#include "options.h"

extern struct options o;
extern struct flags f;

extern host **hosts;


/*
 * Safe malloc routine. checks for errors etc..
 *
 */
 
void *s_malloc(unsigned long size) {

  void *mymem;
  if(size < 0) {
    fatal("Tried to allocate a negative amount of memory!!");
  }
  mymem=malloc(size);
  if(mymem == NULL) {
    fatal("Malloc failed! Probably out of memory!!");
  }

  return(mymem);
  
}

/*
 * Safe calloc routine, checks for errors and zeroes memory.
 *
 */
 
void *s_zmalloc(int size) {

  void *mymem;
  if(size < 0) {
    fatal("Tried to allocate a negative amount of memory!!");
  }
  mymem=calloc(1, size);
  if(mymem == NULL) {
    fatal("Malloc failed! Probably out of memory!!");
  }

  return(mymem);
  
}


/*
 * Like the perl equivilent, it removes the trailing
 * carraige return and or newline.
 *
 */
 
char *chomp(char *string) {

  int len;
  
  len = strlen(string);
  if(len < 1) {
    return(string);
  }
  if(string[len -1] != '\n' && string[len -1] != '\r') {
    return(string);
  }
  if(len > 1 && string[len-2] == '\r') {
    string[len-2] = '\0';
  }
  else {
    string[len-1] = '\0';
  }
  
  return(string);

}


/*
 * This funtion swaps out the macros for the equivelent text
 *
 */
 
void swap_rule(char *dest, const char *rule, const int hostn) {

	strncpy(dest, rule, MAXDATA);
	dest[MAXDATA] = '\0';

	if(strstr(rule, "--NAME--") != NULL) {
		swap_macro(dest, o.name, "--NAME--");
	}

	if(strstr(rule, "--DOMAIN--") != NULL) {
    swap_macro(dest, o.domain, "--DOMAIN--");
  }

	if(strstr(rule, "--IP_ADDRESS--") != NULL) {
    swap_macro(dest, hosts[hostn]->ip_address, "--IP_ADDRESS--");
  }

	if(strstr(rule, "--HOSTNAME--") != NULL && f.resolve_hostnames && hosts[hostn]->resolved) {
    swap_macro(dest, hosts[hostn]->hostname, "--HOSTNAME--");
  }
	else if(strstr(rule, "--HOSTNAME--") != NULL && f.resolve_hostnames) {
		swap_macro(dest, hosts[hostn]->ip_address, "--HOSTNAME--");
  }
		

	return;

}

/*
 * This is the guts of the swapping
 *
 */
 
void swap_macro(char *string, const char *replace, const char *macro) {

	char *p;
	char *buf;

	buf=s_malloc((MAXDATA + 1) * sizeof(char));

	while((p = strstr(string, macro)) != NULL) {
		memcpy(buf, string, p - string);
    buf[p - string] = '\0';
    p += strlen(macro);
    strncat(buf, replace, MAXDATA);
    strncat(buf, p, MAXDATA);
		buf[MAXDATA] = '\0';
		strncpy(string, buf, MAXDATA);
		string[MAXDATA] = '\0';
  }

	free(buf);

	return;

}


/*
 * This just added the "MAIL FROM:" etc to the
 * beginning of the lines
 *
 */
 
void convert_rule(char *string, int ind) {

	char *buf;

	buf=s_malloc((MAXDATA+1) * sizeof(char));

	if(ind == 1) {
		snprintf(buf, MAXDATA, "HELO %s\r\n", string);
		strncpy(string, buf, MAXDATA);
		string[MAXDATA] = '\0';
	}
	else if(ind == 2) {
		snprintf(buf, MAXDATA, "MAIL FROM:%s\r\n", string);
    strncpy(string, buf, MAXDATA);
    string[MAXDATA] = '\0';
  }
  else if(ind == 3) {
		snprintf(buf, MAXDATA, "RCPT TO:%s\r\n", string);
    strncpy(string, buf, MAXDATA);
    string[MAXDATA] = '\0';
  }

	return;

}


/*
 * prints debugging information only if the
 * debugging flag is set
 *
 */
 
void debug(char *fmt, ...) {

  if(f.debug) {
		va_list ap;
  	va_start(ap, fmt);
 		fflush(stdout);
		fprintf(stdout, "DEBUG: ");
  	vfprintf(stderr, fmt, ap);
  	fprintf(stderr, "\n");
  	va_end(ap);
	}

  return;

}

/*
 * Checks the output file by making sure it
 * can open it ok... It also saves the path
 * of the file in the path variable. If there
 * is no path then it just saves "./" as the path
 *
 */
 
int check_file_path(char *filename, char *path) {

  char *s;
  char *p;
  int slash_flag = 0;
  char *fn;

  FILE *fd;


  if((fd=fopen(filename, "w")) == NULL) {
    return(-1);
  }

  fclose(fd);

  fn=s_malloc((strlen(filename)+1) * sizeof(char));
  strncpy(fn, filename, strlen(filename));
  fn[strlen(filename)] = '\0';


  s=fn;
  
  while(*s++) {
    if(*s == '/') {
      p = s;
      slash_flag = 1;
    }
  }

  *++p = '\0';

   if(!slash_flag) {
    path = s_malloc((strlen(SLASHDOT) +2) * sizeof(char));
    strncpy(path, SLASHDOT, strlen(SLASHDOT));
    path[strlen(SLASHDOT)] = '\0';
  }
  else {
    strncpy(path, fn, MAXDATA);
    path[MAXDATA] = '\0';
  }

  
  free(fn);

  return(0);

}
  

void return_data(long cur_host, int rule, char *string) {

  char *buf;

  buf=s_zmalloc((MAXDATA+1) * sizeof(char));
  snprintf(buf, MAXDATA, "Subject: %s\r\n%s\r\n\r\n:SmtpRCKey:%d:%s:%d:\r\n\r\n.\r\n", o.email_subject, o.email, (int) o.time, hosts[cur_host]->ip_address, rule);

  strncpy(string, buf, MAXDATA);
  string[MAXDATA] = '\0';

}  

void set_defaults(void) {

	o.number_of_threads = THREAD_DEFAULT;
	o.c_timeout = CTIMEOUT;
	o.r_timeout = RTIMEOUT;
	o.m_timeout = MTIMEOUT;
	
	o.config_file=s_malloc((strlen(CONFIG_FILE)+1) * sizeof(char));
	strncpy(o.config_file, CONFIG_FILE, strlen(CONFIG_FILE));
	o.config_file[strlen(CONFIG_FILE)] = '\0';
	f.config_file = TRUE;
	
	o.email_template=s_malloc((strlen(EMAIL_TEMPLATE)+1) * sizeof(char));
	strncpy(o.email_template, EMAIL_TEMPLATE, strlen(EMAIL_TEMPLATE));
	o.email_template[strlen(EMAIL_TEMPLATE)] = '\0';
	f.email_template = TRUE;
	
}

void not_implemented(void) {

	fatal("Sorry, This function is not yet implemented");
	
}
  

