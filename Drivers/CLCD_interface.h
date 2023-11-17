/*********************************************************/
/***********		Author: OMAR 			**************/
/***********		Layer: HAL			 	**************/
/***********		Component: CLCD 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-8/2023		 	**************/
/*********************************************************/


/*Preprocessor file guard*/


#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_


#define X_POS  	7
#define Y_POS	0
// function to send the command to the lcd
void CLCD_voidSendCommand (u8 Copy_u8Command);

//function to send the data to the lcd
void CLCD_voidSendData (u8 Copy_u8Data);

//function to initilaize mode of the lcd
void CLCD_voidInit (void);

void CLCD_voidSendString(const char * Copy_phString );

void CLCD_voidSendNumber (u32 Copy_u32Number);

void CLCD_voidGotoXY (u8 Copy_u8PosX ,u8 Copy_u8PosY);

void calc_voidKpd (void);

#endif
