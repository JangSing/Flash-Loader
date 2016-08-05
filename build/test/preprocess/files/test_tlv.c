#include "CustomAssertion.h"
#include "LinkedList.h"
#include "Flash_tb.h"
#include "tlv_tb.h"
#include "unity.h"








void setUp(void)

{

}



void tearDown(void)

{

}



void test_function_tlvReceivedPacket_running_in_correct_state(void)

{

  uint8_t buffer[258]={};

  TlvInfo tlvInfo={TLV_IDLE,0,(TlvPacket *)buffer};

  uint8_t byteReceived=5;





  UnityAssertEqualNumber((_U_SINT)((TLV_IDLE)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

  UnityAssertEqualNumber((_U_SINT)((TYPE1_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)29, UNITY_DISPLAY_STYLE_INT);



 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

  UnityAssertEqualNumber((_U_SINT)((TYPE2_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)32, UNITY_DISPLAY_STYLE_INT);



 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

  UnityAssertEqualNumber((_U_SINT)((LENGTH_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT);



 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

  UnityAssertEqualNumber((_U_SINT)((LENGTH_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT);



 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

  UnityAssertEqualNumber((_U_SINT)((LENGTH_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);



 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

  UnityAssertEqualNumber((_U_SINT)((LENGTH_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_INT);



 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

  UnityAssertEqualNumber((_U_SINT)((LENGTH_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)47, UNITY_DISPLAY_STYLE_INT);



 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

  UnityAssertEqualNumber((_U_SINT)((VALUE_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT);

}



void test_function_tlvReceivedPacket_passing_in_tlv_info_should_give_correct_result(void)

{

  uint8_t buffer[258]={};

  TlvInfo tlvInfo={TLV_IDLE,0,(TlvPacket *)buffer};

  uint8_t byteReceived;

  byteReceived=5;



 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));



  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->type1)), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->type2)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->length)), (((void *)0)), (_U_UINT)71, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->data[0])), (((void *)0)), (_U_UINT)72, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->data[1])), (((void *)0)), (_U_UINT)73, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->data[2])), (((void *)0)), (_U_UINT)74, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->data[3])), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->data[4])), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);

}





void test_element_packet_is_pointing_to_tlvInfo_and_it_was_queued_correctly(void)

{

  LinkedList list;

  linkedListInit(&list);



  TlvElement tlvEle[10]={};

  uint8_t buffer[258]={};

  TlvInfo tlvInfo={TLV_IDLE,0,(TlvPacket *)buffer,list};

  uint8_t byteReceived;

  byteReceived=5;



 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,0,tlvEle);



  customTestTlvEle(5, 5, 5, 5, 5, 5, 5, 5, 0, &(tlvEle[0].tlv), 101);;



  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[0])), (_U_SINT)(_UP)((tlvInfo.list.head)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_HEX32);

  if ((((tlvInfo.list.head->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)104);;};



}



void test_tlvReceivedPacket_the_tlv_queued_correctly_for_multiple_tlv(void){

  LinkedList list;

  linkedListInit(&list);



  TlvElement tlvEle[10]={};

  uint8_t buffer[258]={};

  TlvInfo tlvInfo={TLV_IDLE,0,(TlvPacket *)buffer};

  uint8_t byteReceived;

  byteReceived=1;



 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,0,tlvEle);



  customTestTlvEle(1, 1, 1, 1, 0, 0, 0, 0, 0, &(tlvEle[0].tlv), 124);;

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[0])), (_U_SINT)(_UP)((tlvInfo.list.head)), (((void *)0)), (_U_UINT)125, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[0])), (_U_SINT)(_UP)((tlvInfo.list.tail)), (((void *)0)), (_U_UINT)126, UNITY_DISPLAY_STYLE_HEX32);

  if ((((tlvInfo.list.head->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)127);;};



  byteReceived=2;

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,0,tlvEle);



  customTestTlvEle(1, 1, 1, 1, 0, 0, 0, 0, 0, &(tlvEle[0].tlv), 137);;

  customTestTlvEle(2, 2, 2, 2, 2, 0, 0, 0, 0, &(tlvEle[1].tlv), 138);;

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[1])), (_U_SINT)(_UP)((tlvInfo.list.head)), (((void *)0)), (_U_UINT)139, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[0])), (_U_SINT)(_UP)((tlvInfo.list.head->next)), (((void *)0)), (_U_UINT)140, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[0])), (_U_SINT)(_UP)((tlvInfo.list.tail)), (((void *)0)), (_U_UINT)141, UNITY_DISPLAY_STYLE_HEX32);

  if ((((tlvInfo.list.head->next->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)142);;};



  byteReceived=3;

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,0,tlvEle);



  customTestTlvEle(1, 1, 1, 1, 0, 0, 0, 0, 0, &(tlvEle[0].tlv), 153);;

  customTestTlvEle(2, 2, 2, 2, 2, 0, 0, 0, 0, &(tlvEle[1].tlv), 154);;

  customTestTlvEle(3, 3, 3, 3, 3, 3, 0, 0, 0, &(tlvEle[2].tlv), 155);;

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[2])), (_U_SINT)(_UP)((tlvInfo.list.head)), (((void *)0)), (_U_UINT)156, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[1])), (_U_SINT)(_UP)((tlvInfo.list.head->next)), (((void *)0)), (_U_UINT)157, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[0])), (_U_SINT)(_UP)((tlvInfo.list.head->next->next)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[0])), (_U_SINT)(_UP)((tlvInfo.list.tail)), (((void *)0)), (_U_UINT)159, UNITY_DISPLAY_STYLE_HEX32);

  if ((((tlvInfo.list.head->next->next->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)160);;};

}



void test_tlvInterpreter_deQueue_tlv_and_interprete_correctly(void)

{

  LinkedList list;

  linkedListInit(&list);



  TlvPacket packet[10]={{0x10,1,1,1},{2,2,2,2,2},{3,3,3,3,3,3}};

  TlvElement tlvEle[10]={{((void *)0),packet[0]},{&tlvEle[0],packet[1]},{&tlvEle[1],packet[2]}};

  list.head=(ListElement *)(&tlvEle[2]);

  list.tail=(ListElement *)(&tlvEle[0]);



  FlashInfo flashInfo={FLASH_IDLE,INTERPRETE_READY,((void *)0)};



  tlvInterpreter(&list,&flashInfo);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[2])), (_U_SINT)(_UP)((list.head)), (((void *)0)), (_U_UINT)176, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[1])), (_U_SINT)(_UP)((list.head->next)), (((void *)0)), (_U_UINT)177, UNITY_DISPLAY_STYLE_HEX32);

  if ((((list.head->next->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)178);;};



  UnityAssertEqualNumber((_U_SINT)((FLASH_READ)), (_U_SINT)((flashInfo.state)), (((void *)0)), (_U_UINT)180, UNITY_DISPLAY_STYLE_INT);

}
