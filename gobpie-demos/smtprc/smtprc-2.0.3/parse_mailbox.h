/***************************************************************************
 *   Copyright (C) 2004 by Spencer Hardy                                   *
 *   spencer@warg.co.uk                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
 
 
#ifndef PARSE_MAILBOX_H
#define PARSE_MAILBOX_H


/*************************************includes******************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



/**************************************prototypes***************************/

int parse_mbox(void);
int parse_maildir(void);
int parse_popbox(void);
char *get_sender_address(char *string);
int is_mbox_seperator(char *string);


#endif
