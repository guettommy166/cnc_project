//module.c
#include <hic.h>
#include"init.h"


#if OLDEST
void KeyScan()
{
	if(FlagNoCharge) {		//只在未充电的情况下检测按键
		if(!PinKey) {				
			CntPinKey++;
			CntPinKeyUp = 0;
			if(CntPinKey > COUNT_CNTPINKEY) {
				CntPinKey = 0;
				FlagPinKeyDown = 1;
			}
		} else if(PinKey) {
			if(FlagPinKeyDown) {
				CntPinKey = 0;
				CntPinKeyUp++;
				if(CntPinKeyUp > COUNT_CNTPINKEY) {
					CntPinKeyUp = 0;
					FlagPinKeyDown = 0; 
					FlagPinKey = 1;
				}
			} else {
				CntPinKeyUp = 0;
				CntPinKey = 0;
			}
		}	
	}
}
#endif