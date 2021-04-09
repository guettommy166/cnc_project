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
#define PinCharging					PA3				//������
#define Charging_ActLvl			0

#define PinCharged					PA3				//�������
#define Charged_ActLvl			0

//Batt
#define PinBattery					PA3				//��ص�������
#define PinBattery_MOD			ANPA0			//ģ��ͨ��
#define PinBattery_CHN			ADCHS_AIN0	//ת��ͨ��
//Sway
#define PinSwaying					PA3					//����
#define PinSwaying_MOD			ANPA0				//ģ��ͨ�� 
#define PinSwaying_CHN			ADCHS_AIN0	//ת��ͨ��



//ADSway
typedef enum {				//AD����		ADCCH[7]
	ADFM_H	= 0,
	ADFM_L	= (1<<7),
} ADFM_e;

typedef enum {				//ADʱ��		ADCCH[6:4]
	ADCS_FOSC_01		= 0,	//
	ADCS_FOSC_02		= (1<<4),
	ADCS_FOSC_04		= (2<<4),
	ADCS_FOSC_08		= (3<<4),
	ADCS_FOSC_16		= (4<<4),
	ADCS_FOSC_32		= (5<<4),
	ADCS_FOSC_64		= (6<<4),

} ADCS_e;

typedef enum {			//����ʱ��		ADCCH[3:0]
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


typedef enum {			//�ο���ѹԴ	ADCCL[7:5]
	ADVR_VDD_VSS	= 0,
	ADVR_4V0_VSS	= (1<<5),
	ADVR_3V0_VSS	= (2<<5),
	ADVR_2V1_VSS	= (3<<5),
	ADVR_EFP_VSS	= (4<<5),
	ADVR_EFP_EFN	= (5<<5),


} ADVR_e;


typedef enum {			//ADģ��ͨ��	ADCCL[4:2]
	ADCHS_AIN0	= 0,
	ADCHS_AIN1	= (1<<2),
	ADCHS_AIN2	= (2<<2),
	ADCHS_AIN3	= (3<<2),
	ADCHS_AIN4	= (4<<2),
	ADCHS_AIN5	= (5<<2),
	ADCHS_VDD4	= (6<<2),
	ADCHS_VDD8	= (7<<2),

} ADCH_e;



sbit IsCharge;				//�Ƿ���
sbit IsCircle;				//�Ƿ�ҡͷ
sbit IsRepair;				//�Ƿ����

sbit TimReq_ADChk;			//AD��ʱʱ��
sbit TimFlg_ADChk;			//AD�ɼ�ʱ�䵽��־
sbit EveFlg_ADChk;			//ADת�����




sbit a;
sbit b;
sbit c;
sbit d;
sbit e;

extern u16	TimCnt_Base;		//��ʱ�Ļ�����λ

sbit		TimFlg_Pulse;				//ҡͷ����������л���־
u8			TimCnt_Pulse;				//ҡͷ����ĵ���ʱ��

sbit		TimReq_Shine;
sbit		TimFlg_Shine;				//�����˸��ʱ
extern u8		TimCnt_Shine;	

sbit		TimReq_Water;
sbit		TimFlg_Water;				//��ˮ�Ƽ�ʱ
extern u8		TimCnt_Water;



sbit		TimReq_Speed;				//��ʱ��ʼ��־
sbit		TimFlg_Speed;				//���������־
extern u8		TimCnt_Speed;				//����ֵ

sbit		TimReq_Light;				//��ʱ��ʼ��־
sbit		TimFlg_Light;				//���������־
extern u8		TimCnt_Light;				//����ֵ

sbit		TimReq_Shake;				//��ʱ��ʼ��־
sbit		TimFlg_Shake;				//���������־
extern u8		TimCnt_Shake;				//����ֵ




u8 TimCnt_ADChk;			//AD�ɼ���ʱ
extern u8			EveCnt_ADChk;			//��¼ת������
extern u16		ADRegist;				//��¼ADֵ


//�ٶ�A B C D������Ȧ��ӦPA0 PA1 PA2 PA3
extern u8	Smotp[8];		//Smot����
extern u8	Smotn[8];		//Smot����



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


#define BattVal_Limit				100			//������Ժ�ȷ��
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
#define PinLed_Button				PA3					//������
#define PinLed_Sign01				PA3					//ָʾ��1
#define PinLed_Sign02				PA3					//ָʾ��2
#define PinLed_Sign03				PA3					//ָʾ��3
#define PinLed_Bright				PA3					//������


#define LedButton_ActLvl		0				//��������Ч��ƽ
#define LedSign01_ActLvl		0				//ָʾ
#define LedSign02_ActLvl		0
#define LedSign03_ActLvl		0
#define LedBright_ActLvl		0				//������

#define PinLedBright_MOD		ANPA0		//�����ƶ˿���ģѡ��λ
#define PinLedBright_DIR		PAT0		//�����������

#define PinMotSpeed_MOD			ANPA0		//�������˿���ģѡ��λ



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
#define PinCharge PA1      // 5V������
#define PinTYNCharge PA5   //̫���ܳ��

#define PinKey PA3

#define PinOutCharge  PB3   //̫���ܳ������� 
#define PinOutDischarge  PB2		 //̫���ܷŵ������ 
#define PinOutPWM  PA6     //���������

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
sbit FlagNoCharge;       //  ��5V�����̫���ܳ���־λ
sbit FlagTYNCharging;   //  ̫���ܳ���־λ
sbit FlagTYNChargeFull;   //  ̫���ܳ�������־λ
sbit FlagPinKeyDown;     //   �������±�־λ
sbit FlagPinKey;         //����̧���־λ
sbit FlagDisCharge;     //�ŵ��־λ
sbit FlagDisPlay;    //�ŵ���ʾ��־λ

sbit FlagTYNDisCharge;    //̫���ܷŵ��־λ
sbit FlagTYNDisPlay;   //̫����  ��Ч֮��ŵ���ʾ��־λ

sbit FlagUp;  //������������
sbit FlagDown;  //���������½�
sbit FlagSys250us;




u8 CntSysClk2ms;
u8 CntSysClk10ms;
u8 CntSysClk50ms;
u8 CntSysClk500ms;
u8 CntSysClk1s;
u8 CntADSample;

u8 CntPinKey;   //���¼���
u8 CntPinKeyUp;   //����̧�����
u8 GetsysPinKey; //  ����������Ч֮�������

u8 CntPinCharge;   //5V����������
u8 CntChargingFull;   //5V��������������

u8 CntNoCharging;  // û���κγ�����
u8 CntPinTYNCharge;   //  ̫���ܳ�����
u8 CntTYNChargingFull; //̫���ܳ���������

u8 NowBattaryLV;   //��ص�ѹ
u8 NowLEDDisPlay;
u8 PreLEDPlayLV;
u8 CntPreLEDPlay;
u8 CntFlagDisCharge;
u8 CntNoPWM;


u8 CntCharge;  //��ʾ����
u8 CntDisCharge;  //�ŵ���ʾ
u8 CntNoDisCharge;  //û�г��
u8 CntSleep;  //�͵�ѹ����
u8 CntTYNChargeCur;  //̫���ܳ��ʱ������Ч֮��USB��ADֵ��ת����
u8 CntNOTYNChargeCur;  // ̫���ܳ��ʱ������Ч֮��USB��ADֵ��ת����
u8 CntTYNChangge;     //̫����ת��
u8 CntTYNCharging;
u8 CntDuty;
u8 CntTYN;
u8 CntCur;


u16 ADChaegingSum;    //ADChaegingSum ���ADֵ
u16 ADDisChargeSum;   //   ADDisChargeSum�ŵ�ADֵ
u16 PABuf;
u16 m_ADCValue;
u16 DisChargeCurrut;
u16 DisChargingCurrut;


#define COUNT_NOKEY  2940   //���ܵ���������
#define COUNT_BATSLEEP  2920   //3V   ʵ��2925

#define COUNT_CNTSLEEP 20
#define COUNT_CNTPINKEY 20   //��������

#define COUNT_CNTPINCHARGE 10      //������
#define COUNT_CNTCHARGINGFULL 5    //�������� 
#define COUNT_CNTNOCHARGING 30 //�ǳ�����
#define COUNT_CNTTYNPINCHARGE 5   //̫���ܳ�����
#define COUNT_CNTTYNCHARGINGFULL 5    //̫���ܳ�������

#define COUNT_MINCHARGECUR 10 //��С�� �����
#define COUNT_CNTTYNCHARGECUR 3  //  ̫���ܳ��ʱ������Ч��ʱ5��  200ms *25 = 5miao 
#define COUNT_CNTCHARGECUR 120
#define COUNT_CNTNODISCHARGE 3

#define CNTPRELEDPLAY 20
#define CNTFLAGDISCHARGE 20

#define COUNT_CNTTYN 100

#define COUNT_BATCHARGEL_1  3260  //3.3V   3217 ʵ��3.4
#define COUNT_BATCHARGEL_2  3500   //3.55V  
#define COUNT_BATCHARGEL_3  3800   //3.75V   3656   ʵ��3.88
#define COUNT_BATCHARGEL_4  3990   //3.95V     4080  ʵ��4.18

#define COUNT_BATDISCHARGEHIGHL_1  3217   //3.3V  
#define COUNT_BATDISCHARGEHIGHL_2  3412   //3.5V
#define COUNT_BATDISCHARGEHIGHL_3  3558   //3.65V
#define COUNT_BATDISCHARGEHIGHL_4  3705   //3.8V
#define COUNT_BATDISCHARGEHIGHL_5  4050   //4.2V

#endif