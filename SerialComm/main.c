#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "Serial.h"

void write(HANDLE hSerial,uint8_t value){
  uint8_t inBuff[20];
  *inBuff=value;
  writeToSerialPort(hSerial, inBuff, 1);
}

int main() {
  DWORD size;
  uint8_t buffer[20]={};
  uint8_t receiveBuff;
  uint8_t inBuff[20];
  const char *comPort = "COM3";

  int i=0;

  printf("Opening %s\n", comPort);
  HANDLE hSerial = initSerialComm(comPort, 9600);

  printf("Sending Packet...\n");
  write(hSerial,0x10);//type1
  write(hSerial,0x10);//type2
  write(hSerial,5);//length
  //data start
  write(hSerial,0x00);
  write(hSerial,0x40);
  write(hSerial,0x10);
  write(hSerial,0x08);
  write(hSerial,0);
  //data end
  write(hSerial,0);//checksum

  for(i=0;i<12;i++){
    if(readFromSerialPort(hSerial, buffer, 1)){
      printf("0x%x\n", *buffer);
      fflush(stdout);
    }
  }

  printf("Sending Packet...\n");
  write(hSerial,0x10);//type1
  write(hSerial,0x10);//type2
  write(hSerial,5);//length
  //data start
  write(hSerial,0x00);
  write(hSerial,0x40);
  write(hSerial,0x10);
  write(hSerial,0x08);
  write(hSerial,0);
  //data end
  write(hSerial,0);//checksum

  for(i=0;i<12;i++){
    if(readFromSerialPort(hSerial, buffer, 1)){
      printf("0x%x\n", *buffer);
      fflush(stdout);
    }
  }

  printf("Closing %s\n", comPort);
  closeSerialPort(hSerial);
  return 0;
}

//0x0809 0000