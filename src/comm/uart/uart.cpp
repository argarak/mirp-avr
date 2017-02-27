
/*
 * I would like to give some credit to this page:
 * https://www.cs.mun.ca/~rod/Winter2007/4723/notes/serial/serial.html
 * which helped me write these functions!
 */

#include "uart.h"

void UART::Init() {
#define BAUD 9600
#include <util/setbaud.h>
  UBRR0 = UBRRH_VALUE;
  UBRR0 = UBRRL_VALUE;
#if USE_2X
  UCSR0A |= (1 << U2X0);
#else
  UCSR0A &= ~(1 << U2X0);
#endif

  DDRD |= _BV(1);
  UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);
  UCSR0B = _BV(RXEN0) | _BV(TXEN0);
}

bool UART::IsAvailable() {
  if((UCSR0A & _BV(UDRE0)) == 0)
    return false;
  return true;
}

// TODO Optimise this function
uint16_t strlen(const char* str) {
  uint16_t len;
  for(len = 0; str[len]; len++);
  return len;
}

void UART::Print(const char* data) {
  for(int i = 0; i < strlen(data); i++) {
    while(!UART::IsAvailable())
      ;
    UDR0 = data[i];
  }
}

void UART::PutChar(unsigned char data) {
  while(!UART::IsAvailable())
    ;
  UDR0 = data;
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
  UART::PutChar('\n');

  //uint8_t input = UART::GetChar();

  return command{{0x2e, 0x2e}, 0x01};
}
