#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "unity.h"
#include "tlv.h"
#include "LinkedList.h"
#include "CustomAssertion.h"



void setUp(void)
{
}

void tearDown(void)
{
}

void test_function_tlvStateMachine_running_in_correct_state(void)
{
  uint8_t buffer[258]={};
  TlvInfo tlvInfo={TLV_IDLE,0,(TlvPacket *)buffer};
  uint8_t byteReceived;
  byteReceived=5;

  TEST_ASSERT_EQUAL(TLV_IDLE,tlvInfo.state);
	tlvStateMachine(&tlvInfo,byteReceived); //type1
  TEST_ASSERT_EQUAL(TYPE1_RECEIVED,tlvInfo.state);

	tlvStateMachine(&tlvInfo,byteReceived); //type2
  TEST_ASSERT_EQUAL(TYPE2_RECEIVED,tlvInfo.state);

	tlvStateMachine(&tlvInfo,byteReceived); //length
  TEST_ASSERT_EQUAL(LENGTH_RECEIVED,tlvInfo.state);

	tlvStateMachine(&tlvInfo,byteReceived); //data[0]
  TEST_ASSERT_EQUAL(LENGTH_RECEIVED,tlvInfo.state);

	tlvStateMachine(&tlvInfo,byteReceived); //data[1]
  TEST_ASSERT_EQUAL(LENGTH_RECEIVED,tlvInfo.state);

	tlvStateMachine(&tlvInfo,byteReceived); //data[2]
  TEST_ASSERT_EQUAL(LENGTH_RECEIVED,tlvInfo.state);

	tlvStateMachine(&tlvInfo,byteReceived); //data[3]
  TEST_ASSERT_EQUAL(LENGTH_RECEIVED,tlvInfo.state);

	tlvStateMachine(&tlvInfo,byteReceived); //data[4]
  TEST_ASSERT_EQUAL(VALUE_RECEIVED,tlvInfo.state);
}

void test_function_tlvStateMachine_passing_in_tlv_info_should_give_correct_result(void)
{
  uint8_t buffer[258]={};
  TlvInfo tlvInfo={TLV_IDLE,0,(TlvPacket *)buffer};
  uint8_t byteReceived;
  byteReceived=5;

	tlvStateMachine(&tlvInfo,byteReceived); //type1
	tlvStateMachine(&tlvInfo,byteReceived); //type2
	tlvStateMachine(&tlvInfo,byteReceived); //length
	tlvStateMachine(&tlvInfo,byteReceived); //data[0]
	tlvStateMachine(&tlvInfo,byteReceived); //data[1]
	tlvStateMachine(&tlvInfo,byteReceived); //data[2]
	tlvStateMachine(&tlvInfo,byteReceived); //data[3]
	tlvStateMachine(&tlvInfo,byteReceived); //data[4]

  TEST_ASSERT_EQUAL(5,tlvInfo.ptr->type1);
  TEST_ASSERT_EQUAL(5,tlvInfo.ptr->type2);
  TEST_ASSERT_EQUAL(5,tlvInfo.ptr->length);
  TEST_ASSERT_EQUAL(5,tlvInfo.ptr->data[0]);
  TEST_ASSERT_EQUAL(5,tlvInfo.ptr->data[1]);
  TEST_ASSERT_EQUAL(5,tlvInfo.ptr->data[2]);
  TEST_ASSERT_EQUAL(5,tlvInfo.ptr->data[3]);
  TEST_ASSERT_EQUAL(5,tlvInfo.ptr->data[4]);
}


void test_element_packet_is_pointing_to_tlvInfo(void)
{
  TlvElement tlvEle[10]={};
  uint8_t buffer[DATA_SIZE]={};
  TlvInfo tlvInfo={TLV_IDLE,0,(TlvPacket *)buffer};
  uint8_t byteReceived;
  byteReceived=5;

	tlvStateMachine(&tlvInfo,byteReceived); //type1
	tlvStateMachine(&tlvInfo,byteReceived); //type2
	tlvStateMachine(&tlvInfo,byteReceived); //length
	tlvStateMachine(&tlvInfo,byteReceived); //data[0]
	tlvStateMachine(&tlvInfo,byteReceived); //data[1]
	tlvStateMachine(&tlvInfo,byteReceived); //data[2]
	tlvStateMachine(&tlvInfo,byteReceived); //data[3]
	tlvStateMachine(&tlvInfo,byteReceived); //data[4]

  tlvEle[0].tlv=*(tlvInfo.ptr);

  TEST_ASSERT_TLV_ELE(5,5,5,5,5,5,5,5,0,&(tlvEle[0].tlv));
}

void test_element_packet_is_pointing_to_tlvInfo_for_multiple_element(void)
{
  TlvElement tlvEle[10]={};
  uint8_t buffer[DATA_SIZE]={};
  TlvInfo tlvInfo={TLV_IDLE,0,(TlvPacket *)buffer};

	TlvPacket packet[10]={{5,5,5,5,5,5,5,5},{4,4,4,4,4,4,4,4},{3,3,3,3,3,3,3,3}};

  tlvInfo.ptr=&packet[0];
  tlvEle[0].tlv=*(tlvInfo.ptr);

  TEST_ASSERT_TLV_ELE(5,5,5,5,5,5,5,5,0,&(tlvEle[0].tlv));

  tlvInfo.ptr=&packet[1];
  tlvEle[1].tlv=*(tlvInfo.ptr);

  TEST_ASSERT_TLV_ELE(5,5,5,5,5,5,5,5,0,&(tlvEle[0].tlv));
  TEST_ASSERT_TLV_ELE(4,4,4,4,4,4,4,4,0,&(tlvEle[1].tlv));

  tlvInfo.ptr=&packet[2];
  tlvEle[2].tlv=*(tlvInfo.ptr);

  TEST_ASSERT_TLV_ELE(5,5,5,5,5,5,5,5,0,&(tlvEle[0].tlv));
  TEST_ASSERT_TLV_ELE(4,4,4,4,4,4,4,4,0,&(tlvEle[1].tlv));
  TEST_ASSERT_TLV_ELE(3,3,3,3,3,3,3,3,0,&(tlvEle[2].tlv));
}

//this macro is to enable the program to point to the desirable tlvPacket of the element
#define  ElementPacket(whichEle)   (((TlvElement *)(whichEle))->tlv)

void test_enQueue_whether_the_element_queueing_correctly(void){
  TlvPacket packet[10]={{5,5,5,5,5,5,5,5},{4,4,4,4,4,4,4,4},{3,3,3,3,3,3,3,3}};
  TlvElement tlvEle[10]={{NULL,packet[0]},{NULL,packet[1]},{NULL,packet[2]}};

  LinkedList list;
  linkedListInit(&list);

  enQueue(&list, (ListElement *)(&tlvEle[0]));

  TEST_ASSERT_EQUAL_PTR(&tlvEle[0], list.head);
  TEST_ASSERT_NULL(list.head->next);
  //optional
  TEST_ASSERT_TLV_ELE(5,5,5,5,5,5,5,5,0,&ElementPacket(list.head));

  enQueue(&list, (ListElement *)(&tlvEle[1]));

  TEST_ASSERT_EQUAL_PTR(&tlvEle[1], list.head);
  TEST_ASSERT_EQUAL_PTR(&tlvEle[0], list.head->next);
  TEST_ASSERT_EQUAL_PTR(&tlvEle[0], list.tail);
  TEST_ASSERT_NULL(list.head->next->next);
  //optional
  TEST_ASSERT_TLV_ELE(4,4,4,4,4,4,4,4,0,&ElementPacket(list.head));
  TEST_ASSERT_TLV_ELE(5,5,5,5,5,5,5,5,0,&ElementPacket(list.head->next));

  enQueue(&list, (ListElement *)(&tlvEle[2]));

  TEST_ASSERT_EQUAL_PTR(&tlvEle[2], list.head);
  TEST_ASSERT_EQUAL_PTR(&tlvEle[1], list.head->next);
  TEST_ASSERT_EQUAL_PTR(&tlvEle[0], list.head->next->next);
  TEST_ASSERT_NULL(list.head->next->next->next);
  TEST_ASSERT_EQUAL_PTR(&tlvEle[0], list.tail);
  //optional
  TEST_ASSERT_TLV_ELE(3,3,3,3,3,3,3,3,0,&ElementPacket(list.head));
  TEST_ASSERT_TLV_ELE(4,4,4,4,4,4,4,4,0,&ElementPacket(list.head->next));
  TEST_ASSERT_TLV_ELE(5,5,5,5,5,5,5,5,0,&ElementPacket(list.head->next->next));
}

void test_deQueue_whether_the_element_deQueueing_correctly_like_FIFO(void){
  TlvPacket packet[10]={{5,5,5,5,5,5,5,5},{4,4,4,4,4,4,4,4},{3,3,3,3,3,3,3,3}};
  TlvElement tlvEle[10]={{NULL,packet[0]},{NULL,packet[1]},{NULL,packet[2]}};

  LinkedList list;
  linkedListInit(&list);

  enQueue(&list, (ListElement *)(&tlvEle[0]));
  enQueue(&list, (ListElement *)(&tlvEle[1]));
  enQueue(&list, (ListElement *)(&tlvEle[2]));

  TlvElement *deQEle=NULL;

  deQEle=(TlvElement *)(deQueue(&list));

  TEST_ASSERT_EQUAL_PTR(&tlvEle[2], list.head);
  TEST_ASSERT_EQUAL_PTR(&tlvEle[1], list.head->next);
  TEST_ASSERT_EQUAL_PTR(list.tail, list.head->next);
  TEST_ASSERT_NULL(list.head->next->next);

  TEST_ASSERT_EQUAL_PTR(deQEle, &tlvEle[0]);

  deQEle=(TlvElement *)(deQueue(&list));

  TEST_ASSERT_EQUAL_PTR(&tlvEle[2], list.head);
  TEST_ASSERT_EQUAL_PTR(list.tail, list.head);
  TEST_ASSERT_NULL(list.head->next);

  TEST_ASSERT_EQUAL_PTR(deQEle, &tlvEle[1]);

  deQEle=(TlvElement *)(deQueue(&list));

  TEST_ASSERT_NULL(list.head);
  TEST_ASSERT_NULL(list.tail);

  TEST_ASSERT_EQUAL_PTR(deQEle, &tlvEle[2]);

}
