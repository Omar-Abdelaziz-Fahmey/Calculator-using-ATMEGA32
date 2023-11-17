/*********************************************************/
/***********		Author: OMAR 			**************/
/***********		Layer: HAL			 	**************/
/***********		Component: CLCD 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-8/2023		 	**************/
/*********************************************************/

/*Preprocessor file guard*/
#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_


#define CLCD_DATA_PORT		DIO_u8PORTA

#define CLCD_CTRL_PORT		DIO_u8PORTC
#define CLCD_RS_PIN			DIO_u8PIN0
#define CLCD_RW_PIN			DIO_u8PIN1
#define CLCD_E_PIN			DIO_u8PIN2

#define MODE_8_BIT		1

#define MODE_4_BIT   	2


/*Selectable the mode of the Lcd
 * OptionS :
 * 			1- 8_BIT  MODE:MODE_8_BIT
 * 			2- 4_BIT MODE:MODE_4_BIT*/

#define CLCD_MODE		MODE_4_BIT
// function set



#endif
