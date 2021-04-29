/**
 * @file act1.c
 * @author Ambika C L (259806)
 * @brief states of LED
 * @version 0.1
 * @date 2021-04-28
 *
 * @copyright Copyright (c) 2021
 *
 */
// include files
#include "act1.h"
#include "act2.h"
#include "act3.h"
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


