/**
  ******************************************************************************
  * @file    LCD1602.h
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
#ifndef _LCD1602_H_
#define _LCD1602_H_

#include "system.h"

#define Reg 0   //д�����ͣ�����
#define Data 1  //д�����ͣ�����

#define RS P21  //����/����ѡ��
#define RW P22  //��ȡ/д��ѡ��
#define EN P24	//ʹ���ź�
#define DO P1		//���ݿ�


void LCD1602_Write(unsigned char Write_Type,unsigned char Dat);//LCD1602д������

#endif