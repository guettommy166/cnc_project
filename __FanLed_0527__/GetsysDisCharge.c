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
			if((FlagTYNCharging) || (FlagTYNChargeFull))   //̫���ܳ��ʱ ������Ч��ת�����طŵ�
			{		
				FlagNow = 1; 
				PinOutPWM = 0;  //  PinOutPWM  PA6    5  �� PinOutCharge  PB3  
				PinOutCharge = 0;  // 5 �ų��  PinOutCharge  PB3   
				PinOutDischarge = 1;  // 6 �ŷŵ�  PinOutDischarge  PB2		 //̫���ܳ������� 
				FlagTYNDisPlay = 1;		  //̫���ܷŵ繦��
				FlagDisPlay = 0;
				CntDuty = 0;
				CntCharge = 0;
			}
			else				//��̫���ܳ��ʱ ������Ч���طŵ�
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
			if((FlagTYNCharging) || (FlagTYNChargeFull))   //̫���ܳ��ʱ ������Ч��ת�����طŵ�
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
