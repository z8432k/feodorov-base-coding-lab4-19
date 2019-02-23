#include <stdio.h>
#include <stdlib.h>
#include "include/error.h"

void __error(const char* const msg) {
  fprintf(stderr, "%s\n", msg);
  exit(1);
}
