//module.c
#include <hic.h>
#include"init.h"
extern void PreBatLv();
extern void Sleep();

#if 0
void GetsysStatus()
{
	//if((PinCharge) && (PinTYNCharge) && ())
	//{
		//FlagNoCharge = 0;
	//}
	if((PinCharge) && (!PinTYNCharge))  // 5V�������ж�
	{
		FlagNoCharge = 0;
		CntNoCharging = 0;
		if(!FlagChargeFull)
		{
			CntPinCharge++;
			if(CntPinCharge >= COUNT_CNTPINCHARGE)  ///COUNT_CNTPINCHARGE 10*50= 500MS
			{
				CntPinCharge = 0;
				FlagCharging = 1;
			}
		}
		else 
		{
			CntPinCharge = 0;
		}

		if(FlagCharging)
		{
			if(DisChargingCurrut >= COUNT_BATCHARGEL_4)
			{
				CntChargingFull++;
				if(CntChargingFull >= COUNT_CNTCHARGINGFULL)  //COUNT_CNTCHARGINGFULL 5
				{
					CntChargingFull = 0;
					FlagChargeFull = 1;
					FlagCharging = 0;	
				}
			}
			else
			{
				CntChargingFull = 0;
				FlagChargeFull = 0;
			}
		}
	}
	if(!PinCharge)
	{
		FlagChargeFull = 0;
		FlagCharging = 0;	
		FlagNoCharge = 1;  //  �ǳ��־λ��1
		if((!PinTYNCharge) && (!FlagDisPlay) && (!FlagTYNDisPlay))
		{
			CntNoCharging++;
			if(CntNoCharging >= COUNT_CNTNOCHARGING)  //����COUNT_CNTNOCHARGING 120*50 = 1S�ǳ��
			{
				CntNoCharging = 0;
				Sleep();	
			}
		}
		else 
		{	
			CntNoCharging = 0;
		}
	}

	if(PinTYNCharge)  
	{
		FlagNoCharge = 1;
		CntNoCharging = 0;
		if(!FlagTYNDisPlay)
		{
			CntTYNCharging++;
			if(CntTYNCharging >= 5)
			{
				CntTYNCharging = 0;
				if(!FlagTYNChargeFull)
				{
					CntPinTYNCharge++;
					if(CntPinTYNCharge >= COUNT_CNTTYNPINCHARGE)  //COUNT_CNTPINCHARGE 10*50= 500MS
					{
						CntPinTYNCharge = 0;
						PinOutCharge = 1;   // 5 �ų��  PinOutCharge  PB3  
						PinOutDischarge = 0;  // 6 �ŷŵ�
						PinOutPWM = 0;
						FlagTYNCharging = 1;
						FlagTYNChargeFull = 0;
					}
				}
				if(FlagTYNCharging)
				{
					if(DisChargingCurrut >= COUNT_BATCHARGEL_4)
					{
						CntTYNChargingFull++;
						if(CntTYNChargingFull >= COUNT_CNTTYNCHARGINGFULL)  //COUNT_CNTTYNCHARGINGFULL 5
						{
							CntTYNChargingFull = 0;
							FlagTYNChargeFull = 1;
							FlagTYNCharging = 0;
						}
					}
				}
			}
		}
		else if(FlagTYNDisPlay)
		{
			CntTYNChangge++;
			if(CntTYNChangge >= 10)
			{
				CntTYNChargingFull = 0;
				CntPinTYNCharge = 0;
				CntTYNCharging = 0;
				//CntTYNChangge = 0;
				//CntPinTYNCharge = 0;
				//PinOutCharge = 0;   // 5 �ų��
				//PinOutDischarge = 1;  // 6 �ŷŵ�
				//FlagTYNCharging = 0;
				//FlagTYNChargeFull = 0;
			}
		}
	}
	else if(!PinTYNCharge)  
	{
		CntTYNCharging = 0;
		CntTYNChangge = 0;
		FlagTYNDisPlay = 0;
		FlagTYNDisCharge = 0;
		CntPinTYNCharge = 0;
		PinOutCharge = 0;   // 5 �ų��
		PinOutDischarge = 0;  // 6 �ŷŵ�
		FlagTYNCharging = 0;
		FlagTYNChargeFull = 0;
		CntTYNChargingFull = 0;
	}
}
#endif

