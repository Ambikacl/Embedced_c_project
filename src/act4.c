#include "act1.h"
#include "act4.h"

void InitUSART(uint16_t ubrr_value){
UBRR0L = ubrr_value;
UBRR0H=(ubrr_value>>8)&0x00ff;
UCSR0C=(1<<UCSZ00)|(1<<UCSZ01);
UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}

void USARTWriteChar(char data){
    while (!(UCSR0A & (1<<UDRE0)));
   UDR0=data;
}
void data_display(uint16_t temp)//display temperature value
{
            uint16_t i;
            if(temp<=200)
            {
                char temp_value[33] = "Temperature =20 deg Celsius\n";
                for(i=0;i<33;i++){USARTWriteChar(temp_value[i]);}
                _delay_ms(200);
            }
            else if(temp<=500 && temp>=210)
            {
                char temp_value[33] = "Temperature =25 deg Celsius\n";
                for(i=0;i<33;i++){USARTWriteChar(temp_value[i]);}
                _delay_ms(200);
            }
            else if(temp<=700 && temp>=510)
            {
                char temp_value[33] ="Temperature =29 deg Celsius\n";
                for(i=0;i<33;i++){USARTWriteChar(temp_value[i]);}
                _delay_ms(200);
            }
            else if(temp<=1024 && temp>=710)
            {
                char temp_value[33] = "Temperature =33 deg Celsius\n";
                for(i=0;i<33;i++){USARTWriteChar(temp_value[i]);}
                _delay_ms(200);
            }
}
