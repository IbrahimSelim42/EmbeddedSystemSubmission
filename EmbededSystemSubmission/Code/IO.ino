#include <avr/io.h>
#include "IO.h"

void PinInitial(void) {
    PORTB &= ~(1 << 5); //PB5 is 0 led of initially.
}
 void SetBit(void) {
    DDRB |= (1 << 5); //Set PB5 as Output(LED)
    DDRB &= ~(1 << 3); //Set PB3 as Input(Button)
 }
void PullUp (void){
    PORTB |= (1 << 3); //Set PB3 High to activate PullUp Resistor.
}
