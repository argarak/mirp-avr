F_CPU=16000000UL
BOARD=atmega2560
FILE=mirp
BAUDRATE=115200
ACMPORT=/dev/ttyACM0
AVRDUDE_CONF=/etc/avrdude.conf
BUILD_DIR=build/

LD=avr-ld
CXX=avr-g++
CC=avr-gcc
CFLAGS=-fdata-sections -ffunction-sections -mmcu=$(BOARD) -pedantic -DF_CPU=16000000UL -Os -mcall-prologues

CXXSOURCES=$(shell find . -name "*.cpp")
CSOURCES=$(shell find . -name "*.c")
OBJECTS=$(SOURCES:.c=.o)
HEADERS=$(shell find . -name "*.h")

TARGET=mirp

all: $(TARGET) link hex

routine: clean $(TARGET) link hex upload

$(TARGET): $(HEADERS)
	$(CC) $(CFLAGS) -mmcu=$(BOARD) -c $(CSOURCES)
	$(CXX) $(CFLAGS) -mmcu=$(BOARD) -c $(CXXSOURCES) $(HEADERS)
	mv *.o build

link:
	$(CXX) $(CFLAGS) -Wl,--gc-sections -o "$(BUILD_DIR)$(TARGET).elf" $(BUILD_DIR)*.o

hex:
	avr-objcopy -j .text -j .data -O ihex $(BUILD_DIR)$(TARGET).elf $(TARGET).hex

upload:
	avrdude -v -p m2560 -C $(AVRDUDE_CONF) -c wiring -b $(BAUDRATE) -P $(ACMPORT) -D -U flash:w:./$(FILE).hex:i

clean:
	rm -f build/* *.hex $(shell find . -name "*.gch")
