#include "comm.h"
extern void Select_radio_randomly_waiting_for_connect();

unsigned char client_data_received;
unsigned char No_radio_prepared;
/*******************************************************************************
*
* Now define radio in Server
*
*******************************************************************************/

#define number_of_callsign   7
unsigned char *callsign[]=
{
        "bg0tk","bg1suv","bg2qby","bg3tk","bg4stv","bg5qby","bg6ss"
};

#define number_of_ant      2
unsigned char *ant[]=
{
        "LONG WIRE","LOOP"
};

#define  number_of_qth      6
unsigned char *qth[]=
{
        "SHANXI","SHANDONG","HEBEI","HENAN","GUANGDONG","GUANGXI"
};

#define  number_of_rig      5
unsigned char *rig[]=
{
        "56A","222A","807","FT817","80C"
};

#define  number_of_Frequency  6
unsigned char *Frequency[]=
{
        "750","800","850","700","900","650"
};

#define  number_of_weather   2
unsigned char *weather[]=  {
        "FINE","CLOUDY"
};

#define  number_of_rst      6
unsigned char *rst[]=
{
        "599","589","555","588","599","587"
};

/***********************radio in server defined ok*****************************/
unsigned char *used[]={"0" };

struct Radio {
        unsigned char *callsign;
        unsigned char *ant;
        unsigned char *qth;
        unsigned char *rig;
        unsigned char *weather;
        unsigned char *Frequency;
        unsigned char *rst;
        unsigned char *used;
        unsigned char current_state;
} radio_station_in_client,radio_station_in_server;

unsigned char number_of_key_word=6;
unsigned char *key_word[]=
{
        "QTH","WEATHER","RIG","ANT","RST","CALLSIGN"
};

unsigned char *response_mode_for_key_word[6][3]=
{
        {"QTH ","HR QTH ","MY QTH IN "},
        {"WEATHER ","WEATHER HR ","HR WEATHER "},
        {"RIG TRX IS ","HR RIG TRX IS ","MY RIG TRX IS "},
        {"HR ANT ","HR ANT IS ","MY ANT IS "},
        {"RST ","U RST ","U RST "},
        {"CALLSIGN ","HR CALLSIGN ","MY CALLSIGN "}
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
extern unsigned char *point_Data_from_server;
extern unsigned char *point_Data_to_server;

extern unsigned char Data_to_server[lenth_of_data_buffer];
extern unsigned char Data_from_server[lenth_of_data_buffer];


unsigned char Data_from_client[lenth_of_data_buffer];
unsigned char Data_to_client[lenth_of_data_buffer];
unsigned char CALLSIGN_buffer[10];

unsigned char *radio_in_server_state[6];

void Disp_radio()
{
        printf("\n");

        printf("%s",radio_in_server_state[5]);              printf("\n");
        printf("%s",radio_in_server_state[1]);              printf("\n");
        printf("%s",radio_in_server_state[4]);              printf("\n");
        printf("%s",radio_in_server_state[0]);              printf("\n");
        printf("%s",radio_in_server_state[2]);              printf("\n");
        printf("%s",radio_in_server_state[3]);              printf("\n");
        printf("%s",radio_station_in_server.Frequency);     printf("\n");
        printf("\n");
}

void Select_radio_randomly_waiting_for_connect()
{

        radio_in_server_state[0]=qth[rand()%number_of_qth];
        radio_in_server_state[1]=weather[rand()%number_of_weather];
        radio_in_server_state[2]=rig[rand()%number_of_rig];
        radio_in_server_state[3]=ant[rand()%number_of_ant];
        radio_in_server_state[4]=rst[rand()%number_of_rst];
        radio_in_server_state[5]=callsign[rand()%number_of_callsign];


        radio_station_in_server.Frequency=Frequency[rand()%number_of_Frequency];
        radio_station_in_server.used=used[0];
        radio_station_in_server.current_state=0;

        Disp_radio();
}
void key_word_searching_and_accessing()
{
        unsigned char i;
        char *p;
        unsigned char key_word_find=0;

        unsigned char *p2;

        //printf("----Now in key_word_searching_and_accessing()\n");
        p=strstr(Data_from_client,"CQ");               //searching CQ
        if(p)
        {
                printf("				CQ searched-----------\n");
        }
        //search key word :QTH WEATHER RIG ANT RST CALLSIGN
        for(i=0; i<number_of_key_word; i++)
        {
                p=strstr(Data_from_client,key_word[i]);
                if(p)
                {
                        p2=response_mode_for_key_word[i][rand()%3];/////////

////////////////////////////////////////////////////////////////////////////////
                        point_Data_from_server=p2;
                        strcat(Data_from_server,point_Data_from_server); //把b连接到c的串尾
////////////////////////////////////////////////////////////////////////////////
                        printf("%s",p2);/////
                        printf("%s",radio_in_server_state[i]);/////

                        strcat(Data_from_server,radio_in_server_state[i]);

                        printf(" ");////////
                        strcat(Data_from_server," ");

                        key_word_find=1;
                }
        }
        if(key_word_find)
        {
                printf("de bg3tk k "); printf("\n");
                strcat(Data_from_server,"de bg3tk k ");

                printf("%s",Data_from_server);/////

                key_word_find=0;
        }
        printf("\n");
}

void Set_radio_in_client()
{
        radio_station_in_client.callsign="bg3tk";
        radio_station_in_client.ant="long wire";
        radio_station_in_client.qth="shanxi";
        radio_station_in_client.rig="HB-1A";
        radio_station_in_client.rst="599";
        radio_station_in_client.weather="fine";
        radio_station_in_client.Frequency="750";
        radio_station_in_client.used=used[0];
        radio_station_in_client.current_state=0;
}

void send_data_to_client()
{
        strcpy(Data_from_server,Data_to_client);
        memset(Data_to_client,'\0',sizeof(char));//发送缓冲区清零
}

void Server_State_check()
{
        ;
}
void Server()
{
        if( (*Data_from_client) != '\0')//接收缓冲区非空
        {
                //delay(1000*(rand()%10));
                key_word_searching_and_accessing();
                memset(Data_from_client,'\0',sizeof(char));//接收缓冲区清零
        }
        if (No_radio_prepared)
        {

                printf("Select_radio_randomly_waiting_for_connect-----\n");
                Select_radio_randomly_waiting_for_connect();
                No_radio_prepared=0;
        }
        Server_State_check();
}
