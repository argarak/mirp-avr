#ifndef H_UART_
#define H_UART_

#include "../uart/uart.h"
#include "../../../config/esp.h"

#include <avr/io.h>
#include <util/delay.h>

namespace ESP8266 {
  void Init();
  // device[] ScanDevices();
  int SendCommand(const char* command);
}

#endif
