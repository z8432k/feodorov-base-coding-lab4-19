#include <stdio.h>
#include  <stdlib.h>
#include "include/error.h"
#include "include/data.h"

static void passData(Data_t *data, const char **argv);

int main(const int argc, const char **argv) {
  printf("Pack.\n\n");

  if (argc < 4) {
    __error("Too few CLI arguments. Need three args with int numbers.");
  }

  Data_t *data = newData();
  passData(data, argv);

  printData(data);

  /* encode */
  unsigned short box = packData(data);

  printEncodedData(box);

  free(data);

  return 0;
}

static void passData(Data_t *data, const char **argv) {
  unsigned short channelNumber = (unsigned short) atoi(argv[1]);
  unsigned short signalForm = (unsigned short) atoi(argv[2]);
  unsigned short divisionRatio = (unsigned short) atoi(argv[3]);

  if (channelNumber > 3) {
    __error("Channel number must be in [0; 3].");
  }

  if (signalForm > 3) {
    __error("Signal form must be in [0; 3].");
  }

  if (divisionRatio > 4095) {
    __error("Division ration must be in [0; 4095].");
  }

  data->channelNumber = channelNumber;
  data->signalForm = signalForm;
  data->divisionRatio = divisionRatio;
}
