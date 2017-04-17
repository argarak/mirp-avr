
#include "adc.h"

uint16_t ATDC::val = 0;

void ATDC::Init(uint8_t channel) {
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	io_set_high(ADMUX, REFS0);

	ADCSRA |= (1 << ADATE) | (1 << ADEN) | (1 << ADIE);
  io_set_high(ADCSRA, ADSC);

  ADMUX = (ADMUX & 0xf0) | channel;
}
