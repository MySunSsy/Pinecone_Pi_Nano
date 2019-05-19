/**
  ******************************************************************************
  * @file    watchdog.c
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
#include "watchdog.h"

//========================================================================
// Function:void setup_watchdog(unsigned char WDT_MODE_x)|����: void setup_watchdog(unsigned char WDT_MODE_x)
// Description:|����: Set and make the dog visible.|���ò�ʹ�ܿ��Ź���
// Parameter: WDT_MODE_x: Setting Watchdog Overflow Time
// ����: WDT_MODE_x:�Կ��Ź����ʱ���������
//       
//       
// Return:����: 
// Version:VER1.0.0|�汾: VER1.0.0
// Date:2018-12-20|����: 2018-12-20
// Author: Pinecone Pi����: PineconePi
// Note:|��ע:
//	
//	
//	
//	
//	
//========================================================================
void setup_watchdog(unsigned char WDT_MODE_x)
{
    WDT_CONTR = WDT_MODE_x;            //Enabling and setting watchdogs|ʹ�ܲ����ÿ��Ź�
}	
//========================================================================
// Function:off_watchdog()|����: off_watchdog()
// Description:Close the watchdog|����: �رտ��Ź���
// Parameter:|����: 
//       
//       
// Return:|����: 
// Version:VER1.0.0|�汾: VER1.0.0
// Date:2018-12-20||����: 2018-12-20
// Author: Pinecone Pi|����: PineconePi
// Note:|��ע:
//	
//	
//	
//	
//	
//========================================================================
void off_watchdog()
{
	WDT_CONTR = 0x00; //Close the watchdog|�رտ��Ź�
}
//========================================================================
// Function:void feed_dog()|����: void feed_dog()
// Description:Feed the watchdog, or the system will be reset.|����: //ι���Ź�,����ϵͳ��λ��
// Parameter:|����:  
//       
//       
// Return:|����: 
// Version:VER1.0.0|�汾: VER1.0.0
// Date:2018-12-20||����: 2018-12-20
// Author: Pinecone Pi|����: PineconePi
// Note:|��ע:
//	
//	
//	
//	
//	
//========================================================================
void feed_dog()
{
	WDT_CONTR |= 0x10;                      //Feed the watchdog, or the system will be reset.|ι���Ź�,����ϵͳ��λ
}