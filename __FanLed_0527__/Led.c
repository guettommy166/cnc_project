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
	PinLedBright_MOD = 1;		//数字端口
	PinLedBright_DIR = 0;		//输出
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
1，必要的系统设置
2，设置对应端口为数字模式
3，初始化端口电平
4，配置成输出
5，设置pwm周期
6，设置占空比
7，设置输出精度


T8Pn		计数器
T8PnP		周期寄存器
T8PnR		精度寄存器
T8PnC		控制：模式 后分频 使能 预分频
T8PnPEX	后分频扩展
T8PnPMC	周期匹配选择或PWM输出精度选择
T8PnOC	输出控制：输出使能 精度扩展 输出引脚
T8PnPDT	死区控制



Pwm
1，必要的系统设置
2，设置对应端口为数字模式
3，初始化端口电平
4，配置成输出
5，设置pwm周期
6，设置占空比
7，设置输出精度

;**********************************************/