/**
  ******************************************************************************
  * @file    PCA.c
  * @author  PineconePi
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

unsigned int	PWM0_low;	//PWM����͵�ƽ��PCAʱ���������, �û��㲻�ɼ���
unsigned int	PWM1_low;	//PWM����͵�ƽ��PCAʱ���������, �û��㲻�ɼ���
unsigned int	PWM2_low;	//PWM����͵�ƽ��PCAʱ���������, �û��㲻�ɼ���


/********************* PCA�жϴ�����************************/
void	PCA_Handler (void) interrupt 7
{
	if(CCF0)		//PCAģ��0�ж�
	{
		CCF0 = 0;		//��PCAģ��0�жϱ�־
		if(P25)	CCAP0_tmp += PCA_Timer0;	//���Ϊ�ߵ�ƽ�����Ӱ��Ĵ���װ�ظߵ�ƽʱ�䳤��
		else	CCAP0_tmp += PWM0_low;	//���Ϊ�͵�ƽ�����Ӱ��Ĵ���װ�ص͵�ƽʱ�䳤��
		CCAP0L = (unsigned char)CCAP0_tmp;			//��Ӱ��Ĵ���д�벶��Ĵ�������дCCAP0L
		CCAP0H = (unsigned char)(CCAP0_tmp >> 8);	//��дCCAP0H
	}

	if(CCF1)	//PCAģ��1�ж�
	{
		CCF1 = 0;		//��PCAģ��1�жϱ�־
		if(P26)	CCAP1_tmp += PCA_Timer1;	//���Ϊ�ߵ�ƽ�����Ӱ��Ĵ���װ�ظߵ�ƽʱ�䳤��
		else	CCAP1_tmp += PWM1_low;	//���Ϊ�͵�ƽ�����Ӱ��Ĵ���װ�ص͵�ƽʱ�䳤��
		CCAP1L = (unsigned char)CCAP1_tmp;			//��Ӱ��Ĵ���д�벶��Ĵ�������дCCAP0L
		CCAP1H = (unsigned char)(CCAP1_tmp >> 8);	//��дCCAP0H
	}

	if(CCF2)	//PCAģ��2�ж�
	{
		CCF2 = 0;		//��PCAģ��1�жϱ�־
		if(P27)	CCAP2_tmp += PCA_Timer2;	//���Ϊ�ߵ�ƽ�����Ӱ��Ĵ���װ�ظߵ�ƽʱ�䳤��
		else	CCAP2_tmp += PWM2_low;	//���Ϊ�͵�ƽ�����Ӱ��Ĵ���װ�ص͵�ƽʱ�䳤��
		CCAP2L = (unsigned char)CCAP2_tmp;			//��Ӱ��Ĵ���д�벶��Ĵ�������дCCAP0L
		CCAP2H = (unsigned char)(CCAP2_tmp >> 8);	//��дCCAP0H
	}

/*	if(CF)	//PCA����ж�
	{
		CF = 0;			//��PCA����жϱ�־
	}
*/
}
//========================================================================
// ����: void PWMn_Update(unsigned char PCA_id, unsigned int high)
// ����: ����ռ�ձ����ݡ�
// ����: high: 	ռ�ձ����ݣ���PWM����ߵ�ƽ��PCAʱ�����������
//       
//       
// ����: 
// �汾: VER1.0.0
// ����: 2018-12-20
// ����: PineconePi
// ��ע:
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
		if(high > PWM0_HIGH_MAX)	high = PWM0_HIGH_MAX;	//���д��������ռ�ձ����ݣ�ǿ��Ϊ���ռ�ձȡ�
		if(high < PWM0_HIGH_MIN)	high = PWM0_HIGH_MIN;	//���д��С����Сռ�ձ����ݣ��򷵻ش������2��
		CR = 0;							//ֹͣPCA��
		PCA_Timer0 = high;				//��������ȷ��Χ����װ��ռ�ձȼĴ�����
		PWM0_low = PWM0_DUTY - high;	//���㲢����PWM����͵�ƽ��PCAʱ�����������
		CR = 1;							//����PCA��
	}
	else if(PCA_id == PCA1)
	{
		if(high > PWM1_HIGH_MAX)	high = PWM1_HIGH_MAX;	//���д��������ռ�ձ����ݣ�ǿ��Ϊ���ռ�ձȡ�
		if(high < PWM1_HIGH_MIN)	high = PWM1_HIGH_MIN;	//���д��С����Сռ�ձ����ݣ��򷵻ش������2��
		CR = 0;							//ֹͣPCA��
		PCA_Timer1 = high;				//��������ȷ��Χ����װ��ռ�ձȼĴ�����
		PWM1_low = PWM1_DUTY - high;	//���㲢����PWM����͵�ƽ��PCAʱ�����������
		CR = 1;							//����PCA��
	}
	else if(PCA_id == PCA2)
	{
		if(high > PWM2_HIGH_MAX)		high = PWM2_HIGH_MAX;	//���д��������ռ�ձ����ݣ�ǿ��Ϊ���ռ�ձȡ�
		if(high < PWM2_HIGH_MIN)		high = PWM2_HIGH_MIN;	//���д��С����Сռ�ձ����ݣ��򷵻ش������2��
		CR = 0;						//ֹͣPCA��
		PCA_Timer2 = high;						//��������ȷ��Χ����װ��ռ�ձȼĴ�����
		PWM2_low = PWM2_DUTY - high;				//���㲢����PWM����͵�ƽ��PCAʱ�����������
		CR = 1;						//����PCA��
	}
}


//========================================================================
// ����: UpdatePwm(unsigned char PCA_id, unsigned char pwm_value)
// ����: ����PWMֵ. 
// ����: PCA_id: PCA���. ȡֵ PCA0,PCA1,PCA2,PCA_Counter
//       pwm_value: pwmֵ, ���ֵ������͵�ƽ��ʱ��.
//       
// ����: 
// �汾: VER1.0.0
// ����: 2018-12-20
// ����: PineconePi
// ��ע:
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
// ����: void	PCA_Init(PCA_id, PCA_InitTypeDef *PCAx)
// ����: PCA��ʼ������. 
// ����: PCA_id: PCA���. ȡֵ PCA0,PCA1,PCA2,PCA_Counter
//       PCAx: �ṹ����,��ο�PCA.h��Ľṹ�嶨��.
//       
// ����: 
// �汾: VER1.0.0
// ����: 2018-12-20
// ����: PineconePi
// ��ע:
//	
//	
//	
//	
//	
//========================================================================
void	PCA_Init(unsigned char PCA_id, PCA_InitTypeDef *PCAx)
{
	if(PCA_id > PCA_Counter)	return;		//id����

	if(PCA_id == PCA_Counter)			//���ù���Counter
	{
		CR = 0;
		CH = 0;
		CL = 0;
		P_SW1 = PCAx->PCA_IoUse;			//�л�IO��
		CMOD  = (CMOD  & ~(7<<1)) | PCAx->PCA_Clock;			//ѡ��ʱ��Դ
		CMOD  = (CMOD  & ~1) | (PCAx->PCA_Interrupt_Mode & 1);	//ECF
		if(PCAx->PCA_Polity == PolityHigh)		PPCA = 1;	//�����ȼ��ж�
		else									PPCA = 0;	//�����ȼ��ж�
		CR = 1;
		return;
	}

	PCAx->PCA_Interrupt_Mode &= (3<<4) + 1;
	if(PCAx->PCA_Mode >= PCA_Mode_SoftTimer)	PCAx->PCA_Interrupt_Mode &= ~(3<<4);

	if(PCA_id == PCA0)
	{
		CCAPM0    = PCAx->PCA_Mode | PCAx->PCA_Interrupt_Mode;	//����ģʽ, �ж�ģʽ
		PCA_PWM0  = (PCA_PWM0 & ~(3<<6)) | PCAx->PCA_PWM_Wide;	//PWM���

		PCA_Timer0 = PCAx->PCA_Value;
		B_Capture0 = 0;
		PCA0_mode = PCAx->PCA_Mode;
		CCAP0_tmp = PCA_Timer0;
		CCAP0L = (unsigned char)CCAP0_tmp;			//��Ӱ��Ĵ���д�벶��Ĵ�������дCCAP0L
		CCAP0H = (unsigned char)(CCAP0_tmp >> 8);	//��дCCAP0H
	}
	if(PCA_id == PCA1)
	{
		CCAPM1    = PCAx->PCA_Mode | PCAx->PCA_Interrupt_Mode;
		PCA_PWM1  = (PCA_PWM1 & ~(3<<6)) | PCAx->PCA_PWM_Wide;

		PCA_Timer1 = PCAx->PCA_Value;
		B_Capture1 = 0;
		PCA1_mode = PCAx->PCA_Mode;
		CCAP1_tmp = PCA_Timer1;
		CCAP1L = (unsigned char)CCAP1_tmp;			//��Ӱ��Ĵ���д�벶��Ĵ�������дCCAP0L
		CCAP1H = (unsigned char)(CCAP1_tmp >> 8);	//��дCCAP0H
	}
	if(PCA_id == PCA2)
	{
		CCAPM2    = PCAx->PCA_Mode | PCAx->PCA_Interrupt_Mode;
		PCA_PWM2  = (PCA_PWM2 & ~(3<<6)) | PCAx->PCA_PWM_Wide;

		PCA_Timer2 = PCAx->PCA_Value;
		B_Capture2 = 0;
		PCA2_mode = PCAx->PCA_Mode;
		CCAP2_tmp = PCA_Timer2;
		CCAP2L = (unsigned char)CCAP2_tmp;			//��Ӱ��Ĵ���д�벶��Ĵ�������дCCAP0L
		CCAP2H = (unsigned char)(CCAP2_tmp >> 8);	//��дCCAP0H
	}
}

