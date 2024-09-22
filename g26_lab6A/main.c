#include <stdint.h>
#include "tm4c123gh6pm.h"

volatile uint32_t dutyCycle = 50;  // Initial duty cycle= 50%
volatile uint32_t count = 160;    // Count Value using 16MHz clock freq

void init(void);               //  declaration of init function
void Systick_Init(void);       // declaration  of Systick_Init function
void Int_Handler(void);      // declaration of int handlar Function
void Systick_Handler(void);   // declaration of Systick_handler function
int main(void) {
    init();   // Initializing  GPIO for  LED and switches
    Systick_Init(); // Initialize SysTick timer for software PWM

    while (1) {
        // Main loop does nothing, PWM and duty cycle control is handled by interrupts
    }
}
