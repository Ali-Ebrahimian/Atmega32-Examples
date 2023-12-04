/*
 * 4DigitCounter.c
 *
 * Created: 12/3/2023 10:45:52 AM
 * Author: aliebrahimian
 */

#include <mega32a.h> // jaye io.h
#include <delay.h>   // ketakhane baraye takhir

#define Digit PORTC

unsigned char disp[]={0XFC,0X60,0XDA,0XF2,0X66,0XB6,0XBE,0XE0,0XFE,0XF6};

#define digitShowTime 1
#define countOfDigits 4
#define Sec (1000 / digitShowTime /countOfDigits)

void display(unsigned int input)
{

    unsigned int
    yekan =  (((input % 1000) % 100) % 10),
    dahgan = ((input / 10) % 100)  % 10,
    sadgan = (input / 100) % 10,
    hezargan =  input / 1000;

    PORTC = disp[hezargan];
    PORTD = 0B11111110;
    delay_ms(digitShowTime);
    PORTD = 0b11111111;

    Digit = disp[sadgan];
    PORTD = 0B11111101;
    delay_ms(digitShowTime);
    PORTD = 0XFF;

    Digit = disp[dahgan];
    PORTD = 0B11111011;
    delay_ms(digitShowTime);
    PORTD = 0XFF;

    Digit = disp[yekan];
    PORTD = 0B11110111;
    delay_ms(digitShowTime);
    PORTD = 0XFF;

}
#define afzayesh 0
#define kahesh 1
void main(void)
{
    int i = 0,timer=0;
    unsigned char mode = kahesh;
    DDRC = 0XFF;
    DDRD = 0B00001111;
    PORTD = 0B00001111;
    i = 5000;
while (1)
    {
        if(mode == afzayesh)
        {
            i ++;
            if(i >= 9999)
            {
                mode = kahesh;
            }
        }
        else
        {
            i--;
            if(i <= 0)
            {
                mode = afzayesh;
            }
        }

        for(timer = 0;timer <= Sec;timer++)
        {
            display(i);
        }
    }
}

