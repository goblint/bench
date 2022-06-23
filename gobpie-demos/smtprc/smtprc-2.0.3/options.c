/***************************************************************************
                          options.c  -  description
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


#include "smtprc_error.h"
#include "options.h"
#include "utils.h"
#include "relay.h"

extern struct options o;
extern struct flags f;


void validate_options(void) {

	FILE *fd;
	
	DIR *dip;
	
	char dir[MAXDATA+1];
	char buf[MAXDATA+1];

	if(f.ip_range && f.ip_list) {
		fatal("You cannont supply both an ip list and ip range\n");
	}

	if(f.auto_config && f.generate_config) {
		fatal("You can only generate the auto config file from command line options. You cannot also specify the \'-j\' option.\n");
	}

	if(!f.ip_range && !f.ip_list) {
		fatal("You must supply either an ip range or a file that contains a list of ip addresses to scan.\n");
	}

	if(o.number_of_threads < 5) {
		fatal("You can only scan with a minumum of 5 threads... please increas the number of threads.\n");
	}

	if(f.output_html) {
		if(check_file_path(o.html_file, buf) == -1) {
			fatal("Unable to open output HTML file %s", o.html_file);
		}
		o.html_path=s_malloc((strlen(buf) +1) * sizeof(char));
		strncpy(o.html_path, buf, strlen(buf));
		o.html_path[strlen(buf)] = '\0';
	}

	if(f.output_text) {
		if(check_file_path(o.text_file, buf) == -1) {
			fatal("Unable to open output TEXT file %s", o.text_file);
		}
		o.text_path=s_malloc((strlen(buf) +1) * sizeof(char));
		strncpy(o.text_path, buf, strlen(buf));
		o.text_path[strlen(buf)] = '\0';
	}

	if(f.output_machine) {
		if(check_file_path(o.machine_file, buf) == -1) {
			fatal("Unable to open output MACHINE file %s", o.machine_file);
		}
		o.machine_path=s_malloc((strlen(buf) +1) * sizeof(char));
		strncpy(o.machine_path, buf, strlen(buf));
		o.machine_path[strlen(buf)] = '\0';
	}

	if(f.output_xml) {
		if(check_file_path(o.xml_file, buf) == -1) {
			fatal("Unable to open output XML file %s", o.xml_file);
		}
		o.xml_path=s_malloc((strlen(buf) +1) * sizeof(char));
		strncpy(o.xml_path, buf, strlen(buf));
		o.xml_path[strlen(buf)] = '\0';
	}

	if(f.maildir) {
		if(o.mailbox[strlen(o.mailbox)] == '/') {
			snprintf(dir, MAXDATA, "%snew", o.mailbox);
		} else {
			snprintf(dir, MAXDATA, "%s/new", o.mailbox);
		}

		dir[MAXDATA] = '\0';

		if ((dip = opendir(dir)) == NULL) {
			fatal("Unable to open maildir folder (%s)", dir);
		}
	}
	
	if(f.mbox) {
		if((fd=fopen(o.mailbox, "r")) == NULL) {
			fatal("Unable to mbox (%s)\n", o.mailbox);
		}
	}

	if((f.mbox + f.maildir + f.pop) > 1) {
		fatal("You can only supply one mail retreival format");
	}
	
	if(!f.config_file) {
		printf("\nConfig file not specified, using the default location (%s)\n", o.config_file);
		f.config_file = TRUE;
	}
	
	if(!f.email_template) {
		printf("\nEmail template not specified, using the default location (%s)\n", o.email_template);
		f.email_template = TRUE;
	}
	
	

	o.time = time(NULL);



	return;

}

