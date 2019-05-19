/**
  ******************************************************************************
  * @file    hc_sr04.h
  * @author  PineconePi
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This article will be used for  driving  hc_sr04.
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
#ifndef _HC_SR04_H_
#define _HC_SR04_H_

#include "system.h"

#define Echo_Pin P12   //Echo port|Echo�˿�
#define Trig_Pin P13   //Trig port|Trig�˿�

void HC_SR04_Init(void);//Hardware required to initialize HCSR04|��ʼ��HCSR04����Ӳ��
int HC_SR04_Loop(void); //Get the current distance value|��ȡ��ǰ����ֵ

#endif