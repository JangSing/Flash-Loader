#ifndef tlvAllocator_H
#define tlvAllocator_H
#include "LinkedList.h"
#include "tlv.h"
#include <stdint.h>


void initTlvAllocator(TlvElement *tlvEle,int noOfTlv);
TlvElement *allocateTlv();
void freeTlv(TlvPacket *packet);



#endif // tlvAllocator_H
