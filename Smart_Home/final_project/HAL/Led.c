/*
 * Led.c
 *
 * Created: 6/18/2023 11:03:15 AM
 *  Author: Moaz Refaat
 */ 
#include "Led.h" 
void  Dimmer_Controle(void){
	
	static f32  duty = 0 ;
	LCD_voidSendString("inc intensity: +");
	LCD_voidSetCursor(LCD_U8_ROW_2 , LCD_u8_COLUMN_1);
	LCD_voidSendString("dec intinsity: -");
	LCD_voidSetCursor(LCD_U8_ROW_2 , LCD_u8_COLUMN_16);
	LCD_voidSendString("Exit: 1 ");
	first :
	while (KEYPAD_u8GetPressedButton()=='\0');
	if(KEYPAD_u8GetPressedButton()=='1')
	return ;
	while (KEYPAD_u8GetPressedButton()=='+')
	{ for(duty ; duty<100; duty+=.5)
		{
			TIMER0_void_SetCompareVal(duty);
			if (KEYPAD_u8GetPressedButton()=='\0')
			break;
			_delay_ms(8);
		}
		
	}
	
	
	while (KEYPAD_u8GetPressedButton()=='-')
	{
		for(duty ; duty>1; duty-=5)
		{
			TIMER0_void_SetCompareVal(duty);
			if (KEYPAD_u8GetPressedButton()=='\0')
			break;
			_delay_ms(30);
			
		}
	}
	
	goto first ;
}

void  Led_Controle(void){
	
	first :
	LCD_voidSendString("Toggle led no :1,2,3,4,5");
	LCD_voidSetCursor(LCD_U8_ROW_2 , LCD_u8_COLUMN_1);
	LCD_voidSendString("for exit : X  ");
	while (KEYPAD_u8GetPressedButton()=='\0');
	switch ( KEYPAD_u8GetPressedButton() )
	{
		case '1' :
		if (DIO_u8GetPinValue(DIO_U8_PIN24))
		DIO_voidSetPinValue(DIO_U8_PIN24, DIO_U8_LOW);
		else
		DIO_voidSetPinValue(DIO_U8_PIN24, DIO_U8_HIGH);
		break;
		case '2':
		if (DIO_u8GetPinValue(DIO_U8_PIN25))
		DIO_voidSetPinValue(DIO_U8_PIN25, DIO_U8_LOW);
		else
		DIO_voidSetPinValue(DIO_U8_PIN25, DIO_U8_HIGH);
		break;
		case '3' :
		if (DIO_u8GetPinValue(DIO_U8_PIN26))
		DIO_voidSetPinValue(DIO_U8_PIN26, DIO_U8_LOW);
		else
		DIO_voidSetPinValue(DIO_U8_PIN26, DIO_U8_HIGH);
		break ;
		case '4' :
		if (DIO_u8GetPinValue(DIO_U8_PIN28))
		DIO_voidSetPinValue(DIO_U8_PIN28, DIO_U8_LOW);
		else
		DIO_voidSetPinValue(DIO_U8_PIN28, DIO_U8_HIGH);
		break ;
		case '5' :
		if (DIO_u8GetPinValue(DIO_U8_PIN29))
		DIO_voidSetPinValue(DIO_U8_PIN29, DIO_U8_LOW);
		else
		DIO_voidSetPinValue(DIO_U8_PIN29, DIO_U8_HIGH);
		break;
		case 'X' :
		return ;
		default:
		return ;
	}
	LCD_voidClearDisplay();
	goto first ;
}