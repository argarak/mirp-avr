#ifndef H_STDMSG_
#define H_STDMSG_

#include "../constants/datatypes.h"
#include "../comm/uart/uart.h"

namespace StdMsg {
  extern byte msgtype;

  bool Init();
  bool SendWarning(msg warning);
  bool CommandCompare(command a, command b);
}

#endif
