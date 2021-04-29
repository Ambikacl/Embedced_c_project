#ifndef ACT2_H_INCLUDED
#define ACT2_H_INCLUDED

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
