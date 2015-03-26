#!/bin/bash
# Execute this (c-)file as a shell script, it will be automatically compiled and executed.
# https://github.com/lumaku/C-script
LIBINCL="glib-2.0 gsl" # included libraries
CFLAGS=`pkg-config --cflags $LIBINCL`; LDLIBS=`pkg-config --libs $LIBINCL`
CFLAGS=`echo $CFLAGS -g -Wall -std=gnu11 -O3` # gdb  symbols: -g, Warnings on/off: -Wall/-w
sed -n -e '11,$p' < "$0" | /usr/bin/gcc -x c $CFLAGS $LDFLAGS -o "$0.$$.out" -
if [ -z ${DBG+x} ]; then DBGPARM=""; else DBGPARM="/usr/bin/env gdb -q "; fi;
if [ -f $0.$$.out ]; then $DBGPARM$0.$$.out "$@"; STATUS=$?; rm $0.$$.out; else echo "Error: File $0.$$.out was not generated."; STATUS=1; fi;
exit $STATUS 
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>
#include <glib.h> // GLib
#include <gsl/gsl_math.h> // GNU Scientific Library


int wuerfeln() { return ((rand()%6) + 1); }


int main(int argc, char **argv)
{
  printf("---------------------------    Starting script.   ---------------------------\n");
  for (int i = 0; i < argc; i++)
    printf("argv[%d] -> %s\n", i, argv[i]);
  printf("The integral of a Normal(0, 1) distribution between -1.96 and 1.96 is: %g\n", erf(1.96*sqrt(1/2.)));
  printf("Alea jacta est: %d %d %d %d\n", wuerfeln(), wuerfeln(), wuerfeln(), wuerfeln());
  // ---- print time 
  char temp[100];
  time_t jetzt = time(0);
  strftime (temp, 100, "%Y-%m-%d_%H:%M:%S", localtime(&jetzt));
  printf ("%s\n", temp);
  return 0;
}

