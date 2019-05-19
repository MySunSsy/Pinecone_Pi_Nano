/**
  ******************************************************************************
  * @file    PCA.c
  * @author  PineconePi(���ں꾧�Ƽ�STC15�⺯�������޸�)
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This file is used to configure PAC
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
	
#include	"PCA.h"

bit		B_Capture0,B_Capture1,B_Capture2;
unsigned char		PCA0_mode,PCA1_mode,PCA2_mode;
unsigned int		CCAP0_tmp,PCA_Timer0;
unsigned int		CCAP1_tmp,PCA_Timer1;
unsigned int		CCAP2_tmp,PCA_Timer2;

unsigned int	PWM0_low;	//PWM0 output low level PCA clock pulse number, the user layer is invisible.|PWM����͵�ƽ��PCAʱ���������, �û��㲻�ɼ���
unsigned int	PWM1_low;	//PWM1 output low level PCA clock pulse number, the user layer is invisible.|PWM����͵�ƽ��PCAʱ���������, �û��㲻�ɼ���
unsigned int	PWM2_low;	//PWM2 output low level PCA clock pulse number, the user layer is invisible.|PWM����͵�ƽ��PCAʱ���������, �û��㲻�ɼ���


/********************* PCA Interrupt Handling Function|PCA�жϴ�����************************/
void	PCA_Handler (void) interrupt 7
{
	if(CCF0)		//PCA module 0 interrupt|PCAģ��0�ж�
	{
		CCF0 = 0;		//Clear PCA module 0 interrupt flag|��PCAģ��0�жϱ�־
		if(P25)	CCAP0_tmp += PCA_Timer0;	//If the output is high level, the projection register is loaded with high level time length.|���Ϊ�ߵ�ƽ�����Ӱ��Ĵ���װ�ظߵ�ƽʱ�䳤��
		else	CCAP0_tmp += PWM0_low;	//If the output is low level, the projection register is loaded with low level time length.|���Ϊ�͵�ƽ�����Ӱ��Ĵ���װ�ص͵�ƽʱ�䳤��
		CCAP0L = (unsigned char)CCAP0_tmp;			//Write the projection register to the capture register and write CCAP0L first.|��Ӱ��Ĵ���д�벶��Ĵ�������дCCAP0L
		CCAP0H = (unsigned char)(CCAP0_tmp >> 8);	//Post write CCAP0H|��дCCAP0H
	}

	if(CCF1)	//PCA Module 1 Interruption|PCAģ��1�ж�
	{
		CCF1 = 0;		//Clear the interrupt flag in PCA module 1|��PCAģ��1�жϱ�־
		if(P26)	CCAP1_tmp += PCA_Timer1;	//If the output is high level, the projection register is loaded with high level time length.|���Ϊ�ߵ�ƽ�����Ӱ��Ĵ���װ�ظߵ�ƽʱ�䳤��
		else	CCAP1_tmp += PWM1_low;	//If the output is low level, the projection register is loaded with low level time length.|���Ϊ�͵�ƽ�����Ӱ��Ĵ���װ�ص͵�ƽʱ�䳤��
		CCAP1L = (unsigned char)CCAP1_tmp;			//Write the projection register to the capture register and write CCAP0L first.|��Ӱ��Ĵ���д�벶��Ĵ�������дCCAP0L
		CCAP1H = (unsigned char)(CCAP1_tmp >> 8);	//Post write CCAP0H|��дCCAP0H
	}

	if(CCF2)	//PCA Module 2 Interruption|PCAģ��2�ж�
	{
		CCF2 = 0;		//Clear the interrupt flag in PCA module 1|��PCAģ��1�жϱ�־
		if(P27)	CCAP2_tmp += PCA_Timer2;	//If the output is high level, the projection register is loaded with high level time length.|���Ϊ�ߵ�ƽ�����Ӱ��Ĵ���װ�ظߵ�ƽʱ�䳤��
		else	CCAP2_tmp += PWM2_low;	//If the output is low level, the projection register is loaded with low level time length.|���Ϊ�͵�ƽ�����Ӱ��Ĵ���װ�ص͵�ƽʱ�䳤��
		CCAP2L = (unsigned char)CCAP2_tmp;			//Write the projection register to the capture register and write CCAP0L first.|��Ӱ��Ĵ���д�벶��Ĵ�������дCCAP0L
		CCAP2H = (unsigned char)(CCAP2_tmp >> 8);	//Post write CCAP0H|��дCCAP0H
	}

/*	if(CF)	//PCA����ж�
	{
		CF = 0;			//��PCA����жϱ�־
	}
*/
}
//========================================================================
// Function:void PWMn_Update(unsigned char PCA_id, unsigned int high)|����: void PWMn_Update(unsigned char PCA_id, unsigned int high)
// Description:Update duty cycle data.|����: ����ռ�ձ����ݡ�
// Parametric: high: duty cycle data, i.e. the number of PCA clock pulses with high level output from PWM.
// ����: high: 	ռ�ձ����ݣ���PWM����ߵ�ƽ��PCAʱ�����������    
//       
// Return:|����: 
// Version:VER1.0.0|�汾: VER1.0.0
// Date:2018-12-20|����: 2018-12-20
// Author: Pinecone Pi|����: PineconePi
// Note:|��ע:
//	
//	
//	
//	
//	
//========================================================================
void PWMn_Update(unsigned char PCA_id, unsigned int high)
{
	if(PCA_id == PCA0)
	{
		if(high > PWM0_HIGH_MAX)	high = PWM0_HIGH_MAX;	//If writing data larger than the maximum duty cycle, the maximum duty cycle is mandatory.|���д��������ռ�ձ����ݣ�ǿ��Ϊ���ռ�ձȡ�
		if(high < PWM0_HIGH_MIN)	high = PWM0_HIGH_MIN;	//If less than the minimum duty cycle data is written, error code 2 is returned.|���д��С����Сռ�ձ����ݣ��򷵻ش������2��
		CR = 0;							//Stop PCA.|ֹͣPCA��
		PCA_Timer0 = high;				//When the data is in the correct range, the duty cycle register is loaded.|��������ȷ��Χ����װ��ռ�ձȼĴ�����
		PWM0_low = PWM0_DUTY - high;	//Calculate and save the number of PCA clock pulses with low PWM output level.|���㲢����PWM����͵�ƽ��PCAʱ�����������
		CR = 1;							//Start PCA.|����PCA��
	}
	else if(PCA_id == PCA1)
	{
		if(high > PWM1_HIGH_MAX)	high = PWM1_HIGH_MAX;	//If writing data larger than the maximum duty cycle, the maximum duty cycle is mandatory.|���д��������ռ�ձ����ݣ�ǿ��Ϊ���ռ�ձȡ�
		if(high < PWM1_HIGH_MIN)	high = PWM1_HIGH_MIN;	//If less than the minimum duty cycle data is written, error code 2 is returned.���д��С����Сռ�ձ����ݣ��򷵻ش������2��
		CR = 0;							//Stop PCA.|ֹͣPCA��
		PCA_Timer1 = high;				//When the data is in the correct range, the duty cycle register is loaded.|��������ȷ��Χ����װ��ռ�ձȼĴ�����
		PWM1_low = PWM1_DUTY - high;	//Calculate and save the number of PCA clock pulses with low PWM output level.|���㲢����PWM����͵�ƽ��PCAʱ�����������
		CR = 1;							//Start PCA.|����PCA��
	}
	else if(PCA_id == PCA2)
	{
		if(high > PWM2_HIGH_MAX)		high = PWM2_HIGH_MAX;	//If writing data larger than the maximum duty cycle, the maximum duty cycle is mandatory.|���д��������ռ�ձ����ݣ�ǿ��Ϊ���ռ�ձȡ�
		if(high < PWM2_HIGH_MIN)		high = PWM2_HIGH_MIN;	//If less than the minimum duty cycle data is written, error code 2 is returned.|���д��С����Сռ�ձ����ݣ��򷵻ش������2��
		CR = 0;						//Stop PCA.|ֹͣPCA��
		PCA_Timer2 = high;						//When the data is in the correct range, the duty cycle register is loaded.|��������ȷ��Χ����װ��ռ�ձȼĴ�����
		PWM2_low = PWM2_DUTY - high;				//Calculate and save the number of PCA clock pulses with low PWM output level.|���㲢����PWM����͵�ƽ��PCAʱ�����������
		CR = 1;						//Start PCA.|����PCA��
	}
}


//========================================================================
// Function:UpdatePwm(unsigned char PCA_id, unsigned char pwm_value)|����: UpdatePwm(unsigned char PCA_id, unsigned char pwm_value)
// Description:Update PWM values.|����: ����PWMֵ.
// Parameters: PCA_id: PCA serial number. Values PCA0, PCA1, PCA2, PCA_Counter
// 			   pwm_value: PWM value, which is the time when the low level is output. 
// ����: PCA_id: PCA���. ȡֵ PCA0,PCA1,PCA2,PCA_Counter
//       pwm_value: pwmֵ, ���ֵ������͵�ƽ��ʱ��.
//       
// Return:����: 
// Version:VER1.0.0|�汾: VER1.0.0
// Date:2018-12-20|����: 2018-12-20
// Author: Pinecone Pi|����: PineconePi
// Note:��ע:
//	
//	
//	
//	
//	
//========================================================================
void	UpdatePwm(unsigned char PCA_id, unsigned char pwm_value)
{
	if(PCA_id == PCA0)		CCAP0H = pwm_value;
	else if(PCA_id == PCA1)	CCAP1H = pwm_value;
	else if(PCA_id == PCA2)	CCAP2H = pwm_value;
}

//========================================================================
// Function:void	PCA_Init(PCA_id, PCA_InitTypeDef *PCAx)|����: void	PCA_Init(PCA_id, PCA_InitTypeDef *PCAx)
// Description:PCA initialization program.|����: PCA��ʼ������. 
// Parameters: PCA_id: PCA serial number. Values PCA0, PCA1, PCA2, PCA_Counter
//             PCAx: Structural parameters, please refer to the structure definition in PCA.h.
// ����: PCA_id: PCA���. ȡֵ PCA0,PCA1,PCA2,PCA_Counter
//       PCAx: �ṹ����,��ο�PCA.h��Ľṹ�嶨��.
//       
// Return:|����: 
// Version:VER1.0.0|�汾: VER1.0.0
// Date:2018-12-20|����: 2018-12-20
// Author: Pinecone Pi|����: PineconePi
// Note:|��ע:
//	
//	
//	
//	
//	
//========================================================================
void	PCA_Init(unsigned char PCA_id, PCA_InitTypeDef *PCAx)
{
	if(PCA_id > PCA_Counter)	return;		//ID error|id����

	if(PCA_id == PCA_Counter)			//Setting up Public Counter|���ù���Counter
	{
		CR = 0;
		CH = 0;
		CL = 0;
		P_SW1 = PCAx->PCA_IoUse;			//Toggle IO port|�л�IO��
		CMOD  = (CMOD  & ~(7<<1)) | PCAx->PCA_Clock;			//Selecting Clock Source|ѡ��ʱ��Դ
		CMOD  = (CMOD  & ~1) | (PCAx->PCA_Interrupt_Mode & 1);	//ECF
		if(PCAx->PCA_Polity == PolityHigh)		PPCA = 1;	//High priority interrupt|�����ȼ��ж�
		else									PPCA = 0;	//Low priority interrupt|�����ȼ��ж�
		CR = 1;
		return;
	}

	PCAx->PCA_Interrupt_Mode &= (3<<4) + 1;
	if(PCAx->PCA_Mode >= PCA_Mode_SoftTimer)	PCAx->PCA_Interrupt_Mode &= ~(3<<4);

	if(PCA_id == PCA0)
	{
		CCAPM0    = PCAx->PCA_Mode | PCAx->PCA_Interrupt_Mode;	//Work mode, interrupt mode|����ģʽ, �ж�ģʽ
		PCA_PWM0  = (PCA_PWM0 & ~(3<<6)) | PCAx->PCA_PWM_Wide;	//PWM width|PWM���

		PCA_Timer0 = PCAx->PCA_Value;
		B_Capture0 = 0;
		PCA0_mode = PCAx->PCA_Mode;
		CCAP0_tmp = PCA_Timer0;
		CCAP0L = (unsigned char)CCAP0_tmp;			//Write the projection register to the capture register and write CCAP0L first.|��Ӱ��Ĵ���д�벶��Ĵ�������дCCAP0L
		CCAP0H = (unsigned char)(CCAP0_tmp >> 8);	//Post write CCAP0H|��дCCAP0H
	}
	if(PCA_id == PCA1)
	{
		CCAPM1    = PCAx->PCA_Mode | PCAx->PCA_Interrupt_Mode;
		PCA_PWM1  = (PCA_PWM1 & ~(3<<6)) | PCAx->PCA_PWM_Wide;

		PCA_Timer1 = PCAx->PCA_Value;
		B_Capture1 = 0;
		PCA1_mode = PCAx->PCA_Mode;
		CCAP1_tmp = PCA_Timer1;
		CCAP1L = (unsigned char)CCAP1_tmp;			//Write the projection register to the capture register and write CCAP0L first.|��Ӱ��Ĵ���д�벶��Ĵ�������дCCAP0L
		CCAP1H = (unsigned char)(CCAP1_tmp >> 8);	//Post write CCAP0H|��дCCAP0H
	}
	if(PCA_id == PCA2)
	{
		CCAPM2    = PCAx->PCA_Mode | PCAx->PCA_Interrupt_Mode;
		PCA_PWM2  = (PCA_PWM2 & ~(3<<6)) | PCAx->PCA_PWM_Wide;

		PCA_Timer2 = PCAx->PCA_Value;
		B_Capture2 = 0;
		PCA2_mode = PCAx->PCA_Mode;
		CCAP2_tmp = PCA_Timer2;
		CCAP2L = (unsigned char)CCAP2_tmp;			//Write the projection register to the capture register and write CCAP0L first.|��Ӱ��Ĵ���д�벶��Ĵ�������дCCAP0L
		CCAP2H = (unsigned char)(CCAP2_tmp >> 8);	//Post write CCAP0H|��дCCAP0H
	}
}

