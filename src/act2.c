/**
 * @file act2.c
 * @author Ambika C L(259806)
 * @brief
 * @version 0.1
 * @date 2021-04-28
 *
 * @copyright Copyright (c) 2021
 *
 */
#include<avr/io.h>
#include "act1.h"
#include "act2.h"

#define CONV_INCOMPLETE  ADCSRA & (1<<ADIF)

void InitADC()
{
    ADMUX|=(1<<REFS0);// Select Vref=AVcc
    ADCSRA=(1<<ADEN)|(7<<ADPS0);//set pre-scaller to 128 and enable ADC
}

uint16_t ReadADC(uint8_t ch)
{
    ADMUX &= 0xF8;
    //single conversion mode
    ch &= 0x07;
    ADMUX |= ch;
    ADCSRA |= (1<<ADSC);
    // wait until ADC conversion is complete
    while(!(CONV_INCOMPLETE));
    ADCSRA|=(1<<ADIF);
    return(ADC);
}

