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


#include "display_html.h"
#include "relay.h"
#include "options.h"
#include "utils.h"


extern struct options o;

extern host **hosts;

char *passed = "smtprc_passed.html";
char *errord = "smtprc_errord.html";
char *failed_file;

long smtp_open = 0;


/*
 * This is the main function that displays the HTML
 * it will display a maximum of 50 links per page.
 *
 */

void display_html(void) {

  FILE *failed_fd;
  FILE *passed_fd;
  FILE *errord_fd;

  char buf[MAXDATA];
  char *p;
  char *s;
  char *boo;

  int failed = 0;
  int failed_count = 0;
  int passed_count = 0;
  int errord_count = 0;
  int count = 0;
  long x = 0;
  int y = 0;


  boo=s_malloc((strlen(o.html_file) +1) *sizeof(char));
  strncpy(boo, o.html_file, strlen(o.html_file));
  boo[strlen(o.html_file)] = '\0';

  p = boo;
  while(*p++) {
    if(*p == '/') {
      count++;
      s = ++p;
    }
  }

  if(!count) {
    failed_file=s_malloc((strlen(o.html_file) +1) * sizeof(char));
    strncpy(failed_file, o.html_file, strlen(o.html_file));
    failed_file[strlen(o.html_file)] = '\0';
  } else {
    failed_file=s_malloc((strlen(s) +1) *sizeof(char));
    strncpy(failed_file, s, strlen(s));
    failed_file[strlen(s)] = '\0';
  }


  count = 0;

  /*
   * Open the main HTML pages (Passed, Failed and Errord)
   *                                                           
   */

  if((failed_fd=fopen(o.html_file, "w")) == NULL) {
    fatal("Unable to open html file");
  }

  snprintf(buf, MAXDATA, "%s%s", o.html_path, passed);
  if((passed_fd=fopen(buf, "w")) == NULL) {
    fatal("Unable to open html file");
  }

  snprintf(buf, MAXDATA, "%s%s", o.html_path, errord);
  if((errord_fd=fopen(buf, "w")) == NULL) {
    fatal("Unable to open html file");
  }


  /*
   * Print the header for each of the HTML pages
   *
   */

  print_html_header(failed_fd, "SMTP Relay Checker");
  print_html_header(passed_fd, "SMTP Relay Checker");
  print_html_header(errord_fd, "SMTP Relay Checker");


  /*
   * Print the keys at the top of the HTML pages that indicate
   * what the colors mean on each page
   *
   */

  fprintf(failed_fd, "<font size=\"1\">Scans marked in <font color=\"orange\">Orange</font> are suspected open relays</font><br />\n");
  fprintf(failed_fd, "<font size=\"1\">Scans marked in <font color=\"red\">Red</font> are definite open relays</font><br /><br /><br /><br />\n");

  fprintf(passed_fd, "<font size=\"1\">Scans marked in <font color=\"blue\">Blue</font> are not open relays and have passed all tests</font><br /><br /><br /><br />\n");

  fprintf(errord_fd, "<font size=\"1\">Scans marked in <font color=\"black\">Black</font> Closed the connection after it was established (Probably due to a firewall)</font><br />\n");
  fprintf(errord_fd, "<font size=\"1\">Scans marked in <font color=\"darkblue\">Dark Blue</font> Had restrictions in place to disallow access</font><br />\n");
  fprintf(errord_fd, "<font size=\"1\">Scans marked in <font color=\"green\">Green</font> Produced Read Timeouts</font><br />\n");
  fprintf(errord_fd, "<font size=\"1\">Scans marked in <font color=\"purple\">Purple</font> Produced Unknown Errors</font><br /><br /><br /><br />\n");


  /*
   * Now we want to cycle through the hosts structure
   * (results) and print the appropriate results.
   *
   */


  fprintf(failed_fd, "<table align=\"center\" border=\"0\" cellspacing=\"10\"><tr>\n");
  fprintf(passed_fd, "<table align=\"center\" border=\"0\" cellspacing=\"10\"><tr>\n");
  fprintf(errord_fd, "<table align=\"center\" border=\"0\" cellspacing=\"10\"><tr>\n");

  /*
   * EVIL CODE ... EVIL CODE ... EVIL CODE
   *
   * The following code started off nice but then
   * grew a big hunchback, warts and smells now too.
   *
   * I do plan to clean up this but it sort of
   * works for now so I'll do it later :/
   *
   */

  for(x=0;x<o.no_hostnames;x++) {
    if(hosts[x]->smtp_open) {        /* We only care about the hosts with port 25 open */
      smtp_open++;
    }
  }

  for(x=0;x<o.no_hostnames;x++) {
    if(hosts[x]->smtp_open) {        /* We only care about the hosts with port 25 open */
      for(y=0;y<=o.no_rules;y++) {
        if(hosts[x]->smtp_check[y]->failed == 1 && !hosts[x]->smtp_check[y]->error_code) {
          if(failed < 1) {
            failed = 1;
          }
        }
        if(hosts[x]->smtp_check[y]->failed == 2 && !hosts[x]->smtp_check[y]->error_code) {
          if(failed < 2) {
            failed = 2;
          }
        }
      }
      if(failed) {
        if(failed == 1) {
          fprintf(failed_fd, "<td>");
          failed_count++;
          if(hosts[x]->resolved) {
            snprintf(buf, MAXDATA, "%s.html", hosts[x]->hostname);
            print_link(failed_fd, buf, hosts[x]->hostname, "orange");
            snprintf(buf, MAXDATA, "%s%s.html", o.html_path, hosts[x]->hostname);
          } else {
            snprintf(buf, MAXDATA, "%s.html", hosts[x]->ip_address);
            print_link(failed_fd, buf, hosts[x]->ip_address, "orange");
            snprintf(buf, MAXDATA, "%s%s.html", o.html_path, hosts[x]->ip_address);
          }
          fprintf(failed_fd, "</td>");
          if(failed_count % 5 == 0) {
            fprintf(failed_fd, "</tr><tr>\n");
          }
        } else if(failed == 2) {
          failed_count++;
          fprintf(failed_fd, "<td>");
          if(hosts[x]->resolved) {
            snprintf(buf, MAXDATA, "%s.html", hosts[x]->hostname);
            print_link(failed_fd, buf, hosts[x]->hostname, "red");
            snprintf(buf, MAXDATA, "%s%s.html", o.html_path, hosts[x]->hostname);
          } else {
            snprintf(buf, MAXDATA, "%s.html", hosts[x]->ip_address);
            print_link(failed_fd, buf, hosts[x]->ip_address, "red");
            snprintf(buf, MAXDATA, "%s%s.html", o.html_path, hosts[x]->ip_address);
          }
          fprintf(failed_fd, "</td>");
          if(failed_count % 5 == 0) {
            fprintf(failed_fd, "</tr><tr>\n");
          }
        }
      } else if(hosts[x]->fatal_error && hosts[x]->fatal < 2 && hosts[x]->smtp_check[0]->error_code == 1) {
        errord_count++;
        fprintf(errord_fd, "<td>");
        if(hosts[x]->resolved) {
          snprintf(buf, MAXDATA, "%s.html", hosts[x]->hostname);
          print_link(errord_fd, buf, hosts[x]->hostname, "black");
          snprintf(buf, MAXDATA, "%s%s.html", o.html_path, hosts[x]->hostname);
        } else {
          snprintf(buf, MAXDATA, "%s.html", hosts[x]->ip_address);
          print_link(errord_fd, buf, hosts[x]->ip_address, "black");
          snprintf(buf, MAXDATA, "%s%s.html", o.html_path, hosts[x]->ip_address);
        }
        fprintf(errord_fd, "</td>");
        if(errord_count % 5 == 0) {
          fprintf(errord_fd, "</tr><tr>\n");
        }
      } else if(hosts[x]->fatal_error && hosts[x]->fatal < 2 && hosts[x]->smtp_check[0]->error_code == 2) {
        errord_count++;
        fprintf(errord_fd, "<td>");
        if(hosts[x]->resolved) {
          snprintf(buf, MAXDATA, "%s.html", hosts[x]->hostname);
          print_link(errord_fd, buf, hosts[x]->hostname, "darkblue");
          snprintf(buf, MAXDATA, "%s%s.html", o.html_path, hosts[x]->hostname);
        } else {
          snprintf(buf, MAXDATA, "%s.html", hosts[x]->ip_address);
          print_link(errord_fd, buf, hosts[x]->ip_address, "darkblue");
          snprintf(buf, MAXDATA, "%s%s.html", o.html_path, hosts[x]->ip_address);
        }
        fprintf(errord_fd, "</td>");
        if(errord_count % 5 == 0) {
          fprintf(errord_fd, "</tr><tr>\n");
        }
      } else if(hosts[x]->fatal_error == 3) {
        errord_count++;
        fprintf(errord_fd, "<td>");
        if(hosts[x]->resolved) {
          snprintf(buf, MAXDATA, "%s.html", hosts[x]->hostname);
          print_link(errord_fd, buf, hosts[x]->hostname, "green");
          snprintf(buf, MAXDATA, "%s%s.html", o.html_path, hosts[x]->hostname);
        } else {
          snprintf(buf, MAXDATA, "%s.html", hosts[x]->ip_address);
          print_link(errord_fd, buf, hosts[x]->ip_address, "green");
          snprintf(buf, MAXDATA, "%s%s.html", o.html_path, hosts[x]->ip_address);
        }
        fprintf(errord_fd, "</td>");
        if(errord_count % 5 == 0) {
          fprintf(errord_fd, "</tr><tr>\n");
        }
      } else if(hosts[x]->fatal_error) {
        errord_count++;
        fprintf(errord_fd, "<td>");
        if(hosts[x]->resolved) {
          snprintf(buf, MAXDATA, "%s.html", hosts[x]->hostname);
          print_link(errord_fd, buf, hosts[x]->hostname, "purple");
          snprintf(buf, MAXDATA, "%s%s.html", o.html_path, hosts[x]->hostname);
        } else {
          snprintf(buf, MAXDATA, "%s.html", hosts[x]->ip_address);
          print_link(errord_fd, buf, hosts[x]->ip_address, "purple");
          snprintf(buf, MAXDATA, "%s%s.html", o.html_path, hosts[x]->ip_address);
        }
        fprintf(errord_fd, "</td>");
        if(errord_count % 5 == 0) {
          fprintf(errord_fd, "</tr><tr>\n");
        }
      } else {
        passed_count++;
        fprintf(passed_fd, "<td>");
        if(hosts[x]->resolved) {
          snprintf(buf, MAXDATA, "%s.html", hosts[x]->hostname);
          print_link(passed_fd, buf, hosts[x]->hostname, "blue");
          snprintf(buf, MAXDATA, "%s%s.html", o.html_path, hosts[x]->hostname);
        } else {
          snprintf(buf, MAXDATA, "%s.html", hosts[x]->ip_address);
          print_link(passed_fd, buf, hosts[x]->ip_address, "blue");
          snprintf(buf, MAXDATA, "%s%s.html", o.html_path, hosts[x]->ip_address);
        }
        fprintf(passed_fd, "</td>");
        if(passed_count % 5 == 0) {
          fprintf(passed_fd, "</tr><tr>\n");
        }
      }
      print_check_details(buf, x);

      failed = 0;
    }
  }

  fprintf(errord_fd, "</tr></table>");
  fprintf(failed_fd, "</tr></table>");
  fprintf(passed_fd, "</tr></table>");

  /*
   * That's that done, now check if we actually printed
   * anything. If not print that there were none found
   *
   */

  if(!failed_count) {
    fprintf(failed_fd, "<br /><br /><br /><center><font size=\"2\" color=\"black\"><b>No Open Relays Were Found</b></font></center><br /><br /><br />\n");
  }
  if(!passed_count) {
    fprintf(passed_fd, "<br /><br /><br /><center><font size=\"2\" color=\"black\"><b>No Mail Servers Passed The Tests</b></font></center><br /><br /><br />\n");
  }
  if(!errord_count) {
    fprintf(errord_fd, "<br /><br /><br /><center><font size=\"2\" color=\"black\"><b>No Errors Were Encountered While Scanning</b></font></center><br /><br /><br />\n");
  }

  /*
   * And lastly print the footer and close
   * the files.
   *
   */


  print_html_footer(failed_fd, smtp_open);
  print_html_footer(errord_fd, smtp_open);
  print_html_footer(passed_fd, smtp_open);


  fclose(failed_fd);
  fclose(passed_fd);
  fclose(errord_fd);

  return;

}

/*
 * This fuction prints the details page which lists
 * all of the checks in detail.
 *
 */

void print_check_details(char *filename, long host) {

  FILE *fd;

  char color[MAXDATA+1];

  int y = 0;


  if((fd = fopen(filename, "w")) == NULL) {
    fatal("Unable to open file: %s\n", filename);
  }

  print_html_header(fd, "SMTP Relay Checker");

  for(y=0;y<=o.no_rules;y++) {
    if(hosts[host]->smtp_check[y]->failed == 1) {
      strncpy(color, "orange", MAXDATA);
      color[MAXDATA] = '\0';
    } else if(hosts[host]->smtp_check[y]->failed == 2) {
      strncpy(color, "red", MAXDATA);
      color[MAXDATA] = '\0';
    } else if(hosts[host]->smtp_check[y]->passed) {
      strncpy(color, "blue", MAXDATA);
      color[MAXDATA] = '\0';
    } else {
      strncpy(color, "purple", MAXDATA);
      color[MAXDATA] = '\0';
    }
    if(hosts[host]->fatal_error) {
      if(y <= hosts[host]->fatal) {
        if(hosts[host]->smtp_check[y]->error_code && hosts[host]->smtp_check[y]->error_code < 21) {
          print_errord_check(fd, host, y, "green");
        } else if(hosts[host]->smtp_check[y]->passed || hosts[host]->smtp_check[y]->failed) {
          print_check(fd, host, y, color);
        }
      }
    } else {
      print_check(fd, host, y, color);
    }
  }

  if(hosts[host]->smtp_check[o.no_rules]->error_code > 20 && hosts[host]->fatal == (o.no_rules)) {
    print_quit(fd, host, o.no_rules, "green");
  } else if(!hosts[host]->fatal_error) {
    print_quit(fd, host, o.no_rules, "blue");
  }


  print_html_footer(fd, smtp_open);

  fclose(fd);


  return;

}

void print_quit(FILE *fd, long x, int y, char *color) {

  fprintf(fd, "\n\n<br /><br /><table border=\"0\" cellspacing=\"1\"><font color=\"%s\"><br />\n", color);
  if(hosts[x]->resolved) {
    fprintf(fd, "\n<tr><td colspan=\"2\"><b>Quit sequence for %s [%s]</font></b><br /><br /></td></tr>\n", hosts[x]->hostname, hosts[x]->ip_address);
  } else {
    fprintf(fd, "\n<tr><td colspan=\"2\"><b>Quit sequence for [%s]</font></b><br /><br /></td></tr>\n", hosts[x]->ip_address);
  }

  if(hosts[x]->smtp_check[y]->error_code == 21 || hosts[x]->smtp_check[y]->error_code == 22) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">FATAL ERROR:</font><font color=\"black\"></td>\n<td>&#9;A fatal error occured while trying to read/write</font><br /></td></tr>\n", color);
  }

  fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">QUIT SENT:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, QUIT);
  fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">QUIT REPLY:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, hosts[x]->r_quit);


  fprintf(fd, "</table></font><br /><br /><br />\n\n");



  return;

}

void print_errord_check(FILE *fd, long x, int y, char *color) {

  char *p;

  char *buf;


  fprintf(fd, "\n\n<br /><br /><table border=\"0\" cellspacing=\"1\"><font color=\"%s\"><br />\n", color);
  if(hosts[x]->resolved) {
    fprintf(fd, "\n<tr><td colspan=\"2\"><b>Results for %s [%s] check %d</font></b><br /><br /></td></tr>\n", escape_html_chars(hosts[x]->hostname, p), escape_html_chars(hosts[x]->ip_address, p), y);
  } else {
    fprintf(fd, "\n<tr><td colspan=\"2\"><b>Results for [%s] check %d</font></b><br /><br /></td></tr>\n", escape_html_chars(hosts[x]->ip_address, p), y);
  }

  if(hosts[x]->smtp_check[y]->error_code == 1) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">FATAL ERROR:</font><font color=\"black\"></td>\n<td>&#9;The server closed the connection.... probably due to a firewall</font><br /></td></tr>\n", color);
  }


  if(!hosts[x]->smtp_check[y]->error_code || hosts[x]->smtp_check[y]->error_code > 1) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">BANNER:</font><font color=\"black\"></td>\n<td>&#9;%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[0]->r_banner, p));
  }


  if(hosts[x]->smtp_check[y]->error_code == 3 || hosts[x]->smtp_check[y]->error_code == 4) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">FATAL ERROR:</font><font color=\"black\"></td>\n<td>&#9;An fatal error occured while trying to read/write HELO</font><br /></td></tr>\n", color);
  }


  if(!hosts[x]->smtp_check[y]->error_code || hosts[x]->smtp_check[y]->error_code > 4) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">HELO SENT:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[0]->helo, p));
  }
  if(!hosts[x]->smtp_check[y]->error_code || hosts[x]->smtp_check[y]->error_code > 4) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">HELO REPLY:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[0]->r_helo, p));
  }


  if(hosts[x]->smtp_check[y]->error_code == 6 || hosts[x]->smtp_check[y]->error_code == 7) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">FATAL ERROR:</font><font color=\"black\"></td>\n<td>&#9;An fatal error occured while trying to read/write MAIL FROM</font><br /></td></tr>\n", color);
  }


  if(!hosts[x]->smtp_check[y]->error_code || hosts[x]->smtp_check[y]->error_code > 7) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">MAIL FROM SENT:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[y]->mail_from, p));
  }
  if(!hosts[x]->smtp_check[y]->error_code || hosts[x]->smtp_check[y]->error_code > 7) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">MAIL FROM REPLY:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[y]->r_mail_from, p));
  }


  if(hosts[x]->smtp_check[y]->error_code == 9 || hosts[x]->smtp_check[y]->error_code == 10) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">FATAL ERROR:</font><font color=\"black\"></td>\n<td>&#9;An fatal error occured while trying to read/write RCPT TO</font><br /></td></tr>\n", color);
  }


  if((!hosts[x]->smtp_check[y]->error_code || hosts[x]->smtp_check[y]->error_code > 10) && hosts[x]->smtp_check[y]->passed > 3) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">RCPT TO SENT:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[y]->rcpt_to, p));
  }
  if((!hosts[x]->smtp_check[y]->error_code || hosts[x]->smtp_check[y]->error_code > 10) && hosts[x]->smtp_check[y]->passed > 3) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">RCPT TO REPLY:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[y]->r_rcpt_to, p));
  }


  if(hosts[x]->smtp_check[y]->error_code == 12 || hosts[x]->smtp_check[y]->error_code == 13) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">FATAL ERROR:</font><font color=\"black\"></td>\n<td>&#9;An fatal error occured while trying to read/write DATA</font><br /></td></tr>\n", color);
  }


  if((!hosts[x]->smtp_check[y]->error_code || hosts[x]->smtp_check[y]->error_code > 13) && hosts[x]->smtp_check[y]->passed > 4) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">DATA START SENT:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(DATA, p));
  }
  if((!hosts[x]->smtp_check[y]->error_code || hosts[x]->smtp_check[y]->error_code > 13) && hosts[x]->smtp_check[y]->passed > 4) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">DATA START REPLY:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[y]->r_data_start, p));
  }


  if(hosts[x]->smtp_check[y]->error_code == 15 || hosts[x]->smtp_check[y]->error_code == 16) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">FATAL ERROR:</font><font color=\"black\"></td>\n<td>&#9;An fatal error occured while trying to read/write DATA</font><br /></td></tr>\n", color);
  }


  buf=s_malloc((MAXDATA+1) * sizeof(char));
  return_data(x, y, buf);


  if((!hosts[x]->smtp_check[y]->error_code || hosts[x]->smtp_check[y]->error_code > 16) && hosts[x]->smtp_check[y]->passed > 5) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">DATA SENT:</font> &#9;<font color=\"black\"></td>\n<td><pre>%s</pre></font><br /></td></tr>\n", color, escape_html_chars(buf, p));
  }

  free(buf);

  if((!hosts[x]->smtp_check[y]->error_code || hosts[x]->smtp_check[y]->error_code > 16) && hosts[x]->smtp_check[y]->passed > 6) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">DATA REPLY:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[y]->r_data_end, p));
  }


  if(hosts[x]->smtp_check[y]->error_code == 18 || hosts[x]->smtp_check[y]->error_code == 19) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">FATAL ERROR:</font><font color=\"black\"></td>\n<td>&#9;An fatal error occured while trying to read/write RSET</font><br /></td></tr>\n", color);
  }


  if(!hosts[x]->smtp_check[y]->error_code || hosts[x]->smtp_check[y]->error_code > 19) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">RESET SENT:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(RSET, p));
  }
  if(!hosts[x]->smtp_check[y]->error_code || hosts[x]->smtp_check[y]->error_code > 19) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">RESET REPLY:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[y]->r_reset, p));
  }


  fprintf(fd, "</table></font><br /><br /><br />\n\n");



  return;

}

void print_check(FILE *fd, long x, int y, char *color) {

  int passed = 0;

  char *p;
  char *buf;


  fprintf(fd, "\n\n<br /><br /><table border=\"0\" cellspacing=\"1\"><font color=\"%s\"><br />\n", color);
  if(hosts[x]->resolved) {
    fprintf(fd, "\n<tr><td colspan=\"2\"><b>Results for %s [%s] check %d</font></b><br /><br /></td></tr>\n", escape_html_chars(hosts[x]->hostname, p), escape_html_chars(hosts[x]->ip_address, p), y);
  } else {
    fprintf(fd, "\n<tr><td colspan=\"2\"><b>Results for [%s] check %d</font></b><br /><br /></td></tr>\n", escape_html_chars(hosts[x]->ip_address, p), y);
  }

  if(!hosts[x]->smtp_check[y]->passed || passed < hosts[x]->smtp_check[y]->passed) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">BANNER:</font><font color=\"black\"></td>\n<td>&#9;%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[0]->r_banner, p));
  }
  passed++;

  if(!hosts[x]->smtp_check[y]->passed || passed < hosts[x]->smtp_check[y]->passed) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">HELO SENT:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[0]->helo, p));
  }
  if(!hosts[x]->smtp_check[y]->passed || passed < hosts[x]->smtp_check[y]->passed) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">HELO REPLY:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[0]->r_helo, p));
  }
  passed++;

  if(!hosts[x]->smtp_check[y]->passed || passed < hosts[x]->smtp_check[y]->passed) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">MAIL FROM SENT:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[y]->mail_from, p));
  }
  if(!hosts[x]->smtp_check[y]->passed || passed < hosts[x]->smtp_check[y]->passed) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">MAIL FROM REPLY:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[y]->r_mail_from, p));
  }
  passed++;

  if(!hosts[x]->smtp_check[y]->passed || passed < hosts[x]->smtp_check[y]->passed) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">RCPT TO SENT:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[y]->rcpt_to, p));
  }
  if(!hosts[x]->smtp_check[y]->passed || passed < hosts[x]->smtp_check[y]->passed) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">RCPT TO REPLY:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[y]->r_rcpt_to, p));
  }
  passed++;

  if(!hosts[x]->smtp_check[y]->passed || passed < hosts[x]->smtp_check[y]->passed) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">DATA START SENT:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(DATA, p));
  }
  if(!hosts[x]->smtp_check[y]->passed || passed < hosts[x]->smtp_check[y]->passed) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">DATA START REPLY:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[y]->r_data_start, p));
  }
  passed++;

  buf=s_malloc((MAXDATA+1) * sizeof(char));
  return_data(x, y, buf);

  if(!hosts[x]->smtp_check[y]->passed || passed < hosts[x]->smtp_check[y]->passed) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">DATA SENT:</font> &#9;<font color=\"black\"></td>\n<td><pre>%s</pre></font><br /></td></tr>\n", color, escape_html_chars(buf, p));
  }

  free(buf);

  if(!hosts[x]->smtp_check[y]->passed || passed < hosts[x]->smtp_check[y]->passed) {
    fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">DATA REPLY:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[y]->r_data_end, p));
  }
  passed++;

  //if(!hosts[x]->smtp_check[y]->passed || passed < hosts[x]->smtp_check[y]->passed) {
  fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">RESET SENT:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(RSET, p));
  //}
  //if(!hosts[x]->smtp_check[y]->passed || passed < hosts[x]->smtp_check[y]->passed) {
  fprintf(fd, "\n<tr><td>&#9;<font color=\"%s\">RESET REPLY:</font> &#9;<font color=\"black\"></td>\n<td>%s</font><br /></td></tr>\n", color, escape_html_chars(hosts[x]->smtp_check[y]->r_reset, p));
  //}


  fprintf(fd, "</table></font><br /><br /><br />\n\n");


  return;

}

/*
 * This function prints the generic HTML header that will
 * be on all o the pages
 *
 */

void print_html_header(FILE *fd, char *title) {



  fprintf(fd, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">");
  fprintf(fd, "\t<html xmlns=\"http://www.w3.org/1999/xhtml\">");
  fprintf(fd,"\t<head><LINK rel=\"stylesheet\" type=\"text/css\" href=\"default.css\">");
  fprintf(fd, "\t\t<style type=\"text/css\">");
  fprintf(fd, "\t\t\ttable {\n			}\n			th, td {\n			}\n			h1, h2, h3, h4, h5, h6 {\n				text-transform:capitalize;\n				font-size: medium;");
  fprintf(fd, "\t\t\t}\n			A:link {\n				color: darkblue;\n			}\n			A:visited {\n				color: darkblue;\n			}\n			A:active {\n				color: violet;");
  fprintf(fd, "\t\t\t}\n			body {\n				color: black;\n				background-color: white;\n				font-family: Verdana, Arial, Helvetica, sans-serif;\n");
  fprintf(fd, "\t\t\t\tfont-size: small;\n				border-width: 10px;\n				border-style: solid;\n				border-color: darkblue;\n				padding-top: 10px;\n");
  fprintf(fd, "\t\t\t\tpadding-left: 32px;\n				padding-right: 10px;\n				padding-bottom: 10px;\n				margin: 10px;\n			}\n			blockquote {\n");
  fprintf(fd, "\t\t\t\tpadding:10px;\n				border:red 5px solid;\n				border-style:inset outset inset;\n			}\n		</style>\n");
  fprintf(fd, "\t\t<title>%s</title>\n	</head>\n	<body>", title);

  fprintf(fd, "<Font size=\"5\">Smtp Relay Checker</font><br /><br /><br /><br />\n");
  fprintf(fd, "<table border=\"0\" cellpadding=\"5\" align=\"center\"><tr>\n");
  fprintf(fd, "<td><a href=\"%s\">Checks that Failed</a></td>\n", failed_file);
  fprintf(fd, "<td><a href=\"%s\">Checks that passed</a></td>\n", passed);
  fprintf(fd, "<td><a href=\"%s\">Checks that produced errors</a></td>\n", errord);
  fprintf(fd, "</tr></table>");
  fprintf(fd, "<br /><br />");




  /*
  fprintf(fd, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">");
  fprintf(fd, "\t<html xmlns=\"http://www.w3.org/1999/xhtml\">");
  fprintf(fd,"\t<head>");
  fprintf(fd, "\t\t<style type=\"text/css\">");
  fprintf(fd, "\t\t\ttable {\n			}\n			th, td {\n			}\n			h1, h2, h3, h4, h5, h6 {\n				text-transform:capitalize;\n				font-size: medium;");
  fprintf(fd, "\t\t\t}\n			;");
  fprintf(fd, "\t\t\tbody {\n				background-color: white;\n				font-family: Verdana, Arial, Helvetica, sans-serif;\n");
  fprintf(fd, "\t\t\t\tfont-size: small;\n				border-width: 10px;\n				border-style: solid;\n				border-color: darkblue;\n				padding-top: 10px;\n");
  fprintf(fd, "\t\t\t\tpadding-left: 32px;\n				padding-right: 10px;\n				padding-bottom: 10px;\n				margin: 10px;\n			}\n			blockquote {\n");
  fprintf(fd, "\t\t\t\tpadding:10px;\n				border:red 5px solid;\n				border-style:inset outset inset;\n			}\n		</style>\n");
  fprintf(fd, "\t\t<title>%s</title>\n	</head>\n	<body>", title);

  fprintf(fd, "<Font size=\"5\">Smtp Relay Checker</font><br /><br /><center><hr width=\"40%%\"></center><br /><br />");
  */

  return;

}

/*
 * This prints the Generic HTML footer that will be on
 * all of thje pages
 *
 */

void print_html_footer(FILE *fd, long smtp_open) {

  char buf[MAXDATA+1];

  if(o.hours) {
    snprintf(buf, MAXDATA, "%d Hours, %d Mins and %d Seconds", o.hours, o.mins, o.seconds);
  } else if(o.mins) {
    snprintf(buf, MAXDATA, "%d Mins and %d Seconds", o.mins, o.seconds);
  } else {
    snprintf(buf, MAXDATA, "%d Seconds", o.seconds);
  }


  fprintf(fd, "<br /><br /><center><br /><br /><hr width=\"30%%\">");
  fprintf(fd, "<font size=\"1\">Scanned %ld hosts in %s<br />%ld of which were running mail servers<br />Spencer Hardy - <a href=\"mailto:diceman@dircon.co.uk\">diceman@dircon.co.uk</a><br /><a href=\"http://www.moejo.co.uk/smtprc-website\">http://www.moejo.co.uk/smtprc-website</a></font><hr width=\"30%%\"></center></body>", o.no_hostnames, buf, smtp_open);



  return;

}


/*
 * This just prints a link given the correct format
 *
 */

void print_link(FILE *fd, char *link, char *text, char *color) {

  char buf[30];

  int x = 0;


  while(x<20 && x < strlen(text)) {
    buf[x] = text[x];
    x++;
  }
  buf[x] = '\0';


  fprintf(fd, "<a href=\"%s\"><font color=\"%s\">%s</font></a>", link, color, buf);


  return;

}

char *escape_html_chars(char *string, char *s) {

  char *p;
  //char *t;
  char buf[MAXDATA+1];

  int count = 0;

  memset(buf, 0x0, MAXDATA);

  if(string == NULL) {
    s = s_malloc((strlen("NULL") +2) * sizeof(char));
    strncpy(s, "NULL", 4);
    s[5] = '\0';
    return(s);
  }

  p=string;
  do {
    if(*p == '<') {
      strncat(buf, "&lt;", MAXDATA);
      count+=4;
      continue;
    }
    if(*p == '>') {
      strncat(buf, "&gt;", MAXDATA);
      count+=4;
      continue;
    }
    buf[count] = *p;
    count++;
  } while(*p++ != '\0');

  s = s_malloc((strlen(buf) +1) * sizeof(char));
  strncpy(s, buf, strlen(buf));
  s[strlen(buf)] = '\0';

  return(s);

}
