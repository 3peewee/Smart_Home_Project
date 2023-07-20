
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\Service\STD_types.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\Service\BIT_math.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\MCAL\DIO_int.h"
#include "KEYPAD_int.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"

void KEYPAD_voidInit(void)
{
	#if KEYPAD_U8_MODE == KEYPAD_U8_INTERNAL_RES
	
	DIO_voidSetPinValue(KEYPAD_U8_C1 , DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_C2 , DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_C3 , DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_C4 , DIO_U8_HIGH);
	
	#elif KEYPAD_U8_MODE == KEYPAD_U8_EXTERNAL_RES
	
	#endif
}

u8 KEYPAD_u8GetPressedButton(void)
{
	DIO_voidSetPinValue(KEYPAD_U8_R1 , DIO_U8_LOW);
	DIO_voidSetPinValue(KEYPAD_U8_R2 , DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_R3 , DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_R4 , DIO_U8_HIGH);
	
	if(DIO_u8GetPinValue(KEYPAD_U8_C1) == 0)
	{
		return KEYPAD_U8_R1C1;
	}
	else if(DIO_u8GetPinValue(KEYPAD_U8_C2) == 0)
	{
		return KEYPAD_U8_R1C2;
	}
	else if(DIO_u8GetPinValue(KEYPAD_U8_C3) == 0)
	{
		return KEYPAD_U8_R1C3;
	}
	else if(DIO_u8GetPinValue(KEYPAD_U8_C4) == 0)
	{
		return KEYPAD_U8_R1C4;
	}
	
	DIO_voidSetPinValue(KEYPAD_U8_R1 , DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_R2 , DIO_U8_LOW);
	DIO_voidSetPinValue(KEYPAD_U8_R3 , DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_R4 , DIO_U8_HIGH);
	
	if(DIO_u8GetPinValue(KEYPAD_U8_C1) == 0)
	{
		return KEYPAD_U8_R2C1;
	}
	else if(DIO_u8GetPinValue(KEYPAD_U8_C2) == 0)
	{
		return KEYPAD_U8_R2C2;
	}
	else if(DIO_u8GetPinValue(KEYPAD_U8_C3) == 0)
	{
		return KEYPAD_U8_R2C3;
	}
	else if(DIO_u8GetPinValue(KEYPAD_U8_C4) == 0)
	{
		return KEYPAD_U8_R2C4;
	}
	
	DIO_voidSetPinValue(KEYPAD_U8_R1 , DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_R2 , DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_R3 , DIO_U8_LOW);
	DIO_voidSetPinValue(KEYPAD_U8_R4 , DIO_U8_HIGH);
	
	if(DIO_u8GetPinValue(KEYPAD_U8_C1) == 0)
	{
		return KEYPAD_U8_R3C1;
	}
	else if(DIO_u8GetPinValue(KEYPAD_U8_C2) == 0)
	{
		return KEYPAD_U8_R3C2;
	}
	else if(DIO_u8GetPinValue(KEYPAD_U8_C3) == 0)
	{
		return KEYPAD_U8_R3C3;
	}
	else if(DIO_u8GetPinValue(KEYPAD_U8_C4) == 0)
	{
		return KEYPAD_U8_R3C4;
	}
	
	DIO_voidSetPinValue(KEYPAD_U8_R1 , DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_R2 , DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_R3 , DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_R4 , DIO_U8_LOW);
	
	if(DIO_u8GetPinValue(KEYPAD_U8_C1) == 0)
	{
		return KEYPAD_U8_R4C1;
	}
	else if(DIO_u8GetPinValue(KEYPAD_U8_C2) == 0)
	{
		return KEYPAD_U8_R4C2;
	}
	else if(DIO_u8GetPinValue(KEYPAD_U8_C3) == 0)
	{
		return KEYPAD_U8_R4C3;
	}
	else if(DIO_u8GetPinValue(KEYPAD_U8_C4) == 0)
	{
		return KEYPAD_U8_R4C4;
	}	
	
	return KEYPAD_U8_NULL;
}