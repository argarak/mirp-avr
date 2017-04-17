
/*
 * I would like to give some credit to this page:
 * https://www.cs.mun.ca/~rod/Winter2007/4723/notes/serial/serial.html
 * which helped me write these functions!
 */

#include "uart.h"

void UART::Init() {
#define BAUD 19200
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
uint16_t UART::Strlen(const char* str) {
  uint16_t len;
  for(len = 0; str[len]; len++);
  return len;
}

void UART::Print(const char* data) {
  for(int i = 0; i < UART::Strlen(data); i++) {
    while(!UART::IsAvailable())
      ;
    UDR0 = data[i];
  }
}

void UART::PutChar(unsigned char data) {
  while(!UART::IsAvailable())
    ;
  UDR0 = (int)data;
}

uint8_t UART::GetChar() {
  //loop_until_bit_is_set(UCSR0A, RXC0);
  while(!(UCSR0A & (1 << RXC0)))
    ;
  return UDR0;
}

command UART::SendCommand(command c) {
  UART::PutChar(c.type[0]);
  UART::PutChar(c.type[1]);
  UART::PutChar(c.msg);
  UART::PutChar('\n');

  unsigned char buffer[3];

  for(int i = 0;; i++) {
    uint8_t input = UART::GetChar();

    if(input == '\n')
      break;

    if(input != '\0')
      buffer[i] = input;
  }

  UART::PutChar(buffer[0]);
  UART::PutChar(buffer[1]);
  UART::PutChar(buffer[2]);

  if(UART::Strlen((const char*)buffer) == 3)
    return command{{buffer[0], buffer[1]}, buffer[3]};
  else
    return command{{0, 0}, 0};
}

char* UART::ReadString() {
  char* buf = (char*)malloc(255);

  buf[0] = '\0';

  uint8_t i = 0;
  char b = '\0';

  do {
    do {
      b = UART::GetChar();
      break;

    } while(1);

    buf[i] = b;
    i++;

  } while(b != '\n' && b != '\r' && b != '\0');

  buf[i] = '\0';

  // remember to free()!
  return buf;
}
