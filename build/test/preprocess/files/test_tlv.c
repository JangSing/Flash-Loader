#include "tlvAllocator.h"
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





  UnityAssertEqualNumber((_U_SINT)((TLV_IDLE)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);

 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

  UnityAssertEqualNumber((_U_SINT)((TYPE1_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);



 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

  UnityAssertEqualNumber((_U_SINT)((TYPE2_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_INT);



 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

  UnityAssertEqualNumber((_U_SINT)((LENGTH_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)36, UNITY_DISPLAY_STYLE_INT);



 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

  UnityAssertEqualNumber((_U_SINT)((LENGTH_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)39, UNITY_DISPLAY_STYLE_INT);



 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

  UnityAssertEqualNumber((_U_SINT)((LENGTH_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_INT);



 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

  UnityAssertEqualNumber((_U_SINT)((LENGTH_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_INT);



 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

  UnityAssertEqualNumber((_U_SINT)((LENGTH_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_INT);



 tlvReceivedPacket(&tlvInfo,byteReceived,((void *)0));

  UnityAssertEqualNumber((_U_SINT)((VALUE_RECEIVED)), (_U_SINT)((tlvInfo.state)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->type1)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->type2)), (((void *)0)), (_U_UINT)71, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->length)), (((void *)0)), (_U_UINT)72, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->data[0])), (((void *)0)), (_U_UINT)73, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->data[1])), (((void *)0)), (_U_UINT)74, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->data[2])), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->data[3])), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((tlvInfo.ptr->data[4])), (((void *)0)), (_U_UINT)77, UNITY_DISPLAY_STYLE_INT);

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



  customTestTlvEle(5, 5, 5, 5, 5, 5, 5, 5, 0, &(tlvEle[0].tlv), 102);;



  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[0])), (_U_SINT)(_UP)((tlvInfo.list.head)), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_HEX32);

  if ((((tlvInfo.list.head->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)105);;};



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



  customTestTlvEle(1, 1, 1, 1, 0, 0, 0, 0, 0, &(tlvEle[0].tlv), 125);;

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[0])), (_U_SINT)(_UP)((tlvInfo.list.head)), (((void *)0)), (_U_UINT)126, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[0])), (_U_SINT)(_UP)((tlvInfo.list.tail)), (((void *)0)), (_U_UINT)127, UNITY_DISPLAY_STYLE_HEX32);

  if ((((tlvInfo.list.head->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)128);;};



  byteReceived=2;

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,0,tlvEle);



  customTestTlvEle(1, 1, 1, 1, 0, 0, 0, 0, 0, &(tlvEle[0].tlv), 138);;

  customTestTlvEle(2, 2, 2, 2, 2, 0, 0, 0, 0, &(tlvEle[1].tlv), 139);;

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[1])), (_U_SINT)(_UP)((tlvInfo.list.head)), (((void *)0)), (_U_UINT)140, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[0])), (_U_SINT)(_UP)((tlvInfo.list.head->next)), (((void *)0)), (_U_UINT)141, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[0])), (_U_SINT)(_UP)((tlvInfo.list.tail)), (((void *)0)), (_U_UINT)142, UNITY_DISPLAY_STYLE_HEX32);

  if ((((tlvInfo.list.head->next->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)143);;};



  byteReceived=3;

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,byteReceived,tlvEle);

 tlvReceivedPacket(&tlvInfo,0,tlvEle);



  customTestTlvEle(1, 1, 1, 1, 0, 0, 0, 0, 0, &(tlvEle[0].tlv), 154);;

  customTestTlvEle(2, 2, 2, 2, 2, 0, 0, 0, 0, &(tlvEle[1].tlv), 155);;

  customTestTlvEle(3, 3, 3, 3, 3, 3, 0, 0, 0, &(tlvEle[2].tlv), 156);;

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[2])), (_U_SINT)(_UP)((tlvInfo.list.head)), (((void *)0)), (_U_UINT)157, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[1])), (_U_SINT)(_UP)((tlvInfo.list.head->next)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[0])), (_U_SINT)(_UP)((tlvInfo.list.head->next->next)), (((void *)0)), (_U_UINT)159, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[0])), (_U_SINT)(_UP)((tlvInfo.list.tail)), (((void *)0)), (_U_UINT)160, UNITY_DISPLAY_STYLE_HEX32);

  if ((((tlvInfo.list.head->next->next->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)161);;};

}
