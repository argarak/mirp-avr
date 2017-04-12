F_CPU=16000000UL
BOARD=atmega328p
FILE=mirp
BAUDRATE=115200
ACMPORT=/dev/ttyACM0
AVRDUDE_CONF=/etc/avrdude.conf
BUILD_DIR=build/

LD=avr-ld
CC=avr-gcc
CFLAGS=-ggdb -mmcu=$(BOARD) -pedantic -DF_CPU=16000000UL -Os -mcall-prologues

SOURCES=$(shell find . -name "*.cpp" -o -name "*.c")
OBJECTS=$(SOURCES:.c=.o)
HEADERS=$(shell find . -name "*.h")

TARGET=mirp

all: $(TARGET) link hex

routine: clean $(TARGET) link hex upload

$(TARGET): $(SOURCES) $(HEADERS)
	avr-g++ $(CFLAGS) -mmcu=$(BOARD) -c $^
	mv *.o build

link:
	avr-g++ $(CFLAGS) -o "$(BUILD_DIR)$(TARGET).elf" $(BUILD_DIR)*.o

hex:
	avr-objcopy -j .text -j .data -O ihex $(BUILD_DIR)$(TARGET).elf $(TARGET).hex

upload:
	avrdude -v -p $(BOARD) -C $(AVRDUDE_CONF) -c arduino -b $(BAUDRATE) -P $(ACMPORT) -D -U flash:w:./$(FILE).hex:i

clean:
	rm -f build/* *.hex $(shell find . -name "*.gch")
