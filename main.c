/**
 * @file main.c
 * @author Ambika C L (259806);
 * @brief Activity_1
 * @version 0.1
 * @date 2021-04-24
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "act1.h"
#include "act2.h"

int main(void)
{
    Init_Ports();/* Initialize Ports */
	/* if and only if both button sensor switch and heater switch is on(pressed) LED turns ON */
	  uint16_t temp, i=0;
    InitADC();
    setup_PWM();
    led_State(LED_OFF);
    while(1){
        /*checks whether button and Heater is ON or OFF */
        if(PersonSeated && HeaterOn)
        {
            led_State(LED_ON);
            InitUSART(103);
            temp=ReadADC(0);
            if(temp<=200)
            {
                PWM_TempValue=51;
                char temp_value[33] = "Temperature value=20 deg Celsius";
                for(i=0;i<33;i++){USARTWriteChar(temp_value[i]);}
               _delay_ms(200);
            }
            else if(temp<=500 && temp>=210)
            {
                PWM_TempValue=102;
                char temp_value[33] = "Temperature value=25 deg Celsius";
                for(i=0;i<33;i++){USARTWriteChar(temp_value[i]);}
                _delay_ms(200);
            }
            else if(temp<=700 && temp>=510)
            {
                PWM_TempValue=179;
                char temp_value[33] ="Temperature value=29 deg Celsius";
                for(i=0;i<33;i++){USARTWriteChar(temp_value[i]);}
                _delay_ms(200);
            }
            else if(temp<=1024 && temp>=710)
            {
                PWM_TempValue=242;
                char temp_value[33] = "Temperature value=33 deg Celsius";
                for(i=0;i<33;i++){USARTWriteChar(temp_value[i]);}
                _delay_ms(200);
            }

        }
        else
        {
            led_State(LED_OFF);
            _delay_ms(200);
        }
}

    return 0;
}
