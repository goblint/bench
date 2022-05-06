/***************************************************************************
 *   Copyright (C) 2004 by Spencer Hardy                                   *
 *   spencer@warg.co.uk                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#include "parse_mailbox.h"
#include "relay.h"
#include "options.h"
#include "utils.h"
#include "check_mail_file.h"

extern struct options o;


int parse_mbox(void) {

	FILE *fd;

	char buf[MAXDATA+1];
	char temp[MAXDATA+1];
	char *email_address = NULL;


	if((fd=fopen(o.mailbox, "r")) == NULL) {
		fprintf(stderr, "Unable to open %s for reading\n", o.mailbox);
		exit(1);
	}

	while(fgets(buf, MAXDATA, fd) != NULL) {
	START:
		strncpy(temp, buf, MAXDATA);
		temp[MAXDATA] = '\0';
		if(is_mbox_seperator(temp)) {
			strncpy(temp, buf, MAXDATA);
			temp[MAXDATA] = '\0';
			if((email_address = get_sender_address(temp)) == NULL) {
				continue;
			}
			while(fgets(buf, MAXDATA, fd) != NULL) {
				if(!strncmp(buf, ":SmtpRCKey:", 11)) {
					check_mail_file(email_address, buf);
				}
				strncpy(temp, buf, MAXDATA);
				temp[MAXDATA] = '\0';
				if(is_mbox_seperator(temp)) {
					goto START;
				}
			}
		}
	}


	fclose(fd);

	return(0);

}


int parse_maildir(void) {

	DIR             *dip;
	
	FILE *fd;
	
	struct dirent   *dit;
	
	char dir[MAXDATA+1];
	char buf[MAXDATA+1];
	char temp[MAXDATA+1];
	char filename[MAXDATA+1];
	char *email_address = NULL;

	
	if(o.mailbox[strlen(o.mailbox)] == '/') {
		snprintf(dir, MAXDATA, "%snew", o.mailbox);
	}
	else {
		snprintf(dir, MAXDATA, "%s/new", o.mailbox);
	}
	
	dir[MAXDATA] = '\0';

	if ((dip = opendir(dir)) == NULL) {
		perror("opendir");
		fatal("error opening maildir folder (%s)", dir);
	}

	while ((dit = readdir(dip)) != NULL) {
		if(dit->d_name[0] == '.' && strlen(dit->d_name) < 3) {
			continue;
		}
		snprintf(filename, MAXDATA, "%s/%s", dir, dit->d_name);
		filename[MAXDATA] = '\0';
		if((fd=fopen(filename, "r")) == NULL) {
			fprintf(stderr, "Unable to open mailfile (%s) for reading... Skipping\n", filename);
			continue;
		}
		while(fgets(buf, MAXDATA, fd) != NULL) {
			if(!strncmp(buf, "From: ", 6)) {
				strncpy(temp, buf, MAXDATA);
				temp[MAXDATA] = '\0';
				if((email_address = get_sender_address(temp)) == NULL) {
					continue;
				}
			}
			if(!strncmp(buf, ":SmtpRCKey:", 11)) {
				check_mail_file(email_address, buf);
			}
		}
	}


	if (closedir(dip) == -1) {
		perror("closedir");
		return 0;
	}


	return(0);

}

int parse_popbox(void) {


	return(0);

}


int is_mbox_seperator(char *string) {

	char tmp[9][MAXDATA+1];
	int count = 0;
	char *word;

	if(strncmp(string, "From ", 5)) {
		//printf("1didn't match\n");
		return(0);
	} else {
		for(word=strtok(string, " ");word;word=strtok(NULL, " ")) {
			count++;
			if(count<8) {
				strncpy(tmp[count], word, MAXDATA-1);
			}
		}

		if(count == 7) {
			return(1);
		} else {
			return(0);
		}
	}
}



char *get_sender_address(char *string) {

	int count = 0;
	char *word;
	char *address = NULL;

	for(word=strtok(string, " ");word;word=strtok(NULL, " ")) {
		count++;
		if(count==2 && strlen(word) > 5) {
			address=s_malloc((strlen(word)+1) * sizeof(char));
			strncpy(address, word, strlen(word)+2);
			address[strlen(word)+1] = '\0';
			break;
		}
	}

	if(address != NULL) {
		//printf("returning address: %s\n", address);
		return(address);
	} else {
		return(NULL);
	}
}















