#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "unity.h"
#include "tlv_tb.h"
#include "Flash_tb.h"
#include "LinkedList.h"
#include "CustomAssertion.h"



void setUp(void)
{
}

void tearDown(void)
{
}

void test_function_tlvReceivedPacket_running_in_correct_state(void)
{
  uint8_t buffer[DATA_SIZE]={};
  TlvInfo tlvInfo={TLV_IDLE,0,(TlvPacket *)buffer};
  uint8_t byteReceived=5;


  TEST_ASSERT_EQUAL(TLV_IDLE,tlvInfo.state);
	tlvReceivedPacket(&tlvInfo,byteReceived,NULL); //type1
  TEST_ASSERT_EQUAL(TYPE1_RECEIVED,tlvInfo.state);

	tlvReceivedPacket(&tlvInfo,byteReceived,NULL); //type2
  TEST_ASSERT_EQUAL(TYPE2_RECEIVED,tlvInfo.state);

	tlvReceivedPacket(&tlvInfo,byteReceived,NULL); //length
  TEST_ASSERT_EQUAL(LENGTH_RECEIVED,tlvInfo.state);

	tlvReceivedPacket(&tlvInfo,byteReceived,NULL); //data[0]
  TEST_ASSERT_EQUAL(LENGTH_RECEIVED,tlvInfo.state);

	tlvReceivedPacket(&tlvInfo,byteReceived,NULL); //data[1]
  TEST_ASSERT_EQUAL(LENGTH_RECEIVED,tlvInfo.state);

	tlvReceivedPacket(&tlvInfo,byteReceived,NULL); //data[2]
  TEST_ASSERT_EQUAL(LENGTH_RECEIVED,tlvInfo.state);

	tlvReceivedPacket(&tlvInfo,byteReceived,NULL); //data[3]
  TEST_ASSERT_EQUAL(LENGTH_RECEIVED,tlvInfo.state);

	tlvReceivedPacket(&tlvInfo,byteReceived,NULL); //data[4]
  TEST_ASSERT_EQUAL(VALUE_RECEIVED,tlvInfo.state);
}

void test_function_tlvReceivedPacket_passing_in_tlv_info_should_give_correct_result(void)
{
  uint8_t buffer[DATA_SIZE]={};
  TlvInfo tlvInfo={TLV_IDLE,0,(TlvPacket *)buffer};
  uint8_t byteReceived;
  byteReceived=5;

	tlvReceivedPacket(&tlvInfo,byteReceived,NULL); //type1
	tlvReceivedPacket(&tlvInfo,byteReceived,NULL); //type2
	tlvReceivedPacket(&tlvInfo,byteReceived,NULL); //length
	tlvReceivedPacket(&tlvInfo,byteReceived,NULL); //data[0]
	tlvReceivedPacket(&tlvInfo,byteReceived,NULL); //data[1]
	tlvReceivedPacket(&tlvInfo,byteReceived,NULL); //data[2]
	tlvReceivedPacket(&tlvInfo,byteReceived,NULL); //data[3]
	tlvReceivedPacket(&tlvInfo,byteReceived,NULL); //data[4]

  TEST_ASSERT_EQUAL(5,tlvInfo.ptr->type1);
  TEST_ASSERT_EQUAL(5,tlvInfo.ptr->type2);
  TEST_ASSERT_EQUAL(5,tlvInfo.ptr->length);
  TEST_ASSERT_EQUAL(5,tlvInfo.ptr->data[0]);
  TEST_ASSERT_EQUAL(5,tlvInfo.ptr->data[1]);
  TEST_ASSERT_EQUAL(5,tlvInfo.ptr->data[2]);
  TEST_ASSERT_EQUAL(5,tlvInfo.ptr->data[3]);
  TEST_ASSERT_EQUAL(5,tlvInfo.ptr->data[4]);
}


void test_element_packet_is_pointing_to_tlvInfo_and_it_was_queued_correctly(void)
{
  LinkedList list;
  linkedListInit(&list);
  
  TlvElement tlvEle[10]={};
  uint8_t buffer[DATA_SIZE]={};
  TlvInfo tlvInfo={TLV_IDLE,0,(TlvPacket *)buffer,list};
  uint8_t byteReceived;
  byteReceived=5;

	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //type1
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //type2
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //length
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //data[0]
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //data[1]
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //data[2]
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //data[3]
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //data[4]
	tlvReceivedPacket(&tlvInfo,0,tlvEle); 

  TEST_ASSERT_TLV_ELE(5,5,5,5,5,5,5,5,0,&(tlvEle[0].tlv));
  
  TEST_ASSERT_EQUAL_PTR(&tlvEle[0], tlvInfo.list.head);
  TEST_ASSERT_NULL(tlvInfo.list.head->next);
  
}

void test_tlvReceivedPacket_the_tlv_queued_correctly_for_multiple_tlv(void){
  LinkedList list;
  linkedListInit(&list);
  
  TlvElement tlvEle[10]={};
  uint8_t buffer[DATA_SIZE]={};
  TlvInfo tlvInfo={TLV_IDLE,0,(TlvPacket *)buffer};
  uint8_t byteReceived;
  byteReceived=1;

	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //type1
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //type2
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //length
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //data[0]
	tlvReceivedPacket(&tlvInfo,0,tlvEle); 
  
  TEST_ASSERT_TLV_ELE(1,1,1,1,0,0,0,0,0,&(tlvEle[0].tlv));
  TEST_ASSERT_EQUAL_PTR(&tlvEle[0], tlvInfo.list.head);
  TEST_ASSERT_EQUAL_PTR(&tlvEle[0], tlvInfo.list.tail);
  TEST_ASSERT_NULL(tlvInfo.list.head->next);
  
  byteReceived=2;
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //type1
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //type2
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //length
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //data[0]
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //data[1]
	tlvReceivedPacket(&tlvInfo,0,tlvEle); 
  
  TEST_ASSERT_TLV_ELE(1,1,1,1,0,0,0,0,0,&(tlvEle[0].tlv));
  TEST_ASSERT_TLV_ELE(2,2,2,2,2,0,0,0,0,&(tlvEle[1].tlv));
  TEST_ASSERT_EQUAL_PTR(&tlvEle[1], tlvInfo.list.head);
  TEST_ASSERT_EQUAL_PTR(&tlvEle[0], tlvInfo.list.head->next);
  TEST_ASSERT_EQUAL_PTR(&tlvEle[0], tlvInfo.list.tail);
  TEST_ASSERT_NULL(tlvInfo.list.head->next->next);
  
  byteReceived=3;
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //type1
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //type2
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //length
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //data[0]
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //data[1]
	tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle); //data[2]
	tlvReceivedPacket(&tlvInfo,0,tlvEle); 
  
  TEST_ASSERT_TLV_ELE(1,1,1,1,0,0,0,0,0,&(tlvEle[0].tlv));
  TEST_ASSERT_TLV_ELE(2,2,2,2,2,0,0,0,0,&(tlvEle[1].tlv));
  TEST_ASSERT_TLV_ELE(3,3,3,3,3,3,0,0,0,&(tlvEle[2].tlv));
  TEST_ASSERT_EQUAL_PTR(&tlvEle[2], tlvInfo.list.head);
  TEST_ASSERT_EQUAL_PTR(&tlvEle[1], tlvInfo.list.head->next);
  TEST_ASSERT_EQUAL_PTR(&tlvEle[0], tlvInfo.list.head->next->next);
  TEST_ASSERT_EQUAL_PTR(&tlvEle[0], tlvInfo.list.tail);
  TEST_ASSERT_NULL(tlvInfo.list.head->next->next->next);
}

void test_tlvInterpreter_deQueue_tlv_and_interprete_correctly(void)
{
  LinkedList list;
  linkedListInit(&list);
  
  TlvPacket  packet[10]={{TYPE_READ,1,1,1},{2,2,2,2,2},{3,3,3,3,3,3}};
  TlvElement tlvEle[10]={{NULL,packet[0]},{&tlvEle[0],packet[1]},{&tlvEle[1],packet[2]}};
  list.head=(ListElement *)(&tlvEle[2]);
  list.tail=(ListElement *)(&tlvEle[0]);
  
  FlashInfo flashInfo={FLASH_IDLE,INTERPRETE_READY,NULL};
  
  tlvInterpreter(&list,&flashInfo);
  TEST_ASSERT_EQUAL_PTR(&tlvEle[2], list.head);
  TEST_ASSERT_EQUAL_PTR(&tlvEle[1], list.head->next);
  TEST_ASSERT_NULL( list.head->next->next);
  
  TEST_ASSERT_EQUAL(FLASH_READ,flashInfo.state);
}

// void test_testing(void){
  // uint8_t data[10]={0x12,0x34,0x56,0x78,0x11};
  
  // uint32_t address;
  
  // address=*(uint32_t *)(&data[0]);
  
  // printf("0x%x",address);
  
  
// }
