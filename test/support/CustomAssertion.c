#include "CustomAssertion.h"

#include <stdio.h>

void customTestTlvEle(uint8_t type1,
                      uint8_t type2,
                      uint8_t length,
                      uint8_t data0,
                      uint8_t data1,
                      uint8_t data2,
                      uint8_t data3,
                      uint8_t data4,
                      uint8_t data5,
                      TlvPacket *actual,int lineNo){

  UNITY_TEST_ASSERT_EQUAL_INT8(type1,actual->type1, lineNo, NULL);
  UNITY_TEST_ASSERT_EQUAL_INT8(type2,actual->type2, lineNo, NULL);
  UNITY_TEST_ASSERT_EQUAL_INT8(length,actual->length, lineNo, NULL);
  UNITY_TEST_ASSERT_EQUAL_INT8(data0,actual->data[0], lineNo, NULL);
  UNITY_TEST_ASSERT_EQUAL_INT8(data1,actual->data[1], lineNo, NULL);
  UNITY_TEST_ASSERT_EQUAL_INT8(data2,actual->data[2], lineNo, NULL);
  UNITY_TEST_ASSERT_EQUAL_INT8(data3,actual->data[3], lineNo, NULL);
  UNITY_TEST_ASSERT_EQUAL_INT8(data4,actual->data[4], lineNo, NULL);
  UNITY_TEST_ASSERT_EQUAL_INT8(data5,actual->data[5], lineNo, NULL);
}

