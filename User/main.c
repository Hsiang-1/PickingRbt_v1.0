
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


	// ���̲��������˶�����
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


	// ��е�۶�������1
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


	// ��е�۶�������2
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
	


	// ��϶�������1
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


	// ��϶�������2
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


	// �������
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



// ��ʼ������TIM�ĺ���
void GENERAL_TIM_INIT(void)
{
	GENERAL_TIM2_GPIO_Config();
	GENERAL_TIM2_Mode_Config();
	GENERAL_TIM3_GPIO_Config();
	GENERAL_TIM3_Mode_Config();
	GENERAL_TIM4_GPIO_Config();
	GENERAL_TIM4_Mode_Config();
}

// ��ʼ��GPIO���
void GPIO_INIT(void)
{
	AOUTPUT_Config();
}


// ����צ��A���ſ��Ƕȣ��Ƕȼ�����degree�ķ�ΧΪ0-100
void ClawA_CTL(unsigned int degree)
{
	if(degree > 0 && degree <= 100)
		TIM3_CH_Change(1, (3500 - degree*10));
}

// �ſ�צ��
void ClawA_OPEN(void)
{
	ClawA_CTL(100);
}

// ץ��צ�ӣ��رգ�
void ClawA_CLOSE(void)
{
	ClawA_CTL(1);
}

// �����󲿶��B��ת���Ƕȣ���ֱ��Ϊ0�ȣ����뷶ΧΪ-120-120��
void ArmB_CTL(int degree)
{
	if(degree >= -120 && degree <= 120)
		TIM3_CH_Change(2, (3000 - degree*16));
}

// ���ƴ�С�����Ӷ��C��ת���Ƕȣ���ֱ��Ϊ0�ȣ����뷶ΧΪ-120-120��
void ArmC_CTL(int degree)
{
	if(degree >= -120 && degree <= 120)
		TIM3_CH_Change(3, (3000 - degree*16));
}

// ���ƴ���ⲿ���D��ת���Ƕȣ���ֱ��Ϊ0�ȣ����뷶ΧΪ-60-60��
void ArmD_CTL(int degree)
{
	if(degree >= -60 && degree <= 60)
		TIM3_CH_Change(4, (3000 - degree*16));
}

// ������̨��ת���E��ת���Ƕȣ���ֱ��Ϊ0�ȣ����뷶ΧΪ-120-120��
void RotaE_CTL(int degree)
{
	if(degree >= -120 && degree <= 120)
		TIM4_CH_Change(1, (3000 - degree*16));
}

// ��ʼ״̬�µĻ�е��
void Init_Arm(void)
{
	ClawA_OPEN();
	ArmB_CTL(-20);
	ArmC_CTL(-120);
	ArmD_CTL(-25);
	RotaE_CTL(0);
	Delay_1s();
}



// ���ӵ������ģ��

// ��������A���ٶȣ��ٶȼ�����speed�ķ�ΧΪ1-100
void WheelA_Speed(unsigned int speed)
{
	if(speed > 0 && speed <= 100)
		TIM2_CH_Change(1, 99 + speed);
}

// ��������B���ٶȣ��ٶȼ�����speed�ķ�ΧΪ1-100
void WheelB_Speed(unsigned int speed)
{
	if(speed > 0 && speed <= 100)
		TIM2_CH_Change(2, 99 + speed);
}

// ��������C���ٶȣ��ٶȼ�����speed�ķ�ΧΪ1-100
void WheelC_Speed(unsigned int speed)
{
	if(speed > 0 && speed <= 100)
		TIM2_CH_Change(3, 99 + speed);
}

// ��������D���ٶȣ��ٶȼ�����speed�ķ�ΧΪ1-100
void WheelD_Speed(unsigned int speed)
{
	if(speed > 0 && speed <= 100)
		TIM2_CH_Change(4, 99 + speed);
}



// ��������A���˶�����-1��ת��0ֹͣ��1��ת
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

// ��������B���˶�����-1��ת��0ֹͣ��1��ת
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

// ��������C���˶�����-1��ת��0ֹͣ��1��ת
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

// ��������D���˶�����-1��ת��0ֹͣ��1��ת
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



// �������м̵���
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

// �ر����м̵���
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





// ͣ��
void CAR_STOP(void)
{
	WheelA_Direction(0);
	WheelB_Direction(0);
	WheelC_Direction(0);
	WheelD_Direction(0);
}


// ����ĳ���ٶ���ǰ�ߣ��ٶ�Ϊspeed����Χ1-100
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


// ����ĳ���ٶ���ǰ��ת���ٶ�Ϊspeed����Χ1-100
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

// ����ĳ���ٶ������ת���ٶ�Ϊspeed����Χ1-100
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


// ����ĳ���ٶ���ǰ��ת���ٶ�Ϊspeed����Χ1-100
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


// ����ĳ���ٶ������ת���ٶ�Ϊspeed����Χ1-100
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






// ��ʱ����1
void Delayms(u16 ms)
{
	u16 i,j;
	u8 k;
	for(i=0;i<ms;i++)
		for(j=0;j<0x0500;j++)
			k++;
	return ;
}

// ��ʱ����2
void Delay(void)
{
	Delayms(10000);
	return ;
}

// ��ʱ����3
void Delay_1s(void)
{
	Delayms(5000);
	return ;
}


