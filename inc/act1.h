#ifndef ACT1_H_INCLUDED
#define ACT1_H_INCLUDED

/**
 * @file act1.h
 * @author Ambika C L(259806)
 * @brief Activity_1
 * @version 0.1
 * @date 2021-04-24
 *
 * @copyright Copyright (c) 2021
 *
 */


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

/**
 * Macro Definitions
 */

#define LED_ON 	(0x01)			/**< LED state HIGH */
#define LED_OFF	(0x00)			/**< LED state LOW */
#define LED_PORT (PORTB)    /**< LED Port Number */
#define LED_PIN  (PORTB0)   /**< LED Pin number  */
#define BUTTON_PORT  (PORTD) /**< BUTTON Port number  */
#define HEATER_PORT  (PORTD) /**< HEATER Port number  */
#define BUTTON_PIN  (PORTD1) /**< BUTTON Pin number  */
#define HEATER_PIN  (PORTD2) /**< HEATER Pin number  */
#define PersonSeated !(PIND&(2<<PD0)) /**< Switch-1 pressed**/
#define HeaterOn !(PIND&(4<<PD0))/**< Switch-2 pressed**/
#define SET_PORTB0  DDRB |= (1<<PORTB0) /** Port B0 as output */
#define SET_PD1_AND_PD2  PORTD |= (2<<PD0)|(4<<PD0) /** PD1 and PD2 as pull-up */
#define SET_PORTD  DDRD = 0x00 /** PortD as input */
#define PWM_TempValue OCR1A
/**
 * @brief Function to change LED status
 *
 * @param[in] ON or OFF state
 *
 */
void led_State(uint8_t state);

/**
 * @brief Function to initialize peripherals
 *
 */
void Init_Ports(void);

/**
 * @brief Function to set pin of Button
 *
 *
 */
void Button_On(void);

/**
 * @brief Function to set pin of HeaterSensor
 *
 *
 */
void Heater_On(void);



/**
 * @brief Function to change LED status according to requirement in activity1
 *
 */
void Led_Status(void);

#endif // ACT1_H_INCLUDED
