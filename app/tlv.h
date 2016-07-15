#ifndef tlv_H
#define tlv_H
#include <stdint.h>

#define PROGRAM	0x10000001
#define ERASE	0x10000002
#define READ	0x10000003

typedef enum{IDLE,TYPE1_RECEIVED,TYPE2_RECEIVED,LENGTH_RECEIVED,VALUE_RECEIVED}State;


typedef struct TlvPacket TlvPacket;
struct TlvPacket {
  uint8_t type1;
  uint8_t type2;
  uint8_t length;
  int8_t  data[0];
};

typedef struct{
  State     state;
  int       index;
  TlvPacket *ptr;
}TlvInfo;

typedef struct tlvElement tlvElement;
struct tlvElement{
  tlvElement *next;
  TlvPacket *tlv;
};

void tlvStateMachine(TlvInfo *tlvInfo,uint8_t byteReceived);
#endif // tlv_H
