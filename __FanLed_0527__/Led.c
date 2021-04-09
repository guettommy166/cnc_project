//Light.c
//
#include "init.h"

/**********************************************
;* 
;* Fun:		LedReffer_Init
;* Arg:		None
;* Ret:		None
;* Des:		Led refferring initialization
;*	
;**********************************************/

void LedReffer_Init(void)
{
	PinLed_Sign01 = !LedSign01_ActLvl;
	PinLed_Sign02 = !LedSign02_ActLvl;
	PinLed_Sign03 = !LedSign03_ActLvl;
}



/**********************************************
;* 
;* Fun:  
;* Arg:		None
;* Ret:		None
;* Des:
;*	
;**********************************************/

void LedReffer_RShine(void)
{


}



/**********************************************
;* 
;* Fun:  
;* Arg:		None
;* Ret:		None
;* Des:
;*	
;**********************************************/

void LedReffer_Wlevel(u8 spd)
{
		switch(spd) {
			case LeafLevel_0: {
				PinLed_Sign01 = !LedSign01_ActLvl;
				PinLed_Sign02 = !LedSign01_ActLvl;
				PinLed_Sign03 = !LedSign01_ActLvl;

			} break;

			case LeafLevel_1: {
				PinLed_Sign01 = LedSign01_ActLvl;
				PinLed_Sign02 = !LedSign01_ActLvl;
				PinLed_Sign03 = !LedSign01_ActLvl;

			} break;

			case LeafLevel_2: {
				PinLed_Sign01 = !LedSign01_ActLvl;
				PinLed_Sign02 = LedSign01_ActLvl;
				PinLed_Sign03 = !LedSign01_ActLvl;
			} break;

			case LeafLevel_3: {
				PinLed_Sign01 = !LedSign01_ActLvl;
				PinLed_Sign02 = !LedSign01_ActLvl;
				PinLed_Sign03 = LedSign01_ActLvl;
			} break;
		
			default: {
				PinLed_Sign01 = !LedSign01_ActLvl;
				PinLed_Sign02 = !LedSign01_ActLvl;
				PinLed_Sign03 = !LedSign01_ActLvl;
			} break;
		}
}


/**********************************************
;* 
;* Fun:  
;* Arg:		None
;* Ret:		None
;* Des:
;*	
;**********************************************/

void LedButton_Init(void)
{
	PinLed_Button = !LedButton_ActLvl;
}


/**********************************************
;* 
;* Fun:  
;* Arg:		None
;* Ret:		None
;* Des:
;*	
;**********************************************/

void LedButton_Control(u8 mod)
{
	if(mod) {
		PinLed_Button = LedButton_ActLvl;
	} else {
		PinLed_Button = !LedButton_ActLvl;
	}
}


/**********************************************
;* 
;* Fun:  
;* Arg:		None
;* Ret:		None
;* Des:
;*	
;**********************************************/

void LedBright_Init(void)
{
	PinLed_Bright = !LedBright_ActLvl;
	PinLedBright_MOD = 1;		//���ֶ˿�
	PinLedBright_DIR = 0;		//���
}


/**********************************************
;* 
;* Fun:  
;* Arg:		None
;* Ret:		None
;* Des:
;*	
;**********************************************/
void LedBright_Control(u8 lvl)
{
	switch(lvl) {
		case 0: {
			
		} break;

		default: {
	
		} break;
	
	}
}



/**********************************************
Tim
1����Ҫ��ϵͳ����
2�����ö�Ӧ�˿�Ϊ����ģʽ
3����ʼ���˿ڵ�ƽ
4�����ó����
5������pwm����
6������ռ�ձ�
7�������������


T8Pn		������
T8PnP		���ڼĴ���
T8PnR		���ȼĴ���
T8PnC		���ƣ�ģʽ ���Ƶ ʹ�� Ԥ��Ƶ
T8PnPEX	���Ƶ��չ
T8PnPMC	����ƥ��ѡ���PWM�������ѡ��
T8PnOC	������ƣ����ʹ�� ������չ �������
T8PnPDT	��������



Pwm
1����Ҫ��ϵͳ����
2�����ö�Ӧ�˿�Ϊ����ģʽ
3����ʼ���˿ڵ�ƽ
4�����ó����
5������pwm����
6������ռ�ձ�
7�������������

;**********************************************/