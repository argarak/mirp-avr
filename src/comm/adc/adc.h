
#include <avr/io.h>
#include "../../macros.h"

namespace ATDC {
  void Init(uint8_t channel);
  uint16_t Read(uint8_t ADCX);

  extern uint16_t val;
}
