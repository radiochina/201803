#include "comm.h"
/////////////////////////////////
/////////////////////////////////
unsigned int T_of_WPM[]={
        0,
        0,  0,   0,  0,  0,  0,  0,  0,  0, 120,
        0,  100, 0,  0,  80, 75, 0,  67, 0, 60,
        0,  55,  0,  50, 48, 0,  44, 0,  0, 40,
        0,  38,  0,  0,  34, 0,  32, 0,  0, 30
};

extern void BEEP_ON(int f);
extern void  BEEP_OFF();
extern unsigned char wpm_of_CW;
void Delay(unsigned char i)
{
        usleep(i*1000);        //delay i*1000 ms
}

void Delay_T_time(unsigned char x)
{
        while(x)
        {
                Delay (T_of_WPM[wpm_of_CW]);
                x--;
        }
}

void space()
{
        BEEP_OFF();
        Delay_T_time(7);
}
void dot(int f)
{
        BEEP_ON(f);
        Delay_T_time(1);
        BEEP_OFF();
        Delay_T_time(1);
}
void dash(int f)
{
        BEEP_ON(f);
        Delay_T_time(3);
        BEEP_OFF();
        Delay_T_time(1);
}
void sound(char *xxx,int f)
{
        while(*xxx!='\0')
        {
                if(*xxx=='3') dash(f);
                else if(*xxx=='1') dot(f);
                else if(*xxx==' ') space();

                xxx++;
                Delay_T_time(1);
        }
        Delay_T_time(3);
}

void Send_to_speaker(char *x, int f)
{
        while(*x!='\0')
        {         //printf("%c", *x);
                switch (*x)
                {
                case ' ': sound(" ",f); break;
                case 'A': sound("13",f); break;
                case 'B': sound("3111",f); break;
                case 'C': sound("3131",f); break;
                case 'D': sound("311",f); break;
                case 'E': sound("1",f); break;
                case 'F': sound("1131",f); break;
                case 'G': sound("331",f); break;
                case 'H': sound("1111",f); break;
                case 'I': sound("11",f); break;
                case 'J': sound("1333",f); break;
                case 'K': sound("313",f); break;
                case 'L': sound("1311",f); break;
                case 'M': sound("33",f); break;
                case 'N': sound("31",f); break;
                case 'O': sound("333",f); break;
                case 'P': sound("1331",f); break;
                case 'Q': sound("3313",f); break;
                case 'R': sound("131",f); break;
                case 'S': sound("111",f); break;
                case 'T': sound("3",f); break;
                case 'U': sound("113",f); break;
                case 'V': sound("1113",f); break;
                case 'W': sound("133",f); break;
                case 'X': sound("3113",f); break;
                case 'Y': sound("3133",f); break;
                case 'Z': sound("3311",f); break;

                case 'a': sound("13",f); break;
                case 'b': sound("3111",f); break;
                case 'c': sound("3131",f); break;
                case 'd': sound("311",f); break;
                case 'e': sound("1",f); break;
                case 'f': sound("1131",f); break;
                case 'g': sound("331",f); break;
                case 'h': sound("1111",f); break;
                case 'i': sound("11",f); break;
                case 'j': sound("1333",f); break;
                case 'k': sound("313",f); break;
                case 'l': sound("1311",f); break;
                case 'm': sound("33",f); break;
                case 'n': sound("31",f); break;
                case 'o': sound("333",f); break;
                case 'p': sound("1331",f); break;
                case 'q': sound("3313",f); break;
                case 'r': sound("131",f); break;
                case 's': sound("111",f); break;
                case 't': sound("3",f); break;
                case 'u': sound("113",f); break;
                case 'v': sound("1113",f); break;
                case 'w': sound("133",f); break;
                case 'x': sound("3113",f); break;
                case 'y': sound("3133",f); break;
                case 'z': sound("3311",f); break;

                case '1': sound("13333",f); break;
                case '2': sound("11333",f); break;
                case '3': sound("11133",f); break;
                case '4': sound("11113",f); break;
                case '5': sound("11111",f); break;
                case '6': sound("31111",f); break;
                case '7': sound("33111",f); break;
                case '8': sound("33311",f); break;
                case '9': sound("33331",f); break;
                case '0': sound("33333",f); break;

                case '?': sound("113311",f); break;
                case '.': sound("131313",f); break;
                case ',': sound("331133",f); break;
                case '/': sound("31131",f); break;

                default: break;
                };
                x++;
        }
        printf("----now i_morse.c ---- finished \n");
}
