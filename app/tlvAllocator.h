#ifndef tlv_H
#define tlv_H
#include "LinkedList.h"
#include "tlv.h"
#include <stdint.h>


void initTlvAllocator(TlvElement *tlvEle,int noOfTlv);
TlvPacket *allocateTlv();
void freeTlv(TlvPacket *packet);



#endif // tlvAllocator_H
