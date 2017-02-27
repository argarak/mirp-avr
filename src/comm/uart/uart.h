#ifndef H_UART_
#define H_UART_

#include "../../constants/datatypes.h"

#include <avr/io.h>
//#include <util/setbaud.h>
#include <util/delay.h>

namespace UART {
  void Init();
  bool IsAvailable();
  void Print(const char* data);
  void PutChar(unsigned char data);
  uint8_t GetChar();
  command SendCommand(command c);
}

#endif
