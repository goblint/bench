/***************************************************************************
                          smtprc.c  -  description
                             -------------------
    begin                : Wed May 21 08:13:08 BST 2003
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


#include "relay.h"
#include "utils.h"
#include "usage.h"
#include "parse_args.h"
#include "parse_config_files.h"
#include "scan_engine.h"
#include "display_html.h"
#include "display_machine.h"
#include "display_screen.h"
#include "display_text.h"
#include "display_xml.h"
#include "parse_mailbox.h"


extern struct options o;
extern struct flags f;

extern rule **rules;
extern host **hosts;


int main(int argc, char *argv[]) {

	//char *rule_test;
	time_t b_seconds = 0;		//time when starting scanning
	time_t a_seconds = 0;		//time after scanning
	int t_diff;							//difference between the two times;


	/*
	 * Parse command line args,
	 * validate all options and then parse
	 * all config files
	 *
	 */

	banner();                           //surprisingly, this displays the banner
	set_defaults();											// set program defaults
	parse_args(argc, argv);             //parses the command line args
	if(f.auto_config) {
		parse_aconfig();									//parse auto config file
	}								                    
	validate_options();                 //validate options
	get_ip_range(o.ip_range);           //parse the ip range and save into memory
	parse_config(o.config_file);        //parse the checks config file
	get_domain();                       //parse the email address
	get_email_file(o.email_template);   //parse the template file

	/*
	 * All configs passed... now it's time
	 * to start scanning for open relays
	 *
	 */

	printf("Starting the scan....... Please wait!\n\n\n");


	b_seconds = time(NULL);

	start_scan();

	a_seconds = time(NULL);

	if(b_seconds  == -1 || a_seconds == -1 || a_seconds == b_seconds) {
		a_seconds = 20;
		b_seconds = 0;
	}

	/*
	 * Work out the time it took to perform the scan
	 *
	 */

	t_diff = (a_seconds - b_seconds);

	o.hours = t_diff/(60*60);
	t_diff -= o.hours*(60*60);
	o.mins = t_diff/(60);
	t_diff -= o.mins*(60);
	o.seconds = t_diff;






	/*
	 * Scanning finished... lets display all of the results.
	 *
	 */

	if(f.check_mailbox) {
		printf("\n\n\nFinished Scanning, Waiting %d seconds for mails to arrive......\n\n", o.m_timeout);
		sleep(o.m_timeout);
		printf("Checking mail....... Please Wait!\n");
		if(f.maildir) {
			parse_maildir();
		}
		else if(f.mbox) {
			parse_mbox();
		}
		else if(f.pop) {
			parse_popbox();
		}		
	}


	if(f.output_html) {
		printf("\n\nGenerating HTML results...... Please wait.\n\n");
		display_html();
	}

	if(f.output_text) {
		printf("\n\nGenerating TEXT results...... Please wait.\n\n");
		display_text();
	}

	if(f.output_machine) {
		printf("\n\nGenerating Machine Readable results...... Please wait.\n\n");
		display_machine();
	}

	if(f.output_xml) {
		printf("\n\nGenerating XML results...... Please wait.\n\n");
		display_xml();
	}

	//display_screen();


	banner();


	/*
	 * All done.... we can safely exit now
	 *
	 */



	return EXIT_SUCCESS;
}

