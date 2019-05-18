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
// Function:char EEPROM_read(int addr)|����: char EEPROM_read(int addr)
// Description:Read a byte of data to address addr|����: ���ַaddr�ж�ȡһ���ֽ����ݡ�
// Parameter:Addr: Read address|����: addr:��ȡ��ַ
//       
//       
// Return:Data in a byte of addr address|����: addr��ַ��һ���ֽڵ�����
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

char EEPROM_read(int addr)
{
    char dat;

    IAP_CONTR = WT_24M;                         //ʹ��IAP
    IAP_CMD = 1;                                //����IAP������
    IAP_ADDRL = addr;                           //����IAP�͵�ַ
    IAP_ADDRH = addr >> 8;                      //����IAP�ߵ�ַ
    IAP_TRIG = 0x5a;                            //д��������(0x5a)
    IAP_TRIG = 0xa5;                            //д��������(0xa5)
    _nop_();
    dat = IAP_DATA;                             //��IAP����
    DisableEEPROM();                                  //�ر�IAP����

    return dat;
}

//========================================================================
// Function:void EEPROM_Erase(int addr)|����:void EEPROM_Erase(int addr)
// Description:The address addr is erased.|����: �Ե�ַaddr�������ݲ�����
// Parameter:Addr: The address of the EEPROM to be erased.|����: addr:Ҫ������EEPROM�ĵ�ַ.
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
void EEPROM_Erase(int addr)
{
    IAP_CONTR = WT_24M;                         //ʹ��IAP
    IAP_CMD = 3;                                //����IAP��������
    IAP_ADDRL = addr;                           //����IAP�͵�ַ
    IAP_ADDRH = addr >> 8;                      //����IAP�ߵ�ַ
    IAP_TRIG = 0x5a;                            //д��������(0x5a)
    IAP_TRIG = 0xa5;                            //д��������(0xa5)
    _nop_();                                    //
    DisableEEPROM();                                   //�ر�IAP����
}

//========================================================================
// Function:void EEPROM_write(int addr, char dat)|����:void EEPROM_write(int addr, char dat)
// Description:Write a byte data dat to the address addr.|����: ���ַaddr��д��һ���ֽ�����dat��
// Parameter:Addr: The address of the EEPROM to be written. dat: The data to be written|����: addr:Ҫд���EEPROM�ĵ�ַ.dat:д�������
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
void EEPROM_write(int addr, char dat)
{
    IAP_CONTR = WT_24M;                         //ʹ��IAP
    IAP_CMD = 2;                                //����IAPд����
    IAP_ADDRL = addr;                           //����IAP�͵�ַ
    IAP_ADDRH = addr >> 8;                      //����IAP�ߵ�ַ
    IAP_DATA = dat;                             //дIAP����
    IAP_TRIG = 0x5a;                            //д��������(0x5a)
    IAP_TRIG = 0xa5;                            //д��������(0xa5)
    _nop_();
    DisableEEPROM();                                  //�ر�IAP����
}

