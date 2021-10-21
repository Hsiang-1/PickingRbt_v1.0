
#include "stm32f10x.h"
#include "bsp_GeneralTim.h"
#include "aoutput.h"
#include "buzzer.h"

void Delayms(u16 ms);
void Delay(void);
void Delay_1s(void);


void GENERAL_TIM_INIT(void);
void GPIO_INIT(void);


void ClawA_CTL(unsigned int degree);
void ClawA_OPEN(void);
void ClawA_CLOSE(void);
void ArmB_CTL(int degree);
void ArmC_CTL(int degree);
void ArmD_CTL(int degree);
void RotaE_CTL(int degree);
void Init_Arm(void);

void WheelA_Speed(unsigned int speed);
void WheelB_Speed(unsigned int speed);
void WheelC_Speed(unsigned int speed);
void WheelD_Speed(unsigned int speed);

void WheelA_Direction(int direction);
void WheelB_Direction(int direction);
void WheelC_Direction(int direction);
void WheelD_Direction(int direction);

void CAR_STOP(void);
void CAR_FORWARD( unsigned int speed);
void CAR_BACK(unsigned int speed);

void CAR_FLEFT( unsigned int speed);
void CAR_BLEFT( unsigned int speed);

void CAR_FRIGHT( unsigned int speed);
void CAR_BRIGHT( unsigned int speed);


void POWER_OPEN(void);
void POWER_CLOSE(void);




int main(void)
{
	// -------------------------------
	// BEGIN
	GENERAL_TIM_INIT();
	GPIO_INIT();
	POWER_OPEN();
	Init_Arm();
	// END BEGIN
	// -------------------------------



	// -------------------------------
	// THE PROGRAM


	// 底盘部分所有运动测试
	Delay_1s();
	BUZZER_OPEN();
	Delay_1s();
	BUZZER_CLOSE();
	Delay_1s();

	CAR_STOP();
	CAR_FORWARD(80);
	Delay_1s();
	CAR_STOP();
	Delay_1s();

	CAR_STOP();
	CAR_BACK(80);
	Delay_1s();
	CAR_STOP();
	Delay_1s();

	CAR_STOP();
	CAR_FLEFT(80);
	Delay_1s();
	CAR_STOP();
	Delay_1s();

	CAR_STOP();
	CAR_BLEFT(80);
	Delay_1s();
	CAR_STOP();
	Delay_1s();

	CAR_STOP();
	CAR_FRIGHT(80);
	Delay_1s();
	CAR_STOP();
	Delay_1s();

	CAR_STOP();
	CAR_BRIGHT(80);
	Delay_1s();
	CAR_STOP();
	Delay_1s();


	// 机械臂动作测试1
	BUZZER_OPEN();
	Delay_1s();
	BUZZER_CLOSE();
	Delay_1s();

	ArmD_CTL(30);
	Delay_1s();
	ArmC_CTL(-30);
	Delay_1s();
	ArmB_CTL(30);
	Delay_1s();
	RotaE_CTL(90);
	Delay_1s();

	ClawA_OPEN();
	Delay_1s();
	ClawA_CLOSE();
	Delay_1s();


	// 机械臂动作测试2
	BUZZER_OPEN();
	Delay_1s();
	BUZZER_CLOSE();
	Delay_1s();

	RotaE_CTL(0);
	Delay_1s();
	ArmD_CTL(10);
	Delay_1s();
	ArmC_CTL(-90);
	Delay_1s();
	ArmB_CTL(-30);
	Delay_1s();

	ClawA_OPEN();
	Delay_1s();
	


	// 组合动作测试1
	BUZZER_OPEN();
	Delay_1s();
	BUZZER_CLOSE();
	Delay_1s();
	Delay_1s();
	Delay_1s();


	CAR_STOP();
	CAR_FORWARD(80);
	Delay_1s();
	

	ArmD_CTL(30);
	ArmC_CTL(-30);
	ArmB_CTL(30);
	RotaE_CTL(90);
	ClawA_OPEN();

	Delay_1s();
	CAR_STOP();
	ClawA_CLOSE();
	Delay_1s();
	Delay_1s();


	// 组合动作测试2
	BUZZER_OPEN();
	Delay_1s();
	BUZZER_CLOSE();
	Delay_1s();
	Delay_1s();


	CAR_STOP();
	CAR_FLEFT(80);
	Delay_1s();
	CAR_FORWARD(80);

	RotaE_CTL(0);
	ArmD_CTL(10);
	ArmC_CTL(-90);
	ArmB_CTL(-30);

	Delay_1s();
	ClawA_OPEN();
	CAR_STOP();
	Delay_1s();
	Delay_1s();


	// 测试完毕
	BUZZER_OPEN();
	Delayms(2000);
	BUZZER_CLOSE();
	Delayms(2000);
	BUZZER_OPEN();
	Delayms(2000);
	BUZZER_CLOSE();
	Delayms(2000);
	BUZZER_OPEN();
	Delayms(2000);
	BUZZER_CLOSE();
	Delayms(2000);


	// -------------------------------



	// -------------------------------
	// END
	Delay_1s();
	Init_Arm();
	POWER_CLOSE();
	// END END
	// -------------------------------
}



// 初始化所有TIM的函数
void GENERAL_TIM_INIT(void)
{
	GENERAL_TIM2_GPIO_Config();
	GENERAL_TIM2_Mode_Config();
	GENERAL_TIM3_GPIO_Config();
	GENERAL_TIM3_Mode_Config();
	GENERAL_TIM4_GPIO_Config();
	GENERAL_TIM4_Mode_Config();
}

// 初始化GPIO输出
void GPIO_INIT(void)
{
	AOUTPUT_Config();
}


// 控制爪子A的张开角度，角度即输入degree的范围为0-100
void ClawA_CTL(unsigned int degree)
{
	if(degree > 0 && degree <= 100)
		TIM3_CH_Change(1, (3500 - degree*10));
}

// 张开爪子
void ClawA_OPEN(void)
{
	ClawA_CTL(100);
}

// 抓紧爪子（关闭）
void ClawA_CLOSE(void)
{
	ClawA_CTL(1);
}

// 控制腕部舵机B的转动角度，以直立为0度，输入范围为-120-120度
void ArmB_CTL(int degree)
{
	if(degree >= -120 && degree <= 120)
		TIM3_CH_Change(2, (3000 - degree*16));
}

// 控制大小臂连接舵机C的转动角度，以直立为0度，输入范围为-120-120度
void ArmC_CTL(int degree)
{
	if(degree >= -120 && degree <= 120)
		TIM3_CH_Change(3, (3000 - degree*16));
}

// 控制大臂肘部舵机D的转动角度，以直立为0度，输入范围为-60-60度
void ArmD_CTL(int degree)
{
	if(degree >= -60 && degree <= 60)
		TIM3_CH_Change(4, (3000 - degree*16));
}

// 控制云台旋转电机E的转动角度，以直立为0度，输入范围为-120-120度
void RotaE_CTL(int degree)
{
	if(degree >= -120 && degree <= 120)
		TIM4_CH_Change(1, (3000 - degree*16));
}

// 初始状态下的机械臂
void Init_Arm(void)
{
	ClawA_OPEN();
	ArmB_CTL(-20);
	ArmC_CTL(-120);
	ArmD_CTL(-25);
	RotaE_CTL(0);
	Delay_1s();
}



// 轮子电机驱动模块

// 控制轮子A的速度，速度即输入speed的范围为1-100
void WheelA_Speed(unsigned int speed)
{
	if(speed > 0 && speed <= 100)
		TIM2_CH_Change(1, 99 + speed);
}

// 控制轮子B的速度，速度即输入speed的范围为1-100
void WheelB_Speed(unsigned int speed)
{
	if(speed > 0 && speed <= 100)
		TIM2_CH_Change(2, 99 + speed);
}

// 控制轮子C的速度，速度即输入speed的范围为1-100
void WheelC_Speed(unsigned int speed)
{
	if(speed > 0 && speed <= 100)
		TIM2_CH_Change(3, 99 + speed);
}

// 控制轮子D的速度，速度即输入speed的范围为1-100
void WheelD_Speed(unsigned int speed)
{
	if(speed > 0 && speed <= 100)
		TIM2_CH_Change(4, 99 + speed);
}



// 控制轮子A的运动方向，-1反转，0停止，1正转
void WheelA_Direction(int direction)
{
	switch(direction)
	{
		case 1:
			AA_GOFORWARD();
			break;
		case -1:
			AA_BACKUP();
			break;
		case 0:
			AA_STOP();
			break;
		default:
			break;
	}
}

// 控制轮子B的运动方向，-1反转，0停止，1正转
void WheelB_Direction(int direction)
{
	switch(direction)
	{
		case 1:
			BB_GOFORWARD();
			break;
		case -1:
			BB_BACKUP();
			break;
		case 0:
			BB_STOP();
			break;
		default:
			break;
	}
}

// 控制轮子C的运动方向，-1反转，0停止，1正转
void WheelC_Direction(int direction)
{
	switch(direction)
	{
		case 1:
			CC_GOFORWARD();
			break;
		case -1:
			CC_BACKUP();
			break;
		case 0:
			CC_STOP();
			break;
		default:
			break;
	}
}

// 控制轮子D的运动方向，-1反转，0停止，1正转
void WheelD_Direction(int direction)
{
	switch(direction)
	{
		case 1:
			DD_GOFORWARD();
			break;
		case -1:
			DD_BACKUP();
			break;
		case 0:
			DD_STOP();
			break;
		default:
			break;
	}
}



// 开启所有继电器
void POWER_OPEN(void)
{
	BUZZER_OPEN();
	Delayms(10000);

	CAR_STOP();

	POWER_A24V_OPEN();
	POWER_B20V_OPEN();
	POWER_C6V4_OPEN();

	BUZZER_CLOSE();
}

// 关闭所有继电器
void POWER_CLOSE(void)
{
	BUZZER_OPEN();
	Delayms(10000);
	BUZZER_CLOSE();

	CAR_STOP();

	POWER_A24V_CLOSE();
	POWER_B20V_CLOSE();
	POWER_C6V4_CLOSE();

	BUZZER_OPEN();
	Delayms(5000);
	BUZZER_CLOSE();
}





// 停车
void CAR_STOP(void)
{
	WheelA_Direction(0);
	WheelB_Direction(0);
	WheelC_Direction(0);
	WheelD_Direction(0);
}


// 车以某个速度向前走，速度为speed，范围1-100
void CAR_FORWARD( unsigned int speed)
{
	WheelA_Speed(speed);
	WheelB_Speed(speed);
	WheelC_Speed(speed);
	WheelD_Speed(speed);

	WheelA_Direction(1);
	WheelB_Direction(1);
	WheelC_Direction(1);
	WheelD_Direction(1);
}


void CAR_BACK( unsigned int speed)
{
	WheelA_Speed(speed);
	WheelB_Speed(speed);
	WheelC_Speed(speed);
	WheelD_Speed(speed);

	WheelA_Direction(-1);
	WheelB_Direction(-1);
	WheelC_Direction(-1);
	WheelD_Direction(-1);
}


// 车以某个速度向前左转，速度为speed，范围1-100
void CAR_FLEFT( unsigned int speed)
{
	WheelA_Speed(speed);
	WheelB_Speed(speed);
	WheelC_Speed(speed);
	WheelD_Speed(speed);

	WheelA_Direction(1);
	WheelB_Direction(0);
	WheelC_Direction(1);
	WheelD_Direction(0);
}

// 车以某个速度向后左转，速度为speed，范围1-100
void CAR_BLEFT( unsigned int speed)
{
	WheelA_Speed(speed);
	WheelB_Speed(speed);
	WheelC_Speed(speed);
	WheelD_Speed(speed);

	WheelA_Direction(-1);
	WheelB_Direction(0);
	WheelC_Direction(-1);
	WheelD_Direction(0);
}


// 车以某个速度向前右转，速度为speed，范围1-100
void CAR_FRIGHT( unsigned int speed)
{
	WheelA_Speed(speed);
	WheelB_Speed(speed);
	WheelC_Speed(speed);
	WheelD_Speed(speed);

	WheelA_Direction(0);
	WheelB_Direction(1);
	WheelC_Direction(0);
	WheelD_Direction(1);
}


// 车以某个速度向后右转，速度为speed，范围1-100
void CAR_BRIGHT( unsigned int speed)
{
	WheelA_Speed(speed);
	WheelB_Speed(speed);
	WheelC_Speed(speed);
	WheelD_Speed(speed);

	WheelA_Direction(0);
	WheelB_Direction(-1);
	WheelC_Direction(0);
	WheelD_Direction(-1);
}






// 延时函数1
void Delayms(u16 ms)
{
	u16 i,j;
	u8 k;
	for(i=0;i<ms;i++)
		for(j=0;j<0x0500;j++)
			k++;
	return ;
}

// 延时函数2
void Delay(void)
{
	Delayms(10000);
	return ;
}

// 延时函数3
void Delay_1s(void)
{
	Delayms(5000);
	return ;
}


