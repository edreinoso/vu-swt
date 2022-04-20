#include "mbed.h"
#include "board_freedom.h"
#include "adc.h"
#include <cstdio>
 
// main() runs in its own thread in the OS
int main()
{
    float voltage;
    int temp; // had to force change to int as float wont print
    board_init();
    PwmOut heater_power(PTA7); // this corresponds to PWM3
    heater_power = 1;
    
    while (true) {
        // Read the 0th analog in (library docs has more info)
        uint16_t analog_in_value = adc_read(0);
 
        // Convert 16 bit value to voltage and temperature.
        voltage = analog_in_value * 3 / 65535.0 ;
        temp = (int)((voltage * 1000 - 400) / 19.5);
 
        printf("Temperature is  %d \n\t", temp);        
        ThisThread::sleep_for(1000ms);
    }
}