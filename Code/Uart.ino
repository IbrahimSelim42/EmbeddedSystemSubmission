#if !defined(__AVR_ATmega328P__)
#include <avr/iom328p.h>
#endif
#include "uart.h"

void UartInit(void) {
    UartSetBaudRate(9600); //Here to set Uart BuadRate Register to 9600bps
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);  //Enable transmitter and receiver. Also in this case enabling either transmitter or receiver will enable the other.
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);  //Set frame format: 8 data bits, 1 stop bit
}
void UartSetBaudRate(unsigned short BuadRate){
    unsigned short UBBR = ( (F_CPU / 16) /  BuadRate ) - 1; //Mathmatical equation designated to calculate Uart BuadRate to the desired speed(16 bits).
    UBRR0L = (UBBR & 0xFF); //Here is to load the Upper and Lower total 16 bits of UBBR value into registers. This case is the lower 8 bits.
    UBRR0H = (( UBBR >> 8 ) & 0xFF); //Here is to load the upper 8 bits.
}
void UartSendChar(unsigned char DataByte) {
    while (!(UCSR0A & (1 << UDRE0))); //Wait until transmit buffer is empty.
    UDR0 = DataByte; //Load data into Uart to send it.
}
unsigned char UartIsDataAvailable(void) {
    return (UCSR0A & (1 << RXC0)); //Flag when unread data exists.
}
unsigned char UartReadData(void) {
    while (!(UCSR0A & (1 << RXC0))); //Wait until data is received and ready to be read.
    return UDR0; //Return received data.
}
void UartSendString(char DataString[]) {
    for (int i = 0; DataString[i] != '\0'; i++) { //Transmitting a string, character by a character until null terminator.
        UartSendChar(DataString[i]);
    }
}