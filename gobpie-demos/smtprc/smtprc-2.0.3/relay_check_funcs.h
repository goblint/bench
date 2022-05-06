/***************************************************************************
                          relay_check_funcs.h  -  description
                             -------------------
    begin                : Wed May 28 2003
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


#ifndef SMTPRC_RELAY_FUNCS_CHECK_H
#define SMTPRC_RELAY_FUNCS_CHECK_H


/**********************************includes*********************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




/*********************************prototypes********************************/


int check_banner(int *sockfd, long cur_host, int rule);
int check_helo(int *sockfd, long cur_host, int rule);
int check_mail_from(int *sockfd, long cur_host, int rule);
int check_rcpt_to(int *sockfd, long cur_host, int rule);
int check_send_data_start(int *sockfd, long cur_host, int rule);
int check_send_data(int *sockfd, long cur_host, int rule);

int suspected_open_relay(long cur_host, int rule);

int reset_smtp(int *sockfd, long cur_host, int rule);
int quit_smtp(int *sockfd, long cur_host, int rule);




#endif
