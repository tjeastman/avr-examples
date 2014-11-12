CC = avr-gcc

all: main.hex

main.hex: main.elf
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex

main.elf: main.o
	$(CC) -mmcu=atmega328p -o main.elf main.o

main.o: main.c
	$(CC) -DF_CPU=16000000L -mmcu=atmega328p -Os -c main.c

flash: main.hex
	avrdude -p m328p -c usbtiny -P usb -U flash:w:main.hex

clean:
	rm main.hex main.elf main.o
