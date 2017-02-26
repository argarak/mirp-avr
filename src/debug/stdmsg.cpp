
#include "stdmsg.h"

/*
 * Initialises the standard messaging debug system
 */
bool StdMsg::Init(uint16_t baud) {
  UART::Init(baud);
  return true;
}

/*
 * Sends a warning via stdmsg and hex codes
 */
bool StdMsg::SendWarning(msg warning) {
  return true;
}

bool StdMsg::CommandCompare(command a, command b) {
  return true;
}
