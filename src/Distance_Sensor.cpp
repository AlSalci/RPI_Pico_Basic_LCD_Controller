#include "../include/Distance_Sensor.hpp"
#include "hardware/gpio.h"


  dis_sensor::dis_sensor()
 {
    //GPIO Initialization=====================
    gpio_init(Distance_Sensor_outputs[0]);
    gpio_init(Distance_Sensor_outputs[1]);
    //=========================================

    //Sets gpio directions==========================================
    gpio_set_dir(Distance_Sensor_outputs[0], GPIO_IN);
    gpio_set_dir(Distance_Sensor_outputs[1], GPIO_OUT);
    //=============================================================

    gpio_pull_down(Distance_Sensor_outputs[0]); //sets Echo to idle low

    //Sets a system interrupt to occur on both rising and falling edge of the Echo pin to measure distance
    gpio_set_irq_enabled_with_callback(Distance_Sensor_outputs[0], GPIO_IRQ_EDGE_FALL| GPIO_IRQ_EDGE_RISE, true, &callback); 

 }


void dis_sensor::callback(uint gpio,uint32_t event)
{
   
   
   if(event == GPIO_IRQ_EDGE_RISE)
   {
      
      temp_system_time = to_us_since_boot(get_absolute_time());
   }

   else  {
      distance = (to_us_since_boot(get_absolute_time())-temp_system_time)/52;
   }


}

void dis_sensor::tigger_sensor()
{
   gpio_put(Distance_Sensor_outputs[1],1);
   sleep_us(10);
   gpio_put(Distance_Sensor_outputs[1],0);
}