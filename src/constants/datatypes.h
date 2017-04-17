#ifndef H_DATA_TYPES_
#define H_DATA_TYPES_

#include <avr/io.h>

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

extern struct gpio_t_struct {
  volatile uint8_t ddr;
  volatile uint8_t pin;
  volatile uint8_t* port;
  volatile uint8_t* portd;
} gpio_t_struct;

typedef struct gpio_t_struct gpio_t;

#endif
