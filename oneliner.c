//usr/bin/make -s "${0%.c}" && ./"${0%.c}" "$@"; s=$?; rm ./"${0%.c}"; exit $s


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  printf("Hello world.\n");
}



