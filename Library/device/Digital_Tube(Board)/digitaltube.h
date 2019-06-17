/**
  ******************************************************************************
  * @file    digitaltube.h
  * @author  PineconePi
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This file is used to set up  digital tubes 
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
#ifndef _DIGITALTUBE_H_
#define _DIGITALTUBE_H_

#include "system.h"

#define ENABLE 1  //ʹ��
#define DISABLE 0 //�ر�

#define SMG1 1  //Nixie tube 1|�����1
#define SMG2 2  //Nixie tube 2|�����2


void Digitaltube_Enable(unsigned char SMGx,unsigned char Enable_Disable);//Enabling digital tube|ʹ�������
void Digitaltube_Display(unsigned char Decimal_point_Enable,unsigned char dat);//Enables decimal points to display numbers (0-9)|ʹ��С���㣬��ʾ���֣�0-9��
#endif