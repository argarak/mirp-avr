#ifndef H_UART_
#define H_UART_

#include "../../constants/datatypes.h"

#include <avr/io.h>
//#include <util/setbaud.h>
#include <util/delay.h>

#define BAUD 115200
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)

namespace UART {
  void Init(uint16_t baud);
  bool IsAvailable();
  bool PutChar(byte data);
  uint8_t GetChar();
  command SendCommand(command c);
}

#endif
