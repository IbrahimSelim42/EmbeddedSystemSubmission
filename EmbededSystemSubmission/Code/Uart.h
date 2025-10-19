#ifndef __UART__
#define __UART__
//Header file designed to mention the function and then be recalled throghout other files.
void UartInit(void); //Function to intialize Serial Communication.
void UartSetBaudRate(unsigned short BuadRate); //Here is to set the Buadrate register to the desired speed.
void UartSendChar(unsigned char DataByte); //Flag function to check if recived data avaliable in Uart buffer.
unsigned char UartIsDataAvailable(void); //Flag function to check if recived data avaliable in Uart buffer.
unsigned char UartReadData(); //Function to read received data.
void UartSendString(char DataString[]); //Transmitting a string over Uart.
#endif