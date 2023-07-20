/*
 * ServoMotor.c
 *
 * Created: 6/18/2023 11:03:31 AM
 *  Author: Moaz Refaat
 */ 
#include "ServoMotor.h"

void  Door_Controle(void)
{
	first :
	LCD_voidSendString("Door Open : 1  ");
	LCD_voidSetCursor(LCD_U8_ROW_2 , LCD_u8_COLUMN_1);
	LCD_voidSendString("Door close : 2  ");
	while (KEYPAD_u8GetPressedButton()=='\0');
	switch ( KEYPAD_u8GetPressedButton() )
	{
		case '1':
		TIMER2_void_SetCompareVal(25);
		_delay_ms(100);
		break;
		case '2':
		TIMER2_void_SetCompareVal(12);
		_delay_ms(100);
		break;
		default:
		return;
	}
	LCD_voidClearDisplay();
	goto first ;
}