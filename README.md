Build and deploy the blink program:
```
avr-gcc -DF_CPU=16000000L -mmcu=atmega328p -Os -c main.c
avr-gcc -mmcu=atmega328p -o main.elf main.o
avr-objcopy -j .text -j .data -O ihex main.elf main.hex
avrdude -p m328p -c usbtiny -P usb -U flash:w:main.hex
```
