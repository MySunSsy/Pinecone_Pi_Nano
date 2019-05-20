/**
  ******************************************************************************
  * @file    mp3player.c
  * @author  PineconePi
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This article will be used for  driving  MP3 Player.
  * @License:GNU General Public License v3.0         
  ******************************************************************************
  * @attention
  *	include library/system/uart uart.c & uaet.h
  *
  *  
  * 
  * 
  * 
  * 
  *
  * 
  ******************************************************************************
	**/
#include "mp3player.h"
#define BRT             (65536 - MAIN_Fosc / 9600 / 4)
static unsigned char Send_buf[10] = {0};
bit busy;
char wptr;
char rptr;

//========================================================================
// ����: void Mp3_Init()
// ����: ��ʼ��MP3���ƴ��ڣ�����2��.
// ����:  
//       
//       
// ����: 
// �汾: VER1.0.0
// ����: 2018-12-20
// ����: PineconePi
// ��ע:
//	
//	
//	
//	
//	
//========================================================================
void Mp3_Init()	//��ʼ������2
{
    S2CON = 0x10;
    T2L = BRT;
    T2H = BRT >> 8;
    AUXR = 0x14;
    wptr = 0x00;
    rptr = 0x00;
    busy = 0;
}

//========================================================================
// ����: void DoSum( unsigned char *Str, unsigned char len)
// ����: ���У��.
// ����:  
//       
//       
// ����: 
// �汾: VER1.0.0
// ����: 2018-12-20
// ����: PineconePi
// ��ע:
//		 ��У���˼·����
//            ���͵�ָ�ȥ����ʼ�ͽ��������м��6���ֽڽ����ۼӣ����ȡ����
//             ���ն˾ͽ����յ���һ֡���ݣ�ȥ����ʼ�ͽ��������м�������ۼӣ��ټ��Ͻ��յ���У��
//             �ֽڡ��պ�Ϊ0.�����ʹ�����յ���������ȫ��ȷ��	
//		
//========================================================================
void DoSum( unsigned char *Str, unsigned char len)
{
    unsigned int xorsum = 0;
    unsigned char i;

    for(i=0; i<len; i++)
    {
        xorsum  = xorsum + Str[i];
    }
	xorsum     = 0 -xorsum;
	*(Str+i)   = (unsigned char)(xorsum >>8);
	*(Str+i+1) = (unsigned char)(xorsum & 0x00ff);
}

//========================================================================
// ����: void sendacmd(unsigned char len)
// ����: ���ڷ���һ֡���ݣ�����2��.
// ����:  
//       
//       
// ����: 
// �汾: VER1.0.0
// ����: 2018-12-20
// ����: PineconePi
// ��ע:
//	
//	
//	
//	
//	
//========================================================================
void Uart2Send(char dat)
{
    while (busy);
    busy = 1;
    S2BUF = dat;
	  while((S2CON & S2TI)==0);
	  S2CON &=~S2TI;
	  busy = 0;
}
void sendacmd(unsigned char len)
{
    unsigned char i = 0 ;

    Uart2Send(0x7E); //��ʼ
    for(i=0; i<len; i++)//����
    {
		Uart2Send(Send_buf[i]) ;
    }
    Uart2Send(0xEF) ;//����
}
//========================================================================
// ����: void sendacmd(unsigned char len)
// ����: �������ⷢ���������2��.
// ����:   CMD:��ʾ����ָ������ָ�����������ѯ�����ָ��
//         feedback:�Ƿ���ҪӦ��[DISABLE:����ҪӦ��ENABLE:��ҪӦ��]
//         data:���͵Ĳ���
// ����: 
// �汾: VER1.0.0
// ����: 2018-12-20
// ����: PineconePi
// ��ע:
//	
//	
//	
//	
//	
//========================================================================
void SendCMD(unsigned char CMD ,unsigned char feedback , unsigned int dat)
{
    Send_buf[0] = 0xff;    //�����ֽ� 
    Send_buf[1] = 0x06;    //����
    Send_buf[2] = CMD;     //����ָ��
    Send_buf[3] = feedback;//�Ƿ���Ҫ����
    Send_buf[4] = (unsigned char)(dat >> 8);//datah
    Send_buf[5] = (unsigned char)(dat);     //datal
    DoSum(&Send_buf[0],6);        //У��
	sendacmd(8);       //���ʹ�֡����
}
