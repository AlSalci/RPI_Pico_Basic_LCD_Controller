#include "pico/stdio.h"
#include "hardware/gpio.h"
#include <iostream>
#include <vector>


class LCD 
{
    private:
    /**
    @ Initializes the LCD gpio pins
    @ arguments: none
    @ returns: void
    **/
    void GPIO_Initializtion();

    /**
    @ sets the gpio pins to send a nibble of data
    @ arguments: data(nibble to send)
    @ returns: void
    **/
    void set_nibble(uint8_t data);

    /**
    @ Sets the LCD to operate in 4-bit mode
    @ arguments: none
    @ returns: void
    **/
    void set_4_bit_mode();

     /**
    @ Sets the LCD to default settings
    @ arguments: none
    @ returns: void
    **/
    void default_settings();

     /**
    @ toggles enable pin to allow 4 bit data transfer
    @ arguments: none
    @ returns: void
    **/
    void toggle_enable_pin();



    public:

    LCD();// Constructor

    //Gpio Connections to the LCD 
    //@ connection map
    /*
    @ 0 = RS
    @ 1 = RW
    @ 2 = E
    @ 3-10 = D7-D0
    */
    static std::vector<int> LCD_outputs;    
    


     /**
    @ Sends a command or character to LCD in 4 bit mode
    @ arguments: data(Data to send), isChar(0=command, 1 = character)
    @ returns: void
    **/
    void LCD_Send_Command_or_Char(uint8_t data, bool isChar);

     /**
    @ Clears LCD
    @ arguments: none
    @ returns: void
    **/
    void LCD_clear();

     /**
    @ Returns home
    @ arguments: none
    @ returns: void
    **/
    void LCD_home();

      /**
    @ Prints string onto lcd
    @ arguments: word(word to print)
    @ returns: void
    **/
    void LCD_print_string(std::string word);

    
    


    

};
