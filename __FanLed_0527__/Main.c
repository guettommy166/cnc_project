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
	if(T8P1PIE & T8P1PIF) {		//如果T8P1中断使能，且T8P1周期中断置1
		T8P1PIF = 0;						//须软件清除标志位

		TimCnt_Base++;
		if(IsCircle) {
			if(++TimCnt_Pulse > 3) {
				TimFlg_Pulse = 1;
				TimCnt_Pulse = 0;
			}
		}
		

		if(TimCnt_Base >= 50)	{	//20ms为单位
			TimCnt_Base = 0;

		
	
			//闪烁计时--充电时才用
			if(TimReq_Shine) {
				if(++TimCnt_Shine > 10) {
					TimFlg_Shine		= 1;
					TimCnt_Shine		= 0;
				}
			}


			//流水灯计时--风速4档时才用
			if(TimReq_Water) {
				if(++TimCnt_Water > 10) {
					TimFlg_Water		= 1;
					TimCnt_Water		= 0;
				}		
			}


			//风力按键计时
			if(TimReq_Speed) {		//开始计时
				if(++TimCnt_Speed > 10) {		//时间到
					
					TimFlg_Speed		= 1;
					TimCnt_Speed		= 0;
					TimReq_Speed		= 0;
				} 
			}

			//照明按键
			if(TimReq_Light) {		//开始计时
				if(++TimCnt_Light > 10) {		//时间到
					
					TimFlg_Light		= 1;
					TimCnt_Light		= 0;
					TimReq_Light		= 0;
				} 
			}

			//转向按键
			if(TimReq_Shake) {		//开始计时
				if(++TimCnt_Shake > 10) {		//时间到
					
					TimFlg_Shake		= 1;
					TimCnt_Shake		= 0;
					TimReq_Shake		= 0;
				} 
			}


			#if 0		//
			//AD采集计时--对电池电量和转向时的电压测量
			if(TimReq_ADChk) {		//AD采集计时开始
				if(++TimCnt_ADChk > 10) {
					TimFlg_ADChk		= 1;
					TimCnt_ADChk		= 0;
				}
			
			}
			#endif

		}		
	}


	//AD转换完成
	if(ADIE && ADIF) {
		ADIF = 0;			//清中断标志

		ADRegist			= (ADCRH << 4) | ADCRL;
		TimFlg_ADChk	= 0;
		TimCnt_ADChk	= 0; 

		EveFlg_ADChk	= 1;		//AD转换完成
	
	}


	//端口中断可能有2种选择
	if(KIE & KIF) {				//如果使用4个按键中断KINT0-7
		//还须对相应端口作一次读写操作，以复位中断标志




		KIF = 0;	
	}
	
	//如果使用4个外部中断PINT0-3
	if(KeySpeed_IE && KeySpeed_IF) {
		KeySpeed_IF			= 0;			//清除中断标志

		//如果未开始计时，且标志位未置位
		//说明是按键第一次的有效电平
		if(TimReq_Speed == 0 && TimFlg_Speed == 0) {
			TimReq_Speed	= 1;					//请求计时
			TimCnt_Speed	= 0;					//计时器清零
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

	/*状态初始化*/

	for(;;) {
		CLRWDT();			//清零WDT计数器，以避免不必要的复位
		RCEN = 1;			//WDT定时器工作时，必须置1
	
		/*充电口检测*/
		if(PinCharging == Charging_ActLvl) {		//充电中
			if(PinCharged == Charged_ActLvl) {		//充满
				if(LeafLevel == LeafLevel_0) {			//未工作


				} else {
					//风扇工作中

				}
				
			} else {															//未充满
				if(LeafLevel == LeafLevel_0) {			//风扇未工作
					//此时指示灯以红色闪烁1秒


				} else {	
					//风扇工作中白色显示风力

				}

			}
		} 


		/*按键检测*/
		#if 0				//目前没有要求
		if(TimFlg_Speed && TimFlg_Light && TimFlg_Shake) {		//同时
			TimFlg_Speed = 0;
			TimFlg_Light = 0;
			TimFlg_Shake = 0;

		}		

		if(TimFlg_Speed && TimFlg_Light) {		//两个同时
			TimFlg_Speed = 0;
			TimFlg_Light = 0;
		
		}	
		#endif

		if(TimFlg_Speed) {				//档位键
			TimFlg_Speed = 0;

			LeafLevel = (LeafLevel + 1)%LeafLevel_n;
			if(LeafLevel == LeafLevel_0) {			//停机档
				IsCircle = 0;				//摇头标志清零
				SwayControl(0);			//摇头停止
			}
			LeafControl(LeafLevel);		//档位控制


		}
		
		if(TimFlg_Light) {			//照明键
			TimFlg_Light = 0;
		
		}

		if(TimFlg_Shake) {			//摇头键
			TimFlg_Shake = 0;

			if(LeafLevel != LeafLevel_0) {
				IsCircle = ~IsCircle;		//IsCircle ^= 1;					
						
			}
		}


		/*AD检测*/
		#if 0			//这里是在同时检测的情况
		if(EveFlg_ADChk) {						//AD如果检测完成
			if(++EveCnt_ADChk < 5) {		//转向检测
				if(ADRegist > SwayVal_Limit) {
					//转向

				}
			
			} else {
				EveCnt_ADChk = 0;					//电量检测

				if(ADRegist < BattVal_Level_0) {
				
				} else if(ADRegist < BattVal_Level_1) {
				
				} else if(ADRegist < BattVal_Level_2) {
				
				} else if(ADRegist < BattVal_Level_3) {
				
				} else {
				
				}
			}	
		
		}

		#else

		if(EveFlg_ADChk) {						//AD检测完成
			if(IsCharge) {							//充电情况下只检测电量
				if(ADRegist < BattVal_Level_0) {
					//led1闪
				} else if(ADRegist < BattVal_Level_1) {
					//led1，2闪
				} else if(ADRegist < BattVal_Level_2) {
					//led1，2，3闪
				} else {
				
				}

			} else {										//未充电时，且转速不为0，检测转向
				if(MotSpeed_ActLvl == LeafLevel_0) {
					//led1,2,3全灭

				} else if(MotSpeed_ActLvl == LeafLevel_1) {
					//led1亮

				} else if(MotSpeed_ActLvl == LeafLevel_2) {
					//led2亮

				} else if(MotSpeed_ActLvl == LeafLevel_3) {
					//led3亮

				} else if(MotSpeed_ActLvl == LeafLevel_4) {
					//led1,2,3流水

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
extern void TYNDisCharge();  //  太阳能状态转换
extern void TYNChargeDuty(); 
extern void TYNDisPlay();


void isr(void) interrupt
{
	if(T8P1PIE & T8P1PIF) {		//如果T8P1中断使能，且T8P1周期中断置1
		T8P1PIF = 0;						//须软件清除标志位
		FlagSys250us = 1;				//计时标志置位
		CntSysClk2ms++;					//计时个数自加

		if(CntSysClk2ms >= 10) {		//20ms到
			CntSysClk2ms = 0;					//重新计时
			FlagSysClk2ms = 1;				//标志置位
			CntSysClk10ms++;					//相当于20ms计一次

			if(CntSysClk10ms >= 5) {  //100ms到
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
	
	if(KIE & KIF) {				//如果按键中断使能，且标志位置位
		PABuf = PA;         //取引脚电平 
		KIF = 0;						//标志位清零
	}       
}

void main() {
	InitialMCU();

	while(1) {
		CLRWDT();			//清零WDT计数器，以避免不必要的复位
		RCEN = 1;			//WDT定时器工作时，必须置1
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
			TYNChargeDuty();  //太阳能放电显示
		}

		if(FlagSysClk50ms) {
			FlagSysClk50ms = 0;
			GetsysStatus();    // 充电判断
			//		NOP();      // 0.0065 ms
			GetsysDisCharge();  //放电处理
			//		NOP();      // 0.0358ms
			PreBatLv();      //电池电压检测
			//		NOP();    // 0.0083ms
			lowBatCheck();
			//		NOP();    //0.0023ms			
			//		NOP();   //0.0025ms
		} 

		if(FlagSysClk500ms) {	
			FlagSysClk500ms = 0;
			TYNDisCharge();     //  太阳能状态转换
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
