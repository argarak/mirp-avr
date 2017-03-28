#include "mirp.h"

int main(void) {
  StdMsg::Init();

  // Check if uart communication is avaliable
  // if(UART::IsAvailable()) {
  //   if(StdMsg::CommandCompare(UART::SendCommand(ASK_NETWORK_TYPE),
  //                             CLIENT_TYPE)) {
  //     UART::Print("client_mode\n");
  //     // initialise client_mode
  //   } else {
  //     UART::Print("standalone_mode\n");
  //     // assume that node is standalone in node network
  //     // send UDP command to attempt to communicate with other nodes...
  //   }
  // } else {
  //   // Not connected
  //   //StdMsg::SendWarning(MSG_NOT_CONNECTED);
  // }

  // UART::Print("abc\n");

  while(1) {
    char* b = UART::ReadString();

    if(b[0] != '\0')
      UART::Print(b);

    free(b);
  }

  return 0;
}
