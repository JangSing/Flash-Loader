#ifndef CustomAssertion_H
#define CustomAssertion_H
#include <stdint.h>

#include "unity.h"
#include "tlv.h"

#define TEST_ASSERT_TLV_ELE(type1, type2, length, data0, data1, data2, data3, data4, data5, actual)                                        \
                    customTestTlvEle(type1,                                      \
                                     type2,                                      \
                                     length,                                     \
                                     data0,                                      \
                                     data1,                                      \
                                     data2,                                      \
                                     data3,                                      \
                                     data4,                                      \
                                     data5,                                      \
                                     actual, __LINE__);


#define CUSTOM_TEST_FAIL(msg,...)              {                                                                              \
                                               char buffer[256];                                                              \
                                               sprintf(buffer,msg, ## __VA_ARGS__);                                           \
                                               UNITY_TEST_FAIL(lineNo, buffer);                                               \
                                               }

void customTestTlvEle(uint8_t type1,
                      uint8_t type2,
                      uint8_t length,
                      uint8_t data0,
                      uint8_t data1,
                      uint8_t data2,
                      uint8_t data3,
                      uint8_t data4,
                      uint8_t data5,
                      TlvPacket *actual, int lineNo);



#endif // CustomAssertion_H
