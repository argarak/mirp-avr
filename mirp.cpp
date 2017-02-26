#include "mirp.h"

int main(void) {
  StdMsg::Init(BAUD);

  // Check if uart communication is avaliable
  if(UART::IsAvailable()) {
    if(StdMsg::CommandCompare(UART::SendCommand(ASK_NETWORK_TYPE),
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

  while(1) {
    uint8_t b = UART::GetChar();
    if(b >= 'A' && b <= 'Z') {
      b ^= 0x20;
    }
    PORTC = ~b;
    UART::PutChar(b);
  }

  return 0;
}
