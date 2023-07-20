/*
 * Buzzer.c
 *
 * Created: 12/22/2022 4:48:14 PM
 *  Author: gehad
 */ 


#include "BUZ_int.h"

#define F_CPU 10000000UL
#include <util/delay.h>



void BUZ_voidSetAlarm(void)
{
	DIO_voidSetPinValue(BUZ_U8_A , DIO_U8_HIGH);
	_delay_ms(100);
	DIO_voidSetPinValue(BUZ_U8_A , DIO_U8_LOW);
}