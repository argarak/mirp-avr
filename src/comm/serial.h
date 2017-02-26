#ifndef H_SERIAL_
#define H_SERIAL_

#include "../constants/datatypes.h"

namespace Serial {
  bool IsAvaliable();
  command SendCommand(command c);
}

#endif
