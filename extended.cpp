#!/bin/bash
# Execute this (c++-)file as a shell script, it will be automatically compiled and executed.
# https://github.com/lumaku/C-script
LIBINCL="glib-2.0" # included libraries
CFLAGS=`pkg-config --cflags $LIBINCL`; LDLIBS=`pkg-config --libs $LIBINCL`; ADDARGS=""
CFLAGS=`echo $CFLAGS -g -Wall -std=gnu++14 -O2` # gdb  symbols: -g, Warnings on/off: -Wall/-w
sed -n -e '11,$p' < "$0" | /usr/bin/g++ -x c++ $CFLAGS $LDFLAGS $ADDARGS -o "$0.$$.out" -
if [ -z ${DBG+x} ]; then DBGPARM=""; else DBGPARM="/usr/bin/env gdb -q "; fi;
if [ -f $0.$$.out ]; then $DBGPARM$0.$$.out "$@"; STATUS=$?; rm $0.$$.out; else echo "Error: File $0.$$.out was not generated."; STATUS=1; fi;
exit $STATUS

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main(int argc, char **argv)
{

    cout << "Welcome to the C++ Script"<<std::endl;
    cout << "This is a self-compiling C++ script."<<std::endl;
    cout << "Usage:"<<std::endl;
    cout << "     extended.cpp <arg1> <arg2>"<<std::endl;

    if (argc == 4) {
        cout << "Now your program has two arguments..." << endl;
    } else {
        cout << "Give two arguments to the program." << endl;
        return 0;
    }

    cout <<  "Goodbye" << std::endl;


    return 0;
}

