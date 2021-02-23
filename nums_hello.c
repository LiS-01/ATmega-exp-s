#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>

typedef struct {
	char symbol;
	uint8_t code;
} Symbol;

const Symbol symbolDict[] ={
//              PGFEDCBA
	{'P', 0b00110111 },
	{'R', 0b01110111 },
	{'I', 0b00000110 },
	{'V', 0b01111111 },
	{'E', 0b01111001 },
	{'T', 0b01111000 }
};

void my_putc(char ch){
	int i=0;
	for (i=0; i<sizeof(symbolDict); i++){
		if (ch==symbolDict[i].symbol){
			PORTA = symbolDict[i].code;
			break;
		}
		else
			PORTA = 0b00111111;
	}
};

void main() {
	DDRA = 0XFF;
	
//	char ch = "h";	
	 my_putc('P');

}
