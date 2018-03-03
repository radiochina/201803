#define _AUTO_KEY_C_
#include "comm.h"

unsigned char QSO_buffer[180];
unsigned char KEY_IN_buffer[15];
unsigned char CALLSIGN_buffer[10];


void str(char *p1, char *p2)
{
        char *p = p1; //œ«Ä¿±êÒÅ²úµØÖ·ž³žøÖžÕë±äÁ¿p;œ«Êý×és1µÄÊ×µØÖ·ž³žøÖžÕë±äÁ¿p,
        while(*p1++); //ÖžÕëp1ÒÆµœs1µÄŽ®Î²£»µ±*pµÄÖµ²»ÊÇ\0Ê±, pŸÍÏòºóÎ»ÒÆ Ö±µœ*pÎª\0¡£
        p1--;     //ÒòÎªp1ÏÖÔÚµÄÎ»ÖÃÔÚ\0,ËùÒÔÓŠÏòÇ°ÒÆÒ»žöÎ»ÖÃ
        while(*p1++ = *p2++); //œ«ÔŽŽ®s2ÖÐµÄ×Ö·ûÒÀŽÎžŽÖÆµœÄ¿±êŽ®s1ÖÐ£»  °Ñs2ÖÐµÄ×Ö·ûŽ®žŽÖÆµœs1×Ö·ûŽ®µÄºóÃæ
}

void Low_to_Upper(unsigned char *x)
{
        unsigned char i;
        for(i=0; i<strlen(x); i++)
        {
                x[i]=toupper(x[i]);
        }
}
unsigned char Dot_key=0;
unsigned char Dash_key=0;
void Get_key()
{
        if(KEY_MODE==AUTO_KEY)
        {
                if(L_R_key_changed)
                {
                        if(Key1==0) Dot_key=1;
                        if(Key2==0) Dash_key=1;
                }
                else
                {
                        if(Key2==0) Dot_key=1;
                        if(Key1==0) Dash_key=1;
                }
        }
        else //HAND_KEY
        {
                ;
        }
}


void Auto_key_scan_and_Access()
{
        Get_key();
        if(Dot_key)
        {
                Dot_key=0;
                SET_Frequency(Frequency_of_user);
                dot();
                SET_Frequency(Frequency_of_radio);
                cw_counter<<=4;
                cw_counter+=0x01;

                time_delaying_1ms=Data_for_delay_T[CW_SPEED]*30;
                time_delaying_1000ms=20;
                time_delaying_1S=4*60;

        }
        if(Dash_key)
        {
                Dash_key=0;
                SET_Frequency(Frequency_of_user);
                dash();
                SET_Frequency(Frequency_of_radio);
                cw_counter<<=4;
                cw_counter+=0x03;

                time_delaying_1ms=Data_for_delay_T[CW_SPEED]*30;
                time_delaying_1000ms=20;
                time_delaying_1S=4*60;

        }
        if (time_delaying_1ms==Data_for_delay_T[CW_SPEED]*27) //Í£Ö¹ŒüÈëÒÑŸ­¹ýÁË30-27=3T  ŒÆ3žöÊ±Œäµ¥Î»£¬ÕâÊÇ³É¹ŠœÓÊÕÒ»žö×ÖÄž£š·û£©
        { //55*27=1485
                switch (cw_counter)
                {

                case 0x13:   str(KEY_IN_buffer,"a"); Lcd_disp_letter("a"); break;
                case 0x3111:   str(KEY_IN_buffer,"b"); Lcd_disp_letter("b"); break;
                case 0x3131:   str(KEY_IN_buffer,"c"); Lcd_disp_letter("c"); break;
                case 0x311:   str(KEY_IN_buffer,"d"); Lcd_disp_letter("d"); break;
                case 0x1:   str(KEY_IN_buffer,"e"); Lcd_disp_letter("e"); break;
                case 0x1131:   str(KEY_IN_buffer,"f"); Lcd_disp_letter("f"); break;
                case 0x331:   str(KEY_IN_buffer,"g"); Lcd_disp_letter("g"); break;
                case 0x1111:   str(KEY_IN_buffer,"h"); Lcd_disp_letter("h"); break;
                case 0x11:   str(KEY_IN_buffer,"i"); Lcd_disp_letter("i"); break;
                case 0x1333:   str(KEY_IN_buffer,"j"); Lcd_disp_letter("j"); break;
                case 0x313:   str(KEY_IN_buffer,"k"); Lcd_disp_letter("k"); break;
                case 0x1311:   str(KEY_IN_buffer,"l"); Lcd_disp_letter("l"); break;
                case 0x33:   str(KEY_IN_buffer,"m"); Lcd_disp_letter("m"); break;
                case 0x31:   str(KEY_IN_buffer,"n"); Lcd_disp_letter("n"); break;
                case 0x333:   str(KEY_IN_buffer,"o"); Lcd_disp_letter("o"); break;
                case 0x1331:   str(KEY_IN_buffer,"p"); Lcd_disp_letter("p"); break;
                case 0x3313:   str(KEY_IN_buffer,"q"); Lcd_disp_letter("q"); break;
                case 0x131:   str(KEY_IN_buffer,"r"); Lcd_disp_letter("r"); break;
                case 0x111:   str(KEY_IN_buffer,"s"); Lcd_disp_letter("s"); break;
                case 0x3:   str(KEY_IN_buffer,"t"); Lcd_disp_letter("t"); break;
                case 0x113:   str(KEY_IN_buffer,"u"); Lcd_disp_letter("u"); break;
                case 0x1113:   str(KEY_IN_buffer,"v"); Lcd_disp_letter("v"); break;
                case 0x133:   str(KEY_IN_buffer,"w"); Lcd_disp_letter("w"); break;
                case 0x3113:   str(KEY_IN_buffer,"x"); Lcd_disp_letter("x"); break;
                case 0x3133:   str(KEY_IN_buffer,"y"); Lcd_disp_letter("y"); break;
                case 0x3311:   str(KEY_IN_buffer,"z"); Lcd_disp_letter("z"); break;

                case 0x13333:   str(KEY_IN_buffer,"1"); Lcd_disp_letter("1"); break;;
                case 0x11333:   str(KEY_IN_buffer,"2"); Lcd_disp_letter("2"); break;;
                case 0x11133:   str(KEY_IN_buffer,"3"); Lcd_disp_letter("3"); break;;
                case 0x11113:   str(KEY_IN_buffer,"4"); Lcd_disp_letter("4"); break;;
                case 0x11111:   str(KEY_IN_buffer,"5"); Lcd_disp_letter("5"); break;;
                case 0x31111:   str(KEY_IN_buffer,"6"); Lcd_disp_letter("6"); break;;
                case 0x33111:   str(KEY_IN_buffer,"7"); Lcd_disp_letter("7"); break;;
                case 0x33311:   str(KEY_IN_buffer,"8"); Lcd_disp_letter("8"); break;;
                case 0x33331:   str(KEY_IN_buffer,"9"); Lcd_disp_letter("9"); break;;
                case 0x33333:   str(KEY_IN_buffer,"0"); Lcd_disp_letter("0"); break;;

                case 0x113311:    str(KEY_IN_buffer,"?"); Lcd_disp_letter("?"); break;;
                case 0x131313:    str(KEY_IN_buffer,"."); Lcd_disp_letter("."); break;;
                case 0x331133:    str(KEY_IN_buffer,","); Lcd_disp_letter(","); break;;
                case 0x31131:   str(KEY_IN_buffer,"/"); Lcd_disp_letter("/"); break;;

                default: break;
                }
                cw_counter=0;
        }
        if (time_delaying_1ms==Data_for_delay_T[CW_SPEED]*23)       //Í£Ö¹ŒüÈëÒÑŸ­¹ýÁË30-23=7T  ŒÆ7žöÊ±Œäµ¥Î»£¬ŒŽ³É¹ŠœÓÊÕÒ»žöµ¥ŽÊ¡£
        {         //55*23=1265

                if (KEY_IN_buffer[0]!=0) str(KEY_IN_buffer," ");    //Èç¹û³É¹ŠœÓÊÕÒ»žöµ¥ŽÊ£¬ÔÚµ¥ŽÊºóÃæŒÓ¿Õžñ

                Lcd_disp_letter(" ");                               //Èç¹û³É¹ŠœÓÊÕÒ»žöµ¥ŽÊ£¬ÊµÊ±ÔÚµ¥ŽÊºóÃæÏÔÊŸ¿Õžñ

                str(QSO_buffer,KEY_IN_buffer);                      //œ«œÓÊÕµÄµ¥ŽÊ×ªµœQSO »º³åÇø

                Clear_KEY_IN_buffer();
        }
        if ((time_delaying_1ms==0)&&(QSO_buffer[0])!=0)             //Í£Ö¹ŒüÈëÒÑŸ­¹ýÁË30T  ŒÆ30žöÊ±Œäµ¥Î»£¬ŒŽ³É¹ŠœÓÊÕÒ»žöŸä×Ó¡£
        {
                Lcd_move_bottom_line_to_top_line();   //³É¹ŠÏÔÊŸÒ»žöŸä×Ó£¬Ç¿ÖÆœøÐÐ»»ÐÐ

                Low_to_Upper(QSO_buffer);

                if(Current_Work_Mode==PRACTICE) Key_in_analyse();   //×î¹ØŒüµÄ²¿·ÖÊÇ¶ÔQSOÄÚÈÝœøÐÐ·ÖÎöŽŠÀí£¬ÔÚÕâÀïÁË

                Clear_QSO_buffer();
        }
}

unsigned char Connection_Established=0;
unsigned char RST_exchanged=0;
unsigned char QTH_exchanged=0;
unsigned char ANT_exchanged=0;
unsigned char RIG_exchanged=0;
unsigned char WEATHER_exchanged=0;

unsigned char times_of_mcu_call_cq=0;

void mcu_call_cq()
{
        LCD_cursor_XY_TO_00(Cls_screen);

        MCU_Send_to_speaker_and_disp("CQ CQ CQ DE ",1);
        MCU_Send_to_speaker_and_disp(radio[Sequence_number].callsign,1);
        MCU_Send_to_speaker_and_disp(" ",1);
        MCU_Send_to_speaker_and_disp(radio[Sequence_number].callsign,1);
        MCU_Send_to_speaker_and_disp(" ",1);
        MCU_Send_to_speaker_and_disp(radio[Sequence_number].callsign,1);
        MCU_Send_to_speaker_and_disp(" ",1);
        MCU_Send_to_speaker_and_disp("PSE K",1);

        Lcd_move_bottom_line_to_top_line();
}
void mcu_go_sleep()
{
        MCU_Send_to_speaker_and_disp("S",0);
        LCD_OFF();
        EX0=EX1=1;//¿ªÖÐ¶Ï0¡¢1ÒÔ±ž»œÐÑ
        LIGHT_OFF();
        PCON |= 0x02;     //œ«STOP(PCON.1)ÖÃ1,MCUœ«œøÈëµôµçÄ£Êœ
        _nop_();          //ŽËÊ±CPUÎÞÊ±ÖÓ,²»ÖŽÐÐÖžÁî,ÇÒËùÓûÍâÉèÍ£Ö¹¹€×÷
        _nop_();          //Íâ²¿ÖÐ¶ÏÐÅºÅºÍÍâ²¿žŽÎ»ÐÅºÅ¿ÉÒÔÖÕÖ¹µôµçÄ£Êœ
        _nop_();
        _nop_();
}

unsigned char buffer_of_rnd_data[5];//Ê¹ÓÃ¹ýµÄËæ»úÊý±£ŽæÆðÀŽ£¬ÕâžöÊýŸÝÇøŽóÐ¡±ØÐëµÈÓÚ max_element_number


void clear_buffer_of_rnd_data()
{
        unsigned char i;
        for(i=0; i<max_element_number; i++) buffer_of_rnd_data[i]=0;
}
unsigned char search_used_rnd_in_buffer(unsigned char x)
{
        unsigned char i;
        unsigned char find=0;
        for(i=0; i<max_element_number; i++)
        {
                if(buffer_of_rnd_data[i]==x) find=1;
        }
        return find;
}
void Send_to_speaker_with_rnd_mode(unsigned char *rnd_element_report_mode, unsigned char *radio_element,unsigned char send_element_times,unsigned char R )
{
        unsigned char i;
        MCU_Send_to_speaker_and_disp(CALLSIGN_buffer,1);
        MCU_Send_to_speaker_and_disp(" DE ",1);
        MCU_Send_to_speaker_and_disp(radio[Sequence_number].callsign,1);
        MCU_Send_to_speaker_and_disp(" ",1);
        if(R) MCU_Send_to_speaker_and_disp("R ",1);

        MCU_Send_to_speaker_and_disp(rnd_element_report_mode,1);
        MCU_Send_to_speaker_and_disp(" ",1);
        for(i=0; i<send_element_times; i++)
        {
                MCU_Send_to_speaker_and_disp(radio_element,1);
                MCU_Send_to_speaker_and_disp(" ",1);
        }

        MCU_Send_to_speaker_and_disp(CALLSIGN_buffer,1);
        MCU_Send_to_speaker_and_disp(" DE ",1);
        MCU_Send_to_speaker_and_disp(radio[Sequence_number].callsign,1);
        MCU_Send_to_speaker_and_disp(" K",1);

        Lcd_move_bottom_line_to_top_line();
}

void MCU_Send_to_speaker_radiostation_element(unsigned char x)
{
        unsigned char i;

        switch (x)
        {
        case 1:
                if(QTH_exchanged==0)
                {
                        LCD_cursor_XY_TO_00(Cls_screen);
                        i=rand ()%number_of_qth_report_mode;
                        Send_to_speaker_with_rnd_mode(qth_report_mode[i], radio[Sequence_number].qth,1,0 );
                        QTH_exchanged=1;
                }
                break;
        case 2:
                if(RST_exchanged==0)
                {
                        LCD_cursor_XY_TO_00(Cls_screen);
                        i=rand ()%number_of_rst_report_mode;
                        Send_to_speaker_with_rnd_mode(rst_report_mode[i], radio[Sequence_number].rst,3,0 );
                        RST_exchanged=1;
                }
                break;
        case 3:
                if(WEATHER_exchanged==0)
                {
                        LCD_cursor_XY_TO_00(Cls_screen);
                        i=rand ()%number_of_weather_report_mode;
                        Send_to_speaker_with_rnd_mode(weather_report_mode[i], radio[Sequence_number].weather,1,0 );
                        WEATHER_exchanged=1;
                }
                break;
        case 4:
                if(RIG_exchanged==0)
                {
                        LCD_cursor_XY_TO_00(Cls_screen);
                        i=rand ()%number_of_rig_report_mode;
                        Send_to_speaker_with_rnd_mode(rig_report_mode[i], radio[Sequence_number].rig,1,0 );
                        RIG_exchanged=1;
                }
                break;
        case 5:
                if(ANT_exchanged==0)
                {
                        LCD_cursor_XY_TO_00(Cls_screen);
                        i=rand ()%number_of_ant_report_mode;
                        Send_to_speaker_with_rnd_mode(ant_report_mode[i], radio[Sequence_number].ant,1,0 );
                        ANT_exchanged=1;
                }
                break;
        default:
                break;
        }
}

unsigned char number_of_element_sent=0;
unsigned char number_of_radio_called=0;

void MCU_Send_CW_and_Wait_for_Anwser()
{
        unsigned char i;
        if(!Connection_Established)
        {
                if((time_delaying_1000ms==0)&&(times_of_mcu_call_cq<3))
                {
                        if(Sequence_number_got==0) Get_Sequence_number();
                        mcu_call_cq();
                        times_of_mcu_call_cq++;
                        time_delaying_1000ms=20;
                }
                if((time_delaying_1000ms==0)&&(times_of_mcu_call_cq==3))
                {
                        number_of_radio_called++;
                        Sequence_number_got=0;
                        times_of_mcu_call_cq=0;
                        if(number_of_radio_called==3) {number_of_radio_called=0; mcu_go_sleep();}
                }
        }
/////////////////////////////////////////////////////
        else //(Connection_Established) //œšÁ¢ÁªœÓºóÒÀŽÎ·¢ËÍµçÌšµÄÏà¹ØÐÅÏ¢RST\ANT\RIG\WEATHER...
        {
                if((number_of_element_sent<max_element_number)&&(time_delaying_1000ms==0))
                {

                        do {
                                i=rand()%max_element_number+1;
                        } while(search_used_rnd_in_buffer(i));

                        buffer_of_rnd_data[number_of_element_sent]=i; //±£Žæ²úÉúµÄËæ»úÊýÒÔ±žÏÂÒ»²œÊ¹ÓÃ

                        MCU_Send_to_speaker_radiostation_element(i);

                        number_of_element_sent++;
                        time_delaying_1000ms=20;
                }
                if((time_delaying_1000ms==0)&&(number_of_element_sent==max_element_number))
                {
                        LCD_cursor_XY_TO_00(Cls_screen);
                        MCU_Send_to_speaker_and_disp(CALLSIGN_buffer,1);
                        MCU_Send_to_speaker_and_disp(" DE ",1);
                        MCU_Send_to_speaker_and_disp(radio[Sequence_number].callsign,1);
                        MCU_Send_to_speaker_and_disp(" R ",1);

                        i=rand ()%number_of_end_qso_mode;
                        MCU_Send_to_speaker_and_disp(end_qso_mode[i],1);

                        MCU_Send_to_speaker_and_disp(CALLSIGN_buffer,1);
                        MCU_Send_to_speaker_and_disp(" DE ",1);
                        MCU_Send_to_speaker_and_disp(radio[Sequence_number].callsign,1);
                        MCU_Send_to_speaker_and_disp(" SK TU E E",1);
                        Lcd_move_bottom_line_to_top_line();

                        time_delaying_1000ms=rand ()%10;
                        while(time_delaying_1000ms);

                        Connection_Established=0;
                        RST_exchanged=0;
                        QTH_exchanged=0;
                        ANT_exchanged=0;
                        RIG_exchanged=0;
                        WEATHER_exchanged=0;
                        Sequence_number_got=0;

                        clear_buffer_of_rnd_data();
                        number_of_element_sent=0;// next
                        times_of_mcu_call_cq=0;
                }
        }

}
void move_callsign_from_QSO_buffer_to_CALLSIGN_buffer()
{
        unsigned char  *p1;
        unsigned char  *p2;
        Clear_callsign_buffer();
        p1=strstr(QSO_buffer,"DE ");//¡°DE¡±ŒÓ¿ÕžñºóÊÇºôºÅµÄ¿ªÊŒ£¬ºôºÅÒÔ¿ÕžñœáÊø
        p2=CALLSIGN_buffer;
        p1+=3;

        while(*p1!=0x20)
        {
                *p2=*p1;
                p2++; p1++;
        }
}
void Key_in_analyse()
{
        unsigned char i;
        if(!Connection_Established)
        {
                if((strstr(QSO_buffer,"CQ "))&&(strstr(QSO_buffer,"DE "))&&(strstr(QSO_buffer," K")))
                {
                        move_callsign_from_QSO_buffer_to_CALLSIGN_buffer();

                        time_delaying_1000ms=rand ()%5;
                        while(time_delaying_1000ms);

                        if(Sequence_number_got==0) Get_Sequence_number();

                        LCD_cursor_XY_TO_00(Cls_screen);

                        MCU_Send_to_speaker_and_disp(CALLSIGN_buffer,1);
                        MCU_Send_to_speaker_and_disp(" ",1);
                        MCU_Send_to_speaker_and_disp(CALLSIGN_buffer,1);
                        MCU_Send_to_speaker_and_disp(" ",1);
                        MCU_Send_to_speaker_and_disp(CALLSIGN_buffer,1);
                        MCU_Send_to_speaker_and_disp(" DE ",1);
                        MCU_Send_to_speaker_and_disp(radio[Sequence_number].callsign,1);
                        MCU_Send_to_speaker_and_disp(" ",1);
                        MCU_Send_to_speaker_and_disp(radio[Sequence_number].callsign,1);
                        MCU_Send_to_speaker_and_disp(" K",1);
                        Connection_Established=1;
                        Lcd_move_bottom_line_to_top_line();
                }
                if((strstr(QSO_buffer,radio[Sequence_number].callsign))&&(strstr(QSO_buffer,"DE"))&&(strstr(QSO_buffer," K")))
                {
                        move_callsign_from_QSO_buffer_to_CALLSIGN_buffer();

                        time_delaying_1000ms=rand ()%10;
                        while(time_delaying_1000ms);
                        Connection_Established=1;
                }
        }
        else//(Connection_Established)
        {
                if(strstr(QSO_buffer,"RST")&&(RST_exchanged==0))
                {
                        LCD_cursor_XY_TO_00(Cls_screen);
                        i=rand ()%number_of_rst_report_mode;
                        Send_to_speaker_with_rnd_mode(rst_report_mode[i], radio[Sequence_number].rst,3,1 );
                        RST_exchanged=1;
                        time_delaying_1000ms=10;
                }
                if(strstr(QSO_buffer,"QTH")&&(QTH_exchanged==0))
                {
                        LCD_cursor_XY_TO_00(Cls_screen);
                        i=rand ()%number_of_qth_report_mode;
                        Send_to_speaker_with_rnd_mode(qth_report_mode[i], radio[Sequence_number].qth,1,1 );
                        QTH_exchanged=1;
                        time_delaying_1000ms=10;
                }
                if(strstr(QSO_buffer,"RIG")&&(RIG_exchanged==0))
                {
                        LCD_cursor_XY_TO_00(Cls_screen);
                        i=rand ()%number_of_rig_report_mode;
                        Send_to_speaker_with_rnd_mode(rig_report_mode[i], radio[Sequence_number].rig,1,1 );
                        RIG_exchanged=1;
                        time_delaying_1000ms=10;
                }
                if(strstr(QSO_buffer,"ANT")&&(ANT_exchanged==0))
                {
                        LCD_cursor_XY_TO_00(Cls_screen);
                        i=rand ()%number_of_ant_report_mode;
                        Send_to_speaker_with_rnd_mode(ant_report_mode[i], radio[Sequence_number].ant,1,1 );
                        ANT_exchanged=1;
                        time_delaying_1000ms=10;
                }
                if(strstr(QSO_buffer,"WX")&&(WEATHER_exchanged==0))
                {
                        LCD_cursor_XY_TO_00(Cls_screen);
                        i=rand ()%number_of_ant_report_mode;
                        Send_to_speaker_with_rnd_mode(weather_report_mode[i], radio[Sequence_number].weather,1,1 );
                        WEATHER_exchanged=1;
                        time_delaying_1000ms=10;
                }
                if((strstr(QSO_buffer,"GB "))&&(strstr(QSO_buffer,"SK "))&&(strstr(QSO_buffer,"TU")))
                {
                        LCD_cursor_XY_TO_00(Cls_screen);
                        MCU_Send_to_speaker_and_disp(CALLSIGN_buffer,1);
                        MCU_Send_to_speaker_and_disp(" DE ",1);
                        MCU_Send_to_speaker_and_disp(radio[Sequence_number].callsign,1);
                        MCU_Send_to_speaker_and_disp(" R ",1);

                        i=rand ()%number_of_end_qso_mode;
                        MCU_Send_to_speaker_and_disp(end_qso_mode[i],1);

                        MCU_Send_to_speaker_and_disp(CALLSIGN_buffer,1);
                        MCU_Send_to_speaker_and_disp(" DE ",1);
                        MCU_Send_to_speaker_and_disp(radio[Sequence_number].callsign,1);
                        MCU_Send_to_speaker_and_disp(" SK TU E E",1);
                        Lcd_move_bottom_line_to_top_line();

                        time_delaying_1000ms=rand ()%10;
                        while(time_delaying_1000ms);

                        Connection_Established=0;
                        RST_exchanged=0;
                        QTH_exchanged=0;
                        ANT_exchanged=0;
                        RIG_exchanged=0;
                        WEATHER_exchanged=0;
                        Sequence_number_got=0;
                }
        }
}


unsigned char temp_T_time=0x50;

void Cw_Decode()
{
        if (Key3==0)
        {
                time_delaying_1ms=0;
                while(Key3==0);
                if((time_delaying_1ms>temp_T_time)&&(time_delaying_1ms<temp_T_time*2)) Dot_key=1;
                if((time_delaying_1ms>temp_T_time*3)&&(time_delaying_1ms<temp_T_time*5)) Dash_key=1;
        }
}
unsigned char up;
unsigned char down;
unsigned char Enter_setup_mode;
unsigned char Setup_Mode;
unsigned char Frequency_of_radio;
unsigned char Frequency_of_user;

//  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17
//wpm  16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48 50
void setup_parameter()
{
        if(Set_up_key1_in==0)
        {
                while(Set_up_key1_in==0);
                BEEP_ON();
                Delay_T_time(3);
                BEEP_OFF();
                Setup_Mode++; if(Setup_Mode==5) Setup_Mode=1;
                switch (Setup_Mode)
                {
                case CW_Speed_Set://ÉèÖÃCWËÙ¶È
                        LCD_cursor_XY_TO_00(Cls_screen);
                        Lcd_disp_line("Set Morse Speed ",0);
                        break;
                case CW_Tone_Set://ÉèÖÃÒôµ÷
                        LCD_cursor_XY_TO_00(Cls_screen);
                        Lcd_disp_line("Set Morse Tone  ",0);
                        break;
                case LR_Hand_Set://ÉèÖÃ×óÓÒÊÖ
                        LCD_cursor_XY_TO_00(Cls_screen);
                        Lcd_disp_line("Set key LR HandS",0);
                        break;
                case POWER_Off_Time_Set://ÉèÖÃ×Ô¶¯¹Ø»úÊ±Œä
                        LCD_cursor_XY_TO_00(Cls_screen);
                        Lcd_disp_line("Set Pwroff time ",0);
                        break;
                default: break;

                }
        }
        if(Set_up_key2_out==0)
        {
                while(Set_up_key2_out ==0);
                BEEP_ON();
                Delay_T_time(3);
                BEEP_OFF();
                Enter_setup_mode=0;
                LCD_cursor_XY_TO_00(Cls_screen);
                MCU_Send_to_speaker_and_disp("  SETUP OK",1);
                LCD_cursor_XY_TO_00(Cls_screen);
        }
        if(Enter_setup_mode)
        {
                if((Key1==0)&&(Key2==0)) Enter_setup_mode=0; //escape
                if((Key1==0)&&(Key2==1)) up=1;
                if((Key1==1)&&(Key2==0)) down=1;

                switch (Setup_Mode)
                {
                case CW_Speed_Set://ÉèÖÃCWËÙ¶È
                {
                        if(up)//up
                        {
                                if(CW_SPEED<17) CW_SPEED++; MCU_Send_to_speaker_and_disp("S",1); up=0;
                        }
                        if(down)//down
                        {
                                if(CW_SPEED>0) CW_SPEED--; MCU_Send_to_speaker_and_disp("S",1); down=0;
                        }
                }
                break;
                case CW_Tone_Set://ÉèÖÃÒôµ÷
                {
                        if(up)//up
                        {
                                if(Frequency_of_user<31) Frequency_of_user++;
                                SET_Frequency(Frequency_of_user);
                                MCU_Send_to_speaker_and_disp("T",1);
                                SET_Frequency(Frequency_of_radio);
                                up=0;
                        }
                        if(down)//down
                        {
                                if(Frequency_of_user>12) Frequency_of_user--;
                                SET_Frequency(Frequency_of_user);
                                MCU_Send_to_speaker_and_disp("T",1);
                                SET_Frequency(Frequency_of_radio);

                                down=0;
                        }
                }
                break;
                case LR_Hand_Set://ÉèÖÃ×óÓÒÊÖ
                {
                        if(up)//up
                        {
                                LR_CHANGE;
                                MCU_Send_to_speaker_and_disp("H",1); up=0;
                        }
                        if(down)//down
                        {
                                LR_CHANGE;
                                MCU_Send_to_speaker_and_disp("H",1); down=0;
                        }
                }
                break;
                case POWER_Off_Time_Set://ÉèÖÃ×Ô¶¯¹Ø»úÊ±Œä
                {
                        if(up)//up
                        {
                                ;
                                MCU_Send_to_speaker_and_disp("P",1); up=0;
                        }
                        if(down)//down
                        {
                                ;
                                MCU_Send_to_speaker_and_disp("P",1); down=0;
                        }
                }
                break;
                default:
                        break;
                }
        }
}
