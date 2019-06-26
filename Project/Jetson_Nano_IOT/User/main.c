/**
************************************************************
* @file         main.c
* @brief        MCU�� ����ļ�
* @author       Gizwits
* @date         2016-09-05
* @version      V03010101
* @copyright    Gizwits
* 
* @note         ������.ֻΪ����Ӳ������
*               Gizwits Smart Cloud  for Smart Products
*               ����|��ֵ?|����|����|��ȫ|����|����|��̬
*               www.gizwits.com
*
***********************************************************/
/********************************************************
** ������ֲ˵��
*
* 1��ʵ����ģ��ͨ�Ŵ���������1���ж�������д�뻷�λ�����;2��ʵ��uartWrite()���ڷ��ͺ�����
* 2��ʵ�ִ��ڴ�ӡ����printf()
* 3��ʵ��ms��ʱ����gizTimerMs()ά��ϵͳʱ��
* 4��ʵ��MCU��λ����,ģ�������MCU��λ
* 5��ʵ��������������,����gizwitsSetMode()����ʵ��ģ����������
* 6��ʵ��userHandle()���ݵĲɼ��������߼���
* 7��ʵ��gizwitsEventProcess()��������ľ���ִ��(�����߼�)
* 8��ʵ��mcuRestart()��λ����
* 
*
*********************************************************/
#include <stdint.h>
#include <string.h>
#include <hal_uart.h>
#include <hal_key.h>
#include "gizwits_protocol.h"
#include "gizwits_product.h"

/******************** ��/�ػ�|�������� ***************/
#define Power_on P01
#define Power_off P02
#define Reset P03

/** �û�����ǰ�豸״̬�ṹ��*/
dataPoint_t currentDataPoint;
uint32_t timerMsCount = 0 ;
unsigned int Time = 0;
unsigned int sec1000 = 0;
extern unsigned char	skeycount;		//���ð���ʱ��������
extern unsigned char	skpttime;		//���ð���ʱ��
extern bit		skpflag;				//���ð������±�־
/******************** ���غ������� ***************/
void 	Timer0_Init(void);
void 	Delay_ms(unsigned int n);
void Pin_Init(void);
/******************** ��дputchar���� ***************/
char putchar(char c)
{
    UART2_TxByte(c);//printfӳ�䵽����1�ķ��ͺ���
    return c;
}





/**
* @brief������ں���

* �ڸú���������û���صĳ�ʼ��,�����߼�ѭ��
* @param none
* @return none
*/
int main(void)
{  
	Pin_Init();
	uart1_init();
	uart2_init();
	Timer0_Init();

    userInit();
    gizwitsInit();
    
    while(1)
    {
		setkeyscan();					//��⹦�ܼ�

        userHandle();
 
        gizwitsHandle((dataPoint_t *)&currentDataPoint);
		
		
		
    }
}
/**************���ų�ʼ������**********************/
void Pin_Init()
{
	Power_on=1;
	Power_off=1;
	Reset=1;
}
/**************��ʱ����ʼ������**********************/
void Timer0_Init(void)
{
	TMOD|=0x02;
	TL0=0x40;//0x47;
	TH0=0xa2;//0x47;
	ET0=1;
	TR0=1;
}
/*************��ʱ���жϺ���******************/
void Timer0_Tsr(void) interrupt 1
{
	Time ++;
	if(Time == 5)
	{
		Time = 0;
		gizTimerMs();
	}
	sec1000++;
	if(sec1000 >= 1000)	//1��ʱ�� (1000*1ms=1000ms=1s)
	{
		sec1000 = 0;
		//����Ϊ���ù��ܼ��İ���ʱ����������
		if(skpflag)
		{
		 	skeycount++;
			if(SETKEY) skpttime=skeycount;
		}
	}
}
/**************��ʱ����ʱ����*******************/
void Delay_ms(unsigned int n)
{
	unsigned int  i,j;	
	for(i=0;i<n;i++)
		for(j=0;j<123;j++);
}
