#include "pico/stdio.h"
#include "hardware/gpio.h"
#include <iostream>
#include <vector>
#include "pico/time.h"


class dis_sensor 
{
private:


     /**
    @ callback function to allow distance to be measured by the sensor
    @ arguments: gpio(pin that caused inturrput), event(event that cause inturrupt)
    @ returns: void
    **/
    static void callback(uint gpio,uint32_t event);


    static int temp_system_time; // stores the time that the first inturrupt occurs on the echo pin


public:
dis_sensor();

/*
@ Output Map
@ 0 : Echo
@ 1 : Trig
*/
static std::vector<int> Distance_Sensor_outputs;

void tigger_sensor();

static int distance;


};