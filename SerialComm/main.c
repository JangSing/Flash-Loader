#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include "Serial.h"

int main() {
  DWORD size;
  uint8_t buffer[24];
  uint8_t inBuff[24];
  const char *comPort = "COM3";
  
  printf("Opening %s\n", comPort);
  HANDLE hSerial = initSerialComm(comPort, 9600);
  
  while(1){
    printf("Type Something pls: ");
    scanf("%s",inBuff);
    
    writeToSerialPort(hSerial, inBuff, 31);
    // writeToSerialPort(hSerial, "Hello world xD `", 16);
    // size = readFromSerialPort(hSerial, buffer, 32);
    // printf("%.*s\n", size, buffer);
    printf("End Session?(Y/N): ");
    scanf("%s",inBuff);
    if(*inBuff=='Y')
      break;
  }
  
  
  printf("Closing %s\n", comPort);
  closeSerialPort(hSerial);
  return 0;
}