#include "act1.h"
#include "act3.h"
void setup_PWM(void){
    TCCR1A=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);//Timer_1
    TCCR1B=(1<<WGM12)|(1<<CS11)|(1<<CS10);//64 prescale
    DDRB|=(1<<PB1);
}
void pwmout(uint16_t temp)//temperature values
{
            if(temp<=200)
            {
                PWM_TempValue=51;
            }
            else if(temp<=500 && temp>=210)
            {
                PWM_TempValue=102;
            }
            else if(temp<=700 && temp>=510)
            {
                PWM_TempValue=179;
            }
            else if(temp<=1024 && temp>=710)
            {
                PWM_TempValue=242;
            }
            else
            {
                PWM_TempValue=0;
            }
}


