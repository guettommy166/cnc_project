//module.c
#include <hic.h>
#include"init.h"
extern void BatStatus();

#if OLDEST
void PreBatLv()
{
	BatStatus();
	
	if((FlagCharging) || (FlagTYNCharging))
	{
		NowLEDDisPlay = NowBattaryLV;   //NowLEDDisPlay 等级对比
		if(PreLEDPlayLV < NowLEDDisPlay)   //PreLEDPlay  LED灯亮等级
		{
			CntPreLEDPlay++;
			if(CntPreLEDPlay >= CNTPRELEDPLAY)  //CNTPRELEDPLAY 20
			{
				CntPreLEDPlay = 0;
				PreLEDPlayLV += 1;
				PreLEDPlayLV = NowLEDDisPlay;
			}
		}
		else 
		{
			CntPreLEDPlay = 0;
			PreLEDPlayLV = NowLEDDisPlay;
		}
	}
	//else if(FlagTYNCharging) 
	//{
		//NowLEDDisPlay = NowBattaryLV;   //NowLEDDisPlay 等级对比
		//if(PreLEDPlayLV < NowLEDDisPlay)   //PreLEDPlay  LED灯亮等级
		//{
			//CntPreLEDPlay++;
			//if(CntPreLEDPlay >= CNTPRELEDPLAY)  //CNTPRELEDPLAY 20
			//{
				//CntPreLEDPlay = 0;
				//PreLEDPlayLV += 1;
				//PreLEDPlayLV = NowLEDDisPlay;
			//}
		//}
		//else 
		//{
			//CntPreLEDPlay = 0;
			//PreLEDPlayLV = NowLEDDisPlay;
		//}
	//}

	else if(FlagDisCharge)
	{
		NowLEDDisPlay = NowBattaryLV;   //NowLEDDisPlay 等级对比
		if(NowBattaryLV < NowLEDDisPlay)
		{
			CntFlagDisCharge++;
			if(CntFlagDisCharge >= CNTFLAGDISCHARGE)
			{
				CntFlagDisCharge = 0;
				NowLEDDisPlay -= 1;  //  中间值减1
				//NowLEDDisPlay = NowBattaryLV;
				PreLEDPlayLV = NowLEDDisPlay;
			}
		}
	
		else 
		{
			CntFlagDisCharge = 0;
			PreLEDPlayLV = NowLEDDisPlay;
		}
	}
}
#endif

