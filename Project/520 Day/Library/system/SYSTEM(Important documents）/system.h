/**
  ******************************************************************************
  * @file    system.h
  * @author  PineconePi
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This article will be used for the unified invocation of functions and system configuration. 
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
#ifndef		__SYSTEM_H_
#define		__SYSTEM_H_


/*********************************************************/

  #define MAIN_Fosc		24000000UL	//������ʱ��24Mhz
//#define MAIN_Fosc		22118400UL	//������ʱ��
//#define MAIN_Fosc		12000000UL	//������ʱ��
//#define MAIN_Fosc		11059200UL	//������ʱ��
//#define MAIN_Fosc		 5529600UL	//������ʱ��


/*********************************************************/

#include	"PineconePinano.h"//�⺯��������������д,����Ҫ�Ŀ���ע��

/**************************************************************************/

#define Main_Fosc_KHZ	(MAIN_Fosc / 1000)

/***********************************************************/

#endif