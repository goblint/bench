/***************************************************************************
                          usage.c  -  description
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


#include "usage.h"


void usage(char *pname) {

	printf("\n\nUsage: %s -c [config file] -s [iprange] -w [path to html file] -b [email address to relay to] -e [path to mbox]\n", pname);
	printf("\nOptions:\n\n");
	printf("-p [number of threads]\n");
	printf("\t	Forks the specified number of threads\n");
	printf("\t	Set this to whatever works best for the machine\n");
	printf("\t	FreeBSD seems fine with 400+ The Linux test\n");
	printf("\t	machine won't take anymore that 250\n");
	printf("\n-b [email address]\n");
	printf("\t	When this option is supplied, SmtpRC will send email\n");
	printf("\t	through any servers that fail any tests. It must\n");
	printf("\t	also correspond with the configuration file. see the\n");
	printf("\t	README file for more info.\n");
	printf("\n-e [path to mbox]\n");
	printf("\t	When this opton is used SmtpRC will check the mail file\n");
	printf("\t	specified for relayed emails\n");
	printf("\n-u [path to maildir]\n");
	printf("\t	When this opton is used SmtpRC will check the maildir\n");
	printf("\t	specified for relayed emails\n");
	printf("\n-w [filename]\n");
	printf("\t	Prints detailed HTML output of all failed\n");
	printf("\t	checks to the filename specified. If used with the -a\n");
	printf("\t	option it will print all checks not just those that\n");
	printf("\t	failed\n");
	printf("\n-f [filename]\n");
	printf("\t	Output results in text format\n");
	printf("\n-o [filename]\n");
	printf("\t	Output results in machine readable format (comma\n");
	printf("\t	seperated values)\n");
	printf("\n-c [config file]\n");
	printf("\t	Read the checks from the specified filename.\n");
	printf("\n-y [email template file]\n");
	printf("\t	Specify an email template to use.\n");
	printf("\n-s [ip address range]\n");
	printf("\t	You can use this option to specify\n");
	printf("\t	the ip address range (or single host) to scan for\n");
	printf("\t	open relay's. Must be in the format 127.0.*.1-200\n");
	printf("\n-i [ip list file]\n");
	printf("\t	Use this option to specify a list of ip addresses or\n");
	printf("\t	hostnames to scan\n");
	printf("\n-k [config file to generate]\n");
	printf("\t	Use this option to generate an automatic config file with the options\n");
	printf("\t	used on the command line\n");
	printf("\n-j [auto config file]\n");
	printf("\t	use this option to use an automatic config file\n");
	printf("\n-r [timeout]\n");
	printf("\t	Specify a timeout value used for reading\n");
	printf("\t	data from hosts. The default is 60 seconds but you\n");
	printf("\t	may have to increase it up to 90+.\n");
	printf("\n-m [time to wait]\n");
	printf("\t	Use this option to specify the time to wait before checking\n");
	printf("\t	the mail file\n");
	printf("\n-l [timeout]\n");
	printf("\t	Specify a timeout value used for connecting\n");
	printf("\t	to hosts. The default is 30 seconds but you may\n");
	printf("\t	need to increase it with slow networks\n");
	printf("\n-n\t	Using this option will convert all IP addresses to\n");
	printf("\t	domiain names\n");
	printf("\n-a\t	This option will print all of the checks to the output file\n");
	printf("\t	specified not just the tests that fail. Failed tests\n");
	printf("\t	will be highlighted in red\n");
	printf("\n-v\t	Verbose mode. This is not a rcommended option. It\n");
	printf("\t	displays more output about what's going on.\n");
	fflush(stdout);

  exit(0);

}

void banner(void) {

	printf("\n\n\n\n\t----------------------------\n");
	printf("\t|    SMTP Relay Checker    |\n");
	printf("\t|      Spencer Hardy       |\n");
	printf("\t|   diceman@dircon.co.uk   |\n");
	printf("\t|          2.0.3           |\n");
	printf("\t----------------------------\n\n\n\n");
	fflush(stdout);

  return;

}

