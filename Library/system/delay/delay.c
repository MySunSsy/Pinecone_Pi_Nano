/**
  ******************************************************************************
  * @file    Delay.c
  * @author  PineconePi(���ں꾧�Ƽ�STC15�⺯�������޸�)
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This file is used to complete software Delay
  * @License:GNU General Public License v3.0         
  ******************************************************************************
  * @attention
  *The frequency of crystal oscillator is 24 Mhz
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
#include "delay.h"
#include "intrins.h"
//========================================================================
// Function:void delay_ms(unsigned int ms)|����: void delay_ms(unsigned int ms)
// Description:Delay Function|����: ��ʱ������
// Parameter:Ms, the number of MS to be delayed, where only 1-10000 (10s) MS is supported|����: ms,Ҫ��ʱ��ms��, ����ֻ֧��1~10000 (10s) ms
// Return:none|����: none.
// Version VER1.0.0|�汾: VER1.0.0
// Date:2018-12-20|����: 2018-12-20
// Note:delay_ms(1000);//Delay 1s|��ע: delay_ms(1000);//�ӳ�1s
//========================================================================
void delay_ms(unsigned int ms){
  unsigned int k;
	unsigned char i, j;
	for(k=0;k<ms;k++)
	{
	_nop_();
	i = 32;
	j = 40;
		do
		{
		  while (--j);
		} while (--i);
	}
													   }
//========================================================================
// Function:delay_us(unsigned int us)|����: delay_us(unsigned int us)
// Description:Delay Function|����: ��ʱ������
// Parameter:Us, the number of us delays, where only 1-10000 (10ms) us is supported|����: us,Ҫ��ʱ��us��, ����ֻ֧��1~10000 (10ms) us
// Return:none|����: none.
// Version:VER1.0.0|�汾: VER1.0.0
// Date:2018-12-20|����: 2018-12-20
// Note:delay_us(1000);//delay 1ms|��ע: delay_us(1000);//�ӳ�1ms
//========================================================================
void delay_us(unsigned int us){
  unsigned int k;
	unsigned char i;
	for(k=0;k<us;k++)
	{
	i = 6;
	while (--i);
	}
													    }
