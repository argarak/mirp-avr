
#include "stdmsg.h"

/*
 * Initialises the standard messaging debug system
 */
bool StdMsg::Init() {
  UART::Init();
  return true;
}

/*
 * Sends a warning via stdmsg and hex codes
 */
bool StdMsg::SendWarning(msg warning) {
  UART::PutChar(warning.type[0]);
  UART::PutChar(warning.type[1]);
  UART::PutChar(warning.eid);
  UART::PutChar(warning.msg);
  UART::PutChar('\n');

  return true;
}

/*
 * Compares two commands, returns true if they are
 * the same and vice versa
 */
bool StdMsg::CommandCompare(command a, command b) {
  if(a.type[0] == b.type[0])
    if(a.type[1] == b.type[1])
      if(a.msg == a.msg)
        return true;
  return false;
}
