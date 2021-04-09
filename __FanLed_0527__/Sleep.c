
#include <hic.h>
#include"init.h"


#if 0
void Sleep(void)
{
		CntNOTYNChargeCur = 0;
		CntTYNChargeCur = 0;
		CntNoDisCharge = 0;
		CntDisCharge = 0;
		CntCharge = 0;
		GetsysPinKey = 0;
		CntPinCharge = 0;
		PinLED1 = 0;
		PinLED2 = 0;
		PinLED3 = 0;
		PinLED4 = 0;
		GetsysPinKey = 0;
		PinOutPWM = 0;
		PinOutCharge = 0;  // 5 脚充电  PinOutCharge  PB3   //太阳能充电输出脚
		PinOutDischarge = 0; 
		FlagTYNDisCharge =0;		  //太阳能放电功能
		FlagDisCharge = 0;
		FlagTYNDisPlay = 0;
		FlagDisPlay = 0;
		FlagChargeFull = 0;
		FlagCharging = 0;

		ADCCL = 0x60;      //0110 0000
		PABuf = PA;           
        KIF = 0;   
		KIE = 1;
		RCEN = 0;
		IDLE();   
		NOP();
		NOP();

		while(!SW_HS); //
		ADEN = 1;
		RCEN = 1;
		CLRWDT();
}
#endif
