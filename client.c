#include "comm.h"
extern void Auto_key_scan();
extern unsigned char server_data_received;

extern unsigned char Data_buffer_from_client[180];
extern unsigned char Data_buffer_to_client[180];
extern unsigned char client_data_received;


unsigned char Data_buffer_from_server[180];
unsigned char Data_buffer_to_server[180] = "THIS IS A CQ HELLO TEST3 QTH WEATHER RIG ANT RST CALLSIGN ";
unsigned char Data_buffer_to_server_OK=0;
void Client_State_check()
{
        ;
}
void send_data_to_server()
{
        strcpy(Data_buffer_from_client,Data_buffer_to_server);
        memset(Data_buffer_to_server,'\0',sizeof(char));//发送缓冲区清零
}

void Client()
{
        Auto_key_scan();

        if(Data_buffer_to_server_OK)
        {
                send_data_to_server();
                Data_buffer_to_server_OK=0;
        }

        Client_State_check();

}
