/***************************************************************************
                          display_html.c  -  description
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


#include "check_mail_file.h"
#include "relay.h"
#include "options.h"
#include "utils.h"


extern struct options o;

extern host **hosts;
extern rule **rules;

int check_mail_file(char *email_address, char *key) {

	char mac_buf[MAXDATA+1];
	char tmp[9][MAXDATA+1];
	char *word;

	int count = 0;
	int emailc = 0;
	int x = 0;
	int y = 0;
	int flag = 0;
	
	if(email_address == NULL) {
		return(0);
	}


	for(x=0;x<o.no_hostnames;x++) {
		if(!hosts[x]->smtp_open) {
			continue;
		}
		for(y=0;y<o.no_rules;y++) {
			swap_rule(mac_buf, rules[y]->mail_from, x);
			if(!strncmp(email_address, mac_buf, strlen(mac_buf))) {
				emailc++;
			}
		}
	}
	if(!emailc) {
		return(0);
	} else {
		for(word=strtok(key, ":");word;word=strtok(NULL, ":")) {
			count++;
			if(count<6) {
				strncpy(tmp[count], word, MAXDATA);
				tmp[count][MAXDATA] = '\0';
			}
		}
		if(atoi(tmp[2]) == o.time) {
			for(x = 0;x < o.no_hostnames;x++) {
				y = 0;
				if(strlen(tmp[3]) != strlen(hosts[x]->ip_address)) {
					continue;
				}
				while(tmp[3][y]) {
					if(tmp[3][y] != hosts[x]->ip_address[y]) {
						flag++;
					}
					y++;
				}
				if(!flag) {
					//printf("1*%s*(%d) - 1*%s*(%d)\n", tmp[3], strlen(tmp[3]), hosts[x]->ip_address, strlen(hosts[x]->ip_address));
					hosts[x]->smtp_check[atoi(tmp[4])]->failed = 2;
				}
				flag = 0;
				y = 0;
			}
		}
	}

	//Check for Blind or anonymous SMTP relay's (not yet implemented)
	return(0);

}





