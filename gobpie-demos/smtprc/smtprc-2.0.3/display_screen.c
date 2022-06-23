/***************************************************************************
                          display_screen.c  -  description
                             -------------------
    begin                : Sun Jun 29 2003
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


#include "display_screen.h"
#include "relay.h"
#include "options.h"



extern struct options o;
//extern struct flags f;

//extern rule **rules;
extern host **hosts;

 


void display_screen(void) {

  int x = 0;
  int y = 0;
  

  for(x=0;x<o.no_hostnames;x++) {
		if(hosts[x]->smtp_open) {
			printf("Results for host: %s\n\n", hosts[x]->ip_address);
			if(hosts[x]->fatal_error) {
				printf("There was a fatal error (%d) scanning this host\n", hosts[x]->fatal_error);
				if(hosts[x]->fatal_error == 6 || hosts[x]->fatal_error == 7 || hosts[x]->fatal_error == 8) {
					for(y=0;y<=o.no_rules;y++) {
						printf("\tResults for check: %d\n", y);
						printf("\t\tError code: %d\n", hosts[x]->smtp_check[y]->error_code);
						if(hosts[x]->smtp_check[y]->error_code == 3) {
							printf("\t\t*%s*\n", hosts[x]->smtp_check[y]->r_mail_from);
						}
						if(hosts[x]->smtp_check[y]->error_code == 4) {
              printf("\t\t*%s*\n", hosts[x]->smtp_check[y]->r_rcpt_to);
            }
						if(hosts[x]->smtp_check[y]->error_code == 7) {
              printf("\t\t*%s*\n", hosts[x]->smtp_check[y]->r_reset);
            }
					}
				}
			}
			else {
				for(y=0;y<=o.no_rules;y++) {
					printf("\tResults for check: %d\n", y);
					if(hosts[x]->smtp_check[y]->error_code) {
						printf("This checkl failed with error code (%d)\n", hosts[x]->smtp_check[y]->error_code);
					}
					else if(hosts[x]->smtp_check[y]->passed) {
						printf("\t\t*Passed this check\n");
					}
					else {
							printf("\t\t!Failed this check\n");
					}
				}
			}
		}
	}


  return;

}

