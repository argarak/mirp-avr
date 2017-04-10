#ifndef _H_UART
#define _H_UART

#include "../../constants/datatypes.h"

#include <avr/io.h>
#include <util/delay.h>

#include <stdlib.h>

namespace UART {
  void Init();
  bool IsAvailable();
  void Print(const char* data);
  void PutChar(unsigned char data);
  uint8_t GetChar();
  char* ReadString();
  command SendCommand(command c);
}

#endif
