/***************************************************************************
                          smtprc_error.h  -  description
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

#ifndef SMTPRC_ERROR_H
#define SMTPRC_ERROR_H

/*******************************headers*************************************/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>


/*******************************prototypes*********************************/



void fatal(char *fmt, ...);
void error(char *fmt, ...);


#endif

