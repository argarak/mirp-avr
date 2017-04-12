# mirp-avr

*This repository is a sub-set of the [mirpm](https://github.com/mirpm/mirpm) project. Please see the main [mirpm](https://github.com/mirpm/mirpm) page for more information about this project including how to set it up for your system. The information below is intended for developers and/or maintainers.*

This is the software that provides support for serial connection, esp8266 support (WIP) and support for modules for the AVR platform. It is written in AVR Libc to be most efficient and take up the least space on a microcontroller's ROM.

## Compiling

*This section only covers manual compilation with the avr-toolchain. Clients will compile and upload this firmware automatically (not yet implemented).*

```
git clone https://github.com/mirpm/mirp-avr.git
cd mirp-avr
make routine
```

At the moment, it is necessary to specify the microcontroller's port on the system since no auto-detect method has been implemented yet. Therefore if `avrdude` cannot find the microcontroller (default under `/dev/ttyACM0`), modify the Makefile and change the `ACMPORT` variable to the path of the microcontroller (usually under `/dev/`).
