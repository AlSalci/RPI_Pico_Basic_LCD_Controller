#include <iostream>
#include "hardware/i2c.h"
#include "hardware/gpio.h"
#include "../include/LCD.hpp"
#include "pico/stdio.h"

std::vector<int> LCD::LCD_outputs = 
{
0, //RS
1, //RW
2, //E
3, //D7
4, //D6
5, //D5
6, //D4
};



int main()
{
    stdio_init_all();
    LCD lcd;
   lcd.LCD_print_string("Hello LCD");
   
   
   
    
    
    
    while(true)
    {
   

    
    }
    return 0;

}

