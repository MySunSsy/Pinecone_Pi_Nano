/**
  ******************************************************************************
  * @file    Delay.c
  * @author  PineconePi
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
// ����: void delay_ms(unsigned int ms)
// ����: ��ʱ������
// ����: ms,Ҫ��ʱ��ms��, ����ֻ֧��1~10000 (10s) ms
// ����: none.
// �汾: VER1.0.0
// ����: 2018-12-20
// ��ע: delay_ms(1000);//�ӳ�1s
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
// ����: delay_us(unsigned int us)
// ����: ��ʱ������
// ����: us,Ҫ��ʱ��us��, ����ֻ֧��1~10000 (10ms) us
// ����: none.
// �汾: VER1.0.0
// ����: 2018-12-20
// ��ע: delay_us(1000);//�ӳ�1us
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
