#include <avr/io.h>
#include <util/delay.h>

int main(void){

    //Set to output
    DDRB |= _BV(DDB0);
    DDRB &= ~_BV(PORTB1);

    while(1){
        //PORTB |= _BV(PORTB0);

        uint8_t Input = (PINB & _BV(PORTB1)) >> PORTB1;
        PORTB |=  Input << PORTB0;


        _delay_ms(20);
        PORTB &= ~_BV(PORTB0);
        _delay_ms(20);
    }
}