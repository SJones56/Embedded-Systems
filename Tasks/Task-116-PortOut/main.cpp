#include "mbed.h"

PortOut lights(PortC, 0b0000000001001100);

int main()
{
    //All OFF
    lights = 0;

    while (true)
    {
        lights = 0b000000000000100; //red - PC_2
        wait_us(1000000);
        lights = 0b0000000000001000; //yellow - PC_3
        wait_us(1000000);
        lights = 0b0000000001000000; //green - PC_6
        wait_us(1000000);

        lights = 0b000000000001100; //red+yellow - PC_2+PC_3
        wait_us(1000000);
        lights = 0b0000000001001000; //yellow+green - PC_3+PC_6
        wait_us(1000000);
        lights = 0b0000000001000100; //green+red - PC_6+PC_2
        wait_us(1000000);      

    }
}