
#include "esp.h"

#include "../uart/uart.h"

int ESP8266::SendCommand(const char* command) {
  return 0;
}

void ESP8266::Init() {
  // Set pin mode for the reset pin
  DDRD |= _BV(ESP_RST_DIR);

  PORTD |= _BV(ESP_RST_PIN);
  _delay_ms(500);
  PORTD &= ~_BV(ESP_RST_PIN);

  uint8_t buffer[25];
  buffer[0] = UART::GetChar();

  for(int i = 0; buffer[i] != '\r' ||
        buffer[i] != '\n' || i == 24; i++) {
    buffer[i] = UART::GetChar();
  }
}
