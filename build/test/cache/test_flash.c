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



void test_tlvInterpreter_deQueue_tlv_and_interprete_correctly(void)

{

  LinkedList list;

  linkedListInit(&list);



  TlvPacket packet[10]={{0x10,1,1,1},{2,2,2,2,2},{3,3,3,3,3,3}};

  TlvElement tlvEle[10]={{((void *)0),packet[0]},{&tlvEle[0],packet[1]},{&tlvEle[1],packet[2]}};

  list.head=(ListElement *)(&tlvEle[2]);

  list.tail=(ListElement *)(&tlvEle[0]);



  FlashInfo flashInfo={FLASH_IDLE,PROCESS_READY,((void *)0),&list};



  tlvInterpreter(&flashInfo);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[2])), (_U_SINT)(_UP)((list.head)), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[1])), (_U_SINT)(_UP)((list.head->next)), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_HEX32);

  if ((((list.head->next->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)36);;};



  UnityAssertEqualNumber((_U_SINT)((FLASH_READ)), (_U_SINT)((flashInfo.state)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT);



}



void test_readFlash(void)

{

  LinkedList list;

  linkedListInit(&list);



  TlvPacket packet[10]={{0x10,1,5,0,0,0x09,0x08,2},{2,2,5,2,2},{3,3,5,3,3,3}};

  TlvElement tlvEle[10]={{((void *)0),packet[0]},{&tlvEle[0],packet[1]},{&tlvEle[1],packet[2]}};

  list.head=(ListElement *)(&tlvEle[2]);

  list.tail=(ListElement *)(&tlvEle[0]);



  FlashObject flashObj={READ_IDLE,((void *)0),0,0,((void *)0)};

  FlashInfo flashInfo={FLASH_IDLE,PROCESS_READY,((void *)0),&list,&flashObj};



  tlvInterpreter(&flashInfo);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[2])), (_U_SINT)(_UP)((list.head)), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&tlvEle[1])), (_U_SINT)(_UP)((list.head->next)), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_HEX32);

  if ((((list.head->next->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)58);;};



  UnityAssertEqualNumber((_U_SINT)((FLASH_READ)), (_U_SINT)((flashInfo.state)), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_INT);



  tlvInterpreter(&flashInfo);



  UnityAssertEqualNumber((_U_SINT)(_UP)((flashInfo.tlv)), (_U_SINT)(_UP)((flashObj.tlv)), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((0x08090000)), (_U_SINT)(_UP)((flashObj.address)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((flashObj.length)), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_INT);



}
