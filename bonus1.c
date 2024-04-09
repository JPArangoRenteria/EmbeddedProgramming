#include <stdint.h>
#include "msp.h"
#include "../inc/bsp.h"
#include "../inc/CortexM.h"

uint16_t posx,posy = 0;
uint8_t selector = 1;

void init()
{
	BSP_Joystick_Init();
	BSP_Buzzer_Init((uint16_t) 0);
}
void TimerISR()
{
}