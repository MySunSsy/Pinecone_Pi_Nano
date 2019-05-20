/**
  ******************************************************************************
  * @file    hc_sr04.c
  * @author  PineconePi
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This article will be used for  driving  hc_sr04.
  * @License:GNU General Public License v3.0         
  ******************************************************************************
  * @attention
  *	The frequency of crystal oscillator is 24 Mhz
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
#include"hc_sr04.h"

unsigned int time_start; //Time of sound wave generation|����������ʱ��
unsigned int time_end;   //Time to receive sound waves|�յ�������ʱ�� 
						 //Echo_Pin High Level Duration = Time to Receive Sound Wave - Time to Produce Sound Wave|Echo_Pin�ߵ�ƽ������ʱ��=�յ�������ʱ��-����������ʱ��

//========================================================================
// Function:delay_us_hc_sr04(unsigned int us)|����: delay_us_hc_sr04(unsigned int us)
// Description: Delay function.|����: ��ʱ������
// Parameter: us, the number of us to be delayed, where only 1-10000 (10ms) us is supported|����: us,Ҫ��ʱ��us��, ����ֻ֧��1~10000 (10ms) us
// Return: none.|����: none.
// Version��ver1.0.0|�汾: VER1.0.0
// Date: 2018-12-20|����: 2018-12-20
// Note: delay_us (1000);//delay 1US|��ע: delay_us(1000);//�ӳ�1us
//========================================================================
void delay_us_hcsr04(unsigned int us){
  unsigned int k;
	unsigned char i;
	for(k=0;k<us;k++)
	{
	i = 6;
	while (--i);
	}
}
//========================================================================
// Function:void timer_init()|����: void timer_init()
// Description:Initialization timer 3 (16 bit automatic overload).|����: ��ʼ����ʱ��3 ��16λ�Զ����أ���
// Parameter:|����: 
// Return: none.|����: none.
// Version��ver1.0.0|�汾: VER1.0.0
// Date: 2018-12-20|����: 2018-12-20
// Note:|��ע:
//========================================================================
void timer_init()
{
	T4T3M |= 0x02;		//Timer clock 1T mode|��ʱ��ʱ��1Tģʽ
	T3L = 0x00;		//Setting Timing Initial Value|���ö�ʱ��ֵ
	T3H = 0x00;		//Setting Timing Initial Value|���ö�ʱ��ֵ
	T4T3M |= 0x08;		//Timer 3 starts timing|��ʱ��3��ʼ��ʱ
}
//========================================================================
// Function:HC_SR04_Init()|����: HC_SR04_Init()
// Description:The hardware needed to initialize HC_SR04.|����: ��ʼ��HC_SR04����Ӳ����
// Parameter:|����: 
// Return: none.|����: none.
// Version��ver1.0.0|�汾: VER1.0.0
// Date: 2018-12-20|����: 2018-12-20
// Note:|��ע:
//========================================================================
void HC_SR04_Init()
{
	timer_init();
}
//========================================================================
// Function:HC_SR04_Start()|����: HC_SR04_Start()
// Description:Start sending sound waves.|����: ��ʼ����������
// Parameter:|����: 
// Return: none.|����: none.
// Version��ver1.0.0|�汾: VER1.0.0
// Date: 2018-12-20|����: 2018-12-20
// Note:|��ע:
//========================================================================
void HC_SR04_Start()
{
	Trig_Pin = 0;
	delay_us_hcsr04(45);
	Trig_Pin = 1;
}
//========================================================================
// Function:int HC_SR04_Loop()|����: int HC_SR04_Loop()
// Description:Return distance.|����: ���ؾ��롣
// Parameter:|����:  
// Return: distance: distance (in centimeters).|����: distance:���루��λ�����ף�.
// Version��ver1.0.0|�汾: VER1.0.0
// Date: 2018-12-20|����: 2018-12-20
// Note:|��ע:
//========================================================================
int HC_SR04_Loop()
{
	int distance;//distance|����
	HC_SR04_Start();
	 while(!Echo_Pin);		//Wait when RX is zero|��RXΪ��ʱ�ȴ�
//	 TR0=1;			    //Opening count|��������
		 time_start=T3H*256+T3L;
	 while(Echo_Pin);			//When RX counts to 1 and waits|��RXΪ1�������ȴ�
//	 TR0=0;				//Closing count|�رռ���
	time_end=T3H*256+T3L;
  distance=((time_end-time_start)/24)/58;     //It's CM (int)|�������CM(int)
	return distance;
}
															
															
															
															
															