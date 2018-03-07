#include "comm.h"

extern void Send_to_speaker(char *x, int f);
extern void Disp_radio();
extern void Set_radio_in_client();

unsigned char wpm_of_CW       =25;

void setup_all();
void Server();
void Client();

extern unsigned char client_data_received;
extern unsigned char No_radio_prepared;
extern unsigned char Data_to_server_OK;
//delay second
//sleep(2);
////delay usecond
//usleep(2000000);

/**
 * main start here
 *
 */
int main(void)
{
        setup_all();

        Send_to_speaker("cq", 750);

        Data_to_server_OK=1;

        No_radio_prepared=1;

        while(1)
        {
                Server();
                Client();
                //    Server();
        }
        return 0;
}


////////////////////////////////////////////////////////////////////////////////

void setup_all()
{
        wiringPiSetup ();
        pinMode (Speaker, OUTPUT);
        softToneCreate(Speaker);
        Set_radio_in_client();
}


/*
   make clean

   scp pi@192.168.31.233:/home/pi/mini_2018/* /Users/lijiang/Documents/我的坚果云/Mini_bak/tel_cw/2018/
 */
