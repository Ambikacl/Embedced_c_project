#include "files.h"

int main(void)
{

    // Insert code
     DDRB|=(1<<PB0); //set B0=1 for LED
     DDRD&=~(2<<PD0);//Clear bit
     DDRD&=~(4<<PD0);//Clear bit
     PORTD|=(2<<PD0);//set bit
     PORTD|=(4<<PD0);

       while(1)
    {
        if(!(PIND&(2<<PD0))&& !(PIND&(4<<PD0)))
        {
            PORTB|=(1<<PB0);
            _delay_ms(2000);
        }
        else
        {
            PORTB&=~(1<<PB0);
            _delay_ms(2000);
        }
    }


    return 0;
}
