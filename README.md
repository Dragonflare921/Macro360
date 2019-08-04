Macro360
========

## Overview

Macro360 is a prototype/proof of concept sketch written in the Arduino IDE for the Atmega328p microcontroller on the Arduino Uno which provides input replay "macro" functionality for Xbox 360 controllers intended to aid speedrun segmenting, glitch hunting, and research for Halo titles.  

There is a set of 6 tactile switches used as inputs by the Atmega328p which are "bound" to performing input macros on the fly. Input commands can also be manually sent over serial at 9600 baud.

This v1.0 is very simplistic and only supports the following inputs:
```
BUTTONS:
    A
    B
    X
    Y
    LEFT BUMPER
    RIGHT BUMPER
    DPAD UP
    DPAD DOWN
    DPAD LEFT
    DPAD RIGHT

TRIGGERS (DIGITAL ON/OFF ONLY):
    LEFT TRIGGER
    RIGHT TRIGGER
```

## Notes

There is no support for the start, back, or guide buttons, nor the analog joysticks, their respective tactile switches, or analog input to the left and right triggers.  

All outputs must be manually connected to the controller PCB at their respective contacts, there is no man-in-the-middle or digital signal generation in this PoC. As such, the delay between inputs is merely a product of frame time and guesswork as game engines (and the console) typically only poll the controller state via XInputGetState once per frame.  

3rd party controllers (such as the afterglow) are more likely to have exposed test points which are easier to solder the outputs to as opposed to 1st party official Xbox 360 gamepads.  

The supported buttons can be triggered in sequence to perform various input "combos", used primarily for performing "sword tricks" such as sword cancelling and sword flying in Halo 2. A description of these tricks is not relevant to this repository but can be found easily elsewhere.