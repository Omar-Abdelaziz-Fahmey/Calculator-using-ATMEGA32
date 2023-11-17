/*********************************************************/
/***********		Author: OMAR 			**************/
/***********		Layer: HAL			 	**************/
/***********		Component: CLCD 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-8/2023		 	**************/
/*********************************************************/

//library
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

//mcal layer
#include "DIO_interface.h"
#include "KPD_interface.h"

#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"



void CLCD_voidSendCommand (u8 Copy_u8Command)
{
	//set the register select to zero to active command mode
	 DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	 //set RW to zero to active the effect command on the lcd
	 DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

#if CLCD_MODE==MODE_8_BIT
	 DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);
	 //read the command by enable pin
	 DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	 _delay_ms (2);
	 DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
#elif CLCD_MODE==MODE_4_BIT
	 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN7,GET_BIT(Copy_u8Command,7));
	 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN6,GET_BIT(Copy_u8Command,6));
	 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN5,GET_BIT(Copy_u8Command,5));
	 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN4,GET_BIT(Copy_u8Command,4));

	 DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	 _delay_ms (2);
	 DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

	 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN7,GET_BIT(Copy_u8Command,3));
	 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN6,GET_BIT(Copy_u8Command,2));
	 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN5,GET_BIT(Copy_u8Command,1));
	 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN4,GET_BIT(Copy_u8Command,0));

	 DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	 _delay_ms (2);
	 DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);


#else
#error "WRONG IN SEND COMMAND"
#endif
}
void CLCD_voidSendData (u8 Copy_u8Data)
{
	//set the register select to one to active command mode
	DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	 //set RW to zero to active the effect command on the lcd
	DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);


#if CLCD_MODE==MODE_8_BIT
	//put data on the data port
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);
	 //read the data by enable pin
	DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms (2);
	DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
#elif CLCD_MODE==MODE_4_BIT
	     DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN7,GET_BIT(Copy_u8Data,7));
		 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN6,GET_BIT(Copy_u8Data,6));
		 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN5,GET_BIT(Copy_u8Data,5));
		 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN4,GET_BIT(Copy_u8Data,4));

		 DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
		 _delay_ms (2);
		 DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

		 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN7,GET_BIT(Copy_u8Data,3));
		 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN6,GET_BIT(Copy_u8Data,2));
		 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN5,GET_BIT(Copy_u8Data,1));
		 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN4,GET_BIT(Copy_u8Data,0));

		 DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
		 _delay_ms (2);
		 DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

#else
#error "WRONG IN SEND DATA"
#endif

}
void CLCD_voidInit (void)
{
#if CLCD_MODE==MODE_8_BIT
	_delay_ms (40);
#elif CLCD_MODE==MODE_4_BIT
	_delay_ms (40);
//set the register select to zero to active command mode
 DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
 //set RW to zero to active the effect command on the lcd
 DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
 //put command on the command port

DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN7,0);
DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN6,0);
DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN5,1);
DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN4,0);

DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
_delay_ms (2);
DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
#else
#error "WRONG IN INITIALIZATION"
#endif

	// wait for more than 30 ms

	//function set Set command 2lines , font =5*7
CLCD_voidSendCommand(0b00000010);
_delay_ms (40);

CLCD_voidSendCommand(0b00101000);
_delay_us(45);
CLCD_voidSendCommand(0b00001100);
_delay_us(45);
CLCD_voidSendCommand(0b00000110);
_delay_us(45);
CLCD_voidSendCommand(1);
_delay_ms(2);

	//CLCD_voidSendCommand(0b00000110);





}


void CLCD_voidSendString(const char * Copy_phString )
{
   u8 Local_LoopCounter;
   for (Local_LoopCounter=0;(*(Copy_phString+Local_LoopCounter))!=0;Local_LoopCounter++)
   {
	   CLCD_voidSendData(*(Copy_phString+Local_LoopCounter));

   }
}
void CLCD_voidSendNumber (u32 Copy_u32Number)
{
	u8 Local_u8Counter=0;
	u8 Local_u8Counter1=0;
	u8 Local_u8Counter3 ;
	u32 Local_u8Temp =Copy_u32Number;
	u32 Local_u8Temp2 =Copy_u32Number;
	u32 Local_u8result;
	do {
		Local_u8Temp /=10 ;
		Local_u8Counter++;
}while(Local_u8Temp !=0);
	Local_u8Counter3 =Local_u8Counter;
for (Local_u8Counter1 =0;Local_u8Counter1<Local_u8Counter;Local_u8Counter1++)
{
do
{
	Local_u8result =Local_u8Temp2 %10;
	Local_u8Temp2 /=10 ;
	Local_u8Counter3--;
}
while (Local_u8Counter3>Local_u8Counter1);
Local_u8Counter3 = Local_u8Counter;
Local_u8Temp2 =Copy_u32Number;
CLCD_voidSendData('0'+Local_u8result);

}

}
u8 evaluate (u8 num1, u8 num2, u8 sign)
{
	/* Division by Zero returns error */
	if (sign == '/' && num2 == 0)	return 'E';
	switch(sign)
	{
		case '+':	return num1 + num2;		// Addition operation
		case '-':	return num1 - num2;		// Subtraction operation
		case '*':	return num1 * num2;		// Multiplication operation
		case '/':	return num1 / num2;		// Division operation
	}
}


void calc_voidKpd (void)
{
	s32 Local_u8Value1=0 , Local_u8Value2=0 ,Local_u8Value3=0 ;
	u8 Local_u8PresseKey ;
	u8 Local_u8Operation;
	Local_u8PresseKey=KPD_u8PressKey ();

	while (Local_u8PresseKey==0xff)
	{
		Local_u8PresseKey=KPD_u8PressKey ();
	}
	while ((Local_u8PresseKey != '/')&&(Local_u8PresseKey != '+')&&(Local_u8PresseKey != '-')&&(Local_u8PresseKey != '*')&&(Local_u8PresseKey != 'c')&&(Local_u8PresseKey != '='))
	{
		Local_u8Value1 =Local_u8Value1*10 +Local_u8PresseKey ;
		CLCD_voidSendData('0'+Local_u8PresseKey);
		Local_u8PresseKey=KPD_u8PressKey ();
		while (Local_u8PresseKey==0xff)
	    {
	    	Local_u8PresseKey=KPD_u8PressKey ();
	    }

	}
	Local_u8Operation =Local_u8PresseKey ;
	CLCD_voidSendData(Local_u8PresseKey);


	Local_u8PresseKey=KPD_u8PressKey ();
	while (Local_u8PresseKey==0xff)
	 {
		Local_u8PresseKey=KPD_u8PressKey ();
	 }

	while ((Local_u8PresseKey == '/')||(Local_u8PresseKey == '+')||(Local_u8PresseKey == '-')||(Local_u8PresseKey == '*')||(Local_u8PresseKey == 'c'))
		{
		CLCD_voidSendData(Local_u8PresseKey);
		Local_u8PresseKey=KPD_u8PressKey ();
		while (Local_u8PresseKey==0xff)
			{
				Local_u8PresseKey=KPD_u8PressKey ();
			}

		}
	if (Local_u8PresseKey=='=')
	{
		Local_u8Value3=Local_u8Value1+Local_u8Value2;
		CLCD_voidSendNumber(Local_u8Value3);

	}
	else
	{
		while ((Local_u8PresseKey != '/')&&(Local_u8PresseKey != '+')&&(Local_u8PresseKey != '-')&&(Local_u8PresseKey != '*')&&(Local_u8PresseKey != 'c')&&(Local_u8PresseKey != '='))
		{
			Local_u8Value2 =Local_u8Value2*10 +Local_u8PresseKey ;
			CLCD_voidSendData('0'+Local_u8PresseKey);
			Local_u8PresseKey=KPD_u8PressKey ();
			while (Local_u8PresseKey==0xff)
				    {
				    	Local_u8PresseKey=KPD_u8PressKey ();
				    }

		}
		CLCD_voidSendData(Local_u8PresseKey);
		if (Local_u8PresseKey=='=')
		{
			switch (Local_u8Operation)
						{
						case '+':
						    Local_u8Value3=Local_u8Value1+Local_u8Value2;
						    CLCD_voidSendNumber(Local_u8Value3);
						    break;
						case '-':
							Local_u8Value3=Local_u8Value1-Local_u8Value2;
							if (Local_u8Value3<0)
							{
								Local_u8Value3 *=-1;
								CLCD_voidSendData('-');
							}
							CLCD_voidSendNumber(Local_u8Value3);
							break;
						case '*':
							Local_u8Value3=Local_u8Value1*Local_u8Value2;
							CLCD_voidSendNumber(Local_u8Value3);
							break;
						case '/':
							if(Local_u8Value2==0)
							{
								CLCD_voidSendCommand(1);
								CLCD_voidSendString("Zero Division Error");
							}
							else{
								Local_u8Value3=Local_u8Value1/Local_u8Value2;
								CLCD_voidSendNumber(Local_u8Value3);
							}
							break;
						}

		}

	}
	Local_u8PresseKey=KPD_u8PressKey ();
	while (Local_u8PresseKey==0xff)
	{
		Local_u8PresseKey=KPD_u8PressKey ();
	}
	if (Local_u8PresseKey=='c')
	{
		CLCD_voidSendCommand(1);
		return;
	}
	while (Local_u8PresseKey != '=')
	{
		Local_u8PresseKey=KPD_u8PressKey ();
	}
	CLCD_voidSendCommand(1);


}



void CLCD_voidGotoXY (u8 Copy_u8PosX ,u8 Copy_u8PosY)
{

	u8 Local_u8DDRAMAddress ;

	if (Copy_u8PosY == 0)
	{
		Local_u8DDRAMAddress =Copy_u8PosX;
	}
	else
	{
		Local_u8DDRAMAddress =Copy_u8PosX;
	}

	CLCD_voidSendCommand(Local_u8DDRAMAddress +128);
}








