#ifndef tlv_H
#define tlv_H
#include "LinkedList.h"
#include <stdint.h>

#define DATA_SIZE 258

typedef enum{ IDLE_RECEIVE,TYPE1_RECEIVE,TYPE2_RECEIVE,LENGTH_RECEIVE,VALUE_RECEIVE,
              IDLE_SEND,TYPE1_SEND,TYPE2_SEND,LENGTH_SEND,VALUE_SEND}TlvState;

typedef enum{ PROCESS_COMPLETE,
              PROCESS_READY,
              PROCESS_BUSY,
              PROCESS_ERROR}Status;

typedef struct TlvPacket TlvPacket;
struct TlvPacket {
  uint8_t type1;
  uint8_t type2;
  uint8_t length;
  uint8_t  data[DATA_SIZE];
};

typedef struct{
  Status      status;
  TlvState    state;
  int         index;
  TlvPacket   *ptr;
  LinkedList  *list;
}TlvInfo;

typedef struct TlvElement TlvElement;
struct TlvElement{
  TlvElement *next;
  TlvPacket tlv;
};

void tlvReceivePacket( TlvInfo *tlvInfo);
void tlvSendPacket(TlvInfo *tlvInfo);



#endif // tlv_H
