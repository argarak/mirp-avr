#ifndef H_COMMAND_
#define H_COMMAND_

#define ASK {0x61, 0x3f}
#define ASK_NETWORK_TYPE command{ASK, 0x01}

#define RESPOND {0x2e, 0x2e}
#define CLIENT_TYPE command{RESPOND, 0x01}

#endif
