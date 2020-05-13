# Solder_UART

## Functions

* Adjustable temperature, from 100 - 500 ceils

* led indicator

## how to adjust temperature

Adjust temperature through UART.

PC send a number from 100 - 500 plue '\n' (ASCII 10, AKA LF) to the MCU. The MCU receive the number. If the number is out of range, the MCU send "Number out of range", else, the MCU send "Temperature change to %d, number".

## Design details

### platform

STSTM32: bluepill f103c8

### framework

Arduino

```cpp

void setup(){
    //setup MOSFET IO

    //setup serial

    //setup ADC IO

}

void loop(){
    //get ADC

    //determin to heat or not

    //check serial

    //determin to change temperature or not

}
```
