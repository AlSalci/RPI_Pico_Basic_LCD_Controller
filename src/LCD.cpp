#include "../include/LCD.hpp"
#include "hardware/gpio.h"
#include "pico/time.h"
#include <cstdint>



LCD::LCD()
{
    GPIO_Initializtion();
    set_4_bit_mode();
    
    default_settings();
    
}

void LCD::GPIO_Initializtion()
{
    for(int i = 0;i < LCD_outputs.size();i++)
    {
     gpio_init(LCD_outputs[i]);
     gpio_set_dir(LCD_outputs[i],GPIO_OUT); 

    }
}

void LCD::LCD_Send_Command_or_Char(uint8_t data, bool isChar)
{
    gpio_put(LCD_outputs[0],isChar); // Sets register to instruction register
    gpio_put(LCD_outputs[1],0); // Sets functionality to write
    
    set_nibble((data & 0xF0)>>4); 
    toggle_enable_pin();
    set_nibble(data & 0x0F);
    toggle_enable_pin();


}

void LCD::set_nibble(uint8_t data)
{
    uint8_t mask = 1;
    for(int i = LCD_outputs.size()-1; i >= 3; i --)
    {
        if((mask&data) != 0)
        {
            gpio_put(LCD_outputs[i],1); 

        }
        else  {
            gpio_put(LCD_outputs[i],0);
        }

    mask *= 2;
    }


}


void LCD::toggle_enable_pin()
{
    gpio_put(LCD_outputs[2],1);
    sleep_us(500);
    gpio_put(LCD_outputs[2],0);

}

void LCD::set_4_bit_mode()
{
    //Redunduntly sends command to assure 4 bit mode is set
    LCD_Send_Command_or_Char(0b00100000,0);
    LCD_Send_Command_or_Char(0b00100000,0);
    LCD_Send_Command_or_Char(0b00100000,0);
}


 void LCD::default_settings()
 {
    sleep_ms(200);
    LCD_Send_Command_or_Char(0b00001100,0);// Defualt cursor settings(No Blink)
    sleep_ms(200);
    LCD_Send_Command_or_Char(0b00101000,0);// Defualts to 2 lines
    
 }



 void LCD::LCD_clear()
 {
    LCD_Send_Command_or_Char(0b00000001,0);
 }

void LCD::LCD_home()
{
    LCD_Send_Command_or_Char(0b00000010,0);
}

void LCD::LCD_print_string(std::string word)
{
    for (int i = 0; i < word.length();i++)
    {
        LCD_Send_Command_or_Char(word[i],1);
    }
}

