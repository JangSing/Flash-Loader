#ifndef tlv_H
#define tlv_H
#include <stdint.h>


#define DATA_SIZE 258

typedef enum{TLV_IDLE,TYPE1_RECEIVED,TYPE2_RECEIVED,LENGTH_RECEIVED,VALUE_RECEIVED}TlvState;

typedef struct TlvPacket TlvPacket;
struct TlvPacket {
  uint8_t type1;
  uint8_t type2;
  uint8_t length;
  uint8_t  data[DATA_SIZE];
};

typedef struct{
  TlvState  state;
  int       index;
  TlvPacket *ptr;
}TlvInfo;

typedef struct TlvElement TlvElement;
struct TlvElement{
  TlvElement *next;
  TlvPacket tlv;
};

void tlvStateMachine(TlvInfo *tlvInfo,uint8_t byteReceived);
#endif // tlv_H
