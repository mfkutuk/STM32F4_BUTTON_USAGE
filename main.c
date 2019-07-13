/*	Stm32f4 Discovery kartinin üzerinde bulunan mavi buton kullanilarak led yakma uygulamasi 
		Stm32f4 user manuelin 31. sayfasi incelenir ise mavi butonun PA0 pinine bagli oldugu görülür
		
		Led lighting application using the blue button which on the Stm32f4 Discovery board
		If page 31 of Stm32f4 user manual is examined, it is seen that the blue button is connected to the PA0 pin.
*/

#include "stm32f4xx.h"                  // Device header

int main()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); // GPIOA portu için clock sinyali aktiflestirilir - The clock signal for the GPIOA port is activated
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE); // GPIOD portu için clock sinyali aktiflestirilir - The clock signal for the GPIOD port is activated
	
	//led init
	GPIO_InitTypeDef GPIO_Structure_Led;
	GPIO_Structure_Led.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_Structure_Led.GPIO_OType=GPIO_OType_PP;
	GPIO_Structure_Led.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_Structure_Led.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_Structure_Led.GPIO_Speed=GPIO_Fast_Speed;
	GPIO_Init(GPIOD,&GPIO_Structure_Led);
	
	//Button Init
	GPIO_InitTypeDef GPIO_Structure_Button;
	GPIO_Structure_Button.GPIO_Mode=GPIO_Mode_IN; // INPUT
	GPIO_Structure_Button.GPIO_OType=GPIO_OType_PP;
	GPIO_Structure_Button.GPIO_Pin=GPIO_Pin_0;
	GPIO_Structure_Button.GPIO_PuPd=GPIO_PuPd_DOWN; // Button connected PA0 with pull down resistor so we select it to PULL DOWN
	GPIO_Structure_Button.GPIO_Speed=GPIO_Fast_Speed;
	GPIO_Init(GPIOA,&GPIO_Structure_Button);
	
	while(1)
	{
		int input=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);
		
		if(input) //if the button is pressed 
			{
			GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			}
		else 
			{
			GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			}
		
	}	
	
}
