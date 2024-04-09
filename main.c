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
int main()
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;
	init();
	while(1){
		BSP_Joystick_Input(&posx, &posy, &selector);
			if ((posx > 341) && (posx <=682)){
				if (posy <= 341){
					//Suqare 2
					TA0CCR0 = (3000000 / 988) -1; // check clock
					BSP_Buzzer_Set(0.5*1024); // check frequency
				};
				if ((posy > 341) && (posy <= 682)){
					//Square 0
					TA0CCR0 = (3000000 / 880) -1;
					BSP_Buzzer_Set(0.5*0);//check frequency
				};
				if ((posy > 682) && (posy <= 1023)){
					//Square 7
					TA0CCR0 = (3000000 / 1661) -1;
					BSP_Buzzer_Set(0.5*1024);
					
				};
			};
			if (posx<= 341){
				if (posy <= 341){
					//Square 6
					TA0CCR0 = (3000000 / 1480) -1;
					BSP_Buzzer_Set(0.5*1024);
				};
				if ((posy > 341) && (posy <= 682)){
					//Square 4
					TA0CCR0 = (3000000 / 1175) -1;
					BSP_Buzzer_Set(0.5*1024);
				};
				if ((posy > 682) && (posy <= 1023)){
					//Square 1
					TA0CCR0 = (3000000 / 880) -1;
					BSP_Buzzer_Set(0.5*1024);
				};
			};
			if (posx > 682){
				if (posy <= 341){
					//Square 3
					TA0CCR0 = (3000000 / 1109) -1;
					BSP_Buzzer_Set(0.5*1024);
				};
				if ((posy > 341) && (posy <= 682)){
					//Square 5
					TA0CCR0 = (3000000 / 1319) -1;
					BSP_Buzzer_Set(0.5*1024);
				};
				if ((posy > 682) && (posy <= 1023)){
					//Square 8
					TA0CCR0 = (3000000 / 1760) -1;
					BSP_Buzzer_Set(0.5*1024);
				};
			};
	}
}