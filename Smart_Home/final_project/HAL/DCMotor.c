/*
 * DCMotor.c
 *
 * Created: 6/18/2023 11:01:32 AM
 *  Author: Moaz Refaat
 */ 

#include "DCMotor.h" 
 void Dc_Motor_Enable(void){
	 DIO_voidSetPinValue(DIO_U8_PIN23,DIO_U8_HIGH);
 }
 void Dc_Motor_Disable(void) {
	 
	  DIO_voidSetPinValue(DIO_U8_PIN23,DIO_U8_LOW);
 }
