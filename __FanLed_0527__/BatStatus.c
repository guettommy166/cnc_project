//module.c

#include <hic.h>
#include"init.h"

#if 0
void BatStatus()
{	
	if((FlagCharging) && (!FlagChargeFull))
	{
		if(DisChargingCurrut < COUNT_BATCHARGEL_1)  //COUNT_BATCHARGEL_1 3217  //3.3V 
		{
			NowBattaryLV = 1;
		}
		else if(DisChargingCurrut < COUNT_BATCHARGEL_2)  //COUNT_BATCHARGEL_1 3217  //3.3V 
		{
			NowBattaryLV = 2;
		}
		else if(DisChargingCurrut < COUNT_BATCHARGEL_3) // COUNT_BATCHARGEL_2  3422   3.5V
		{
			NowBattaryLV = 3;
		}
		else if(DisChargingCurrut < COUNT_BATCHARGEL_4)   //COUNT_BATCHARGEL_3  3656   //3.75V
		{
			NowBattaryLV = 4;
		}
		if(FlagNow)
		{
			FlagNow = 0;
			CntCharge = 0;
			PreLEDPlayLV = NowBattaryLV;
		}
	}
	else if((FlagTYNCharging) && (!FlagTYNChargeFull))
	{
		if(DisChargingCurrut < COUNT_BATCHARGEL_1)  //COUNT_BATCHARGEL_1 3217  //3.3V 
		{
			NowBattaryLV = 1;
		}
		else if(DisChargingCurrut < COUNT_BATCHARGEL_2)  //COUNT_BATCHARGEL_1 3217  //3.3V 
		{
			NowBattaryLV = 2;
		}
		else if(DisChargingCurrut < COUNT_BATCHARGEL_3) // COUNT_BATCHARGEL_2  3422   3.5V
		{
			NowBattaryLV = 3;
		}
		else if(DisChargingCurrut < COUNT_BATCHARGEL_4)   //COUNT_BATCHARGEL_3  3656   //3.75V
		{
			NowBattaryLV = 4;
		}
		if(FlagNow)
		{
			FlagNow = 0;
			CntCharge = 0;
			PreLEDPlayLV = NowBattaryLV;
		}
	}
	else if(FlagTYNDisPlay)
	{
		//if(DisChargingCurrut < COUNT_BATDISCHARGEHIGHL_2)  //COUNT_BATDISCHARGEHIGHL_5 4095 
		//{
			//NowBattaryLV = 1;
		//}
		//else if(DisChargingCurrut < COUNT_BATDISCHARGEHIGHL_3)  //COUNT_BATDISCHARGEHIGHL_4 3851
		//{
			//NowBattaryLV = 2;
		//}
		//else if(DisChargingCurrut < COUNT_BATDISCHARGEHIGHL_4)  //COUNT_BATDISCHARGEHIGHL_3  3658
		//{
			//NowBattaryLV = 3;
		//}
		//else if(DisChargingCurrut < COUNT_BATDISCHARGEHIGHL_5)   //COUNT_BATDISCHARGEHIGHL_2 3465
		//{
			//NowBattaryLV = 4;
		//}
		//else if(DisChargingCurrut < COUNT_BATDISCHARGEHIGHL_5)  //COUNT_BATDISCHARGEHIGHL_1 3217
		//{
			//NowBattaryLV = 5;
		//}
		if(FlagNow)
		{
			FlagNow = 0;
			CntCharge = 0;
			PreLEDPlayLV = 4;   
		}
	}
	else if(FlagDisPlay)
	{
		if(DisChargingCurrut < COUNT_BATDISCHARGEHIGHL_1)  //COUNT_BATDISCHARGEHIGHL_5 4095 
		{
			NowBattaryLV = 1;
		}
		else if(DisChargingCurrut < COUNT_BATDISCHARGEHIGHL_2)  //COUNT_BATDISCHARGEHIGHL_4 3851
		{
			NowBattaryLV = 2;
		}
		else if(DisChargingCurrut < COUNT_BATDISCHARGEHIGHL_3)  //COUNT_BATDISCHARGEHIGHL_3  3658
		{
			NowBattaryLV = 3;
		}
		else if(DisChargingCurrut < COUNT_BATDISCHARGEHIGHL_4)   //COUNT_BATDISCHARGEHIGHL_2 3465
		{
			NowBattaryLV = 4;
		}
		else if(DisChargingCurrut < COUNT_BATDISCHARGEHIGHL_5)  //COUNT_BATDISCHARGEHIGHL_1 3217
		{
			NowBattaryLV = 5;
		}
		if(FlagNow)
		{
			FlagNow = 0;
			CntCharge = 0;
			PreLEDPlayLV = NowBattaryLV;   
		}
	}
}
#endif
