
#include <avr/io.h>

#define DDR_SPI DDRB
#define DD_MOSI PB3
#define DD_SCK  PB5

namespace SPI {
  void Init();
  bool SendComplete();
  void Send(uint8_t d);
}
