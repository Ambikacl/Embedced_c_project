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
#include <avr/io.h>
#include <util/delay.h>
#include "act1.h"
#include "act2.h"
#include "act3.h"
#include "act4.h"

int main(void)
{
    Init_Ports();//Initialize ports for led blinking
    InitADC();//Initialize ADC ports
    uint16_t temp=0; //declare temp value to 0
    setup_PWM();//start PWM generation
    InitUSART(103);//Initialize ports for USART
    led_State(LED_OFF);

    while(1)
          {
              if(PersonSeated && HeaterOn)//checks whether button and Heater is ON or OFF
              {
                    led_State(LED_ON);//blinking of the led
                    _delay_ms(200);

                    temp= ReadADC(0);//reading the adjusted temp value
                    _delay_ms(200);

                    pwmout(temp);//pwm generation
                    data_display(temp);

              }
               else
                {
                    led_State(LED_OFF);
                    _delay_ms(200);
                     OCR1A = 0; //PWM wave 0
                }
          }

    return 0;
}
