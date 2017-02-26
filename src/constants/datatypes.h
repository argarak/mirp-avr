#ifndef H_DATA_TYPES_
#define H_DATA_TYPES_

typedef unsigned char byte;

extern struct command_struct {
  byte type[2];
  byte msg;
} command_struct;

typedef struct command_struct command;

extern struct msg_struct {
  byte type[2];
  byte eid;
  byte msg;
} msg_struct;

typedef struct msg_struct msg;

#endif
