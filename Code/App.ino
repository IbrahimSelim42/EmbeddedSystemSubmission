#include <avr/io.h>
#include <util/delay.h>
#include "IO.h"
#include "Uart.h"

int main(void) { //Mapping main program function.
    PullUp();
    SetBit();
    PinInitial();
    UartInit(); //From line 7 to 10 already commented in Header files.
    UartSendString("\nSystemReady\n"); //Sending a start up message (Optional could be deleted just to know the Arduino finished uploading).
    unsigned char LastButtonState = 1; //Storing last button state.
    while (1) {
        unsigned char CurrentButtonState = (PINB & (1 << 3)); //Setting current button state.
        if (LastButtonState && !CurrentButtonState) { //Detecting Button press.
            UartSendString("\nButtonPressed");
        }
        else if (!LastButtonState && CurrentButtonState) { //Detecting button release.
            UartSendString("\nButtonReleased");
        }

        LastButtonState = CurrentButtonState; //Updating button state

        if (UartIsDataAvailable()) { // Uart command processing

            unsigned char cmd = UartReadData(); // Read command

            if (cmd == '1') { //Serial monitor == 1
                PORTB |= (1 << 5);  //PB5 = 1
                UartSendString("\nLedOn");
            }
            else if (cmd == '0') { //Serial monitor == 0
                PORTB &= ~(1 << 5); // PB5 = 0
                UartSendString("\nLedOff");
            }
        }
        _delay_ms(50); //Delay for button Debounce.
    }
    return 0;
}