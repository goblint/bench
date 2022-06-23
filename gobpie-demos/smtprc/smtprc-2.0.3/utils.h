/***************************************************************************
                          utils.h  -  description
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

#ifndef SMTPRC_UTILS_H
#define SMTPRC_UTILS_H


/*****************************includes*************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#include "smtprc_error.h"


/****************************defines*****************************/


#ifndef MAX
#define MAX(x,y) (((x)>(y))?(x):(y))
#endif

#ifndef MIN
#define MIN(x,y) (((x)<(y))?(x):(y))
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif


/***************************prototypes***************************/


void *s_malloc(unsigned long size);
void *s_zmalloc(int size);
char *chomp(char *string);
void swap_rule(char *dest, const char *rule, const int hostn);
void swap_macro(char *string, const char *replace, const char *macro);
void convert_rule(char *string, int ind);
void debug(char *fmt, ...);
int check_file_path(char *filename, char *path);
void return_data(long cur_host, int rule, char *string);
void set_defaults(void);
void not_implemented(void);


#endif

