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

#define WDT_MODE_1 0x23 //For watchdog, spillover time is about 0.3s.|ʹ�ܿ��Ź�,���ʱ��ԼΪ0.3s
#define WDT_MODE_2 0x24 //For watchdog, spillover time is about 0.5s.|ʹ�ܿ��Ź�,���ʱ��ԼΪ0.5s
#define WDT_MODE_3 0x27 //For watchdog, spillover time is about 4.5s.|ʹ�ܿ��Ź�,���ʱ��ԼΪ4.5s

void setup_watchdog(unsigned char WDT_MODE_x);//Set and make the dog visible|���ò�ʹ�ܿ��Ź�
void off_watchdog();//Close the watchdog|�رտ��Ź�
void feed_dog();//feed a dog|ι��
	
#endif