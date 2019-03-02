#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include/error.h"

#define PW(x) (powf(x, 2))

int main(const int argc, const char **argv) {
  if (argc < 7) {
    eprintf("Too few CLI arguments. Need six args with numbers.");
  }

  float x0 = atof(argv[1]);
  float xn = atof(argv[2]);
  float dx = atof(argv[3]);
  float a = atof(argv[4]);
  float b = atof(argv[5]);
  float c = atof(argv[6]);

  printf("┏━━━━━━━━━━━┯━━━━━━━━━━━┓\n");
  printf("┃     X     │     Y     ┃\n");
  printf("┃━━━━━━━━━━━┿━━━━━━━━━━━┃\n");

  float x;
  for (x = x0; x <= xn; x += dx) {
    double y = 0;

    if (x < 5 && b != 0) {
      y = a * PW(x + 7) - b;
    }
    else if (x > 5 && b == 0) {
      y = (x - a * c) / (a * x);
    }
    else {
      y = x / c;
    }

    printf("┃%11.4f│%11.4f┃\n", x, y);
    printf("┃───────────┼───────────┃\n");
  }

  printf("┗━━━━━━━━━━━┷━━━━━━━━━━━┛\n");

  return 0;
}

