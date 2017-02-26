#ifndef H_STDMSG_
#define H_STDMSG_

#include "../constants/datatypes.h"
#include "../comm/uart/uart.h"

namespace StdMsg {
  extern byte msgtype;

  bool Init(uint16_t baud);
  bool SendWarning(msg warning);
  bool CommandCompare(command a, command b);
};

#endif
