/**
  ******************************************************************************
  * @file    watchdog.h
  * @author  PineconePi
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This file is used to Configure internal WATCHDOG 
  * @License:GNU General Public License v3.0         
  ******************************************************************************
  * @attention
  *
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
#ifndef _WATCHDOG_H_
#define _WATCHDOG_H_

#include "system.h"

#define WDT_MODE_1 0x23 //ʹ�ܿ��Ź�,���ʱ��ԼΪ0.3s
#define WDT_MODE_2 0x24 //ʹ�ܿ��Ź�,���ʱ��ԼΪ0.5s
#define WDT_MODE_3 0x27 //ʹ�ܿ��Ź�,���ʱ��ԼΪ4.5s

void setup_watchdog(unsigned char WDT_MODE_x);//���ò�ʹ�ܿ��Ź�
void off_watchdog();//�رտ��Ź�
void feed_dog();//ι��
	
#endif