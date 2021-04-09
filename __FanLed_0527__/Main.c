/*sample.c*/
#include <hic.h>
#include "init.h"


u8	LeafLevel				= LeafLevel_0;				//
u8	LampLevel				= LampLevel_0;				//

u16 TimCnt_Base			= 0;
u8	TimCnt_Light		= 0;
u8	TimCnt_Shake		= 0;
u8	TimCnt_Shine		= 0;
u8	TimCnt_Speed		= 0;
u8	TimCnt_Water		= 0;
u8	TimCnt_ADChk		= 0;


u16	ADRegist				= 0;



extern void InitialMCU();
extern void SwayControl(u8 spd);
extern void LeafControl(u8 spd);



void isr(void) interrupt
{
	if(T8P1PIE & T8P1PIF) {		//���T8P1�ж�ʹ�ܣ���T8P1�����ж���1
		T8P1PIF = 0;						//����������־λ

		TimCnt_Base++;
		if(IsCircle) {
			if(++TimCnt_Pulse > 3) {
				TimFlg_Pulse = 1;
				TimCnt_Pulse = 0;
			}
		}
		

		if(TimCnt_Base >= 50)	{	//20msΪ��λ
			TimCnt_Base = 0;

		
	
			//��˸��ʱ--���ʱ����
			if(TimReq_Shine) {
				if(++TimCnt_Shine > 10) {
					TimFlg_Shine		= 1;
					TimCnt_Shine		= 0;
				}
			}


			//��ˮ�Ƽ�ʱ--����4��ʱ����
			if(TimReq_Water) {
				if(++TimCnt_Water > 10) {
					TimFlg_Water		= 1;
					TimCnt_Water		= 0;
				}		
			}


			//����������ʱ
			if(TimReq_Speed) {		//��ʼ��ʱ
				if(++TimCnt_Speed > 10) {		//ʱ�䵽
					
					TimFlg_Speed		= 1;
					TimCnt_Speed		= 0;
					TimReq_Speed		= 0;
				} 
			}

			//��������
			if(TimReq_Light) {		//��ʼ��ʱ
				if(++TimCnt_Light > 10) {		//ʱ�䵽
					
					TimFlg_Light		= 1;
					TimCnt_Light		= 0;
					TimReq_Light		= 0;
				} 
			}

			//ת�򰴼�
			if(TimReq_Shake) {		//��ʼ��ʱ
				if(++TimCnt_Shake > 10) {		//ʱ�䵽
					
					TimFlg_Shake		= 1;
					TimCnt_Shake		= 0;
					TimReq_Shake		= 0;
				} 
			}


			#if 0		//
			//AD�ɼ���ʱ--�Ե�ص�����ת��ʱ�ĵ�ѹ����
			if(TimReq_ADChk) {		//AD�ɼ���ʱ��ʼ
				if(++TimCnt_ADChk > 10) {
					TimFlg_ADChk		= 1;
					TimCnt_ADChk		= 0;
				}
			
			}
			#endif

		}		
	}


	//ADת�����
	if(ADIE && ADIF) {
		ADIF = 0;			//���жϱ�־

		ADRegist			= (ADCRH << 4) | ADCRL;
		TimFlg_ADChk	= 0;
		TimCnt_ADChk	= 0; 

		EveFlg_ADChk	= 1;		//ADת�����
	
	}


	//�˿��жϿ�����2��ѡ��
	if(KIE & KIF) {				//���ʹ��4�������ж�KINT0-7
		//�������Ӧ�˿���һ�ζ�д�������Ը�λ�жϱ�־




		KIF = 0;	
	}
	
	//���ʹ��4���ⲿ�ж�PINT0-3
	if(KeySpeed_IE && KeySpeed_IF) {
		KeySpeed_IF			= 0;			//����жϱ�־

		//���δ��ʼ��ʱ���ұ�־λδ��λ
		//˵���ǰ�����һ�ε���Ч��ƽ
		if(TimReq_Speed == 0 && TimFlg_Speed == 0) {
			TimReq_Speed	= 1;					//�����ʱ
			TimCnt_Speed	= 0;					//��ʱ������
		}
	}

	if(KeyLight_IE && KeyLight_IF) {
		KeyLight_IF			= 0;

		if(TimReq_Light == 0 && TimFlg_Light == 0) {
			TimReq_Light	= 1;
			TimCnt_Light	= 0;
		}
	}

	if(KeyShake_IE && KeyShake_IF) {
		KeyShake_IF			= 0;

		if(TimReq_Shake == 0 && TimFlg_Shake == 0) {
			TimReq_Shake	= 1;
			TimCnt_Shake	= 0;
		}
	}

}



/************************************************************


************************************************************/

void main(void)
{
//	InitialMCU();

	/*״̬��ʼ��*/

	for(;;) {
		CLRWDT();			//����WDT���������Ա��ⲻ��Ҫ�ĸ�λ
		RCEN = 1;			//WDT��ʱ������ʱ��������1
	
		/*���ڼ��*/
		if(PinCharging == Charging_ActLvl) {		//�����
			if(PinCharged == Charged_ActLvl) {		//����
				if(LeafLevel == LeafLevel_0) {			//δ����


				} else {
					//���ȹ�����

				}
				
			} else {															//δ����
				if(LeafLevel == LeafLevel_0) {			//����δ����
					//��ʱָʾ���Ժ�ɫ��˸1��


				} else {	
					//���ȹ����а�ɫ��ʾ����

				}

			}
		} 


		/*�������*/
		#if 0				//Ŀǰû��Ҫ��
		if(TimFlg_Speed && TimFlg_Light && TimFlg_Shake) {		//ͬʱ
			TimFlg_Speed = 0;
			TimFlg_Light = 0;
			TimFlg_Shake = 0;

		}		

		if(TimFlg_Speed && TimFlg_Light) {		//����ͬʱ
			TimFlg_Speed = 0;
			TimFlg_Light = 0;
		
		}	
		#endif

		if(TimFlg_Speed) {				//��λ��
			TimFlg_Speed = 0;

			LeafLevel = (LeafLevel + 1)%LeafLevel_n;
			if(LeafLevel == LeafLevel_0) {			//ͣ����
				IsCircle = 0;				//ҡͷ��־����
				SwayControl(0);			//ҡͷֹͣ
			}
			LeafControl(LeafLevel);		//��λ����


		}
		
		if(TimFlg_Light) {			//������
			TimFlg_Light = 0;
		
		}

		if(TimFlg_Shake) {			//ҡͷ��
			TimFlg_Shake = 0;

			if(LeafLevel != LeafLevel_0) {
				IsCircle = ~IsCircle;		//IsCircle ^= 1;					
						
			}
		}


		/*AD���*/
		#if 0			//��������ͬʱ�������
		if(EveFlg_ADChk) {						//AD���������
			if(++EveCnt_ADChk < 5) {		//ת����
				if(ADRegist > SwayVal_Limit) {
					//ת��

				}
			
			} else {
				EveCnt_ADChk = 0;					//�������

				if(ADRegist < BattVal_Level_0) {
				
				} else if(ADRegist < BattVal_Level_1) {
				
				} else if(ADRegist < BattVal_Level_2) {
				
				} else if(ADRegist < BattVal_Level_3) {
				
				} else {
				
				}
			}	
		
		}

		#else

		if(EveFlg_ADChk) {						//AD������
			if(IsCharge) {							//��������ֻ������
				if(ADRegist < BattVal_Level_0) {
					//led1��
				} else if(ADRegist < BattVal_Level_1) {
					//led1��2��
				} else if(ADRegist < BattVal_Level_2) {
					//led1��2��3��
				} else {
				
				}

			} else {										//δ���ʱ����ת�ٲ�Ϊ0�����ת��
				if(MotSpeed_ActLvl == LeafLevel_0) {
					//led1,2,3ȫ��

				} else if(MotSpeed_ActLvl == LeafLevel_1) {
					//led1��

				} else if(MotSpeed_ActLvl == LeafLevel_2) {
					//led2��

				} else if(MotSpeed_ActLvl == LeafLevel_3) {
					//led3��

				} else if(MotSpeed_ActLvl == LeafLevel_4) {
					//led1,2,3��ˮ

				} else {
				
				}
			
			}
		
		}

		#endif

		NOP();
		NOP();
	}

}


#if OLDEST


extern void ADCharge();
extern void GetsysStatus();
extern void KeyScan();
extern void PWMOut();
extern void PWMChange(); 

extern void BatStatus();
extern void PreBatLv();
extern void DisPlay();
extern void GetsysDisCharge(); 
extern void lowBatCheck();
extern void PWMOutCheck();
extern void PWMChange();
extern void GetPWMCharge();
extern void TYNDisCharge();  //  ̫����״̬ת��
extern void TYNChargeDuty(); 
extern void TYNDisPlay();


void isr(void) interrupt
{
	if(T8P1PIE & T8P1PIF) {		//���T8P1�ж�ʹ�ܣ���T8P1�����ж���1
		T8P1PIF = 0;						//����������־λ
		FlagSys250us = 1;				//��ʱ��־��λ
		CntSysClk2ms++;					//��ʱ�����Լ�

		if(CntSysClk2ms >= 10) {		//20ms��
			CntSysClk2ms = 0;					//���¼�ʱ
			FlagSysClk2ms = 1;				//��־��λ
			CntSysClk10ms++;					//�൱��20ms��һ��

			if(CntSysClk10ms >= 5) {  //100ms��
				CntSysClk10ms = 0;
				FlagSysClk10ms = 1;
				CntSysClk50ms++;
				if(CntSysClk50ms >= 5) {  //COUNT_DELAY = 10
					FlagSysClk50ms = 1;
					CntSysClk50ms = 0;
					CntSysClk500ms++;
					if(CntSysClk500ms >= 10) {
						CntSysClk500ms = 0;
						FlagSysClk500ms = 1;
						CntSysClk1s++;
						if(CntSysClk1s >= 2) {
							CntSysClk1s = 0;
							FlagSysClk1s = 1;
						}
					}				
				}
			}
		}
	}
	
	if(KIE & KIF) {				//��������ж�ʹ�ܣ��ұ�־λ��λ
		PABuf = PA;         //ȡ���ŵ�ƽ 
		KIF = 0;						//��־λ����
	}       
}

void main() {
	InitialMCU();

	while(1) {
		CLRWDT();			//����WDT���������Ա��ⲻ��Ҫ�ĸ�λ
		RCEN = 1;			//WDT��ʱ������ʱ��������1
		if(FlagSys250us) {
			FlagSys250us = 0;
			TYNDisPlay();
		}

		if(FlagSysClk2ms) {
			FlagSysClk2ms = 0;
			//		NOP();
			ADCharge();
			//		NOP();    //  0.1013 ms
			KeyScan();
			//		NOP();   //  0.0023ms			
		}

		if(FlagSysClk10ms) {
			FlagSysClk10ms = 0;
			TYNChargeDuty();  //̫���ܷŵ���ʾ
		}

		if(FlagSysClk50ms) {
			FlagSysClk50ms = 0;
			GetsysStatus();    // ����ж�
			//		NOP();      // 0.0065 ms
			GetsysDisCharge();  //�ŵ紦��
			//		NOP();      // 0.0358ms
			PreBatLv();      //��ص�ѹ���
			//		NOP();    // 0.0083ms
			lowBatCheck();
			//		NOP();    //0.0023ms			
			//		NOP();   //0.0025ms
		} 

		if(FlagSysClk500ms) {	
			FlagSysClk500ms = 0;
			TYNDisCharge();     //  ̫����״̬ת��
			//		NOP();    //0.0253ms
			DisPlay();
			//		NOP();     //0.0053
		}

		if(FlagSysClk1s)
			FlagSysClk1s = 0;

		NOP();
	}
}  
#endif
