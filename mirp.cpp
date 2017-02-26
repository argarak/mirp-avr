#include "mirp.h"

int main(void) {
  StdMsg::Init();

  // Check if communication is avaliable
  if(Serial::IsAvaliable()) {
    if(StdMsg::CommandCompare(Serial::SendCommand(ASK_NETWORK_TYPE),
                              CLIENT_TYPE)) {
      // initialise client_mode
    } else {
      // assume that node is standalone in node network
      // send UDP command to attempt to communicate with other nodes...
    }
  } else {
    // Not connected
    StdMsg::SendWarning(MSG_NOT_CONNECTED);
  }
}
