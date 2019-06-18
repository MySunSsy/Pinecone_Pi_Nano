/**
  ******************************************************************************
  * @file    W25Q128.c
  * @author  PineconePi(User)
  * @version V1.0.0
  * @date    17-June-2019
  * @brief  This document is used to drive W25Q128.
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
#include <W25Q128.h>

//========================================================================
// ����: unsigned char SPI_Send_Reception(unsigned char Dat)
// ����: SPI����������ֽڡ�
// ����: Dat,��������
// ����: SPDAT,��������.
// �汾: VER1.0.0
// ����: 2019-06-17
// ��ע: 
//========================================================================
unsigned char SPI_Send_Reception(unsigned char Dat){
	SPDAT=Dat;
	while(!(SPSTAT&0x80));
	SPSTAT=0xC0;
	return SPDAT;
}
//========================================================================
// ����: void SetW25Q128WriteEnable()
// ����: W25Q128дʹ�ܡ�
// ����: none.
// ����: none.
// �汾: VER1.0.0
// ����: 2019-06-17
// ��ע: 
//========================================================================
void SetW25Q128WriteEnable(){
	CS=0;
	SPI_Send_Reception(0x06);
	CS=1;
}
//========================================================================
// ����: ClearW25Q128WriteEnable()
// ����: W25Q128д���ܡ�
// ����: none.
// ����: none.
// �汾: VER1.0.0
// ����: 2019-06-17
// ��ע: 
//========================================================================
void ClearW25Q128WriteEnable(){
	CS=0;
	SPI_Send_Reception(0x04);
	CS=1;
}
//========================================================================
// ����: unsigned char ReadW25Q128StatusRegister()
// ����: ��ȡW25Q128�ֽ�״̬���ж�busy��
// ����: none.
// ����: temp���Ƿ�æ.
// �汾: VER1.0.0
// ����: 2019-06-17
// ��ע: 
//========================================================================
unsigned char ReadW25Q128StatusRegister(){
	unsigned char temp;
	CS=0;
	SPI_Send_Reception(0x05);
	temp=SPI_Send_Reception(0xFF);
	CS=1;
	return temp;
}
//========================================================================
// ����: await_busy()
// ����: �ȴ�busy��ɡ�
// ����: none.
// ����: none.
// �汾: VER1.0.0
// ����: 2019-06-17
// ��ע: 
//========================================================================
void await_busy(){
	while(ReadW25Q128StatusRegister()&1);
}
//========================================================================
// ����: ReadW25Q128Operation(unsigned long addr)
// ����: ��ȡW25Q128���ݡ�
// ����: Addr,��ȡ��ַ.
// ����: none.
// �汾: VER1.0.0
// ����: 2019-06-17
// ��ע: 
//========================================================================
void ReadW25Q128Operation(unsigned long Addr){
	await_busy();
	CS=0;
	SPI_Send_Reception(0x03);
	SPI_Send_Reception(Addr>>16);
	SPI_Send_Reception(Addr>>8);
	SPI_Send_Reception(Addr);
}
//========================================================================
// ����: WriteW25Q128Operation(unsigned int Addr)
// ����: W25Q128д�룬һ��256�ֽڡ�
// ����: Addr,д���ַ.
// ����: none.
// �汾: VER1.0.0
// ����: 2019-06-17
// ��ע: 
//========================================================================
void WriteW25Q128Operation(unsigned int Addr){
	await_busy();
	SetW25Q128WriteEnable();
	CS=0;
	SPI_Send_Reception(0x02);
	SPI_Send_Reception(Addr>>8);
	SPI_Send_Reception(Addr);
	SPI_Send_Reception(0);
}
//========================================================================
// ����: EraseW25Q128Operation(unsigned int Addr)
// ����: ��W25Q128������
// ����: Addr,������ַ.
// ����: none.
// �汾: VER1.0.0
// ����: 2019-06-17
// ��ע: 
//========================================================================
void EraseW25Q128Operation(unsigned int Addr){//��W25Q128����
	await_busy();
	SetW25Q128WriteEnable();
	CS=0;
  SPI_Send_Reception(0x20);
	SPI_Send_Reception(Addr/16);
	SPI_Send_Reception(Addr*16);
	SPI_Send_Reception(0);
	CS=1;
}
//========================================================================
// ����: W25Q128_Write_SR(unsigned char Sr)
// ����: W25Q128д״̬�Ĵ�����
// ����: Sr,�Ĵ���״̬.
// ����: none.
// �汾: VER1.0.0
// ����: 2019-06-17
// ��ע: 
//========================================================================
void W25Q128_Write_SR(unsigned char Sr){
	SetW25Q128WriteEnable();
	CS=0;
	SPI_Send_Reception(0x01);
	SPI_Send_Reception(Sr);
	CS=1;
}