#include <avr/io.h>
#include <util/delay.h>

uint8_t get_Input(void){
    return (PINB & _BV(PORTB1)) >> PORTB1;
}

int main(void){

    //Set to output
    DDRB |= _BV(DDB0);
    DDRD |= _BV(DDD7) | _BV(DDD6);
    DDRB &= ~_BV(PORTB1);

    while(1){
        //PORTB |= _BV(PORTB0);
        PORTB |=  get_Input() << PORTB0;
        _delay_ms(20);
        PORTB &= ~_BV(PORTB0);

        PORTD |=  get_Input() << PORTD7;
        _delay_ms(20);
        PORTD &= ~_BV(PORTD7);

        PORTD |=  get_Input() << PORTD6;
        _delay_ms(20);
        PORTD &= ~_BV(PORTD6);

    }
}