/*
 * final_project.c
 *
 * Created: 12/5/2023 3:01:13 PM
 * Author : Moaz Refaat
 */ 
#define  F_CPU 10000000UL
#include <util/delay.h>
#include <avr/interrupt.h>


#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\Service\STD_types.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\Service\BIT_math.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\MCAL\DIO_int.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\HAL\LCD_int.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\HAL\KEYPAD_int.h"

extern int length;
extern int Is_There_Admin;
#include "interfacee.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\MCAL\EEPROM.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\MCAL\Timer_int.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\MCAL\Timer2_int.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\MCAL\ADC_int.h"
//#include "MCAL/UART_int.h"
//#include "MCAL/EXTI_int.h"
//#include "MCAL/GIE_int.h"

#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\HAL\BUZ_int.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\HAL\Led.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\HAL\ServoMotor.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\HAL\DCMotor.h"
u8 Home_User [5];
u8 Home_Pass [5];


/*
ISR(USART_RXC_vect)  // received someting , go read it
{
	LCD_voidSendString("adminnnn");
	while (KEYPAD_u8GetPressedButton()=='\0');
	u8 Home_AllData [10];
	
	UART_voidReieveString(Home_AllData) ;
	
	Home_Pass[0]=Home_AllData[0];
	Home_Pass[1]=Home_AllData[1];
	Home_Pass[2]=Home_AllData[2];
	Home_Pass[3]=Home_AllData[3];
	Home_Pass[4]=Home_AllData[4];
	Home_User[0]=Home_AllData[5];
	Home_User[1]=Home_AllData[6];
	Home_User[2]=Home_AllData[7];
	Home_User[3]=Home_AllData[8];
	Home_User[4]=Home_AllData[9];
	 LCD_voidSendString("adminnnn");
	 while (KEYPAD_u8GetPressedButton()=='\0');
	////////////////////////////////////
	if (IsUserExist(Home_Pass,Home_User))
	{UART_voidSendByte('a');
	}
	else{UART_voidSendByte('b');
		
	}
	
}
 */
int main(void)
{
	DIO_voidInit();
	LCD_voidInit();
	KEYPAD_voidInit();
	//UART_voidInit();
//EXTI_voidInit();
//EXTI_voidEnable_INT0();
TIMER0_void_Init();
TIMER2_void_Init();
//GIE_voidEnable();
//GIE_voidDisable();
ADC_voidInit();
TIMER2_void_SetCompareVal(12) ;

f32 Local_u8Analog = 0;
u16 Local_u8Digital = 0;
int Buz_Flag = 0 ;
length =1 ;
	while (1)
	{   
		 u8 Check_Eeprom_Admin =EEPROM_ui8ReadByteFromAddress(0x0029) ;
		
		if (Check_Eeprom_Admin==5)
		/* admin has already registered */
		/* now he can login */
/*11111111*/ { /*11111111*/ 
		while (KEYPAD_u8GetPressedButton()=='\0');
		LCD_voidClearDisplay();
		LCD_voidSendString("admin :+");
		LCD_voidSetCursor(LCD_U8_ROW_2 , LCD_u8_COLUMN_1);
		LCD_voidSendString("user: - ");	
		while (KEYPAD_u8GetPressedButton()=='\0');
		if (KEYPAD_u8GetPressedButton() == '+' )
/*222222 */ { /*222222 */ // Logging as admin */ 
			
			LCD_voidClearDisplay();
			   u8 admin_Check[5] ;
			   u8 Admin_Pass_Check[5] ;
			   Read_Name_Pass( admin_Check , Admin_Pass_Check);
			while (KEYPAD_u8GetPressedButton()=='\0');
			if (IsAdminExist(Admin_Pass_Check,admin_Check))
	/*3333*/ 		{ /* admin successful login */
				LCD_voidSendString("successful login ");
				LCD_voidClearDisplay();
				
			if (Buz_Flag!=0){
			Buz_Flag=0;
			}
				LCD_voidSendString("System :1 ");
				LCD_voidSetCursor(LCD_U8_ROW_2 , LCD_u8_COLUMN_1);
				
				LCD_voidSendString("registering:+  ");
				LCD_voidSetCursor(LCD_U8_ROW_1 , LCD_u8_COLUMN_15);
				LCD_voidSendString("delete:- ");
				LCD_voidSetCursor(LCD_U8_ROW_2 , LCD_u8_COLUMN_15);
				LCD_voidSendString("For exit : X ");
				while (KEYPAD_u8GetPressedButton()=='\0');
				LCD_voidClearDisplay();
				if (KEYPAD_u8GetPressedButton() == 'X')
				{
					continue;
				}
				else if (KEYPAD_u8GetPressedButton() == '+')
				{
					u8 user_Jar[5] ;
					u8 Pass_Jar[5] ;
				 Read_Name_Pass( user_Jar, Pass_Jar);

					
					if (AddEntry(user_Jar,Pass_Jar))
					{
						LCD_voidSendString("added successfully ");
						
						
					}
					else{
						LCD_voidSendString("wasnt added successfully ");
						LCD_voidSetCursor(LCD_U8_ROW_2 , LCD_u8_COLUMN_1);
						LCD_voidSendString("database is complete");
					}
					LCD_voidClearDisplay();
					LCD_voidSetCursor(LCD_U8_ROW_2 , LCD_u8_COLUMN_1);
					LCD_voidSendString("For exit : X ");
					while (KEYPAD_u8GetPressedButton()=='\0');
					LCD_voidClearDisplay();
					if (KEYPAD_u8GetPressedButton() == 'X')
					{
						continue;
					}
					
					
				}
				else if (KEYPAD_u8GetPressedButton() == '-')
				{
					u8 user_Delete[5] ;
					u8 Pass_Delete[5] ;
					 Read_Name_Pass( user_Delete , Pass_Delete);

					
					
					while (KEYPAD_u8GetPressedButton()=='\0');
					if (Find_Delete(Pass_Delete,user_Delete))
					{
						
						LCD_voidSendString(" deleted successfully ");
						while (KEYPAD_u8GetPressedButton()=='\0');
						LCD_voidClearDisplay();
						LCD_voidSetCursor(LCD_U8_ROW_2 , LCD_u8_COLUMN_1);
						LCD_voidSendString("For exit : X ");
						while (KEYPAD_u8GetPressedButton()=='\0');
						LCD_voidClearDisplay();
						if (KEYPAD_u8GetPressedButton() == 'X')
						{
							continue;
						}
					}
					else{
						LCD_voidSendString("dont exist  ");
						LCD_voidSetCursor(LCD_U8_ROW_2 , LCD_u8_COLUMN_1);
						LCD_voidSendString("try again ");
						while (KEYPAD_u8GetPressedButton()=='\0');
						LCD_voidClearDisplay();
						continue;
						
				}
				}
				else{
					
		///////////////////////////////////////////////////* admin's system */
					LCD_voidSendString("welcome to system ");
					
					Local_u8Digital = ADC_u16Convert(ADC_u8_Channel0);
					Local_u8Analog = ((f32)(Local_u8Digital) * 5.0) / 10.24;
					//itoa ( Local_u8Analog, buffer, 10);
					//dtostrf(float_value, min_width, num_digits_after_decimal, where_to_store_string)
					//dtostrf(Local_u8Analog, 20, 15, buffer);
					//LCD_voidSendString(buffer);
					//_delay_ms(50);
					
					if (Local_u8Analog >= 25 )
					{
						Dc_Motor_Enable();
					}
					else{
					Dc_Motor_Disable();
					}
					LCD_voidClearDisplay();
					LCD_voidSendString("for System Controle :1 ");
					LCD_voidSetCursor(LCD_U8_ROW_2 , LCD_u8_COLUMN_1);
					LCD_voidSendString("For exit : X ");
					while (KEYPAD_u8GetPressedButton()=='\0');
					LCD_voidClearDisplay();
					if (KEYPAD_u8GetPressedButton() == '1'){
						
						switch (Sys_Contole())
						{
							case '1':
							LCD_voidClearDisplay();
							Led_Controle();
							
							break;
							case '2':
							LCD_voidClearDisplay();
							Dimmer_Controle();
							
							break;
							case '3':
							LCD_voidClearDisplay();
							Door_Controle();
							break;
						}
					}
					
		////////////	///	///////////////////////////////
				}
				
			}
			
		/* 33333 */ /* admin hasn't successfully logged in */ 	
	else{
			LCD_voidSendString("wrong admin password ");
			LCD_voidSetCursor(LCD_U8_ROW_2 , LCD_u8_COLUMN_1);
			LCD_voidSendString("try again ");
			Buz_Flag++;
			if (Buz_Flag==3){
				Buz_Flag=0;
					BUZ_voidSetAlarm();
					continue;
			}
			while (KEYPAD_u8GetPressedButton()=='\0');
			LCD_voidClearDisplay();
			continue;
		// counter to  check how many times he tryed .
		// then a buzzer should work 
		}
		
		
/*222222*/ } /*222222*///user login ///////////////////////
	
		else{
			
			
			LCD_voidClearDisplay();
			u8 user_Check[5] ;
			u8 Pass_Check[5] ;
			
			 Read_Name_Pass( user_Check , Pass_Check);
			
			while (KEYPAD_u8GetPressedButton()=='\0');
			if (IsUserExist(Pass_Check,user_Check))
			{   
				if (Buz_Flag!=0){
					Buz_Flag=0;
				}
				LCD_voidSendString("successful login ");
				LCD_voidClearDisplay();
				
				///////////////////////////////////////////////////* user's system */
				LCD_voidSendString("welcome to system ");
				
				Local_u8Digital = ADC_u16Convert(ADC_u8_Channel0);
				Local_u8Analog = ((f32)(Local_u8Digital) * 5.0) / 10.24;
				//itoa ( Local_u8Analog, buffer, 10);
				//dtostrf(float_value, min_width, num_digits_after_decimal, where_to_store_string)
				//dtostrf(Local_u8Analog, 20, 15, buffer);
				//LCD_voidSendString(buffer);
				//_delay_ms(50);
				
				if (Local_u8Analog >= 25 )
				{
					Dc_Motor_Enable();
				}
				else{
					Dc_Motor_Disable();
				}
				LCD_voidClearDisplay();
				LCD_voidSendString("for System Controle :1 ");
				LCD_voidSetCursor(LCD_U8_ROW_2 , LCD_u8_COLUMN_1);
				LCD_voidSendString("For exit : X ");
				while (KEYPAD_u8GetPressedButton()=='\0');
				LCD_voidClearDisplay();
				if (KEYPAD_u8GetPressedButton() == 'X')
				{
					continue;
				}
				else if (KEYPAD_u8GetPressedButton() == '1'){
					
					switch (Sys_Contole_For_User())
					{
						case '1':
						LCD_voidClearDisplay();
						Led_Controle();
						
						break;
						case '2':
						LCD_voidClearDisplay();
						Dimmer_Controle();
						
						break;
						
					}
				}
				
				////////////	///	/////////////////////////////// 
				
				/////////////////////////////
				
			}
			else{
				LCD_voidSendString("wrong password ");
				LCD_voidSetCursor(LCD_U8_ROW_2 , LCD_u8_COLUMN_1);
				LCD_voidSendString("try again ");
				Buz_Flag++;
				if (Buz_Flag==3){
					Buz_Flag=0;
					BUZ_voidSetAlarm();
					continue;
				}
				while (KEYPAD_u8GetPressedButton()=='\0');
				LCD_voidClearDisplay();
				continue;
			}
			
		}
		
		
	
	/*11111111*/ } /*11111111*/ 
		
		else{
			///////////////////////////////////////
			//there is no admin , we will ask them to register thier admin
			LCD_voidSendString(" First time  ? . Register as admin ");
			LCD_voidSetCursor(LCD_U8_ROW_2 , LCD_u8_COLUMN_1);
			u8 admin_Jar[5] ;
			u8 Admin_Pass_Jar[5] ;
			
			 Read_Name_Pass( admin_Jar, Admin_Pass_Jar);

			if (AddAdmin(admin_Jar,Admin_Pass_Jar))
			{
				LCD_voidSendString("added successfully ");
				LCD_voidClearDisplay();
				LCD_voidSetCursor(LCD_U8_ROW_2 , LCD_u8_COLUMN_1);
				LCD_voidSendString("For exit : X ");
				while (KEYPAD_u8GetPressedButton()=='\0');
				LCD_voidClearDisplay();
				if (KEYPAD_u8GetPressedButton() == 'X')
				{
					continue;
				}
				
			}
			
			
		}
	
	
	
	////////////		
		}
		
	}
	


//put after /*22222*/ { /* 22222*/
/* code to check how many users has login 

while (KEYPAD_u8GetPressedButton()=='\0');
u8 Check_Eeprom =EEPROM_ui8ReadByteFromAddress(0x001E) ;
switch (Check_Eeprom )
{case 0 :
	length = 0;
	break ;
	case 1:
	length = 1;
	break ;
	case 2 :
	length = 2;
	break ;
	case 3 :
	length = 3 ;
	break ;
	
}


switch (length )
{
	case 0 :
	LCD_voidSendString("zero");
	break ;
	case 1:
	LCD_voidSendString("one ");
	break ;
	case 2 :
	LCD_voidSendString("two ");
	break ;
	case 3 :
	LCD_voidSendString("three");
	break ;
	default:
	LCD_voidSendString("other ");
	break ;
	
}
*/
//for clearing EEprom from software .
//write digital 1 to the address .
//EEPROM_vWriteByteToAddress(0x001E,1);
/*
EEPROM_vWriteByteToAddress(0x001F,1);
EEPROM_vWriteByteToAddress(0x0020,1);
EEPROM_vWriteByteToAddress(0x0021,1);
EEPROM_vWriteByteToAddress(0x0022,1);
EEPROM_vWriteByteToAddress(0x0023,1);

EEPROM_vWriteByteToAddress(0x0024,1);
EEPROM_vWriteByteToAddress(0x0025,1);
EEPROM_vWriteByteToAddress(0x0026,1);
EEPROM_vWriteByteToAddress(0x0027,1);
EEPROM_vWriteByteToAddress(0x0028,1);
EEPROM_vWriteByteToAddress(0x0029,1);

EEPROM_vWriteByteToAddress(0x0000,1);
EEPROM_vWriteByteToAddress(0x0001,1);
EEPROM_vWriteByteToAddress(0x0002,1);
EEPROM_vWriteByteToAddress(0x0003,1);
EEPROM_vWriteByteToAddress(0x0004,1);

EEPROM_vWriteByteToAddress(0x0005,1);
EEPROM_vWriteByteToAddress(0x0006,1);
EEPROM_vWriteByteToAddress(0x0007,1);
EEPROM_vWriteByteToAddress(0x0008,1);
EEPROM_vWriteByteToAddress(0x0009,1);
EEPROM_vWriteByteToAddress(0x001E,1);
 */ 