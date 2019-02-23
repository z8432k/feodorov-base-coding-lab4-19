#include <stdio.h>
#include <stdlib.h>
#include "include/data.h"

Data_t* newData(void) {
  return (Data_t *) malloc(sizeof(Data_t));
}

unsigned short packData(const Data_t *const data) {
  unsigned short box = 0;

  box = data->channelNumber;
  box = (box << SIGNAL_FORM_SIZE) | data->signalForm;
  box = (box << DIVISION_RATIO_SIZE) | data->divisionRatio;

  return box;
}

Data_t* unpackData(const unsigned short box) {
  Data_t *data = newData();

  data->divisionRatio = box & DIVISION_RATIO_MASK;
  data->signalForm = (box >> DIVISION_RATIO_SIZE) & SIGNAL_FORM_MASK;
  data->channelNumber = (box >> (DIVISION_RATIO_SIZE + SIGNAL_FORM_SIZE)) & CHANNEL_NUMBER_MASK;

  return data;
}

void printData(const Data_t* data) {
  printf("Channel number\t:%u\n", data->channelNumber);
  printf("Signal form\t:%u\n", data->signalForm);
  printf("Division ratio\t:%u\n\n", data->divisionRatio);
}

void printEncodedData(const unsigned short box) {
  printf("Encoded data\t:%X\n\n", box);
}
