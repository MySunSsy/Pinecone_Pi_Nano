/**
  ******************************************************************************
  * @file    eeprom.h
  * @author  PineconePi(���ں꾧�Ƽ�STC15�⺯�������޸�)
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This file is used to Configure internal EEPROM 
  * @License:GNU General Public License v3.0         
  ******************************************************************************
  * @attention
  *Pinecone Pi NANO: The size of EEPROM is set by STC-ISP
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
#ifndef	__EEPROM_H
#define	__EEPROM_H

#include	"system.h"

#define WT_30M          0x80
#define WT_24M          0x81   //IRC Crystal Oscillator Frequency 24Mhz in NANO|NANO�ڲ�IRC����Ƶ��24Mhz
#define WT_20M          0x82
#define WT_12M          0x83
#define WT_6M           0x84
#define WT_3M           0x85
#define WT_2M           0x86
#define WT_1M           0x87


void	DisableEEPROM(void);//Turn off IAP function|�ر�IAP����
char EEPROM_read(int addr);//Read a byte of data to address addr|���ַaddr�ж�ȡһ���ֽ�����
void EEPROM_write(int addr, char dat);//Write a byte data dat to address addr|���ַaddr��д��һ���ֽ�����dat
void EEPROM_Erase(int addr);//Data erase for address addr|�Ե�ַaddr�������ݲ���


#endif