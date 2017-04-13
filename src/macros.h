
#ifndef _H_MACROS
#define _H_MACROS

#include <avr/io.h>

// I/O Access
#define BIT_T(p,b)                (PD ## b)
#define PORT_T(p,b)               (PORT ## p)
#define PIN_T(p,b)                (PORT ## p ## b)
#define DDR_T(p,b)                (DDR ## p)
#define BITD_T(p,b)               (DD ## p ## b)

#define BIT(...) BIT_T(__VA_ARGS__)
#define PORT(...) PORT_T(__VA_ARGS__)
#define PIN(...) PIN_T(__VA_ARGS__)
#define DDR(...) DDR_T(__VA_ARGS__)
#define BITD(...) BITD_T(__VA_ARGS__)

void io_set_high(volatile uint8_t* port, uint16_t pin) __attribute__((always_inline));
void io_set_low(volatile uint8_t* port, uint16_t pin) __attribute__((always_inline));
void io_toggle(volatile uint8_t* port, uint16_t pin) __attribute__((always_inline));
void io_mode_output(volatile uint8_t* portd, uint16_t pind) __attribute__((always_inline));
void io_mode_input(volatile uint8_t* portd, uint16_t pind) __attribute__((always_inline));

void inline io_set_high(volatile uint8_t* port, uint16_t pin) {
  *(port) |= _BV(pin);
}

void inline io_set_low(volatile uint8_t* port, uint16_t pin) {
  *(port) &= ~_BV(pin);
}

void inline io_toggle(volatile uint8_t* port, uint16_t pin) {
  *(port) ^= _BV(pin);
}

// PORTD = Port direction (e.g. DDRA)
// PIND  = Pin direction (e.g. DDD5)
void inline io_mode_output(volatile uint8_t* portd, uint16_t pind) {
  *(portd) |= _BV(pind);
}

void inline io_mode_input(volatile uint8_t* portd, uint16_t pind) {
  *(portd) &= ~_BV(pind);
}

#endif
