# PBLE02_firmware

In this project, the group takes a PCB from another group, and we are responsible for place all the components on the board, solder everything and fix possible errors. After all of it, we have to build a firmware to validate the correct operation of the board. Despite of participate in all steps of the project, I was especifically designated to make the **Validation Firmware**.

This firmware was developed in the MPLAB IDE, using MCC(MPLAB Code Configurator), to help manage the pins of the microcontroller and to generate some codes, such as: I2C and UART libraries. Also, the project was made with the support of teacher Rodrigo Maximiniano. 

## Requirements

1. Languages: user must be able to change between English and Portuguese;

2. Alarms: it must have 2 alarms. User must be able to change the low and high levels of each one;

3. Time: user must be able to change the time that lasts one main loop;

4. Memory: all the variables mentioned above, must be saved in an external memory chip. When the user reset the board for some reason, all variables must remain the same.

## Finit State Machine (FSM)

To match these requirements, it was made a MENU, so the user can select what parameter that he want to change. This menu is controlled by a Finit State Machine(FSM), as you can see below: 

![fsm](https://user-images.githubusercontent.com/130314603/235377411-003ca25a-0612-4dbf-a3c2-0f0da7dacf81.jpeg)

As you can see, the finit state machine has 8 states. The transition between states is controlled by the keyboard, using 3 keys: enter, right and left. 
