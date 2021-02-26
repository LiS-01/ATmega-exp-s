;
; AssemblerApplication1.asm
;
; Created: 2/26/2021 4:24:29 PM
; Author : Admin
;


.include "m16def.inc"
 
.org 0x0000
   rjmp start

start:
    ldi r16, 0           
    out SREG, r16        
    ldi r16, low(RAMEND)
    out SPL, r16
    ldi r16, high(RAMEND)
    out SPH, r16
 
    sbi DDRB, DDB0       
_loop:
    sbi PORTB, PORTB0    
    rcall _delay
    cbi PORTB, PORTB0    
    rcall _delay
    rjmp _loop
 
_delay:
    ldi r24, 0x00        
    ldi r23, 0xd4 
    ldi r22, 0x30 
_d1:                     
    subi r24, 1   
    sbci r23, 0   
    sbci r22, 0
    brcc _d1
    ret