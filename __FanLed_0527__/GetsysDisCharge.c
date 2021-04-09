//module.c
#include <hic.h>
#include"init.h"


#if 0
void GetsysDisCharge()
{
	if(FlagPinKey)
	{
		CntNoCharging = 0;
		FlagPinKey = 0;
		GetsysPinKey++;
		switch(GetsysPinKey)
		{
			case 1:
			if((FlagTYNCharging) || (FlagTYNChargeFull))   //太阳能充电时 按键有效则翻转给负载放电
			{		
				FlagNow = 1; 
				PinOutPWM = 0;  //  PinOutPWM  PA6    5  脚 PinOutCharge  PB3  
				PinOutCharge = 0;  // 5 脚充电  PinOutCharge  PB3   
				PinOutDischarge = 1;  // 6 脚放电  PinOutDischarge  PB2		 //太阳能充电输出脚 
				FlagTYNDisPlay = 1;		  //太阳能放电功能
				FlagDisPlay = 0;
				CntDuty = 0;
				CntCharge = 0;
			}
			else				//非太阳能充电时 按键有效则电池放电
			{
				if(DisChargingCurrut >= COUNT_NOKEY)
				{
					FlagNow = 1; 
					FlagTYNDisPlay = 0;
					FlagDisPlay = 1;
					PinOutPWM = 1;
					PinOutCharge = 0;
					PinOutDischarge = 0;
					CntCharge = 0;
				}
			}
			break;

			case 2:
			if((FlagTYNCharging) || (FlagTYNChargeFull))   //太阳能充电时 按键有效则翻转给负载放电
			{
				FlagTYNDisPlay = 0;	
				PinOutPWM = 0;
				FlagDisPlay = 0;
				PinOutCharge = 1;
				PinOutDischarge = 0;		
				GetsysPinKey = 0;
				CntCharge = 0;
			}
			else 
			{
				FlagTYNDisPlay = 0;	
				PinOutPWM = 0;
				FlagDisPlay = 0;
				PinOutCharge = 0;
				PinOutDischarge = 0;	
				GetsysPinKey = 0;
				CntCharge = 0;
			}
			break;

			default:
			GetsysPinKey = 0;
			break;	
		}
	}
}
#endif
