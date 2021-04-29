// include files
#include "act1.h"
#include "act2.h"
#include "act3.h"
#include "act4.h"
/**
 * @brief Change the state of the LED Pin according to the value of state
 *
 * @param state Pin level to which the LED Pin should be set
 */

void led_State(uint8_t state)
{
	LED_PORT = (state << LED_PIN);
}

void Button_On(void)
{
	BUTTON_PORT |= (1 << BUTTON_PIN);
}

void Heater_On(void)
{
	HEATER_PORT |= (1 << HEATER_PIN);
}

void Init_Ports(void)
{
	/* Configure LED Pin */
	SET_PORTB0;
        SET_PORTD;
	SET_PD1_AND_PD2; //for input
        Button_On();
        Heater_On();
}

void Led_Status(void)
{
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
                char temp_value[33] = "Temperature = 20 deg Celsius\n";
                for(i=0;i<33;i++){USARTWriteChar(temp_value[i]);}
               _delay_ms(200);
            }
            else if(temp<=500 && temp>=210)
            {
                PWM_TempValue=102;
                char temp_value[33] = "Temperature = 25 deg Celsius\n";
                for(i=0;i<33;i++){USARTWriteChar(temp_value[i]);}
                _delay_ms(200);
            }
            else if(temp<=700 && temp>=510)
            {
                PWM_TempValue=179;
                char temp_value[33] ="Temperature = 29 deg Celsius\n";
                for(i=0;i<33;i++){USARTWriteChar(temp_value[i]);}
                _delay_ms(200);
            }
            else if(temp<=1024 && temp>=710)
            {
                PWM_TempValue=242;
                char temp_value[33] = "Temperature = 33 deg Celsius\n";
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
}
