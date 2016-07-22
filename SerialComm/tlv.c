#include "Tlv.h"

typedef struct TlvPacketSendingObject TlvPacketSendingObject;
struct TlvPacketSendingObject {
  State   state;
  Queue   *pktQueue;          // Sending queue of TLV packets
  int32_t retryCount;         // The number of retry done
  Exception *exception;       // Holds exception object to be thrown
  // ...
  // ...some other variables related to this TLV sender...
  // ...
};

typedef struct TlvPacketReceivingObject TlvPacketReceivingObject;
struct TlvPacketReceivingObject {
  State   state;
  Queue   *pktQueue;          // Receiving queue of TLV packets
  Exception *exception;       // Holds exception object to be thrown
  // ...
  // ...some other variables related to this TLV receiver...
  // ...
};

TlvPacketSendingObject   txObj;     // The object that holds information
                                    // about tlvHandlePacketSending()
TlvPacketReceivingObject rxObj;     // The object that holds information
                                    // about tlvHandlePacketReception()

static void tlvHandlePacketSending(TlvPacketSendingObject *obj);
static void tlvHandlePacketReception(TlvPacketReceivingObject *obj);

/**
 * Initialize TLV module
 */
void tlvInit(void) {
  // Initialize USB or UART/USART
  // ...
  // Initialize txObj
  // ...
  // Initialize rxObj
  // ..
}

/**
 * Service the TLV processes
 */
void tlvRunService(void) {
  tlvHandlePacketSending(&txObj);
  tlvHandlePacketReception(&rxObj);
}

/**
 * Initiate the sending of TLV packet. This function is non-blocking, which
 * means it returns to the caller immediately after queueing the packet to
 * tlvHandlePacketSending() for sending.
 */
void tlvSendPacket(TlvPacket *tlvPacket) {
  // ...the implementation here...
}

/**
 * Try to retrieve an incoming TLV packet. If none available, NULL is
 * returned. This function is non-blocking.
 */
TlvPacket *tlvGetPacket(void) {
  // ...the implementation here...
}

/**
 * This function implements the state machine of the sending process of the
 * TLV packet. If packet sent not received by the receiver, the sender will
 * retry sending until MAX_SENDING_RETRY is reached, after which an exeception
 * is generated.
 */
void tlvHandlePacketSending(TlvPacketSendingObject *obj) {
  // ...the state machine implementatiton here...
  // ...this function will call commSendByte()
}

/**
 * This function implements the state machine of the receiving process of the
 * TLV packet. If packet received is damaged, it responses with a NACK to
 * request sender to resend.
 */
void tlvHandlePacketReception(TlvPacketReceivingObject *obj) {
  // ...the state machine implementatiton here...
  // ...this function will call commGetByte()
}