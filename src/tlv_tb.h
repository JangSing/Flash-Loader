#ifndef tlv_H
#define tlv_H
#include "LinkedList.h"
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
  LinkedList list;
}TlvInfo;

typedef struct TlvElement TlvElement;
struct TlvElement{
  TlvElement *next;
  TlvPacket tlv;
};

// void tlvReceivedPacket(TlvInfo *tlvInfo,TlvElement *tlvEle, LinkedList *list);
void tlvReceivedPacket( TlvInfo *tlvInfo,
                        uint8_t byteReceived,
                        TlvElement *tlvEle);

// TlvPacket *alocateTlvPacket();
// void freeTlvPacket(TlvPacket *tlv);




#endif // tlv_H
