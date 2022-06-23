/***************************************************************************
                          connect.h  -  description
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


#ifndef SMTPRC_CONNECT_H
#define SMTPRC_CONNECT_H

/******************************includes************************************/

#include "relay.h"
#include "smtprc_error.h"







/****************************prototypes*************************************/


long get_ip(char *host);
int tcp_connect(long ipa);
int connect_non_blocking(int sockfd, const struct sockaddr *thaddr, socklen_t salen, int nsec);
int read_timeo(int sockfd, char *string, int max, int timeo);
char *get_hostname(const char *addr);


#endif
