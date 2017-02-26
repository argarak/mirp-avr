
/*
 * I would like to give some credit to this page:
 * https://www.cs.mun.ca/~rod/Winter2007/4723/notes/serial/serial.html
 * which helped me write these functions!
 */

#include "uart.h"

void UART::Init(uint16_t baud) {
  DDRD |= _BV(1);
  UBRR0 = baud;
  UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);
  UCSR0A = 0;
  UCSR0B = _BV(RXEN0) | _BV(TXEN0);
}

bool UART::IsAvailable() {
  if((UCSR0A & _BV(TXC0)) == 0)
    return false;
  return true;
}

bool UART::PutChar(byte data) {
  while(!UART::IsAvailable())
    ;

  UDR0 = data;

  _delay_ms(100);

  return true;
}

uint8_t UART::GetChar() {
  uint16_t delay = 500;
  while(!UART::IsAvailable()) {
    _delay_ms(1);
    delay--;
    if(delay == 0)
      return 0;
  }

  return UDR0;
}

command UART::SendCommand(command c) {
  UART::PutChar(c.type[0]);
  UART::PutChar(c.type[1]);
  UART::PutChar(c.msg);

  uint8_t input = UART::GetChar();

  return (command){{0x2e, 0x2e}, 0x01};
}