#include <avr/io.h>
#include <util/setbaud.h>
#include <util/delay.h>

void uart_init(void) {
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

#if USE_2X
    UCSR0A |= _BV(U2X0);
#else
    UCSR0A &= ~(_BV(U2X0));
#endif

    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); // 8-bit data
    UCSR0B = _BV(RXEN0) | _BV(TXEN0); // enable RX and TX
}

void uart_putchar(char c) {
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = c;
}

int main(void) {
  uart_init();

  while (1) {
    uart_putchar('H');
    uart_putchar('e');
    uart_putchar('l');
    uart_putchar('l');
    uart_putchar('o');
    uart_putchar(',');
    uart_putchar(' ');
    uart_putchar('W');
    uart_putchar('o');
    uart_putchar('r');
    uart_putchar('l');
    uart_putchar('d');
    uart_putchar('!');
    uart_putchar('\r');
    uart_putchar('\n');
    _delay_ms(1000);
  }

  return 0;
}
