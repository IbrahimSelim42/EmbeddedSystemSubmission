| **Author**              | `Ibrahim Selim Abomosalam`                                       |
|:------------------------|:-----------------------------------------------------|
| **Status**              | `Draft/Inspection/Approved`                          |
| **Version**             | `1.0`                                                |
| **Date**                | `dd/mm/yyyy`                                         |

## 1.Introduction
This document discusses the detailed design of the UART-based button and LED control system, which simulate a form of the embedded data acquisition and communication platform. The system operates on an ATmega328P microcontroller and uses UART communication interface to transmit, receive and control signals. This document further explains software and hardware architecture, functional behavior, and integration details of the UART module.

### 1.1 Purpose
The purpose of this document is to describe how the UART module enables serial communication between the microcontroller and an external component, allowing real-time data transmission and data reception. Moreover, it ensures that the design can be easily implemented and integrated with system components.
### 1.2 Scope
This design covers UART communication module and its interaction with inputs and outputs interfaces of the embedded system. The system is capable to detect button press and release events, sending corresponding status messages over UART and receiving UART commands to control the LED state.

## 2.Architectural Overview
The UART-based button and LED control module provides a communication interface between the microcontroller and external devices such as a computer or monitoring system via serial transmission. Also, the module interacts with the digital input and output to read the button state and control the LED output.
### 2.1 Assumptions and constraints 
On the one hand, the system operates on an ATmega328P microcontroller running at a clock frequency of 16 MHz. UART communication is configured at a baud rate of 9600bps using 8 data bits and 1 stop bit. On the other hand, only one button input and one LED output are supported in the current implementation and the communication timing is limited by the selected baud rate.

## 3.Functional Description
The UART-based module enables two-way communication between microcontroller and an external device performing three main functions input monitoring, serial communication and output control. Firstly, the system monitors the push button connected to pin PB3, when an event is detected, a corresponding message is transmitted over the UART. Moreover, the UART transmits, ’ButtonPressed’’ when button pressed and ‘’button released’’ once button released, nevertheless, the system listens for incoming UART data receiving one and zero. Finally, once receiving data the system controls output by either turning the LED on or off, according to the recipient data.

## 4.Implementaion of the Module
To begin with, the implementation phase is divided into three core elements, Uart.ino Uart.h, IO.ino IO.h, App.ino. Firstly, Uart.ino and Uart.h this module provides low-level UART communication functionality for instance, UartInit(void) initializes UART register, in other words, this section handles all serial communication between microcontroller and the external system. Secondly, IO.ino and IO,h these elements are the core configurations of the system inputs and outputs, which allowing the main application to operate independently of direct register manipulation. Finally, App.ino, which also could be called the mapping of the main system that detects button press and release, moreover, it send corresponding UART messages, as it process UART commands for LED control.

## 5.Integration and Configuration
### 5.1 Static Files
| File name | Contents                             |
|-----------|--------------------------------------|
| Uart.ino  | Initializing serial communications   |
| Uart.h    | Header file (functions)              |
| IO.ino    | configuring inputs and outputs       |
| IO.h      | Header file (functions)              |
| App.ino   | Integrating the IO and Uart module   |


