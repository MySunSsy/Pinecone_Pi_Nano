/**
  ******************************************************************************
  * @file    digitaltube.c
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
#include "digitaltube.h"

unsigned char Segment_code[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};  //Digital Tube Segment Table|����ܶα�

//========================================================================
// Function:void digitaltube_enable(unsigned char SMGx,unsigned char Enable_Disable)|����: void digitaltube_enable(unsigned char SMGx,unsigned char Enable_Disable)
// Description:Enabling digital tube.|����: ʹ������ܡ�
// Parameters: SMGx: Digital Tube Sequence Number
//             Enable_Disable: Enable
// ����: SMGx:��������
//       Enable_Disable���Ƿ�ʹ��
//       
// Return:|����: 
// Version: ver1.0.0|�汾: VER1.0.0
// Date: 2018-12-20|����: 2018-12-20
// Author: Pinecone Pi|����: PineconePi
// Note:|��ע:
//	
//	
//	
//	
//	
//========================================================================
void Digitaltube_Enable(unsigned char SMGx,unsigned char Enable_Disable)
{
	if(SMGx==SMG1){
		if(Enable_Disable == ENABLE)
			P44 = 0;
		else if(Enable_Disable == DISABLE)
			P44 = 1;
	}
	else if(SMGx==SMG2)
	{
				if(Enable_Disable == ENABLE)
         P43 = 0;
		else if(Enable_Disable == DISABLE)
         P43 = 1;
	}
}
//========================================================================
// Function:void digitaltube_display(unsigned char Decimal_point_Enable,unsigned char dat)|����: void digitaltube_display(unsigned char Decimal_point_Enable,unsigned char dat)
// Description:Whether to open decimal point, digital tube display.|����: �Ƿ���С���㣬�������ʾ��
// Parameter: Decimal_point_Enable: Open decimal point or not
//            dat: Number of displays (0-9)
// ����: Decimal_point_Enable:�Ƿ���С����
//       dat����ʾ���� ��0-9��
//       
// Return:|����: 
// Version: ver1.0.0|�汾: VER1.0.0
// Date: 2018-12-20|����: 2018-12-20
// Author: Pinecone Pi|����: PineconePi
// Note:|��ע:
//	
//	
//	
//	
//	
//========================================================================
void Digitaltube_Display(unsigned char Decimal_point_Enable,unsigned char dat)
{
	if(Decimal_point_Enable == ENABLE)
	{
		P1 = (Segment_code[dat]|0x80);
	}
	else if(Decimal_point_Enable == DISABLE)
	{
		P1 = Segment_code[dat];
	}
}	