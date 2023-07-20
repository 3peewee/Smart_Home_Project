/*
 * interfacee.h
 *
 * Created: 12/3/2022 10:45:54 PM
 *  Author: Moaz Refaat
 */ 


#ifndef INTERFACEE_H_
#define INTERFACEE_H_
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\Service\STD_types.h"

#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\MCAL\DIO_int.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\HAL\LCD_int.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\HAL\KEYPAD_int.h"

#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\MCAL\EEPROM.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\MCAL\Timer_int.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\MCAL\Timer2_int.h"
typedef enum {false, true} bool;

/* 
struct  User{
	u8   UserName[10];
	u8    PassWord[10];
	//u8   Mode ;
	//u8   Authority  ;
	struct User *next ; // next is a name of a pointer that points to a node type , and also it is amember .
};
*/
bool IsAdminExist(u8 Check_Password[] ,u8 Check_UserName[] );
bool AddEntry ( u8 Enter_UserName[]  ,u8 Enter_Password[] );
bool IsUserExist(u8 Check_Password[] ,u8 Check_UserName[] );
bool Find_Delete(u8 Check_Password[] ,u8 Check_UserName[] );
int SBD_GetUsedSize(void);
bool AddAdmin ( u8 Enter_Admin[]  ,u8 Enter_Admin_Password[] );
void Read_Name_Pass(u8 ReadName[5] ,u8 ReadPass[5]);
int SBD_GetUsedSize(void);
u8 Sys_Contole(void);
u8 Sys_Contole_For_User(void);
#endif /* INTERFACEE_H_ */
///////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
