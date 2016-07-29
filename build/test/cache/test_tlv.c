#include "CustomAssertion.h"
#include "LinkedList.h"
#include "tlv.h"
#include "unity.h"






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



  UnityAssertEqualNumber((_U_SINT)((TLV_IDLE)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

 tlvStateMachine(&tlvInfo,byteReceived);

  UnityAssertEqualNumber((_U_SINT)((TYPE1_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);



 tlvStateMachine(&tlvInfo,byteReceived);

  UnityAssertEqualNumber((_U_SINT)((TYPE2_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)31, UNITY_DISPLAY_STYLE_INT);



 tlvStateMachine(&tlvInfo,byteReceived);

  UnityAssertEqualNumber((_U_SINT)((LENGTH_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT);



 tlvStateMachine(&tlvInfo,byteReceived);

  UnityAssertEqualNumber((_U_SINT)((LENGTH_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);



 tlvStateMachine(&tlvInfo,byteReceived);

  UnityAssertEqualNumber((_U_SINT)((LENGTH_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)40, UNITY_DISPLAY_STYLE_INT);



 tlvStateMachine(&tlvInfo,byteReceived);

  UnityAssertEqualNumber((_U_SINT)((LENGTH_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT);



 tlvStateMachine(&tlvInfo,byteReceived);

  UnityAssertEqualNumber((_U_SINT)((LENGTH_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_INT);



 tlvStateMachine(&tlvInfo,byteReceived);

  UnityAssertEqualNumber((_U_SINT)((VALUE_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

}



void test_function_tlvStateMachine_passing_in_tlv_info_should_give_correct_result(void)

{

  uint8_t buffer[258]={};

  TlvInfo tlvInfo={TLV_IDLE,0,(TlvPacket *)buffer};

  uint8_t byteReceived;

  byteReceived=5;



 tlvStateMachine(&tlvInfo,byteReceived);

 tlvStateMachine(&tlvInfo,byteReceived);

 tlvStateMachine(&tlvInfo,byteReceived);

 tlvStateMachine(&tlvInfo,byteReceived);

 tlvStateMachine(&tlvInfo,byteReceived);

 tlvStateMachine(&tlvInfo,byteReceived);

 tlvStateMachine(&tlvInfo,byteReceived);

 tlvStateMachine(&tlvInfo,byteReceived);



  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->type1)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->type2)), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->length)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->data[0])), (((void *)0)), (_U_UINT)71, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->data[1])), (((void *)0)), (_U_UINT)72, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->data[2])), (((void *)0)), (_U_UINT)73, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->data[3])), (((void *)0)), (_U_UINT)74, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->data[4])), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

}





void test_element_packet_is_pointing_to_tlvInfo(void)

{

  TlvElement tlvEle[10]={};

  uint8_t buffer[258]={};

  TlvInfo tlvInfo={TLV_IDLE,0,(TlvPacket *)buffer};

  uint8_t byteReceived;

  byteReceived=5;



 tlvStateMachine(&tlvInfo,byteReceived);

 tlvStateMachine(&tlvInfo,byteReceived);

 tlvStateMachine(&tlvInfo,byteReceived);

 tlvStateMachine(&tlvInfo,byteReceived);

 tlvStateMachine(&tlvInfo,byteReceived);

 tlvStateMachine(&tlvInfo,byteReceived);

 tlvStateMachine(&tlvInfo,byteReceived);

 tlvStateMachine(&tlvInfo,byteReceived);



  tlvEle[0].tlv=*(tlvInfo.ptr);



  customTestTlvEle(5, 5, 5, 5, 5, 5, 5, 5, 0, &(tlvEle[0].tlv), 98);;

}



void test_element_packet_is_pointing_to_tlvInfo_for_multiple_element(void)

{

  TlvElement tlvEle[10]={};

  uint8_t buffer[258]={};

  TlvInfo tlvInfo={TLV_IDLE,0,(TlvPacket *)buffer};



 TlvPacket packet[10]={{5,5,5,5,5,5,5,5},{4,4,4,4,4,4,4,4},{3,3,3,3,3,3,3,3}};



  tlvInfo.ptr=&packet[0];

  tlvEle[0].tlv=*(tlvInfo.ptr);



  customTestTlvEle(5, 5, 5, 5, 5, 5, 5, 5, 0, &(tlvEle[0].tlv), 112);;



  tlvInfo.ptr=&packet[1];

  tlvEle[1].tlv=*(tlvInfo.ptr);



  customTestTlvEle(5, 5, 5, 5, 5, 5, 5, 5, 0, &(tlvEle[0].tlv), 117);;

  customTestTlvEle(4, 4, 4, 4, 4, 4, 4, 4, 0, &(tlvEle[1].tlv), 118);;



  tlvInfo.ptr=&packet[2];

  tlvEle[2].tlv=*(tlvInfo.ptr);



  customTestTlvEle(5, 5, 5, 5, 5, 5, 5, 5, 0, &(tlvEle[0].tlv), 123);;

  customTestTlvEle(4, 4, 4, 4, 4, 4, 4, 4, 0, &(tlvEle[1].tlv), 124);;

  customTestTlvEle(3, 3, 3, 3, 3, 3, 3, 3, 0, &(tlvEle[2].tlv), 125);;

}









void test_enQueue_whether_the_element_queueing_correctly(void){

  TlvPacket packet[10]={{5,5,5,5,5,5,5,5},{4,4,4,4,4,4,4,4},{3,3,3,3,3,3,3,3}};

  TlvElement tlvEle[10]={{((void *)0),packet[0]},{((void *)0),packet[1]},{((void *)0),packet[2]}};



  LinkedList list;

  linkedListInit(&list);



  enQueue(&list, (ListElement *)(&tlvEle[0]));



  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[0])), (_U_SINT)(_UP)((list.head)), (((void *)0)), (_U_UINT)140, UNITY_DISPLAY_STYLE_HEX32);

  if ((((list.head->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)141);;};



  customTestTlvEle(5, 5, 5, 5, 5, 5, 5, 5, 0, &(((TlvElement *)(list.head))->tlv), 143);;



  enQueue(&list, (ListElement *)(&tlvEle[1]));



  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[1])), (_U_SINT)(_UP)((list.head)), (((void *)0)), (_U_UINT)147, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[0])), (_U_SINT)(_UP)((list.head->next)), (((void *)0)), (_U_UINT)148, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[0])), (_U_SINT)(_UP)((list.tail)), (((void *)0)), (_U_UINT)149, UNITY_DISPLAY_STYLE_HEX32);

  if ((((list.head->next->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)150);;};



  customTestTlvEle(4, 4, 4, 4, 4, 4, 4, 4, 0, &(((TlvElement *)(list.head))->tlv), 152);;

  customTestTlvEle(5, 5, 5, 5, 5, 5, 5, 5, 0, &(((TlvElement *)(list.head->next))->tlv), 153);;



  enQueue(&list, (ListElement *)(&tlvEle[2]));



  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[2])), (_U_SINT)(_UP)((list.head)), (((void *)0)), (_U_UINT)157, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[1])), (_U_SINT)(_UP)((list.head->next)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[0])), (_U_SINT)(_UP)((list.head->next->next)), (((void *)0)), (_U_UINT)159, UNITY_DISPLAY_STYLE_HEX32);

  if ((((list.head->next->next->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)160);;};

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[0])), (_U_SINT)(_UP)((list.tail)), (((void *)0)), (_U_UINT)161, UNITY_DISPLAY_STYLE_HEX32);



  customTestTlvEle(3, 3, 3, 3, 3, 3, 3, 3, 0, &(((TlvElement *)(list.head))->tlv), 163);;

  customTestTlvEle(4, 4, 4, 4, 4, 4, 4, 4, 0, &(((TlvElement *)(list.head->next))->tlv), 164);;

  customTestTlvEle(5, 5, 5, 5, 5, 5, 5, 5, 0, &(((TlvElement *)(list.head->next->next))->tlv), 165);;

}



void test_deQueue_whether_the_element_deQueueing_correctly_like_FIFO(void){

  TlvPacket packet[10]={{5,5,5,5,5,5,5,5},{4,4,4,4,4,4,4,4},{3,3,3,3,3,3,3,3}};

  TlvElement tlvEle[10]={{((void *)0),packet[0]},{((void *)0),packet[1]},{((void *)0),packet[2]}};



  LinkedList list;

  linkedListInit(&list);



  enQueue(&list, (ListElement *)(&tlvEle[0]));

  enQueue(&list, (ListElement *)(&tlvEle[1]));

  enQueue(&list, (ListElement *)(&tlvEle[2]));



  TlvElement *deQEle=((void *)0);



  deQEle=(TlvElement *)(deQueue(&list));



  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[2])), (_U_SINT)(_UP)((list.head)), (((void *)0)), (_U_UINT)183, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[1])), (_U_SINT)(_UP)((list.head->next)), (((void *)0)), (_U_UINT)184, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((list.tail)), (_U_SINT)(_UP)((list.head->next)), (((void *)0)), (_U_UINT)185, UNITY_DISPLAY_STYLE_HEX32);

  if ((((list.head->next->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)186);;};



  UnityAssertEqualNumber((_U_SINT)(_UP)((deQEle)), (_U_SINT)(_UP)((&tlvEle[0])), (((void *)0)), (_U_UINT)188, UNITY_DISPLAY_STYLE_HEX32);



  deQEle=(TlvElement *)(deQueue(&list));



  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[2])), (_U_SINT)(_UP)((list.head)), (((void *)0)), (_U_UINT)192, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((list.tail)), (_U_SINT)(_UP)((list.head)), (((void *)0)), (_U_UINT)193, UNITY_DISPLAY_STYLE_HEX32);

  if ((((list.head->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)194);;};



  UnityAssertEqualNumber((_U_SINT)(_UP)((deQEle)), (_U_SINT)(_UP)((&tlvEle[1])), (((void *)0)), (_U_UINT)196, UNITY_DISPLAY_STYLE_HEX32);



  deQEle=(TlvElement *)(deQueue(&list));



  if ((((list.head)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)200);;};

  if ((((list.tail)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)201);;};



  UnityAssertEqualNumber((_U_SINT)(_UP)((deQEle)), (_U_SINT)(_UP)((&tlvEle[2])), (((void *)0)), (_U_UINT)203, UNITY_DISPLAY_STYLE_HEX32);



}
