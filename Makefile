CC = avr-gcc
OBJCOPY = avr-objcopy
F_CPU = 16000000L
CFLAGS = -DF_CPU=$(F_CPU) -mmcu=atmega328p -Os -c

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

%.elf: %.o
	$(CC) -mmcu=atmega328p -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

all: main.hex

flash: main.hex
	avrdude -p m328p -c usbtiny -P usb -U flash:w:main.hex

clean:
	rm main.hex main.elf main.o
