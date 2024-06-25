#include <LPC21XX.H>

char switchStatus;

int main(void)
{
    PINSEL0 = 0x00000000; // Configure pins as GPIO
    IO0DIR &= ~0x00000001; // Configure P0.0 as input (switch)
    IO0DIR |= 0x00000002; // Configure P0.1 as output (LED)

    while(1)
    {
        switchStatus = (IOPIN0 & 0x01); // Read the state of the switch (P0.0)
        
        if (switchStatus == 0x01) // Check if the switch is pressed
            IO0SET = 0x00000002; // Turn on the LED (P0.1)
        else
            IO0CLR = 0x00000002; // Turn off the LED (P0.1)
    }
}
