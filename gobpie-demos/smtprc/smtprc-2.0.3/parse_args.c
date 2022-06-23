/***************************************************************************
                          parse_args.c  -  description
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

#include "parse_args.h"
#include "usage.h"
#include "utils.h"

struct options o;
struct flags f;


void parse_args(int argc, char * const *argv) {


	char c;

	while((c = getopt(argc, argv, "ab:c:de:f:g:hi:j:k:l:m:no:p:qr:s:tu:vw:x:y:"))!=-1) {


		switch(c) {
			case 'a':		//display all results even those that pass
				f.display_all = TRUE;
				break;
			case 'b':  //email addy to use to replace --NAME-- --DOMAIN--
				f.send_email = TRUE;
				o.email_address=s_malloc((strlen(optarg)+1) * sizeof(char));
				strncpy(o.email_address, optarg, strlen(optarg));
				o.email_address[strlen(optarg)] = '\0';
				break;
			case 'c':  //Specify the config file to use
				f.config_file = TRUE;
				if((o.config_file=realloc(o.config_file, strlen((optarg)+1) * sizeof(char))) == NULL) {
					fatal("Realloc Error\n");
				}
				//o.config_file=s_malloc((strlen(optarg)+1) * sizeof(char));
				strncpy(o.config_file, optarg, strlen(optarg));
				o.config_file[strlen(optarg)] = '\0';
				break;
			case 'd':  //Switch on DEBUG MODE
				f.debug = TRUE;
				break;
			case 'e':  //Specify a local mailbox
				f.check_mailbox = TRUE;
				f.mbox = TRUE;
				o.mailbox=s_malloc((strlen(optarg)+1) * sizeof(char));
				strncpy(o.mailbox, optarg, strlen(optarg));
				o.mailbox[strlen(optarg)] = '\0';
				break;
			case 'f':	//Txtx file to output to
				not_implemented();
				f.output_text = TRUE;
				o.text_file=s_malloc((strlen(optarg)+1) * sizeof(char));
				strncpy(o.text_file, optarg, strlen(optarg));
				o.text_file[strlen(optarg)] = '\0';
				break;
			case 'h': //Display the help file
				usage(argv[0]);
				break;
			case 'i':	//specify an ip list
				f.ip_list = TRUE;
				o.ip_list=s_malloc((strlen(optarg)+1) * sizeof(char));
				strncpy(o.ip_list, optarg, strlen(optarg));
				o.ip_list[strlen(optarg)] = '\0';
				break;
			case 'j': //specify an auto config file
				f.auto_config = TRUE;
				o.auto_config_file=s_malloc((strlen(optarg)+1) * sizeof(char));
				strncpy(o.auto_config_file, optarg, strlen(optarg));
				o.auto_config_file[strlen(optarg)] = '\0';
				break;
			case 'k': //generate a config file
				f.generate_config = TRUE;
				o.generate_file=s_malloc((strlen(optarg)+1) * sizeof(char));
				strncpy(o.generate_file, optarg, strlen(optarg));
				o.generate_file[strlen(optarg)] = '\0';
				break;
			case 'l': //READ TIMEOUT
				o.c_timeout = atoi(optarg);
				break;
			case 'm': //TIME OUT before checking mail file
				o.m_timeout = atoi(optarg);
				break;
			case 'n': //Resolve hostnames
				f.resolve_hostnames = TRUE;
				break;
			case 'o': //PRINT OUTPUT IN MACHINE READABLE FORMAT
				f.output_machine = TRUE;
				o.machine_file=s_malloc((strlen(optarg)+1) * sizeof(char));
				strncpy(o.machine_file, optarg, strlen(optarg));
				o.machine_file[strlen(optarg)] = '\0';
				break;
			case 'p': //NUMBER OF THREADS
				o.number_of_threads = atoi(optarg);
				break;
			case 'q':
				f.display_only_ips = TRUE;
				break;
			case 'r': //READ TIMEOUT
				o.r_timeout = atoi(optarg);
				break;
			case 's': //IP RANGE TO SCAN
				f.ip_range = TRUE;
				o.ip_range=s_malloc((strlen(optarg)+1) * sizeof(char));
				strncpy(o.ip_range, optarg, strlen(optarg));
				o.ip_range[strlen(optarg)] = '\0';
				break;
			case 'u':  //maildir mailbox
				f.check_mailbox = TRUE;
				f.maildir = TRUE;
				o.mailbox=s_malloc((strlen(optarg)+1) * sizeof(char));
				strncpy(o.mailbox, optarg, strlen(optarg));
				o.mailbox[strlen(optarg)] = '\0';
				break;
			case 'v':		//be verbose
				f.verbose++;
				break;
			case 'w':  //output to html file
				f.output_html = TRUE;
				o.html_file=s_malloc((strlen(optarg)+1) * sizeof(char));
				strncpy(o.html_file, optarg, strlen(optarg));
				o.html_file[strlen(optarg)] = '\0';
				break;
			case 'x':  //output to html file
				not_implemented();
				f.output_xml = TRUE;
				o.xml_file=s_malloc((strlen(optarg)+1) * sizeof(char));
				strncpy(o.xml_file, optarg, strlen(optarg));
				o.xml_file[strlen(optarg)] = '\0';
			case 'y':  //specify email file
				f.email_template = TRUE;
				if((o.email_template=realloc(o.email_template, strlen((optarg)+1) * sizeof(char))) == NULL) {
					fatal("Realloc Error\n");
				}
				//o.email_template=s_malloc((strlen(optarg)+1) * sizeof(char));
				strncpy(o.email_template, optarg, strlen(optarg));
				o.email_template[strlen(optarg)] = '\0';;
				break;
			case 'z':  //output to html file
				not_implemented();
				f.output_machine = TRUE;
				o.machine_file=s_malloc((strlen(optarg)+1) * sizeof(char));
				strncpy(o.machine_file, optarg, strlen(optarg));
				o.machine_file[strlen(optarg)] = '\0';
			case'?':
				usage(argv[0]);
			default:
				usage(argv[0]);
		}
	}

	return;

}

int get_domain() {

	char *p;
	char *t;
	char email[strlen(o.email_address)+1];
	int flag = 0;

	strncpy(email, o.email_address, sizeof(email));

	p = o.email_address;

	while(*p++) {
		if(*p == '\0' || isalnum((int)*p) || *p == '.' || *p == '-' || *p == '_' || *p == '@') {
			if(*p == '@') {
				flag++;
				t = p;
				if(!isalnum((int)*++t)) {
					fatal("The email address you have supplied %s is incorrect!!\n", email);
				}
				t = p;
				if(!isalnum((int)*--t)) {
					fatal("The email address you have supplied %s is incorrect!!\n", email);
				}
				t = p;
				*t = '\0';
				t++;
				p++;
			}
		} else {
			fatal("The email address you have supplied %s is incorrect!!\n", email);
		}
	}
	if(!flag||flag>2) {
		fatal("The email address you have supplied %s is incorrect!!\n", email);
	}
	o.domain=s_malloc((strlen(t)+1) * sizeof(char));
	strncpy(o.domain, t, strlen(t));
	o.domain[strlen(t)] = '\0';
	o.name=s_malloc((strlen(o.email_address)+1) * sizeof(char));
	strncpy(o.name, o.email_address, strlen(o.email_address));
	o.name[strlen(o.email_address)] = '\0';

	debug("name: %s domain: %s\n", o.name, o.domain);

	return(0);

}

