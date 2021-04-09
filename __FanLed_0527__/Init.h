//module.h

#include <hic.h>

#define PF		1

#define CLRWDT() __Asm CWDT
#define NOP()    __Asm NOP
#define IDLE()   __Asm IDLE


typedef unsigned char  u8; 
typedef unsigned int   u16;



#if PF

//Charge
#define PinCharging					PA3				//充电检测脚
#define Charging_ActLvl			0

#define PinCharged					PA3				//满电检测脚
#define Charged_ActLvl			0

//Batt
#define PinBattery					PA3				//电池电量检测脚
#define PinBattery_MOD			ANPA0			//模拟通道
#define PinBattery_CHN			ADCHS_AIN0	//转换通道
//Sway
#define PinSwaying					PA3					//引脚
#define PinSwaying_MOD			ANPA0				//模拟通道 
#define PinSwaying_CHN			ADCHS_AIN0	//转换通道



//ADSway
typedef enum {				//AD对齐		ADCCH[7]
	ADFM_H	= 0,
	ADFM_L	= (1<<7),
} ADFM_e;

typedef enum {				//AD时钟		ADCCH[6:4]
	ADCS_FOSC_01		= 0,	//
	ADCS_FOSC_02		= (1<<4),
	ADCS_FOSC_04		= (2<<4),
	ADCS_FOSC_08		= (3<<4),
	ADCS_FOSC_16		= (4<<4),
	ADCS_FOSC_32		= (5<<4),
	ADCS_FOSC_64		= (6<<4),

} ADCS_e;

typedef enum {			//采样时间		ADCCH[3:0]
	ADST_0,
	ADST_1,
	ADST_2,
	ADST_3,
	ADST_4,
	ADST_5,
	ADST_6,
	ADST_7,
	ADST_8,
	ADST_9,
	ADST_A,
	ADST_B,
	ADST_C,
	ADST_D,
	ADST_E,
	ADST_F,

} ADST_e;


typedef enum {			//参考电压源	ADCCL[7:5]
	ADVR_VDD_VSS	= 0,
	ADVR_4V0_VSS	= (1<<5),
	ADVR_3V0_VSS	= (2<<5),
	ADVR_2V1_VSS	= (3<<5),
	ADVR_EFP_VSS	= (4<<5),
	ADVR_EFP_EFN	= (5<<5),


} ADVR_e;


typedef enum {			//AD模拟通道	ADCCL[4:2]
	ADCHS_AIN0	= 0,
	ADCHS_AIN1	= (1<<2),
	ADCHS_AIN2	= (2<<2),
	ADCHS_AIN3	= (3<<2),
	ADCHS_AIN4	= (4<<2),
	ADCHS_AIN5	= (5<<2),
	ADCHS_VDD4	= (6<<2),
	ADCHS_VDD8	= (7<<2),

} ADCH_e;



sbit IsCharge;				//是否充电
sbit IsCircle;				//是否摇头
sbit IsRepair;				//是否调试

sbit TimReq_ADChk;			//AD计时时机
sbit TimFlg_ADChk;			//AD采集时间到标志
sbit EveFlg_ADChk;			//AD转换完成




sbit a;
sbit b;
sbit c;
sbit d;
sbit e;

extern u16	TimCnt_Base;		//计时的基本单位

sbit		TimFlg_Pulse;				//摇头电机的相数切换标志
u8			TimCnt_Pulse;				//摇头电机的单相时间

sbit		TimReq_Shine;
sbit		TimFlg_Shine;				//红灯闪烁计时
extern u8		TimCnt_Shine;	

sbit		TimReq_Water;
sbit		TimFlg_Water;				//流水灯计时
extern u8		TimCnt_Water;



sbit		TimReq_Speed;				//计时开始标志
sbit		TimFlg_Speed;				//按键处理标志
extern u8		TimCnt_Speed;				//计数值

sbit		TimReq_Light;				//计时开始标志
sbit		TimFlg_Light;				//按键处理标志
extern u8		TimCnt_Light;				//计数值

sbit		TimReq_Shake;				//计时开始标志
sbit		TimFlg_Shake;				//按键处理标志
extern u8		TimCnt_Shake;				//计数值




u8 TimCnt_ADChk;			//AD采集计时
extern u8			EveCnt_ADChk;			//记录转换次数
extern u16		ADRegist;				//记录AD值


//假定A B C D四组线圈对应PA0 PA1 PA2 PA3
extern u8	Smotp[8];		//Smot正表
extern u8	Smotn[8];		//Smot反表



//Bright
extern u8 LampLevel;

//FanSpeed
extern u8 LeafLevel;





typedef enum {
	BattVal_Level_0		= 100,
	BattVal_Level_1		= 300,
	BattVal_Level_2		= 500,
	BattVal_Level_3		= 1000,

} BattVal_Level_e;


#define BattVal_Limit				100			//均需测试后确定
#define SwayVal_Limit				100




//Key
#define PinKey_Speed				PA3
#define PinKey_Light				PA3
#define PinKey_Shake				PA3

#define KeySpeed_ActLvl			0
#define KeyLight_ActLvl			0
#define KeyShake_ActLvl			0

#define KeySpeed_IE					PIE0
#define KeyLight_IE					PIE0
#define KeyShake_IE					PIE0

#define KeySpeed_IF					PIF0
#define KeyLight_IF					PIF0
#define KeyShake_IF					PIF0		


//TimFlag	
#define TimCnt_MAX					1000



//Led
#define PinLed_Button				PA3					//按键灯
#define PinLed_Sign01				PA3					//指示灯1
#define PinLed_Sign02				PA3					//指示灯2
#define PinLed_Sign03				PA3					//指示灯3
#define PinLed_Bright				PA3					//照明灯


#define LedButton_ActLvl		0				//按键灯有效电平
#define LedSign01_ActLvl		0				//指示
#define LedSign02_ActLvl		0
#define LedSign03_ActLvl		0
#define LedBright_ActLvl		0				//照明灯

#define PinLedBright_MOD		ANPA0		//照明灯端口数模选择位
#define PinLedBright_DIR		PAT0		//输入输出控制

#define PinMotSpeed_MOD			ANPA0		//风速马达端口数模选择位



//Smot
#define PinMot_ShakeA				PA3
#define PinMot_ShakeB				PA3
#define PinMot_ShakeC				PA3
#define PinMot_ShakeD				PA3
#define MotShake_ActLvl			0


//Mot
#define PinMot_Speed				PA3
#define MotSpeed_ActLvl			0



//Wind
typedef enum {
	LeafLevel_0		= 0,
	LeafLevel_1,
	LeafLevel_2,
	LeafLevel_3,
	LeafLevel_4,

	LeafLevel_n,
} LeafLevel_e;

//Bright
typedef enum {
	LampLevel_0		= 0,
	LampLevel_1,
	LampLevel_2,
	LampLevel_3,

	LampLevel_n,
} LampLevel_e;


//LedColor
typedef enum {
	LedColor_non	= 0,
	LedColor_red,
	LedColor_sof,

	LedColor_cnt,
} LedColor_e;

//Charge
typedef enum {
	ChgStat_und		= 0,
	ChgStat_ing,
	ChgStat_ok,

} ChgStat_e;

//Workmod
typedef enum {
	WM_STP,
	WM_CHG,
	WM_RUN,
	WM_DBG,

} WM_e;



typedef struct {
	u8 a;
	u8 b;
} A;

typedef struct {
	u8 flg:1;
	u8 cnt:7;
} Tim_t;

typedef union {
	u8 a;
	u16 b;
} U;
#endif















#if 0
#define PinCharge PA1      // 5V充电接入
#define PinTYNCharge PA5   //太阳能充电

#define PinKey PA3

#define PinOutCharge  PB3   //太阳能充电输出脚 
#define PinOutDischarge  PB2		 //太阳能放电输出脚 
#define PinOutPWM  PA6     //按键输出脚

#define PinLED1 PA4
#define PinLED2 PA7
#define PinLED3 PB0
#define PinLED4 PB1

#define  AD_CHANNEL_0 0x61
#define  AD_CHANNEL_1 0x65
#define  AD_CHANNEL_2 0x69
#define  AD_CHANNEL_3 0x6d
#define  AD_CHANNEL_4 0x71
#define  AD_CHANNEL_5 0x75
#define  AD_CHANNEL_6 0x79
#define  AD_CHANNEL_7 0x7d

sbit FlagSysClk2ms;
sbit FlagSysClk10ms;
sbit FlagSysClk50ms;
sbit FlagSysClk1s;
sbit FlagSysClk500ms;
sbit FlagNow;

sbit FlagCharging;
sbit FlagChargeFull;
sbit FlagNoCharge;       //  非5V充电与太阳能充电标志位
sbit FlagTYNCharging;   //  太阳能充电标志位
sbit FlagTYNChargeFull;   //  太阳能充电充满标志位
sbit FlagPinKeyDown;     //   按键按下标志位
sbit FlagPinKey;         //按键抬起标志位
sbit FlagDisCharge;     //放电标志位
sbit FlagDisPlay;    //放电显示标志位

sbit FlagTYNDisCharge;    //太阳能放电标志位
sbit FlagTYNDisPlay;   //太阳能  有效之后放电显示标志位

sbit FlagUp;  //呼吸计数上升
sbit FlagDown;  //呼吸计数下降
sbit FlagSys250us;




u8 CntSysClk2ms;
u8 CntSysClk10ms;
u8 CntSysClk50ms;
u8 CntSysClk500ms;
u8 CntSysClk1s;
u8 CntADSample;

u8 CntPinKey;   //按下计数
u8 CntPinKeyUp;   //按下抬起计数
u8 GetsysPinKey; //  按键按下有效之后处理计数

u8 CntPinCharge;   //5V正常充电计数
u8 CntChargingFull;   //5V正常充电充满计数

u8 CntNoCharging;  // 没有任何充电计数
u8 CntPinTYNCharge;   //  太阳能充电计数
u8 CntTYNChargingFull; //太阳能充电充满计数

u8 NowBattaryLV;   //电池电压
u8 NowLEDDisPlay;
u8 PreLEDPlayLV;
u8 CntPreLEDPlay;
u8 CntFlagDisCharge;
u8 CntNoPWM;


u8 CntCharge;  //显示函数
u8 CntDisCharge;  //放电显示
u8 CntNoDisCharge;  //没有充电
u8 CntSleep;  //低电压休眠
u8 CntTYNChargeCur;  //太阳能充电时按键有效之后USB有AD值翻转计数
u8 CntNOTYNChargeCur;  // 太阳能充电时按键有效之后USB无AD值翻转计数
u8 CntTYNChangge;     //太阳能转换
u8 CntTYNCharging;
u8 CntDuty;
u8 CntTYN;
u8 CntCur;


u16 ADChaegingSum;    //ADChaegingSum 电池AD值
u16 ADDisChargeSum;   //   ADDisChargeSum放电AD值
u16 PABuf;
u16 m_ADCValue;
u16 DisChargeCurrut;
u16 DisChargingCurrut;


#define COUNT_NOKEY  2940   //不能点亮照明灯
#define COUNT_BATSLEEP  2920   //3V   实际2925

#define COUNT_CNTSLEEP 20
#define COUNT_CNTPINKEY 20   //按键消抖

#define COUNT_CNTPINCHARGE 10      //充电计数
#define COUNT_CNTCHARGINGFULL 5    //充满计数 
#define COUNT_CNTNOCHARGING 30 //非充电计数
#define COUNT_CNTTYNPINCHARGE 5   //太阳能充电计数
#define COUNT_CNTTYNCHARGINGFULL 5    //太阳能充满计数

#define COUNT_MINCHARGECUR 10 //最小放 电电流
#define COUNT_CNTTYNCHARGECUR 3  //  太阳能充电时按键有效计时5秒  200ms *25 = 5miao 
#define COUNT_CNTCHARGECUR 120
#define COUNT_CNTNODISCHARGE 3

#define CNTPRELEDPLAY 20
#define CNTFLAGDISCHARGE 20

#define COUNT_CNTTYN 100

#define COUNT_BATCHARGEL_1  3260  //3.3V   3217 实际3.4
#define COUNT_BATCHARGEL_2  3500   //3.55V  
#define COUNT_BATCHARGEL_3  3800   //3.75V   3656   实际3.88
#define COUNT_BATCHARGEL_4  3990   //3.95V     4080  实际4.18

#define COUNT_BATDISCHARGEHIGHL_1  3217   //3.3V  
#define COUNT_BATDISCHARGEHIGHL_2  3412   //3.5V
#define COUNT_BATDISCHARGEHIGHL_3  3558   //3.65V
#define COUNT_BATDISCHARGEHIGHL_4  3705   //3.8V
#define COUNT_BATDISCHARGEHIGHL_5  4050   //4.2V

#endif