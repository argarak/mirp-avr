
#include "serial.h"

bool Serial::IsAvaliable() {
  return true;
}

command Serial::SendCommand(command c) {
  return (command){{0x2e, 0x2e}, 0x01};
}
