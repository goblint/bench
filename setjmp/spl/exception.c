/*
 * File: exception.c
 * -----------------
 * This file implements the C exception handler.  Much of the
 * real work is done in the exception.h header file.
 */

/*************************************************************************/
/* Stanford Portable Library                                             */
/* Copyright (C) 2013 by Eric Roberts <eroberts@cs.stanford.edu>         */
/*                                                                       */
/* This program is free software: you can redistribute it and/or modify  */
/* it under the terms of the GNU General Public License as published by  */
/* the Free Software Foundation, either version 3 of the License, or     */
/* (at your option) any later version.                                   */
/*                                                                       */
/* This program is distributed in the hope that it will be useful,       */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of        */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         */
/* GNU General Public License for more details.                          */
/*                                                                       */
/* You should have received a copy of the GNU General Public License     */
/* along with this program.  If not, see <http://www.gnu.org/licenses/>. */
/*************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include "exception.h"
#include "cslib.h"

/* Constants */

#define MAX_UNHANDLED_MESSAGE 100
#define ERROR_EXIT_STATUS 1

/* Publicly accessible exceptions */

exception ANY = { "ANY" };
exception ErrorException = { "ErrorException" };

/* Global variables (not thread safe) */

static ExceptionContextBlock *exceptionStack = NULL;

/* Prototypes for friends functions */

void unhandledError(string msg);
void unhandledException(string name);

/*
 * Triggers an exception by finding an appropriate handler and then
 * using <code>longjmp</code> to return to the context stored there
 * after resetting the exception stack.  If no handler exists, the
 * function calls <code>error</code> with an unhandled exception.
 */

void throwException(exception *e, string name, void *value) {
   if (exceptionStack == NULL) {
      if (e == &ErrorException) {
         unhandledError((string) value);
      } else {
         unhandledException(name);
      }
   }
   exceptionStack->id = e;
   exceptionStack->name = name;
   exceptionStack->value = value;
   longjmp(exceptionStack->jmp, 1);
}

/* Friends entries */

/*
 * Implementation notes: unhandledError
 * ------------------------------------
 * Called when an unhandled <code>ErrorException</code> occurs.
 */

void unhandledError(string msg) {
   fprintf(stderr, "error: %s\n", msg);
   exit(ERROR_EXIT_STATUS);
}

/*
 * Implementation notes: unhandledException
 * ----------------------------------------
 * Called when an unhandled exception occurs.
 */

void unhandledException(string name) {
   fprintf(stderr, "Unhandled exception: %s\n", name);
   exit(E_UNHANDLED_EXCEPTION);
}

/* Private functions */

/*
 * Pushes a new exception context on the exception stack.
 */

void pushExceptionStack(ExceptionContextBlock *cptr) {
   cptr->link = exceptionStack;
   exceptionStack = cptr;
}

/*
 * Discards the top exception context from the exception stack.
 */

void popExceptionStack(void) {
   if (exceptionStack != NULL) exceptionStack = exceptionStack->link;
}

/*
 * Reraises an exception in the top stack frame.
 */

void unwindException(ExceptionContextBlock *cptr) {
   if (exceptionStack == NULL) {
      if (cptr->id == &ErrorException) {
         unhandledError((string) cptr->value);
      } else {
         unhandledException(cptr->name);
      }
   }
   exceptionStack->id = cptr->id;
   exceptionStack->name = cptr->name;
   exceptionStack->value = cptr->value;
   longjmp(exceptionStack->jmp, 1);
}
