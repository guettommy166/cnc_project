//module.c
#include <hic.h>

/*********************************************
;* Include headfiles 
;********************************************/
#include"init.h"


/*********************************************
;* Private variables 
;********************************************/


/**********************************************
;* 
;* Function Name: RAM_HR7P153_CLEAR routine
;* Inputs:        None
;* Returns:       None
;* Description:   the RAM_HR7P153_CLEAR process
;*	
;**********************************************/

void RAM_HR7P153_CLEAR(void)
{
	__asm
	{
		MOVI    0x00
		MOVA    IAAH
		MOVI    0x00
		MOVA    IAAL 

		RAM0_CLEAR:
		CLR     IAD               
		INC     IAAL,1
		JBS     IAAL,6
		GOTO    RAM0_CLEAR
	}		
}
		     // IAAH  IAAL  清0
	         // 清除section的RAM数据0x00-0x7f
		 
/**********************************************
;* 
;* Function Name: InitUser routine
;* Inputs:        None
;* Returns:       None
;* Description:   the InitUser process
;*	
;**********************************************/

void  InitUser(void)
{
    CLRWDT();
    //FlagNow = 1;   
}

/**********************************************
;* 
;* Function Name: InitialMCU routine
;* Inputs:        None
;* Returns:       None
;* Description:   the InitialMCU process
;*	
;**********************************************/

void InitialMCU(void)
{
	/*CLK*/
	OSCP		= 0x55;		//解锁时钟控制写保护，当OSCC写入后会自动复位
	OSCC		= 0xE0;		//切换到8M高速时钟，时钟控制寄存器
										//OSCC时钟控制寄存器，切换高速或低速时钟源，频率选择
										//这里选用内部高速16MHz作为系统时钟源，使用8MHz时钟
	while(!SW_HS);		//等待高速时钟切换完成
	 
	/*WDT*/
	WDTC		= 0x17;		//使能WDT预分频，且预分频比为1：256
//	SREN		= 1;		//低电压复位使能
	RCEN		= 1;			//WDT内部RC时钟使能
	LPM			= 0;			//休眠模式默认0模式


	/*PORT*/
	ANS			= 0x3a;		//端口类型选择 0011_1010  设置PA7 PB1 PB0 PA2 PA1 PA0
										//这里PA7 PB1 PB0 PA1为数字端口，PA2 PA0为模拟端口
	PA			= 0x00;		//端口电平状态寄存器        
	PAT			= 0x2f;		//端口输入输出控制 0010_1111    PA5 PA3 PA2 PA1 PA0 为输入，其它为输出
										//其中PA3任何时候只能作输入用
	N_PAU		= 0xf7;		//端口弱上拉控制 1111_0111  PA3弱上拉使能，其余禁止 

	PB			= 0x00;		//0000_0000           
	PBT			= 0x00;		//0000_0000
	N_PBU		= 0xff;		//全部弱上拉使能

	ADCCL		= 0x61;		//0110_0001 ADC控制器低8位，用以选择参考电压，通道，转换启动和使能
										//011 参考电压2.1V  000 通道为AIN0，对应PA0脚 0 停止转换 1使能ADC
	ADCCH		= 0xB8;		//1011_1000 ADC控制器高8位，设置转换格式，时钟，采样时间
										//1 低位对齐   011 即8分频   1000 采样时间为8个ADC时钟
	

	/*TIM*/
	INTG		= 0x00;		//默认中断模式，中断入口地址 0x004
	T8P1PMC	= 0x00;		//周期匹配控制，设置pwm模式下精度，或定时模式下周期匹配选择
	T8P1OC	= 0x00;		//输出控制寄存器，如果是pwm模式，需设置输出使能，精度，引脚等
	T8P1P		= 199;		//计数时钟为4MHz，预分频后1MHz，一次定时1us，故200us
										//也就是，T8P1每200us置位T8P1PIF。同时，T8P1复位重计时，后分频器加1
	T8P1C		= 0x05;		//设置 T8P1 定时器模式，后分频 1:1，使能，且预分频 1:4 
	T8P1PEX = 0x00;		//如果有必要的设置后分频比扩展寄存器
										//如果后分频器计数值与后分频比相同，复位后分频器，并置T8P1TIF
	T8P1PIF	= 0;			//清除 T8P1 中断标志
	T8P1PIE	= 1;			//使能 T8P1 周期中断
	

//	LVDC	= 0x00;
//	PWRC	= 0x48;
//	WKDC	= 0x55;

	RAM_HR7P153_CLEAR();	//SRAM初始化

	/* Interrupt */
	INTC0		= 0x2A;		//KINT中断控制器 0010_1010禁止遮蔽KINT5 3 1中断
	INTC1		= 0x00;		//PINT中断触发边沿选择
	INTF0		= 0x00;		//需要软件清除中断标志
	INTF1		= 0x00;		//清除所有中断标志
	INTE0		= 0x41;		//KINT TINT ADINT中断使能 0100_0001，使能T8P1中断和KINT
	INTE1		= 0x00;		//PINT中断使能 这里禁止所有PINT中断，即PINT3-0
	
	while(GIE == 1)
		GIE		= 0;

	GIE			= 1;			//使能总中断

	InitUser();				//再次清零WDT计数器，以避免不必要的复位
	
}

