#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "unity.h"
#include "tlv_tb.h"
#include "Flash_tb.h"
#include "LinkedList.h"
#include "CustomAssertion.h"
#include "tlvAllocator.h"



void setUp(void)
{
}

void tearDown(void)
{
}

void test_tlvInterpreter_deQueue_tlv_and_interprete_correctly(void)
{
  LinkedList list;
  linkedListInit(&list);
  
  TlvPacket  packet[10]={{TYPE_READ,1,1,1},{2,2,2,2,2},{3,3,3,3,3,3}};
  TlvElement tlvEle[10]={{NULL,packet[0]},{&tlvEle[0],packet[1]},{&tlvEle[1],packet[2]}};
  list.head=(ListElement *)(&tlvEle[2]);
  list.tail=(ListElement *)(&tlvEle[0]);
  
  FlashInfo flashInfo={FLASH_IDLE,PROCESS_READY,NULL,&list};
  
  tlvInterpreter(&flashInfo);
  TEST_ASSERT_EQUAL_PTR(&tlvEle[2], list.head);
  TEST_ASSERT_EQUAL_PTR(&tlvEle[1], list.head->next);
  TEST_ASSERT_NULL( list.head->next->next);
  
  TEST_ASSERT_EQUAL(FLASH_READ,flashInfo.state);
  
}

void test_readFlash(void)
{
  LinkedList list;
  linkedListInit(&list);
  
  TlvPacket  packet[10]={{TYPE_READ,1,5,0,0,0x09,0x08,2},{2,2,5,2,2},{3,3,5,3,3,3}};
  TlvElement tlvEle[10]={{NULL,packet[0]},{&tlvEle[0],packet[1]},{&tlvEle[1],packet[2]}};
  list.head=(ListElement *)(&tlvEle[2]);
  list.tail=(ListElement *)(&tlvEle[0]);
  
  FlashObject flashObj={READ_IDLE,NULL,0,0,NULL};
  FlashInfo flashInfo={FLASH_IDLE,PROCESS_READY,NULL,&list,&flashObj};
  
  tlvInterpreter(&flashInfo);
  TEST_ASSERT_EQUAL_PTR(&tlvEle[2], list.head);
  TEST_ASSERT_EQUAL_PTR(&tlvEle[1], list.head->next);
  TEST_ASSERT_NULL( list.head->next->next);
  
  TEST_ASSERT_EQUAL(FLASH_READ,flashInfo.state);
  
  tlvInterpreter(&flashInfo);
  
  TEST_ASSERT_EQUAL_PTR(flashInfo.tlv,flashObj.tlv);
  TEST_ASSERT_EQUAL_PTR(0x08090000,flashObj.address);
  TEST_ASSERT_EQUAL(2,flashObj.length);
  
}
