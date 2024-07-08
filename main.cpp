#include "mbed.h"

/*
    This program prints to screen the number of times the blue button on the board is pressed and released.

    The button is mapped to PC_13
    The while loop is an infinate loop as it is always true

    The count increments with each press and release

*/

InterruptIn blue_btn(PC_13);
volatile int trig = 0;

void btnFall(){
    trig = 1;
}

void btnRise(){
    trig = 2;
}

int main()
{ 
    int numPressed = 0;
    int numReleased = 0;
    blue_btn.fall(&btnFall);
    blue_btn.rise(&btnRise);
    printf("Total times button pressed is %i times\r\n", numPressed);
    while(true){        
        if(trig == 1){
            trig = 0;
            numPressed++;
            printf("Button pressed %i times\r\n", numPressed);
        } else if (trig == 2) {
            trig = 0;
            numReleased++;
            printf("Button released %i times\r\n", numReleased);
        }
    }

    return 0;
}
