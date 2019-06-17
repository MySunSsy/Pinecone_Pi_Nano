/**
  ******************************************************************************
  * @file    LCD1602.c
  * @author  PineconePi(User)
  * @version V1.0.0
  * @date    17-June-2019
  * @brief  This document is used to drive LCD1602.
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
#include "LCD1602.h"

//========================================================================
// ����: void LCD1602_operation(unsigned char Dat)
// ����: LCD1602д�롣
// ����: Dat,����
// ����: none.
// �汾: VER1.0.0
// ����: 2019-06-17
// ��ע: 
//========================================================================
void LCD1602_operation(unsigned char Dat){
	unsigned int delay;
	RW=0;
	EN=1;
	DO=Dat;
	EN=0;
	for(delay=800;--delay;);
}
//========================================================================
// ����: void LCD1602_Write(unsigned char Write_Type,unsigned char Dat)
// ����: LCD1602д�뺯����
// ����: Write_Type,����/���� Dat,д�������
// ����: none.
// �汾: VER1.0.0
// ����: 2019-06-17
// ��ע: 	��ڶ��е�һ��д�� 0
//    		LCD1602_Write(Reg,0x0c);
//      	LCD1602_Write(Data,'0');
//========================================================================
void LCD1602_Write(unsigned char Write_Type,unsigned char Dat){
	RS=Write_Type;
  LCD1602_operation(Dat);
}
