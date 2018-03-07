#include "comm.h"
extern void Auto_key_scan();
extern void Send_to_speaker(char *x, int f);

unsigned char server_data_received;

extern unsigned char Data_from_client[lenth_of_data_buffer];
extern unsigned char Data_to_client[lenth_of_data_buffer];
extern unsigned char client_data_received;


unsigned char Data_from_server[lenth_of_data_buffer];
unsigned char Data_to_server[lenth_of_data_buffer] = "THIS IS A CQ HELLO TEST3 QTH WEATHER RIG ANT RST CALLSIGN ";

unsigned char *point_Data_from_server;
unsigned char *point_Data_to_server;

unsigned char Data_to_server_OK=0;
void Client_State_check()
{
        ;
}
void send_data_to_server()
{
        strcpy(Data_from_client,Data_to_server);
        memset(Data_to_server,'\0',sizeof(char));//发送缓冲区清零
}

void Client()
{
        Auto_key_scan();

        if(Data_to_server_OK)
        {
                send_data_to_server();
                Data_to_server_OK=0;
        }
        printf("------client test-----------\n");
        printf("%s",point_Data_from_server); printf("\n");
        printf("------client test-----------\n");
        //if( (*Data_buffer_from_server) != '\0')//接收缓冲区非空
        // {
        //      delay(1000*(rand()%8));
        Send_to_speaker(Data_from_server, 750);
        //        memset(Data_buffer_from_server,'\0',sizeof(char));//接收缓冲区清零
        //   }

        Client_State_check();

}
