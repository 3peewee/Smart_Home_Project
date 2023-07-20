/*
 * Led.h
 *
 * Created: 6/18/2023 11:03:03 AM
 *  Author: Moaz Refaat
 */ 


#ifndef LED_H_
#define LED_H_
#define F_CPU 10000000UL
#include <util/delay.h>

#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\Service\STD_types.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\MCAL\DIO_int.h"
#include "LCD_int.h"
#include "KEYPAD_int.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\MCAL\Timer_int.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\MCAL\Timer2_int.h"
void  Dimmer_Controle(void);
void  Led_Controle(void);



#endif /* LED_H_ */