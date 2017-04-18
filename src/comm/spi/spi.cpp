
/*
 * And if you are wondering, yes these are from
 * the datasheet (atmega328p).
 */

#include "spi.h"

void SPI::Init() {
  // Set MOSI and SCK output, all others input
  DDR_SPI = (1 << DD_MOSI) | (1 << DD_SCK);

  // Enable SPI, Master, set clock rate fck/16
  SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

bool SPI::SendComplete() {
  return SPSR & (1 << SPIF);
}

void SPI::Send(uint8_t d) {
  // Send byte
  SPDR = d;

  // Wait until completed
  while(!SPI::SendComplete())
    ;
}
