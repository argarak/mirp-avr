#ifndef H_UART_
#define H_UART_

#include "../../constants/datatypes.h"

#include <avr/io.h>
//#include <util/setbaud.h>
#include <util/delay.h>

// Make sure it's not over 65535!
#define BAUD 57600
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)

namespace UART {
  void Init(uint16_t baud);
  bool IsAvailable();
  bool Print(const char* data);
  uint8_t GetChar();
  command SendCommand(command c);
}

#endif
