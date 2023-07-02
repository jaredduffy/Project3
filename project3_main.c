// Project 3 started code. Good luck!
#include <HAL/Button.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <stdio.h>

#include "HAL/LED.h"
#include "HAL/Timer.h"
#include "HAL/Graphics.h"

void initialize();
void main_loop(GFX *gfx_p);
void sleep();

int main(void)
{

    initialize();

    /* GFX struct. Works in the same as it did in the previous projects. */
    GFX gfx = GFX_construct(GRAPHICS_COLOR_WHITE, GRAPHICS_COLOR_BLACK);

    while (1) {
        sleep();

        main_loop(&gfx);
    }
}

void sleep() {
    // The Launchpad Green LED is used to signify the processor is in low-power mode.
    // From the human perspective, it should seem the processor is always asleep except for fractions of second here and there.

    TurnOn_LLG();
    // Enters the Low Power Mode 0 - the processor is asleep and only responds to interrupts
    PCM_gotoLPM0();
    TurnOff_LLG();

}
void main_loop(GFX *gfx_p) {
    // The first step is update the tapping status of all buttons
    buttons_t buttons = updateButtons();

    // This example code can be removed from your project
    // Tapping the Joystick push button (JSB) toggles the Launchpad LED1
    if (buttons.JSBtapped)
        Toggle_LL1();

    // TODO: You probably want to define a state variable and an enum associated with it
    // You can then control the state of your application based on the hardware inputs
    // Refer to the Guess-the-color example.

    }

// Initialization part is always device dependent and therefore does not change much with HAL
void initialize()
{

    // Stop watchdog timer
    WDT_A_hold(WDT_A_BASE);
    InitSystemTiming();

    initLEDs();
    initButtons();

    // TODO: Add other initializations here
}


