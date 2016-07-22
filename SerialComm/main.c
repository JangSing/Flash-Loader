#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include "Serial.h"

int main() {
  DWORD size;
  uint8_t buffer;
  uint8_t inBuff[20];
  const char *comPort = "COM3";
  
  printf("Opening %s\n", comPort);
  HANDLE hSerial = initSerialComm(comPort, 9600);
  
  while(1){
    printf("Send a byte...\n");
    *inBuff=0x10;
    writeToSerialPort(hSerial, inBuff, 1);
    // size = readFromSerialPort(hSerial, buffer, 32);
    // printf("%.*s\n", size, buffer);
      
  }
  
  
  printf("Closing %s\n", comPort);
  closeSerialPort(hSerial);
  return 0;
}