/**
  ******************************************************************************
  * @file    eeprom.c
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
	
#include "system.h"
#include "eeprom.h"
#include "intrins.h"

//========================================================================
// Function:void DisableEEPROM(void)|����: void	DisableEEPROM(void)
// Description:Turn off the IAP function.|����: �ر�IAP���ܡ�
// Parameter:|����: 
//       
//       
// Return:|����: 
// Version:VER1.0.0|�汾: VER1.0.0
// Date:2018-12-20|����: 2018-12-20
// Author:PineconePi|����: PineconePi
// Note:��ע:
//	
//	
//	
//	
//	
//========================================================================
void	DisableEEPROM(void)
{
    IAP_CONTR = 0;                              //�ر�IAP����
    IAP_CMD = 0;                                //�������Ĵ���
    IAP_TRIG = 0;                               //��������Ĵ���
    IAP_ADDRH = 0x80;                           //����ַ���õ���IAP����
    IAP_ADDRL = 0;
}

//========================================================================
// Function:char EEPROM_Read(int Addr)|����: char EEPROM_Read(int Addr)
// Description:Read a byte of data to address Addr|����: ���ַAddr�ж�ȡһ���ֽ����ݡ�
// Parameter:Addr: Read address|����: Addr:��ȡ��ַ
//       
//       
// Return:Data in a byte of Addr address|����: Addr��ַ��һ���ֽڵ�����
// Version:VER1.0.0|�汾: VER1.0.0
// Date:2018-12-20|����: 2018-12-20
// Author:PineconePi|����: PineconePi
// Note:|��ע:
//	
//	
//	
//	
//	
//========================================================================

char EEPROM_Read(int Addr)
{
    char dat;

    IAP_CONTR = WT_24M;                         //ʹ��IAP
    IAP_CMD = 1;                                //����IAP������
    IAP_ADDRL = Addr;                           //����IAP�͵�ַ
    IAP_ADDRH = Addr >> 8;                      //����IAP�ߵ�ַ
    IAP_TRIG = 0x5a;                            //д��������(0x5a)
    IAP_TRIG = 0xa5;                            //д��������(0xa5)
    _nop_();
    dat = IAP_DATA;                             //��IAP����
    DisableEEPROM();                                  //�ر�IAP����

    return dat;
}

//========================================================================
// Function:void EEPROM_Erase(int Addr)|����:void EEPROM_Erase(int Addr)
// Description:The address Addr is erased.|����: �Ե�ַAddr�������ݲ�����
// Parameter:Addr: The address of the EEPROM to be erased.|����: Addr:Ҫ������EEPROM�ĵ�ַ.
//       
//       
// Return:|����: 
// Version:VER1.0.0|�汾: VER1.0.0
// Date:2018-12-20|����: 2018-12-20
// Author:PineconePi|����: PineconePi
// Note:|��ע:
//	
//	
//	
//	
//	
//========================================================================
void EEPROM_Erase(int Addr)
{
    IAP_CONTR = WT_24M;                         //ʹ��IAP
    IAP_CMD = 3;                                //����IAP��������
    IAP_ADDRL = Addr;                           //����IAP�͵�ַ
    IAP_ADDRH = Addr >> 8;                      //����IAP�ߵ�ַ
    IAP_TRIG = 0x5a;                            //д��������(0x5a)
    IAP_TRIG = 0xa5;                            //д��������(0xa5)
    _nop_();                                    //
    DisableEEPROM();                                   //�ر�IAP����
}

//========================================================================
// Function:void EEPROM_Write(int Addr, char Dat)|����:void EEPROM_Write(int Addr, char Dat)
// Description:Write a byte data Dat to the address Addr.|����: ���ַAddr��д��һ���ֽ�����Dat��
// Parameter:Addr: The address of the EEPROM to be written. Dat: The data to be written|����: Addr:Ҫд���EEPROM�ĵ�ַ.Dat:д�������
//       
//       
// Return:|����: 
// Version:VER1.0.0|�汾: VER1.0.0
// Date:2018-12-20|����: 2018-12-20
// Author:PineconePi|����: PineconePi
// Note:|��ע:
//	
//	
//	
//	
//	
//========================================================================
void EEPROM_Write(int Addr, char Dat)
{
    IAP_CONTR = WT_24M;                         //ʹ��IAP
    IAP_CMD = 2;                                //����IAPд����
    IAP_ADDRL = Addr;                           //����IAP�͵�ַ
    IAP_ADDRH = Addr >> 8;                      //����IAP�ߵ�ַ
    IAP_DATA = Dat;                             //дIAP����
    IAP_TRIG = 0x5a;                            //д��������(0x5a)
    IAP_TRIG = 0xa5;                            //д��������(0xa5)
    _nop_();
    DisableEEPROM();                                  //�ر�IAP����
}

