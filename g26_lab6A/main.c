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
void init(void) {
    SYSCTL_RCGCGPIO_R |= 0x020;
                       GPIO_PORTF_LOCK_R = 0x4C4F434B;
                       GPIO_PORTF_CR_R |= 0x10;          // Allow changes to PORTF4

                           // Configure PF1 as output (LED)
                           GPIO_PORTF_DIR_R = 0x02;
                           GPIO_PORTF_DEN_R = 0x13;

                           GPIO_PORTF_PUR_R = 0x11;


                       GPIO_PORTF_IS_R = 0x00;   //  edge-sensitive
                          GPIO_PORTF_IBE_R = 0x00;  // Interrupt controlled by IEV
                          GPIO_PORTF_IEV_R = 0x00;  // falling edge trigger
                          GPIO_PORTF_ICR_R = 0x11;   // removing prior interrupt
                          GPIO_PORTF_IM_R = 0x11;    // Unmask interrupt for PORTF4

                          NVIC_EN0_R = 0x40000000;
}
