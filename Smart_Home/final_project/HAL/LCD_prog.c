
/****************************************/
/*          Author: Khaled Mohsen       */        
/*          Date: 3-9-2022              */
/*          Version: 1.0                */
/*          Module: LCD                 */
/****************************************/

#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\Service\STD_types.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\Service\BIT_math.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\MCAL\DIO_int.h"
#include "LCD_int.h"
#include "LCD_private.h"
#include "LCD_config.h"
#define F_CPU 16000000UL
#include<util/delay.h>

void LCD_voidInit(void)
{
	/*_delay_ms(35);
	
	#if LCD_U8_DATA_LENGTH  == LCD_U8_4_BIT
	LCD_voidSendCommand(0b00101000);
	#elif LCD_U8_DATA_LENGTH  == LCD_U8_8_BIT
	LCD_voidSendCommand(0b00111000);
	#endif
	
	_delay_ms(1);
	LCD_voidSendCommand(0b00001111);
	_delay_ms(1);
	LCD_voidSendCommand(0b00000001);
	_delay_ms(2);
	LCD_voidSendCommand(0b00000110);*/
	
		_delay_ms(35);
		LCD_voidSendCommand(0x33);
		_delay_ms(2);
		LCD_voidSendCommand(0x32);
		_delay_ms(2);
		LCD_voidSendCommand(0b00101000);     // function set 
		_delay_ms(2);
		LCD_voidSendCommand(0b00001100);     //DISPLAY ON , of CONTROLE 
		_delay_ms(2);
		LCD_voidSendCommand(0b00000110);          //display clear 
		_delay_ms(2);
		LCD_voidSendCommand(0b00000001);     // entry mode set
		_delay_ms(2);
}
void LCD_voidSendData(u8 Copy_u8Data)
{
	DIO_voidSetPinValue(LCD_U8_RS,DIO_U8_HIGH);
	DIO_voidSetPinValue(LCD_U8_RW,DIO_U8_LOW);
	
    #if LCD_U8_DATA_LENGTH  == LCD_U8_4_BIT
	if(GET_BIT(Copy_u8Data , 4) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D4,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D4,DIO_U8_LOW);
	}


	if(GET_BIT(Copy_u8Data , 5) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D5,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D5,DIO_U8_LOW);
	}


	if(GET_BIT(Copy_u8Data , 6) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D6,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D6,DIO_U8_LOW);
	}

	if(GET_BIT(Copy_u8Data , 7) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D7,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D7,DIO_U8_LOW);
	}
	
	DIO_voidSetPinValue(LCD_U8_E,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_U8_E,DIO_U8_LOW);
	_delay_ms(1);	

	if(GET_BIT(Copy_u8Data , 0) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D4,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D4,DIO_U8_LOW);
	}


	if(GET_BIT(Copy_u8Data , 1) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D5,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D5,DIO_U8_LOW);
	}


	if(GET_BIT(Copy_u8Data , 2) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D6,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D6,DIO_U8_LOW);
	}

	if(GET_BIT(Copy_u8Data , 3) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D7,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D7,DIO_U8_LOW);
	}

	
	#elif LCD_U8_DATA_LENGTH  == LCD_U8_8_BIT
	if(GET_BIT(Copy_u8Data , 0) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D0,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D0,DIO_U8_LOW);
	}
	
	if(GET_BIT(Copy_u8Data , 1) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D1,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D1,DIO_U8_LOW);
	}
	
	if(GET_BIT(Copy_u8Data , 2) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D2,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D2,DIO_U8_LOW);
	}

	if(GET_BIT(Copy_u8Data , 3) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D3,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D3,DIO_U8_LOW);
	}


	if(GET_BIT(Copy_u8Data , 4) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D4,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D4,DIO_U8_LOW);
	}


	if(GET_BIT(Copy_u8Data , 5) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D5,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D5,DIO_U8_LOW);
	}


	if(GET_BIT(Copy_u8Data , 6) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D6,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D6,DIO_U8_LOW);
	}

	if(GET_BIT(Copy_u8Data , 7) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D7,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D7,DIO_U8_LOW);
	}	
	
	#endif
	
	DIO_voidSetPinValue(LCD_U8_E,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_U8_E,DIO_U8_LOW);
	_delay_ms(1);
	
}
void LCD_voidSendCommand(u8 Copy_u8Command)
{
	DIO_voidSetPinValue(LCD_U8_RS,DIO_U8_LOW);
	DIO_voidSetPinValue(LCD_U8_RW,DIO_U8_LOW);
    #if LCD_U8_DATA_LENGTH  == LCD_U8_4_BIT
	
	if(GET_BIT(Copy_u8Command , 4) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D4,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D4,DIO_U8_LOW);
	}


	if(GET_BIT(Copy_u8Command , 5) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D5,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D5,DIO_U8_LOW);
	}


	if(GET_BIT(Copy_u8Command , 6) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D6,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D6,DIO_U8_LOW);
	}

	if(GET_BIT(Copy_u8Command , 7) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D7,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D7,DIO_U8_LOW);
	}
	
	
	DIO_voidSetPinValue(LCD_U8_E,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_U8_E,DIO_U8_LOW);
	_delay_ms(1);	
	
		if(GET_BIT(Copy_u8Command , 0) == 1)
		{
			DIO_voidSetPinValue(LCD_U8_D4,DIO_U8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(LCD_U8_D4,DIO_U8_LOW);
		}


		if(GET_BIT(Copy_u8Command , 1) == 1)
		{
			DIO_voidSetPinValue(LCD_U8_D5,DIO_U8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(LCD_U8_D5,DIO_U8_LOW);
		}


		if(GET_BIT(Copy_u8Command , 2) == 1)
		{
			DIO_voidSetPinValue(LCD_U8_D6,DIO_U8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(LCD_U8_D6,DIO_U8_LOW);
		}

		if(GET_BIT(Copy_u8Command , 3) == 1)
		{
			DIO_voidSetPinValue(LCD_U8_D7,DIO_U8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(LCD_U8_D7,DIO_U8_LOW);
		}
	
	#elif LCD_U8_DATA_LENGTH  == LCD_U8_8_BIT
	if(GET_BIT(Copy_u8Command , 0) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D0,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D0,DIO_U8_LOW);
	}
	
	if(GET_BIT(Copy_u8Command , 1) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D1,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D1,DIO_U8_LOW);
	}
	
	if(GET_BIT(Copy_u8Command , 2) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D2,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D2,DIO_U8_LOW);
	}

	if(GET_BIT(Copy_u8Command , 3) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D3,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D3,DIO_U8_LOW);
	}


	if(GET_BIT(Copy_u8Command , 4) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D4,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D4,DIO_U8_LOW);
	}


	if(GET_BIT(Copy_u8Command , 5) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D5,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D5,DIO_U8_LOW);
	}


	if(GET_BIT(Copy_u8Command , 6) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D6,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D6,DIO_U8_LOW);
	}

	if(GET_BIT(Copy_u8Command , 7) == 1)
	{
		DIO_voidSetPinValue(LCD_U8_D7,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D7,DIO_U8_LOW);
	}	
	
	#endif
	
	DIO_voidSetPinValue(LCD_U8_E,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_U8_E,DIO_U8_LOW);
	_delay_ms(1);
	
}
void LCD_voidSendString(s8* P_s8String)
{
	u8 Local_u8Counter = 0;
	while(P_s8String[Local_u8Counter] != '\0')
	{
		LCD_voidSendData(P_s8String[Local_u8Counter]);
		Local_u8Counter++;
	}
}
void LCD_voidSetCursor(u8 Copy_u8Row ,u8 Copy_u8Column ){
	u8 Local_u8adress = 0;
	switch (Copy_u8Row)
	{  case LCD_U8_ROW_1 :
		Local_u8adress = (0x80 +Copy_u8Column ) ; break;
		case LCD_U8_ROW_2 :
		Local_u8adress =( 0xC0 +Copy_u8Column ) ; break;
	}
	LCD_voidSendCommand(Local_u8adress);
}
void LCD_voidClearDisplay(void){
	LCD_voidSendCommand( 0b00000001   );
}