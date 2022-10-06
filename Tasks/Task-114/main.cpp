#include "mbed.h"

DigitalOut RedLED(PC_2, 1);
DigitalOut AmberLED(PC_3, 1);
DigitalOut GreenLED(PC_6, 1);



int counter;

// main() runs in its own thread in the OS
int main()
{

    wait_us(500000);
    AmberLED = 0;
    GreenLED = 0;

    while (true) 
    {
        counter = 0;
        RedLED = 1;
        wait_us(8000000);

        AmberLED = 1;
        wait_us(2000000);

        RedLED = 0;
        AmberLED = 0;

        GreenLED = 1;
        wait_us(10000000);
        
        GreenLED = 0;
        while(counter < 8)
        {
            
            counter = counter + 1;
            AmberLED = !AmberLED;
            wait_us(500000);

        }

    }
}

