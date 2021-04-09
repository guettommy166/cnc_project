//module.c
#include <hic.h>

/*********************************************
;* Include headfiles 
;********************************************/
#include"init.h"


/*********************************************
;* Private variables 
;********************************************/


/**********************************************
;* 
;* Function Name: RAM_HR7P153_CLEAR routine
;* Inputs:        None
;* Returns:       None
;* Description:   the RAM_HR7P153_CLEAR process
;*	
;**********************************************/

void RAM_HR7P153_CLEAR(void)
{
	__asm
	{
		MOVI    0x00
		MOVA    IAAH
		MOVI    0x00
		MOVA    IAAL 

		RAM0_CLEAR:
		CLR     IAD               
		INC     IAAL,1
		JBS     IAAL,6
		GOTO    RAM0_CLEAR
	}		
}
		     // IAAH  IAAL  ��0
	         // ���section��RAM����0x00-0x7f
		 
/**********************************************
;* 
;* Function Name: InitUser routine
;* Inputs:        None
;* Returns:       None
;* Description:   the InitUser process
;*	
;**********************************************/

void  InitUser(void)
{
    CLRWDT();
    //FlagNow = 1;   
}

/**********************************************
;* 
;* Function Name: InitialMCU routine
;* Inputs:        None
;* Returns:       None
;* Description:   the InitialMCU process
;*	
;**********************************************/

void InitialMCU(void)
{
	/*CLK*/
	OSCP		= 0x55;		//����ʱ�ӿ���д��������OSCCд�����Զ���λ
	OSCC		= 0xE0;		//�л���8M����ʱ�ӣ�ʱ�ӿ��ƼĴ���
										//OSCCʱ�ӿ��ƼĴ������л����ٻ����ʱ��Դ��Ƶ��ѡ��
										//����ѡ���ڲ�����16MHz��Ϊϵͳʱ��Դ��ʹ��8MHzʱ��
	while(!SW_HS);		//�ȴ�����ʱ���л����
	 
	/*WDT*/
	WDTC		= 0x17;		//ʹ��WDTԤ��Ƶ����Ԥ��Ƶ��Ϊ1��256
//	SREN		= 1;		//�͵�ѹ��λʹ��
	RCEN		= 1;			//WDT�ڲ�RCʱ��ʹ��
	LPM			= 0;			//����ģʽĬ��0ģʽ


	/*PORT*/
	ANS			= 0x3a;		//�˿�����ѡ�� 0011_1010  ����PA7 PB1 PB0 PA2 PA1 PA0
										//����PA7 PB1 PB0 PA1Ϊ���ֶ˿ڣ�PA2 PA0Ϊģ��˿�
	PA			= 0x00;		//�˿ڵ�ƽ״̬�Ĵ���        
	PAT			= 0x2f;		//�˿������������ 0010_1111    PA5 PA3 PA2 PA1 PA0 Ϊ���룬����Ϊ���
										//����PA3�κ�ʱ��ֻ����������
	N_PAU		= 0xf7;		//�˿����������� 1111_0111  PA3������ʹ�ܣ������ֹ 

	PB			= 0x00;		//0000_0000           
	PBT			= 0x00;		//0000_0000
	N_PBU		= 0xff;		//ȫ��������ʹ��

	ADCCL		= 0x61;		//0110_0001 ADC��������8λ������ѡ��ο���ѹ��ͨ����ת��������ʹ��
										//011 �ο���ѹ2.1V  000 ͨ��ΪAIN0����ӦPA0�� 0 ֹͣת�� 1ʹ��ADC
	ADCCH		= 0xB8;		//1011_1000 ADC��������8λ������ת����ʽ��ʱ�ӣ�����ʱ��
										//1 ��λ����   011 ��8��Ƶ   1000 ����ʱ��Ϊ8��ADCʱ��
	

	/*TIM*/
	INTG		= 0x00;		//Ĭ���ж�ģʽ���ж���ڵ�ַ 0x004
	T8P1PMC	= 0x00;		//����ƥ����ƣ�����pwmģʽ�¾��ȣ���ʱģʽ������ƥ��ѡ��
	T8P1OC	= 0x00;		//������ƼĴ����������pwmģʽ�����������ʹ�ܣ����ȣ����ŵ�
	T8P1P		= 199;		//����ʱ��Ϊ4MHz��Ԥ��Ƶ��1MHz��һ�ζ�ʱ1us����200us
										//Ҳ���ǣ�T8P1ÿ200us��λT8P1PIF��ͬʱ��T8P1��λ�ؼ�ʱ�����Ƶ����1
	T8P1C		= 0x05;		//���� T8P1 ��ʱ��ģʽ�����Ƶ 1:1��ʹ�ܣ���Ԥ��Ƶ 1:4 
	T8P1PEX = 0x00;		//����б�Ҫ�����ú��Ƶ����չ�Ĵ���
										//������Ƶ������ֵ����Ƶ����ͬ����λ���Ƶ��������T8P1TIF
	T8P1PIF	= 0;			//��� T8P1 �жϱ�־
	T8P1PIE	= 1;			//ʹ�� T8P1 �����ж�
	

//	LVDC	= 0x00;
//	PWRC	= 0x48;
//	WKDC	= 0x55;

	RAM_HR7P153_CLEAR();	//SRAM��ʼ��

	/* Interrupt */
	INTC0		= 0x2A;		//KINT�жϿ����� 0010_1010��ֹ�ڱ�KINT5 3 1�ж�
	INTC1		= 0x00;		//PINT�жϴ�������ѡ��
	INTF0		= 0x00;		//��Ҫ�������жϱ�־
	INTF1		= 0x00;		//��������жϱ�־
	INTE0		= 0x41;		//KINT TINT ADINT�ж�ʹ�� 0100_0001��ʹ��T8P1�жϺ�KINT
	INTE1		= 0x00;		//PINT�ж�ʹ�� �����ֹ����PINT�жϣ���PINT3-0
	
	while(GIE == 1)
		GIE		= 0;

	GIE			= 1;			//ʹ�����ж�

	InitUser();				//�ٴ�����WDT���������Ա��ⲻ��Ҫ�ĸ�λ
	
}

