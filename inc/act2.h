#ifndef ACT2_H_INCLUDED
#define ACT2_H_INCLUDED
#define F_CPU 16000000UL 	/**< Clock Frequency of MCU is 16 MHz */

#define PersonSeated !(PIND&(2<<PD0)) /**< Switch-1 pressed**/
#define HeaterOn !(PIND&(4<<PD0))/**< Switch-2 pressed**/
#define LED_ON PORTB|=(1<<PB0)		/**< LED state HIGH */
#define LED_OFF PORTB&=~(1<<PB0)			/**< LED state LOW */
/**
 * @file act2.h
 * @author Ambika C L (259806)
 * @brief ADC function definition
 * @version 0.1
 * @date 2021-04-28
 *
 * @copyright Copyright (c) 2021
 *
 */


/**
 * @brief Function to initialize ADC registers
 *
 */
uint16_t ReadADC(uint8_t ch);
/**
 * @brief  Function to select particular MUX Channel
 *
 * @param channel
 * @return uint16_t
 */

void InitADC();
#endif // ACT2_H_INCLUDED
