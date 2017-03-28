cmake_minimum_required(VERSION 2.6)
project(mirp-avr C CXX)

set(BOARD              atmega328p                                          )
set(OUTPUT_EXECUTABLE  mirp                                                )
set(BAUDRATE           115200                                              )
set(ACMPORT            /dev/ttyACM0                                       )
set(CPUFREQ            16000000UL                                          )

set(CC                 avr-gcc                                             )
set(CXX                avr-g++                                             )
set(LD                 avr-ld                                              )
set(OBJCOPY            avr-objcopy                                         )
set(AVRDUDE            avrdude                                             )

set(CFLAGS             "-ggdb -mmcu=$(BOARD) -pedantic -DF_CPU=$(CPUFREQ)")

set(BUILD_DIR          build/                                              )
set(LIB_DIR            lib/                                                )
set(SRC_DIR            src/                                                )

file(GLOB SOURCES "$(SRC_DIR)/**/*.cpp" "$(SRC_DIR)/**/*.c")

include_directories(includes)
add_executable(mirp-avr ${SOURCES})
set_target_properties($(OUTPUT_EXECUTABLE) PROPERTIES OUTPUT_NAME "$(OUTPUT_EXECUTABLE).elf")

add_custom_target()


