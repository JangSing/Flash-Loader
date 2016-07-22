#ifndef TLV_H_
#define TLV_H_

#include <stdint.h>

typedef struct TlvPacket TlvPacket;
struct TlvPacket {
  uint8_t type1;
  uint8_t type2;
  uint8_t length;
  int8_t  data[0];
};

/**
 * Initiate the sending of TLV packet. This function is non-blocking, which
 * means it returns to the caller immediately after queueing the packet to
 * tlvHandlePacketSending() for sending.
 */
void tlvSendPacket(TlvPacket *tlvPacket);

/**
 * Try to retrieve an incoming TLV packet. If none available, NULL is
 * returned. This function is non-blocking.
 */
TlvPacket *tlvGetPacket(void);

/**
 * Initialize TLV module
 */
void tlvInit(void);

/**
 * Service the TLV processes
 */
void tlvRunService(void);

#endif   // TLV_H_