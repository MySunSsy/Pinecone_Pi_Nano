/**
  ******************************************************************************
  * @file    ws2812b.h
  * @author  PineconePi
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This article will be used for  driving  ws2812b.
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
#ifndef _WS2812B_H_
#define	_WS2812B_H_

#include "system.h"

#define rgb_pin P12   //RGB�˿�
#define n_ws2812b 12  //RGB������
#define clear_ws2812b 24  //roll_2���� ����֤��ȫ���㣬clear_ws2812b = 2*n_ws2812b)
#define normal 0  //��ͨģʽ
#define  roll 1	  //��������ˮģʽ
#define roll_back_1 2 //������ˮģʽ
#define roll_back_2 3 //��������ˮģʽ
#define roll_delay 100	  //��ˮģʽ�������λ��ms��
#define breathe 4 //����ģʽ   
void delay_ms_2812b(unsigned int ms);
void n_ws2812b_display(unsigned char display_mode,unsigned char green,unsigned char red,unsigned char blue);//n��ws2812b����
#endif