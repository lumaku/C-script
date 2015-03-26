# C-script
- Execute a C source code file as a shell script
- The code gets automatically compiled and executed
- Debug using `gdb`
- Handles command line arguments, additional linked libraries

### Usage
The script can be started with
- `./oneliner.c` 
- `./extended.c arg1 arg2`

To directly debug the script with `gdb`, type
- `DBG=1 ./extended.c`

No installation or modification of shell variables necessary.

### How it works
- *oneliner.c* The first line invokes `make` which handles the file based on its file name extension (that must be *.c).
- *extended.c* A multiline shebang generates the library linking parameters and redirects the C source code to the compiler. Additional libraries are automatically parsed to linker arguments. Doesn't need the *.c file name extension.

### Ideas from and Credits to
- [C-script](https://github.com/junjihashimoto/c-script): "script programing environment for c++" (install requred). Similar to [jit](https://github.com/radiospiel/jit), [c99sh](https://github.com/RhysU/c99sh)
- [Discussion on HN](https://news.ycombinator.com/item?id=9144467): User lambda [posted](https://news.ycombinator.com/item?id=9145279) the one-line shebang
- The [Multiline shebang](http://rosettacode.org/wiki/Multiline_shebang#C) extracts the C source code part with `sed -n -e '7,$p' < "$0" | /usr/bin/gcc`. The content of the file (`$0`) from the 7th line to the end (`7,$p`) is piped into `gcc`.
- ... and yet another [C script](https://gist.github.com/khirbat/1471088) by khirbat.
