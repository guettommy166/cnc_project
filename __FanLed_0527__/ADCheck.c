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
	//1，AD转换时钟		ADCCH.ADCS
	ADCS0 = 0;		//000-Fosc
	ADCS1 = 0;
	ADCS2 = 0;

	//2，参考电压			ADCCL.ADVREFS
	ADVREFS0 = 0;		//000-参考电压源正端VDD，负端VSS
	ADVREFS1 = 0;
	ADVREFS2 = 0;

	//3，采样时间			ADCCH.ADST
	ADST0 = 0;			//1000-8个ADC时钟
	ADST1 = 0;
	ADST2 = 0;
	ADST3 = 1;

	//4，端口选择			ANS
	PinBattery_MOD = 0;		//模拟端口

	//5，通道选择			ADCCCL.ADCHS
	ADCHS0 = 0;				//AIN0
	ADCHS1 = 0;
	ADCHS2 = 0;

	//6，转换结果			ADCCH.ADFM
	ADFM = 0;					//高位对齐

	//7，中断可选			INTE0.ADIE
	ADIE = 1;
	//8，AD使能				ADCCL.ADEN

	//9，触发方式			ADCCL.ADTRG or ADCCL.TRIGEN

	//10,状态轮询			ADCCL.ADTRG

	//11,读取结果			ADCRH ADCRL
	#endif


	#if 0		//查询方式
	PinSwaying_MOD	= 0;		//摇头模拟
	ADCCH	= ADFM_H | ADCS_FOSC_08 | ADST_8;	//数据格式，时钟，采样
	ADCCL = ADVR_VDD_VSS | PinSwaying_CHN;	//参考电压，通道

	ADTRG = 1;		//启动AD转换
	#else
	PinSwaying_MOD	= 0;		//摇头模拟
	ADCCH	= ADFM_H | ADCS_FOSC_08 | ADST_8;	//数据格式，时钟，采样
	ADCCL = ADVR_VDD_VSS | PinSwaying_CHN;	//参考电压，通道
	ADIE = 1;			//还须使能全局中断
	ADTRG = 1;		//启动AD转换
	
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
#if 1			//软启动，查询方式
	while(1) {
		if(ADTRG == 0) {		//等待AD转换完成
			ADRegist = (ADCRH << 4) | ADCRL;
			ADTRG = 1;				//再次软件启动转换
		}
	}
#else			//软启动中断方式

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