#include <hal_key.h>
#include "gizwits_protocol.h"


unsigned char	skeycount;		//���ð���ʱ��������
unsigned char	skpttime;		//���ð���ʱ��
unsigned char	longflag;		//���ó�����־
unsigned char	sflag;			//������ʾ״̬��־,0-��ͨ����,1-��ʱ����,2-����ʱ������
bit		skpflag;				//���ð������±�־



		
void delay1ms(unsigned char ms);//��ʱ����
void setkeyscan();				//���ü���ɨ���жϺ���
void pro_sklp();				//�������ù��ܼ��Ĵ�����
void pro_sksp();				//�̰����ù��ܼ��Ĵ�����


 
//=======�ӳ���==================================
/*��⼰����๦�����ð���k2*/
void setkeyscan()
{
	if (skpflag)										//�ж��Ƿ��Ѿ��м�����δ������
	{
		if(skeycount>LONGPRESS)							//����ǳ�����ִ�г��������ù���
		{
			pro_sklp();
			skpflag=0;
			longflag=1;
		}
		else if((skpttime>0) && (skpttime<=LONGPRESS))	//��������Ƕ̰���ִ�ж̰��Ĺ���,������ֱ������
		{
			pro_sksp();
			skpflag=0;
		}
	}
	else
	{
		if(!SETKEY)								//�������ü�
		{
			delay1ms(10);						//���̷���
			if((!SETKEY)&&longflag == 0)
			{
				skeycount=0;					//��ʼ������ʱ��������
				skpttime=0;						//��ʼ������ʱ��
				skpflag=1;						//��־�Ѿ��м�������
				longflag=0;
			}
		}else{
                        longflag=0;
              	}
	}
}


/* ��ʱ����*/
void delay1ms(unsigned char ms)
{	while(ms--)						//ÿѭ��һ��,Լ�ӳ�1ms
	{	unsigned char i;
		for(i = 0; i< 250; i++)     //ѭ��250��,��12M����ʱԼ��ʱ1ms
		{
			_nop_();			   //ִ��һ��_nop_()ָ��Ϊһ����������
			_nop_();
			_nop_();
			_nop_();
		}
	}
}		
	

/*(�̰�k2)*/
void pro_sksp()
{
	sflag=0;								//����״̬��־
	//����Ϊ�̰����Ĵ������
	gizwitsSetMode(WIFI_AIRLINK_MODE);//����airlink����ģʽ
}


/*(����k2)*/
void pro_sklp()
{
	sflag=0;								//����״̬��־
	//����Ϊ�������Ĵ������
	gizwitsSetMode(WIFI_RESET_MODE);//resetģ��

}

void key_init()
{
	skeycount=0;						//��ʼ�����ܼ�����ʱ��������
	skpttime=0;							//��ʼ�����ܼ����µ���ʱ��
	sflag=0;							//��ʼ����ʾ״̬��־,0-��ͨ����,1-��ʱ����,2-����ʱ������
	SETKEY=1;							//k2,����Ϊ����˿�
	longflag =0;
}

