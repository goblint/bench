/***************************************************************************
                          display_html.h  -  description
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

#ifndef SMTPRC_DISPLAY_HTML_H
#define SMTPRC_DISPLAY_HTML_H


/*************************************includes******************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



/**************************************prototypes***************************/

void display_html(void);
void print_html_header(FILE *fd, char *title);
void print_html_footer(FILE *fd, long smtp_open);
void print_link(FILE *fd, char *link, char *text, char *color);
void print_check(FILE *fd, long x, int y, char *color);
void print_errord_check(FILE *fd, long x, int y, char *color);
void print_check_details(char *filename, long host);
void print_quit(FILE *fd, long x, int y, char *color);
char *escape_html_chars(char *string, char *s);




#endif

