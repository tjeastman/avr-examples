#include <avr/io.h>
#include <util/delay.h>

#define LED_ON_MS 1000
#define LED_OFF_MS 100

int main (void)
{
  // set the data direction register to make all pins on port B output pins
  DDRB = 0b11111111;

  while (1) {
    // set pins on port B to HIGH to turn the LED on
    PORTB = 0xFF;
    _delay_ms(LED_ON_MS);

    // set pins on port B to LOW to turn the LED off
    PORTB = 0x00;
    _delay_ms(LED_OFF_MS);
  }

  return(0);
}
