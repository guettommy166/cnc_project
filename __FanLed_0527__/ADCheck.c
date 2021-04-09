//ADCheck.c
//

#include "Init.h"

/**********************************************
;* 
;* Fun:  
;* Arg:		None
;* Ret:		None
;* Des:
;*	
;**********************************************/
void ADBatt_Init(void)
{
	#if 0
	//1��ADת��ʱ��		ADCCH.ADCS
	ADCS0 = 0;		//000-Fosc
	ADCS1 = 0;
	ADCS2 = 0;

	//2���ο���ѹ			ADCCL.ADVREFS
	ADVREFS0 = 0;		//000-�ο���ѹԴ����VDD������VSS
	ADVREFS1 = 0;
	ADVREFS2 = 0;

	//3������ʱ��			ADCCH.ADST
	ADST0 = 0;			//1000-8��ADCʱ��
	ADST1 = 0;
	ADST2 = 0;
	ADST3 = 1;

	//4���˿�ѡ��			ANS
	PinBattery_MOD = 0;		//ģ��˿�

	//5��ͨ��ѡ��			ADCCCL.ADCHS
	ADCHS0 = 0;				//AIN0
	ADCHS1 = 0;
	ADCHS2 = 0;

	//6��ת�����			ADCCH.ADFM
	ADFM = 0;					//��λ����

	//7���жϿ�ѡ			INTE0.ADIE
	ADIE = 1;
	//8��ADʹ��				ADCCL.ADEN

	//9��������ʽ			ADCCL.ADTRG or ADCCL.TRIGEN

	//10,״̬��ѯ			ADCCL.ADTRG

	//11,��ȡ���			ADCRH ADCRL
	#endif


	#if 0		//��ѯ��ʽ
	PinSwaying_MOD	= 0;		//ҡͷģ��
	ADCCH	= ADFM_H | ADCS_FOSC_08 | ADST_8;	//���ݸ�ʽ��ʱ�ӣ�����
	ADCCL = ADVR_VDD_VSS | PinSwaying_CHN;	//�ο���ѹ��ͨ��

	ADTRG = 1;		//����ADת��
	#else
	PinSwaying_MOD	= 0;		//ҡͷģ��
	ADCCH	= ADFM_H | ADCS_FOSC_08 | ADST_8;	//���ݸ�ʽ��ʱ�ӣ�����
	ADCCL = ADVR_VDD_VSS | PinSwaying_CHN;	//�ο���ѹ��ͨ��
	ADIE = 1;			//����ʹ��ȫ���ж�
	ADTRG = 1;		//����ADת��
	
	#endif
}



/**********************************************
;* 
;* Fun:  
;* Arg:		None
;* Ret:		None
;* Des:
;*	
;**********************************************/
void BattCheck(void)
{
#if 1			//����������ѯ��ʽ
	while(1) {
		if(ADTRG == 0) {		//�ȴ�ADת�����
			ADRegist = (ADCRH << 4) | ADCRL;
			ADTRG = 1;				//�ٴ��������ת��
		}
	}
#else			//�������жϷ�ʽ

#endif

}



/**********************************************
;* 
;* Fun:  
;* Arg:		None
;* Ret:		None
;* Des:
;*	
;**********************************************/
void ADSway_Init(void)
{


}



/**********************************************
;* 
;* Fun:  
;* Arg:		None
;* Ret:		None
;* Des:		Judge if sway is needed
;*	
;**********************************************/
void SwayCheck(void)
{


}