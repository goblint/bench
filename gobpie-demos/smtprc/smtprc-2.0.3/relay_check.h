/***************************************************************************
                          relay_check.h  -  description
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


#ifndef SMTPRC_RELAY_CHECK_H
#define SMTPRC_RELAY_CHECK_H


/**********************************includes*********************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>




/*********************************prototypes********************************/



int relay_check(int *sockfd, long cur_host);


#endif

