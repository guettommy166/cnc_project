//module.c
#include <hic.h>
#include "init.h"
extern void Sleep();


#if 0
void lowBatCheck()
{
	if(FlagDisCharge)
	{
		if(DisChargingCurrut <= COUNT_BATSLEEP)
		{
			CntSleep++;
			if(CntSleep >= COUNT_CNTSLEEP)
			{
				CntSleep = 0;
				FlagDisCharge = 0;
				Sleep();	
			}
		}
	}
}
#endif
