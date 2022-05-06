/***************************************************************************
                          relay_check.c  -  description
                             -------------------
    begin                : Tue May 27 2003
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



#include "relay_check.h"
#include "relay_check_funcs.h"
#include "relay.h"
#include "options.h"
#include "utils.h"




extern struct options o;
extern struct flags f;

extern host **hosts;
extern rule **rules;


int relay_check(int *sockfd, long cur_host) {

  int rule = 0;
  int res = 0;
  int padding = PADDING;
  char checking[MAXDATA+1];

  if(f.resolve_hostnames && hosts[cur_host]->resolved && !f.display_only_ips) {
    snprintf(checking, padding, "Checking %s%200c", hosts[cur_host]->hostname, ' ');
  } else {
    snprintf(checking, padding, "Checking %s%200c", hosts[cur_host]->ip_address, ' ');
  }


  for(rule=0;rule<=o.no_rules;rule++) {
    if(!rule) {
      if((res = check_banner(sockfd, cur_host, rule)) == -1) {
        strncat(checking, " !", MAXDATA);
        if(f.verbose) {
          printf("%s\n", checking);
        }
        //close(sockfd);
        return(-1);
      } else if(res == 1) {
        strncat(checking, " o", MAXDATA);
        goto RESET;
      }

      if((res = check_helo(sockfd, cur_host, rule)) == -1) {
        strncat(checking, " !", MAXDATA);
        if(f.verbose) {
          printf("%s\n", checking);
        }
        //close(sockfd);
        return(-1);
      } else if(res == 1) {
        strncat(checking, " o", MAXDATA);
        goto RESET;
      }
    }

    if((res = check_mail_from(sockfd, cur_host, rule)) == -1) {
      strncat(checking, " !", MAXDATA);
      if(f.verbose) {
        printf("%s\n", checking);
      }
      //close(sockfd);
      return(-1);
    } else if(res == 1) {
      strncat(checking, " o", MAXDATA);
      goto RESET;
    }

    if((res = check_rcpt_to(sockfd, cur_host, rule)) == -1) {
      strncat(checking, " !", MAXDATA);
      if(f.verbose) {
        printf("%s\n", checking);
      }
      //close(sockfd);
      return(-1);
    } else if(res == 1) {
      strncat(checking, " o", MAXDATA);
      goto RESET;
    }

    if((res = check_send_data_start(sockfd, cur_host, rule)) == -1) {
      strncat(checking, " !", MAXDATA);
      if(f.verbose) {
        printf("%s\n", checking);
      }
      //close(sockfd);
      return(-1);
    } else if(res == 1) {
      strncat(checking, " o", MAXDATA);
      goto RESET;
    }

    if((res = check_send_data(sockfd, cur_host, rule)) == -1) {
      strncat(checking, " !", MAXDATA);
      if(f.verbose) {
        printf("%s\n", checking);
      }
      //close(sockfd);
      return(-1);
    } else if(res == 1) {
      strncat(checking, " o", MAXDATA);
      goto RESET;
    }

    /*
     * If we get to here then it means that the check failed
     * and we have found a suspected open relay. mark it as
     * open reset the server and carry on with the scanning.
     *
     */

    strncat(checking, " x", MAXDATA);
    hosts[cur_host]->smtp_check[rule]->failed = 1;
    suspected_open_relay(cur_host, rule);

  RESET:

    if((res = reset_smtp(sockfd, cur_host, rule)) == -1) {
      strncat(checking, " !", MAXDATA);
      printf("%s\n", checking);
      return(-1);
    }
  }

  /*
   * We have finished scanning this host so quit the smtp
   * session, print the results and return.
   *
   */

  if((res = quit_smtp(sockfd, cur_host, o.no_rules)) == -1) {
    strncat(checking, " !", padding);
    printf("%s\n", checking);
    return(-1);
  }

  printf("%s\n", checking);


  return(0);

}









