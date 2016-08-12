#include <stdint.h>
#include <stdlib.h>
#include "tlv.h"
#include "LinkedList.h"
#include "tlvAllocator.h"


LinkedList allocatorList;

void initTlvAllocator(TlvElement *tlvEle,int noOfTlv){
  int i;
  
  linkedListInit(&allocatorList);
  
  for(i=0;i<noOfTlv;i++){
    addFirst(&allocatorList,(ListElement *)&tlvEle[i]);
  }
  
}

TlvPacket *allocateTlv(){
  TlvElement *allocatedEle;
  allocatedEle=(TlvElement *)removeLast(&allocatorList);
  
  return &(allocatedEle->tlv);
  
  
}