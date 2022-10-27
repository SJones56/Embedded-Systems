#include "uop_msb.h"
using namespace uop_msb;

BusIn buttons(PG_0, PG_1, PG_2, PG_3);

DigitalOut redLED(TRAF_RED1_PIN);       //Red Traffic 1
DigitalOut yellowLED(TRAF_YEL1_PIN);    //Yellow Traffic 1
DigitalOut greenLED(TRAF_GRN1_PIN);     //Green Traffic 1

//Dual Digit 7-segment Display
LatchedLED disp(LatchedLED::SEVEN_SEG);

int main(void)
{
    int count = 0;
    
    //Configure switches
    buttons[2].mode(PullDown);
    buttons[3].mode(PullDown);

    //Turn ON the 7-segment display
    disp.enable(true);

    //Update display
    disp = count;

    while (true) {
        
        //Read button without blocking
        int btn = buttons;     //Local to the while-loop  

        switch (btn) 
        
        {
            case 0:
            //Nothing pressed
            greenLED = 0;
            yellowLED = 0;
            redLED = 0;
            break;

            case 1:
            //Button A only
            redLED = !redLED;
            yellowLED = 0;            
            greenLED = 0;
            break;

            case 2:                         
            //Button B                
            redLED = 0;                     
            yellowLED = !yellowLED;            
            greenLED = 0;
            break;

            //case 3:                         //case (binary):
            //Button A and B                
            //redLED = 0;                     
            //yellowLED = !yellowLED;            
            //greenLED = 0;
            //break;

            case 4:                         //case (binary):
            //Button C                
            redLED = 0;                     
            yellowLED = 0;            
            greenLED = !greenLED;
            break;

            case 5:
            case 15:    
            //happens for both case 5 and 15              
            redLED = !redLED;                     
            yellowLED = !yellowLED;            
            greenLED = !greenLED;;
            break;



            default:
            //All others
            redLED = !redLED;                     
            yellowLED = !yellowLED;            
            greenLED = !greenLED;
            break;

        }
       
        // Slow it down a bit (and debounce the switches)
        wait_us(100000); 

   
    }
}



