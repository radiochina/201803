#include "comm.h"


void BEEP_ON(int f)
{
        softToneWrite (Speaker, f);
}
void  BEEP_OFF()
{
        softToneWrite (Speaker, 0);
}


//test rmate
