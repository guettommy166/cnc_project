//module.c
#include <hic.h>
#include"init.h"
//extern void Sleep();


#if OLDEST
/**********************************************
;* 
;* Function Name: ADCharge routine
;* Inputs:        None
;* Returns:       None
;* Description:   the ADCharge process
;*	
;**********************************************/

u16 GetADC(u8 channel)
{
    ADCCH = 0xB8;
    ADCCL = channel;
    ADTRG = 1;
    while (ADTRG)
    {
        ;
    }
    m_ADCValue = (ADCRH << 8) + ADCRL;
    return(m_ADCValue);
    
}

void ADCharge()
{
    CntADSample++;
    if(CntADSample != 17)
    {	
		ADChaegingSum += GetADC(AD_CHANNEL_0); 
		ADDisChargeSum += GetADC(AD_CHANNEL_2);         	
	}
  	else
	{	
		DisChargingCurrut = (ADChaegingSum >> 4);   //电池电压
		DisChargeCurrut = (ADDisChargeSum >> 4);    //放电电流
		CntADSample = 0;
		ADChaegingSum = 0;
		ADDisChargeSum = 0;
	}
	
}
#endif
