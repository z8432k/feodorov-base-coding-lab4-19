#define CHANNEL_NUMBER_SIZE 2
#define SIGNAL_FORM_SIZE 2
#define DIVISION_RATIO_SIZE 12

#define CHANNEL_NUMBER_MASK 0x3
#define SIGNAL_FORM_MASK 0x3
#define DIVISION_RATIO_MASK 0xFFF

typedef struct Data {
  unsigned short channelNumber;
  unsigned short signalForm;
  unsigned short divisionRatio;
} Data_t;

Data_t* newData(void);
unsigned short packData(const Data_t* data);
Data_t* unpackData(const unsigned short);
void printData(const Data_t* data);
void printEncodedData(const unsigned short box);
