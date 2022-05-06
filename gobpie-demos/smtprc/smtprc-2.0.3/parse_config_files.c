/***************************************************************************
                          parse_config_files.c  -  description
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


#include "parse_config_files.h"
#include "relay.h"
#include "smtprc_error.h"
#include "utils.h"
#include "options.h"

host **hosts;
rule **rules;

extern struct options o;
extern struct flags f;


/*
 * Parse ip address range into individual ip addresses
 *
 * This is really quite messy and could do with a rewrite
 * but it's staying for now.
 *
 */

int get_ip_range(char *iprange) {


	int start[4];
	int startc[4];
	int tstart[4];
	int tstartc[4];
	int end[4];
	int endc[4];
	int tend[4];
	int tendc[4];
	int i = 0;
	int last = 0;
	int hostnames = 0;
	char *r;
	char *t;
	char *p;
	char buf[MAXDATA+1];
	char *addy[5];
	char *temp[2];
	char *iprange2;
	char hostnamet[MAXDATA+1];

	if(strstr(iprange, "/")) {
		fatal("Netmask notation is not supported yet...... please use the format 192.168.*.1-255\n");
	}

	printf("\nCreating a list of IP's to scan....... Please wait!\n\n");


	if(strstr(iprange, ",") == NULL) {
		strncpy(buf, iprange, MAXDATA);
		buf[strlen(iprange)] ='\0';
		last = 1;
		goto GETIP;
	} else {
		p = iprange;
		t = p;
		while(*p++) {
			if(*p==',') {
				*p = '\0';
				p+=1;
				strncpy(buf, t, MAXDATA);
			GETIP:
				iprange2=s_malloc((strlen(buf)+1) * sizeof(char));
				strncpy(iprange2, buf, strlen(buf));
				iprange2[strlen(buf)] = '\0';

				addy[0] = addy[1] = addy[2] = addy[3] = addy[4] = NULL;

				addy[0] = r = buf;

				debug("R == %s\n", r);

				while(*++r) {
					if (*r == '.' && ++i < 4) {
						*r = '\0';
						addy[i] = (r + 1);
					} else if (*r != '.' && *r != '*' && *r != '-' && !isdigit((int)*r) && *r != '\n') {
						fatal("Invalid character in IP address notation\n");
					}
				}
				if(i!=3) {
					fatal("IP address format is illegal\n");
				}
				i = 0;

				for(i=0;i<4;i++) {
					if(*addy[i] == '*') {
						if(i==0) {
							fatal("For some reason I don't think it's wise scanning the whole bloody net\n\nBut if you sure then edit the source and remove this line\n");
						}
						if(i==1) {
							fprintf(stderr, "Sure you wanna scan a entire class A.... \n\n..... OK!\n\n");
						}
						start[i] = 1;
						startc[i] = 1;
						end[i] = 255;
						endc[i] = 255;
					} else {
						if((strstr(addy[i], "-")) != NULL) {
							temp[0] = addy[i];
							while(*addy[i] != '\n' && *addy[i] != '.' && *addy[i]) {
								if(*addy[i] == '-') {
									*addy[i] = '\0';
									temp[1] = addy[i] + 1;
									start[i] = atoi(temp[0]);
									startc[i] = atoi(temp[0]);
									end[i] = atoi(temp[1]);
									endc[i] = atoi(temp[1]);
								} else if (!isdigit((int)*addy[i])) {
									fatal("Invalid host specification\n");
								}
								if(*addy[i]++) {};
							}
						} else {
							start[i] = atoi(addy[i]);
							startc[i] = atoi(addy[i]);
							end[i] =  atoi(addy[i]);
							endc[i] =  atoi(addy[i]);
						}
					}
					tstart[i]=start[i];
					tstartc[i]=start[i];
					tend[i]=end[i];
					tendc[i]=endc[i];
					if((start[i] > end[i]) || (start[i]<0) || (end[i]>255)) {
						fatal("Invalid ip range\n");
					}
				}
				for(i=0;i<1;i++) {
					for(;start[i]<=end[i];start[i]++) {
						for(;start[i+1]<=end[i+1];start[i+1]++) {
							for(;start[i+2]<=end[i+2];start[i+2]++) {
								for(;start[i+3]<=end[i+3];start[i+3]++) {
									o.no_hostnames++;
								}
								start[i+3]=tstart[i+3];
								end[i+3]=tend[i+3];
							}
							start[i+2]=tstart[i+2];
							end[i+2]=tend[i+2];
						}
						start[i+1]=tstart[i+1];
						end[i+1]=tend[i+1];
					}
				}
				if(hosts == NULL) {
					hosts=s_malloc((o.no_hostnames + 1) * sizeof(host **));
				} else {
					hosts=realloc(hosts, (o.no_hostnames + 1) * sizeof(host **));
				}
				for(i=0;i<1;i++) {
					for(;startc[i]<=endc[i];startc[i]++) {
						for(;startc[i+1]<=endc[i+1];startc[i+1]++) {
							for(;startc[i+2]<=endc[i+2];startc[i+2]++) {
								for(;startc[i+3]<=endc[i+3];startc[i+3]++) {
									if(f.debug) {
										fprintf(stderr, "list == %i.%i.%i.%i\n", startc[i], startc[i+1], startc[i+2], startc[i+3]);
										fprintf(stderr, "end --> %i.%i.%i.%i\n", endc[i], endc[i+1], endc[i+2], endc[i+3]);
									}
									snprintf(hostnamet, MAXDATA, "%i.%i.%i.%i", startc[i], startc[i+1], startc[i+2], startc[i+3]);
									hosts[hostnames]=s_malloc(sizeof(host));
									hosts[hostnames]->resolved = 0;
									hosts[hostnames]->smtp_open = 0;
									hosts[hostnames]->fatal = 0;
									hosts[hostnames]->fatal_error = 0;
									hosts[hostnames]->ip_address=s_malloc((strlen(hostnamet)+1) * sizeof(char));
									strncpy(hosts[hostnames]->ip_address, hostnamet, strlen(hostnamet));
									hosts[hostnames]->ip_address[strlen(hostnamet)] = '\0';
									if(f.debug) {
										fprintf(stderr, "Hostname == %s", hosts[hostnames]->ip_address);
									}
									hostnames++;
								}
								startc[i+3]=tstartc[i+3];
								endc[i+3]=tendc[i+3];
							}
							startc[i+2]=tstartc[i+2];
							endc[i+2]=tendc[i+2];
						}
						startc[i+1]=tstartc[i+1];
						endc[i+1]=tendc[i+1];
					}
				}
				if(last) {
					goto END;
				}
				if(iprange2 != NULL) {
					free(iprange2);
					iprange2=NULL;
				}
				strncpy(buf, t, MAXDATA);
				t = p;
				i = 0;
			}
		}
		if(t) {
			if(iprange2 != NULL) {
				free(iprange2);
				iprange2 = NULL;
			}
			strncpy(buf, t, MAXDATA);
			t = p;
			i = 0;
			last = 1;
			goto GETIP;
		}
	}
END:

	if(iprange2 != NULL) {
		free(iprange2);
		iprange2 = NULL;
	}
	
	return(0);

}


int parse_config(char *configfile) {



	FILE *fd;
	int i=0;
	int nolines = 0;
	char *buf1;
	char buf2[3][250];
	char c;


	if((fd = fopen(configfile, "r")) == NULL) {
		fatal("Unable to open config file \"%s\"\n", configfile);
	}


	while((c=fgetc(fd))!=EOF)
		if(c=='\n') nolines++;
	nolines++;
	rewind(fd);

	rules=s_malloc(nolines * sizeof(rule **));

	i = 0;

	buf1=s_malloc((350+2) * sizeof(char));
	while(fgets(buf1,350,fd)) {
		if(buf1[0] == '#' || buf1[0] == '\n' || buf1[0] == ' ') continue;
		if((strstr(buf1, "--NAME--") != NULL) || (strstr(buf1, "--DOMAIN--") != NULL)) {
			if(!f.send_email) {
				fatal("You can only use the --NAME-- and --DOMAIN-- macro's if you supply the -b (email_address) option");
			}
			f.got_name_macro = 1;
		}
		if(!f.resolve_hostnames && (strstr(buf1, "--HOSTNAME--") != NULL)) {
			fatal("You can only use the --HOSTNAME-- macro's in the configuration file\nif you specify the -n option on the command line or set RESOLVEDOMAINS:Yes in the auto config file\n");
		}
		if(sscanf(buf1, "%240s%240s%240s", buf2[0], buf2[1], buf2[2])==3) {

			rules[i]=s_malloc(sizeof(rule *));

			rules[i]->helo=s_malloc((strlen(buf2[0]) + 1) * sizeof(char));
			strncpy(rules[i]->helo, buf2[0], strlen(buf2[0]));
			rules[i]->helo[strlen(buf2[0])] = '\0';
			debug("Rules->helo: %s\n", rules[i]->helo);

			rules[i]->mail_from=s_malloc((strlen(buf2[1]) + 1) * sizeof(char));
			strncpy(rules[i]->mail_from, buf2[1], strlen(buf2[1]));
			rules[i]->mail_from[strlen(buf2[1])] = '\0';
			debug("Rules->mail_from: %s\n", rules[i]->mail_from);

			rules[i]->rcpt_to=s_malloc((strlen(buf2[2]) + 1) * sizeof(char));
			strncpy(rules[i]->rcpt_to, buf2[2], strlen(buf2[2]));
			rules[i]->rcpt_to[strlen(buf2[2])] = '\0';
			debug("Rules->rcpt_to: %s\n", rules[i]->rcpt_to);
			o.no_rules++;
			i++;
		}

	}

	o.no_rules--;     //We need to reduce this as it will be to high by one.

	fclose(fd);

	return(0);

}

int get_email_file(char *email_file) {

	FILE *fd;

	char *p;
	char *t;
	char *s;
	char buf[MAXDATA+1];
	char c;
	char *temp;

	int subject = 0;
	int body = 0;
	int rflag=0;
	int nflag=0;
	int size=0;
	int count = 0;

	if((fd=fopen(email_file, "r"))==NULL) {
		fprintf(stderr, "\n\nERROR:\n\nUnable to open the email file [%s] you specified\nDo you wan to continue using the default?\n\n"
		        "Continue:\t[y] [n]\n:", email_file);
		if((c=fgetc(stdin)) == 'y' || ((c=fgetc(stdin)) == 'Y')) {
			f.got_email = 0;
			return(1);
		} else {
			exit(1);
		}
	}

	while(fgets(buf, MAXDATA, fd)) {
		if(!strncmp(buf, "SUBJECT:", 8)) {
			subject = 1;
			p = buf+8;
			if(*p!='\0') {
				if(f.debug) {
					fprintf(stderr, "DEBUG: email subject == [%s]\n", p);
				}
				size=strlen(p);
				if((t=strstr(p, "ENDSUBJECT"))!=NULL) {
					*t = '\0';
					size=strlen(p);
					o.email_subject=s_malloc((size+1) * sizeof(char));
					strncpy(o.email_subject, p, size);
					o.email_subject[size]='\0';
					break;
				}
				o.email_subject=s_malloc((size+1) * sizeof(char));
				strncpy(o.email_subject, p, size);
				o.email_subject[size]='\0';
			}
			do {
				if(fgets(buf, MAXDATA, fd)==NULL) {
					subject = 0;
					break;
				}
				size+=strlen(buf);
				if(f.debug) {
					fprintf(stderr, "DEBUG: email subject == [%s]\r\n", buf);
				}
				if((t=strstr(buf, "ENDSUBJECT"))!=NULL) {
					*t = '\0';
					size+=strlen(buf);
					if((o.email_subject=realloc(o.email_subject, (size+2) * sizeof(char))) == NULL) {
						fatal("Realloc Error\n");
					}
					strncat(o.email_subject, buf, size);
					o.email[size]='\0';
					break;
				}
				if((o.email_subject=realloc(o.email_subject, (size+1) * sizeof(char))) == NULL) {
					fatal("Realloc Error\n");
				}
				strncat(o.email_subject, buf, size);
				o.email[size]='\0';
			} while(strstr(buf, "ENDSUBJECT") == NULL);
		}
	}

	rewind(fd);

	while(fgets(buf, MAXDATA, fd)) {
		if(!strncmp(buf, "BODY:", 5)) {
			body = 1;
			p = buf+5;
			if(*p!='\0') {
				if(f.debug) {
					fprintf(stderr, "DEBUG: email body == [%s]\n", p);
				}
				size=strlen(p);
				if((t=strstr(buf, "ENDBODY"))!=NULL) {
					*t = '\0';
					size=strlen(buf);
					o.email=s_malloc((size+1) * sizeof(char));
					strncpy(o.email, p, size);
					o.email[size]='\0';
					break;
				}
				o.email=s_malloc((size+1) * sizeof(char));
				strncpy(o.email, p, size);
				o.email[size]='\0';
			}
			do {
				if(fgets(buf, MAXDATA, fd)==NULL) {
					body = 0;
					break;
				}
				size+=strlen(buf);
				if(f.debug) {
					fprintf(stderr, "DEBUG: email body == [%s]\n", buf);
				}
				if((t=strstr(buf, "ENDBODY"))!=NULL) {
					*t = '\0';
					size+=strlen(buf);
					if((o.email=realloc(o.email, (size+1) * sizeof(char))) == NULL) {
						fatal("Realloc Error\n");
					}
					strncat(o.email, buf, size);
					o.email[size]='\0';
					break;
				}
				if((o.email=realloc(o.email, (size+1) * sizeof(char))) == NULL) {
					fatal("Realloc Error\n");
				}
				strncat(o.email, buf, size);
				o.email[size]='\0';
			} while(strstr(buf, "ENDBODY")==NULL);
		}
	}

	if(!body || !subject) {
		fprintf(stderr, "\n\nERROR:\n\nEmail file is in the wrong format\n"
		        "Do you want to continue using the default?\n"
		        "\nContinue\t[y] [n]\t:");
		if((c=fgetc(stdin)) == 'y' || ((c=fgetc(stdin)) == 'Y')) {
			f.got_email = 0;
			return(1);
		} else {
			exit(1);
		}
	}
	if(!o.email) {
		fprintf(stderr, "\n\nERROR:\n\nThe body of your email is empty\n"
		        "Do you want to continue using the default?\n"
		        "\nContinue\t[y] [n]\t:");
		if((c=fgetc(stdin)) == 'y' || ((c=fgetc(stdin)) == 'Y')) {
			f.got_email = 0;
			return(1);
		} else {
			exit(1);
		}
	}
	if(!o.email_subject) {
		fprintf(stderr, "\n\nERROR:\n\nThe subject of your email is empty\n"
		        "Do you want to continue using the default?\n"
		        "\nContinue\t[y] [n]\t:");
		if((c=fgetc(stdin)) == 'y' || ((c=fgetc(stdin)) == 'Y')) {
			f.got_email = 0;
			return(1);
		} else {
			exit(1);
		}
	}
	if(strlen(o.email)<2) {
		fprintf(stderr, "\n\nERROR:\n\nThe body of your email contains 1 character\n"
		        "Do you want to continue using the default?\n"
		        "\nContinue\t[y] [n]\t:");
		if((c=fgetc(stdin)) == 'y' || ((c=fgetc(stdin)) == 'Y')) {
			f.got_email = 0;
			return(1);
		} else {
			exit(1);
		}
	}
	if(strlen(o.email_subject)<2) {
		fprintf(stderr, "\n\nERROR:\n\nThe subject of your email contains 1 character\n"
		        "Do you want to continue using the default?\n"
		        "\nContinue\t[y] [n]\t:");
		if((c=fgetc(stdin)) == 'y' || ((c=fgetc(stdin)) == 'Y')) {
			f.got_email = 0;
			return(1);
		} else {
			exit(1);
		}
	}

	p=o.email_subject;
	do {
		if(*p == '\n') {
			nflag++;
		}
		if(*p == '\r') {
			rflag++;
		}
	}	while(*p++!='\0');
	if(nflag > 1 || rflag > 1) {
		fprintf(stderr, "\n\nERROR:\n\nThere is more than one line feed in the email subject\n"
		        "Do you want to continue using the default?\n"
		        "\nContinue\t[y] [n]\t:");
		if((c=fgetc(stdin)) == 'y' || ((c=fgetc(stdin)) == 'Y')) {
			f.got_email = 0;
			return(1);
		} else {
			exit(1);
		}
	} else if(nflag == 0 && rflag == 0) {
		strcat(o.email_subject, "\r\n");
	} else if(nflag == 0 && rflag == 1) {
		strcat(o.email_subject, "\r");
	} else if(nflag == 1 && rflag == 1) {
		nflag = 0;
		rflag = 0;
		p=o.email_subject;
		do {
			if(*p == '\n') {
				s=p;
				if(--*s == '\r') {
					rflag++;
				}
			}
		} while(*p++!='\0');
		if(!rflag) {
			fprintf(stderr, "\n\nERROR:\n\nThere is supurious carraige return in the subject\n"
			        "Do you want to continue using the default?\n"
			        "\nContinue\t[y] [n]\t:");
			if((c=fgetc(stdin)) == 'y' || ((c=fgetc(stdin)) == 'Y')) {
				f.got_email = 0;
				return(1);
			} else {
				exit(1);
			}
		}
	}
	temp=s_malloc((strlen(o.email)+1) * sizeof(char));
	strncpy(temp, o.email, strlen(o.email));
	p=temp;
	rflag = 0;
	count = 0;
	memset(buf, 0x0, MAXDATA);
	do {
		if(*p == '\n') {
			if(!count) {
				strncat(buf, "\r\n", MAXDATA);
				rflag++;
				rflag++;
				continue;
			}
			s=p;
			if(--*s != '\r') {
				strncat(buf, "\r\n", MAXDATA);
				rflag++;
				rflag++;
				continue;
			}
		}
		if(*p == '\0') {
			break;
		}
		buf[rflag] = *p;
		count++;
		rflag++;
	} while(*p++!='\0');
	if((o.email=realloc(o.email, (strlen(buf)+1) * sizeof(char))) == NULL) {
		fatal("Realloc Error\n");
	}
	strncpy(o.email, buf, strlen(buf));
	o.email[strlen(buf)]='\0';
	if(f.debug) {
		fprintf(stderr, "DEBUG: end subject == [%s]\n", o.email_subject);
		fprintf(stderr, "DEBUG: end body == [%s]\n", o.email);
	}
	
	free(temp);

	return(0);

}

int parse_aconfig() {


	FILE *fd;
	char buf[MAXDATA];
	char *p;


	if((fd = fopen(o.auto_config_file, "r")) == NULL) {
		fatal("Unable to open auto config file %s\n\n", o.auto_config_file);
	}

	while(fgets(buf, MAXDATA-1, fd)!=NULL) {
		if(buf[0] == '#' || buf[1] == '#' || buf[0] == ' ' || buf[0] == '\n') {
			continue;
		}

		if(!strncmp(buf, "IPRANGE:", 8)) {
			if(!f.ip_range) {
				p = &buf[8];
				f.ip_range = TRUE;
				o.ip_range=s_malloc((strlen(p)+1)*sizeof(char));
				strncpy(o.ip_range, chomp(p), strlen(p));
				o.ip_range[strlen(p)] = '\0';
			}
		} else if(!strncmp(buf, "CONFIGFILE:", 11)) {
			if(!f.config_file) {
				p = &buf[11];
				f.config_file = TRUE;
				o.config_file=s_malloc((strlen(p)+1)*sizeof(char));
				strncpy(o.config_file, chomp(p), strlen(p));
				o.config_file[strlen(p)]='\0';
			}
		} else if(!strncmp(buf, "WEBPAGE:", 8)) {
			if(!f.output_html) {
				p = &buf[8];
				f.output_html = TRUE;
				o.html_file=s_malloc((strlen(p)+1) * sizeof(char));
				strncpy(o.html_file, chomp(p), strlen(p));
				o.html_file[strlen(p)] = '\0';
				//open_file(o.html_file);
			}
		} else if(!strncmp(buf, "THREADS:", 8)) {
			if(!f.threads) {
				p = &buf[8];
				o.number_of_threads = atoi(p);
			}
		} else if(!strncmp(buf, "IPLIST:", 7)) {
			if(!f.ip_list) {
				p = &buf[7];
				if(f.ip_range) {
					fatal("IPLIST and IPRANGE can't both be define in the config file\n");
				}
				f.ip_list = TRUE;
				o.ip_list=s_malloc((strlen(p)+1)*sizeof(char)+1);
				strncpy(o.ip_list, chomp(p), strlen(p));
				o.ip_list[strlen(p)] = '\0';
			}
		} else if(!strncmp(buf, "RELAYEMAIL:", 11)) {
			if(!f.send_email) {
				p = &buf[11];
				f.send_email = TRUE;
				o.email_address=s_malloc((strlen(p)+1)*sizeof(char));
				strncpy(o.email_address, chomp(p), strlen(p));
				o.email_address[strlen(p)]='\0';
			}
		} else if(!strncmp(buf, "MBOXMAILBOX:", 12)) {
			if(!f.check_mailbox) {
				p = &buf[12];
				f.check_mailbox = TRUE;
				f.mbox	= TRUE;
				o.mailbox=s_malloc((strlen(p)+1)*sizeof(char));
				strncpy(o.mailbox, chomp(p), strlen(p));
				o.mailbox[strlen(p)] = '\0';
			}
			f.mbox = TRUE;
		} else if(!strncmp(buf, "MAILDIRMAILBOX:", 15)) {
			if(!f.check_mailbox) {
				p = &buf[15];
				f.check_mailbox = TRUE;
				f.maildir = TRUE;
				o.mailbox=s_malloc((strlen(p)+1)*sizeof(char));
				strncpy(o.mailbox, chomp(p), strlen(p));
				o.mailbox[strlen(p)] = '\0';
			}
			f.maildir = TRUE;
		} else if(!strncmp(buf, "ALLSCANS:", 9)) {
			p = &buf[9];
			if(!strncmp(p, "Yes", 3)||!strncmp(p, "YES", 3)||!strncmp(p, "yes", 3)) {
				f.display_all = TRUE;
			}
		} else if(!strncmp(buf, "RESOLVEDOMAINS:", 15)) {
			p = &buf[15];
			if(!strncmp(p, "Yes", 3)||!strncmp(p, "YES", 3)||!strncmp(p, "yes", 3)) {
				f.resolve_hostnames = TRUE;
			}
		} else if(!strncmp(buf, "CONNECTTIMEOUT:", 15)) {
			if(!o.c_timeout) {
				p = &buf[15];
				o.c_timeout = atoi(p);
			}
		} else if(!strncmp(buf, "READTIMEOUT:", 12)) {
			if(!o.r_timeout) {
				p = &buf[12];
				o.r_timeout = atoi(p);
			}
		} else if(!strncmp(buf, "WAITFORMAILTIME:", 16)) {
			if(!o.m_timeout == MTIMEOUT) {
				p = &buf[16];
				o.m_timeout = atoi(p);
			}
		} else if(!strncmp(buf, "EMAILTEMPLATE:", 14)) {
			if(!f.got_email) {
				p = &buf[14];
				f.got_email = TRUE;
				o.email_template=s_malloc((strlen(p)+1)*sizeof(char));
				strncpy(o.email_template, chomp(p), strlen(p));
				o.email_template[strlen(p)] = '\0';
			}
		} else if(!strncmp(buf, "DISPLAYONLYIPS:", 15)) {
			p = &buf[15];
			if(!strncmp(p, "Yes", 3)||!strncmp(p, "YES", 3)||!strncmp(p, "yes", 3)) {
				f.display_only_ips = TRUE;
			}
		} else {
			fatal("Detected error \"%s\" in configuration file...\n", buf);
		}
	}

	return(0);
}



