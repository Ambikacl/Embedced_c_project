#ifndef ACT4_H_INCLUDED
#define ACT4_H_INCLUDED

/**
 * @file act4.h
 * @author Ambika C L(259806)
 * @brief Activity_1
 * @version 0.1
 * @date 2021-04-24
 *
 * @copyright Copyright (c) 2021
 *
 */

void InitUSART(uint16_t);
char USARTReadChar();
void USARTWriteChar(char);
/** \brief to send the USART the modified temperature value and dispkay it on the serial monitor
 *
 * \param temp_value
 */
void data_display(uint16_t);


#endif // ACT4_H_INCLUDED
