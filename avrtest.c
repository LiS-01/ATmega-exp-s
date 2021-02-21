#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

unsigned char digits[] = {
//        PGFEDCBA	
	0b00111111, // 0
	0b00000110, // 1
	0b01011011, // 2
	0b01001111, // 3
	0b01100110, // 4
	0b01101101, // 5
	0b01111101, // 6
	0b00000111, // 7
	0b01111111, // 8
	0b01101111  // 9
};

unsigned char hello[] = {
//        PGFEDCBA
	0b11110110, // H
	0b11111001, // E
	0b10111000, // L
	0b10111000, // L
	0b10111111  // O
};



void main() {
	DDRA = 0xFF;
	int i = 0;
	int j = 5 +2;
	PORTA = digits[j];
	_delay_ms(5000);
	while (i<5) {
		PORTA = hello[i];
		_delay_ms(1000);
		i++;
	}
	while (1) {
		PORTA = digits[i++];
		if ( i > 9 ) {
			i = 0;
		}
		_delay_ms(1000);
	}
}
