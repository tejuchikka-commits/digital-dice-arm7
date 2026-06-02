# Digital Dice using ARM7

## Project Overview

The **Digital Dice using ARM7** is an embedded system mini project developed using the **ARM7 LPC2129 microcontroller**. This project simulates the working of a traditional dice electronically. When a switch is pressed, the microcontroller generates a dice value from **1 to 6** and displays the result using an output device such as LEDs, LCD, or a 7-segment display.

This project is useful for understanding **Embedded C programming**, **GPIO configuration**, **external interrupts**, and basic real-time input/output handling in ARM7 microcontroller-based systems.

---

## Objective

The main objective of this project is to design and implement a digital dice system using the ARM7 LPC2129 microcontroller. The system should detect user input through a switch or interrupt and display a dice value between 1 and 6.

---

## Technologies Used

- ARM7 LPC2129 Microcontroller
- Embedded C
- Keil µVision IDE
- GPIO Programming
- External Interrupts
- LCD / 7-Segment Display Interfacing
- Embedded System Design

---

## Components Used

- ARM7 LPC2129 Development Board
- Push Button / Switch
- LCD Display or 7-Segment Display
- LEDs, if used
- Connecting Wires
- Power Supply
- Keil µVision Software

---

## Features

- Generates dice values from 1 to 6
- Uses switch input or external interrupt
- Displays the dice value electronically
- Demonstrates GPIO input/output operations
- Helps understand interrupt handling in ARM7
- Simple and beginner-friendly embedded system project

---

## Working Principle

The Digital Dice system waits for a switch press or external interrupt. When the switch is pressed, the ARM7 LPC2129 microcontroller detects the input and generates a dice value between 1 and 6.

The generated value is displayed through an output device such as an LCD, LEDs, or a 7-segment display. After displaying the value, the system waits for the next switch press and repeats the process.

The switch acts as the input device, the ARM7 microcontroller acts as the processing unit, and the display device acts as the output unit.

---

## Block Diagram

```text
+-------------------+        +-----------------------+        +----------------------+
| Push Button /     | -----> | ARM7 LPC2129          | -----> | LCD / 7-Segment      |
| External Interrupt|        | Microcontroller       |        | Display              |
+-------------------+        +-----------------------+        +----------------------+
                                      |
                                      |
                              +---------------+
                              | Power Supply  |
                              +---------------+
