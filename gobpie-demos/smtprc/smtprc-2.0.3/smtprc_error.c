/***************************************************************************
                          smtprc_error.c  -  description
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



#include "smtprc_error.h"


//Print error string and exit
void fatal(char *fmt, ...) {

  va_list ap;
  va_start(ap, fmt);
  fflush(stdout);
  fprintf(stderr, "ERROR: ");
  vfprintf(stderr, fmt, ap);
  fprintf(stderr, "\nQUITTING!\n");
  va_end(ap);
  exit(1);
  
  return;

}


//Print error string and continue
void error(char *fmt, ...) {

  va_list ap;
  va_start(ap, fmt);
  fflush(stdout);
  vfprintf(stderr, fmt, ap);
  fprintf(stderr, "\n");
  va_end(ap);

  return;

}

