//module.c
#include <hic.h>
#include"init.h"


#if OLDEST
void DisPlay()
{
	if((FlagCharging) && (!FlagChargeFull))  //充电
	{
		switch(PreLEDPlayLV)
		{	
			case 1:    //小于 3.3V
			CntCharge++;
			switch(CntCharge)
			{
				case 1:
				PinLED1 = 1;
				PinLED2 = 0;
				PinLED3 = 0;
				PinLED4 = 0;
				break;

				case 2:
				PinLED2 = 1;
				break;

				case 3:
				PinLED3 = 1;
				break;

				case 4:
				PinLED4 = 1;
				
				break;

				case 5:
				PinLED1 = 0;
				PinLED2 = 0;
				PinLED3 = 0;
				PinLED4 = 0;
				CntCharge = 0;
				break;	
				
				default:
				CntCharge = 0;
				break;
			}
			break;

			case 2:   //不小于3.3 小于3.5
			PinLED1 = 1;
			CntCharge++;
			switch(CntCharge)
			{
				case 1:
				PinLED2 = 1;
				break;
				case 2:
				PinLED3 = 1;
				break;
				case 3:
				PinLED4 = 1;
				break;
				case 4:
				PinLED2 = 0;
				PinLED3 = 0;
				PinLED4 = 0;
				CntCharge = 0;
				break;	
				default:
				CntCharge = 0;
				break;
			}
			break;

			case 3:   //不小于3.5 小于3.75 
			PinLED1 = 1;
			PinLED2 = 1;
			CntCharge++;
			switch(CntCharge)
			{
				case 1:
				PinLED3 = 1;
				break;
				case 2:
				PinLED4 = 1;
				break;
				case 3:
				PinLED3 = 0;
				PinLED4 = 0;
				CntCharge = 0;
				break;	
				default:
				CntCharge = 0;
				break;
			}
			break;

			case 4:  //不小于3.75 小于4095
			PinLED1 = 1;
			PinLED2 = 1;
			PinLED3 = 1;
			CntCharge++;
			switch(CntCharge)
			{
				case 1:
				PinLED4 = 1;
				break;
				case 2:
				PinLED4 = 0;
				CntCharge = 0;
				break;
				default:
				CntCharge = 0;
				break;
			}
			break;

			default:
			CntCharge = 0;
			break;
		}
		
	}

	else if(FlagChargeFull) //充满
	{
		PinLED1 = 1;
		PinLED2 = 1;
		PinLED3 = 1;
		PinLED4 = 1;
		CntCharge = 0;
	}

	else if((FlagTYNCharging) && (!FlagTYNChargeFull))
	{
		switch(PreLEDPlayLV)
		{	
			case 1:    //小于 3.3V
			CntCharge++;
			switch(CntCharge)
			{
				case 1:
				PinLED1 = 1;
				PinLED2 = 0;
				PinLED3 = 0;
				PinLED4 = 0;
				break;

				case 2:
				PinLED2 = 1;
				break;

				case 3:
				PinLED3 = 1;
				break;

				case 4:
				PinLED4 = 1;
				
				break;

				case 5:
				PinLED1 = 0;
				PinLED2 = 0;
				PinLED3 = 0;
				PinLED4 = 0;
				CntCharge = 0;
				break;	
				
				default:
				CntCharge = 0;
				break;
			}
			break;

			case 2:   //不小于3.3 小于3.5
			PinLED1 = 1;
			CntCharge++;
			switch(CntCharge)
			{
				case 1:
				PinLED2 = 1;
				break;
				case 2:
				PinLED3 = 1;
				break;
				case 3:
				PinLED4 = 1;
				break;
				case 4:
				PinLED2 = 0;
				PinLED3 = 0;
				PinLED4 = 0;
				CntCharge = 0;
				break;	
				default:
				CntCharge = 0;
				break;
			}
			break;

			case 3:   //不小于3.5 小于3.75 
			PinLED1 = 1;
			PinLED2 = 1;
			CntCharge++;
			switch(CntCharge)
			{
				case 1:
				PinLED3 = 1;
				break;
				case 2:
				PinLED4 = 1;
				break;
				case 3:
				PinLED3 = 0;
				PinLED4 = 0;
				CntCharge = 0;
				break;	
				default:
				CntCharge = 0;
				break;
			}
			break;

			case 4:  //不小于3.75 小于4095
			PinLED1 = 1;
			PinLED2 = 1;
			PinLED3 = 1;
			CntCharge++;
			switch(CntCharge)
			{
				case 1:
				PinLED4 = 1;
				break;
				case 2:
				PinLED4 = 0;
				CntCharge = 0;
				break;
				default:
				CntCharge = 0;
				break;
			}
			break;

			default:
			CntCharge = 0;
			break;
		}
	}

	

	else if(FlagDisPlay)
	{
		switch(PreLEDPlayLV)
		{
			case 1:
			CntCharge++;
			switch(CntCharge)
			{
				case 1:
				PinLED1 = 1;
				PinLED2 = 0;
				PinLED3 = 0;
				PinLED4 = 0;
				break;
				case 2:
				PinLED1 = 0;
				CntCharge = 0;
				break;
				default:
				CntCharge = 0;
				break;
			}
			break;

			case 2:
			PinLED1 = 1;
			PinLED2 = 0;
			PinLED3 = 0;
			PinLED4 = 0;
			break;

			case 3:
			PinLED1 = 1;
			PinLED2 = 1;
			PinLED3 = 0;
			PinLED4 = 0;
			break;

			case 4:
			PinLED1 = 1;
			PinLED2 = 1;
			PinLED3 = 1;
			PinLED4 = 0;
			break;

			case 5:
			PinLED1 = 1;
			PinLED2 = 1;
			PinLED3 = 1;
			PinLED4 = 1;
			break;

			default:
			CntCharge = 0;
			break;
		}
	}
	else if(FlagTYNChargeFull) //充满
	{
		PinLED1 = 1;
		PinLED2 = 1;
		PinLED3 = 1;
		PinLED4 = 1;
		CntCharge = 0;
	}

}
#endif
