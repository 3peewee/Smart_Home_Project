/*
 * progg.c
 *
 * Created: 12/3/2022 10:45:27 PM
 *  Author: Moaz Refaat
 */ 

#include "interfacee.h"

  int Is_There_Admin=0;
  int length=0;
//struct User* headone =NULL ;
//int flag=0 ;
void Read_Name_Pass(u8 ReadName[5] ,u8 ReadPass[5])
{
	LCD_voidSendString("enter username");
	while (KEYPAD_u8GetPressedButton()=='\0');
	while (KEYPAD_u8GetPressedButton()=='\0'); // wait here till he writes something
	LCD_voidClearDisplay();
	for (int i = 0 ; i<5 ;i++)
	{
		ReadName[i]  = KEYPAD_u8GetPressedButton();
		LCD_voidSendData('*');
		while(KEYPAD_u8GetPressedButton() != KEYPAD_U8_NULL);
		while (KEYPAD_u8GetPressedButton()=='\0');
	}
	LCD_voidClearDisplay();
	////////////
	LCD_voidSendString("enter password");
	while (KEYPAD_u8GetPressedButton()=='\0');
	LCD_voidClearDisplay();
	
	for (int i = 0 ; i<5 ;i++)
	{
		ReadPass[i]  = KEYPAD_u8GetPressedButton();
			LCD_voidSendData('*');
		while(KEYPAD_u8GetPressedButton() != KEYPAD_U8_NULL);
		while (KEYPAD_u8GetPressedButton()=='\0');
	}
	LCD_voidClearDisplay();	
}

bool AddAdmin ( u8 Enter_Admin[]  ,u8 Enter_Admin_Password[] ){
	
		EEPROM_vWriteByteToAddress(0x001F,Enter_Admin[0]);
		EEPROM_vWriteByteToAddress(0x0020,Enter_Admin[1]);
		EEPROM_vWriteByteToAddress(0x0021,Enter_Admin[2]);
		EEPROM_vWriteByteToAddress(0x0022,Enter_Admin[3]);
		EEPROM_vWriteByteToAddress(0x0023,Enter_Admin[4]);
		
		EEPROM_vWriteByteToAddress(0x0024,Enter_Admin_Password[0]);
		EEPROM_vWriteByteToAddress(0x0025,Enter_Admin_Password[1]);
		EEPROM_vWriteByteToAddress(0x0026,Enter_Admin_Password[2]);
		EEPROM_vWriteByteToAddress(0x0027,Enter_Admin_Password[3]);
		EEPROM_vWriteByteToAddress(0x0028,Enter_Admin_Password[4]);
		EEPROM_vWriteByteToAddress(0x0029,5);
		Is_There_Admin++;
		return true;
	
}
bool IsAdminExist(u8 Check_Password[] ,u8 Check_UserName[] ){
	if ((EEPROM_ui8ReadByteFromAddress(0x001F) == Check_UserName[0])&&(EEPROM_ui8ReadByteFromAddress(0x0020) == Check_UserName[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0021) == Check_UserName[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0022) == Check_UserName[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0023) == Check_UserName[4]) )
	{
		if ((EEPROM_ui8ReadByteFromAddress(0x0024) == Check_Password[0])&&(EEPROM_ui8ReadByteFromAddress(0x0025) == Check_Password[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0026) == Check_Password[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0027) == Check_Password[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0028) == Check_Password[4]) )
		{
			return true ;
		}
	}
	return false ;
	
	
}
bool AddEntry ( u8 Enter_UserName[]  ,u8 Enter_Password[] ) {

		switch (length)
		{   case 0 :
			EEPROM_vWriteByteToAddress(0x0000,Enter_UserName[0]);
			EEPROM_vWriteByteToAddress(0x0001,Enter_UserName[1]);
			EEPROM_vWriteByteToAddress(0x0002,Enter_UserName[2]);
			EEPROM_vWriteByteToAddress(0x0003,Enter_UserName[3]);
			EEPROM_vWriteByteToAddress(0x0004,Enter_UserName[4]);
			
			EEPROM_vWriteByteToAddress(0x0005,Enter_Password[0]);
			EEPROM_vWriteByteToAddress(0x0006,Enter_Password[1]);
			EEPROM_vWriteByteToAddress(0x0007,Enter_Password[2]);
			EEPROM_vWriteByteToAddress(0x0008,Enter_Password[3]);
			EEPROM_vWriteByteToAddress(0x0009,Enter_Password[4]);
			EEPROM_vWriteByteToAddress(0x001E,1);
			length++;
			break;  //optional
			
			case 1 :
			EEPROM_vWriteByteToAddress(0x000A,Enter_UserName[0]);
			EEPROM_vWriteByteToAddress(0x000B,Enter_UserName[1]);
			EEPROM_vWriteByteToAddress(0x000C,Enter_UserName[2]);
			EEPROM_vWriteByteToAddress(0x000D,Enter_UserName[3]);
			EEPROM_vWriteByteToAddress(0x000E,Enter_UserName[4]);
			
			EEPROM_vWriteByteToAddress(0x000F,Enter_Password[0]);
			EEPROM_vWriteByteToAddress(0x0010,Enter_Password[1]);
			EEPROM_vWriteByteToAddress(0x0011,Enter_Password[2]);
			EEPROM_vWriteByteToAddress(0x0012,Enter_Password[3]);
			EEPROM_vWriteByteToAddress(0x0013,Enter_Password[4]);
			EEPROM_vWriteByteToAddress(0x001E,2);
			length++;
			break;  //optional
			
			case 2 :
			EEPROM_vWriteByteToAddress(0x0014,Enter_UserName[0]);
			EEPROM_vWriteByteToAddress(0x0015,Enter_UserName[1]);
			EEPROM_vWriteByteToAddress(0x0016,Enter_UserName[2]);
			EEPROM_vWriteByteToAddress(0x0017,Enter_UserName[3]);
			EEPROM_vWriteByteToAddress(0x0018,Enter_UserName[4]);
			
			EEPROM_vWriteByteToAddress(0x0019,Enter_Password[0]);
			EEPROM_vWriteByteToAddress(0x001A,Enter_Password[1]);
			EEPROM_vWriteByteToAddress(0x001B,Enter_Password[2]);
			EEPROM_vWriteByteToAddress(0x001C,Enter_Password[3]);
			EEPROM_vWriteByteToAddress(0x001D,Enter_Password[4]);
		    EEPROM_vWriteByteToAddress(0x001E,3);
		    length++;
			
			break;  //optional
			
			default:
			return false ;
		}
			
		return true ;

}
// flag is global in main .
bool IsUserExist(u8 Check_Password[] ,u8 Check_UserName[] ){


switch (length)
 
{
	 
	   case 1 :
	if ((EEPROM_ui8ReadByteFromAddress(0x0000) == Check_UserName[0])&&(EEPROM_ui8ReadByteFromAddress(0x0001) == Check_UserName[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0002) == Check_UserName[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0003) == Check_UserName[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0004) == Check_UserName[4]) )
	{
		if ((EEPROM_ui8ReadByteFromAddress(0x0005) == Check_Password[0])&&(EEPROM_ui8ReadByteFromAddress(0x0006) == Check_Password[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0007) == Check_Password[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0008) == Check_Password[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0009) == Check_Password[4]) )
		{ 
			return true ;
		}
	}
	
	
	break;  //optional
	
	case 2 :
	if ((EEPROM_ui8ReadByteFromAddress(0x0000) == Check_UserName[0])&&(EEPROM_ui8ReadByteFromAddress(0x0001) == Check_UserName[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0002) == Check_UserName[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0003) == Check_UserName[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0004) == Check_UserName[4]) )
	{
		if ((EEPROM_ui8ReadByteFromAddress(0x0005) == Check_Password[0])&&(EEPROM_ui8ReadByteFromAddress(0x0006) == Check_Password[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0007) == Check_Password[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0008) == Check_Password[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0009) == Check_Password[4]) )
		{
			return true ;
		}
	}
	 
	 if ((EEPROM_ui8ReadByteFromAddress(0x000A) == Check_UserName[0])&&(EEPROM_ui8ReadByteFromAddress(0x000B) == Check_UserName[1]) &&(EEPROM_ui8ReadByteFromAddress(0x000C) == Check_UserName[2]) &&(EEPROM_ui8ReadByteFromAddress(0x000D) == Check_UserName[3]) &&(EEPROM_ui8ReadByteFromAddress(0x000E) == Check_UserName[4]) )
	 {
		 if ((EEPROM_ui8ReadByteFromAddress(0x000F) == Check_Password[0])&&(EEPROM_ui8ReadByteFromAddress(0x0010) == Check_Password[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0011) == Check_Password[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0012) == Check_Password[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0013) == Check_Password[4]) )
		 {
			 return true ;
		 }
	 }
	

	break;  //optional
	
	case 3 :
	if ((EEPROM_ui8ReadByteFromAddress(0x0000) == Check_UserName[0])&&(EEPROM_ui8ReadByteFromAddress(0x0001) == Check_UserName[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0002) == Check_UserName[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0003) == Check_UserName[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0004) == Check_UserName[4]) )
		{
			if ((EEPROM_ui8ReadByteFromAddress(0x0005) == Check_Password[0])&&(EEPROM_ui8ReadByteFromAddress(0x0006) == Check_Password[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0007) == Check_Password[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0008) == Check_Password[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0009) == Check_Password[4]) )
			{
				return true ;
			}
		}
		
		if ((EEPROM_ui8ReadByteFromAddress(0x000A) == Check_UserName[0])&&(EEPROM_ui8ReadByteFromAddress(0x000B) == Check_UserName[1]) &&(EEPROM_ui8ReadByteFromAddress(0x000C) == Check_UserName[2]) &&(EEPROM_ui8ReadByteFromAddress(0x000D) == Check_UserName[3]) &&(EEPROM_ui8ReadByteFromAddress(0x000E) == Check_UserName[4]) )
		{
			if ((EEPROM_ui8ReadByteFromAddress(0x000F) == Check_Password[0])&&(EEPROM_ui8ReadByteFromAddress(0x0010) == Check_Password[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0011) == Check_Password[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0012) == Check_Password[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0013) == Check_Password[4]) )
			{
				return true ;
			}
		}
	
	if ((EEPROM_ui8ReadByteFromAddress(0x0014) == Check_UserName[0])&&(EEPROM_ui8ReadByteFromAddress(0x0015) == Check_UserName[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0016) == Check_UserName[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0017) == Check_UserName[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0018) == Check_UserName[4]) )
	{
		if ((EEPROM_ui8ReadByteFromAddress(0x0019) == Check_Password[0])&&(EEPROM_ui8ReadByteFromAddress(0x001A) == Check_Password[1]) &&(EEPROM_ui8ReadByteFromAddress(0x001B) == Check_Password[2]) &&(EEPROM_ui8ReadByteFromAddress(0x001C) == Check_Password[3]) &&(EEPROM_ui8ReadByteFromAddress(0x001D) == Check_Password[4]) )
		{
			return true ;
		}
	}
	

	break;  //optional
	
	default:
	return false ;
}
return false ;

}

bool Find_Delete(u8 Check_Password[] ,u8 Check_UserName[] ){


	switch (length)
	
	{
		
		case 1 :
		if ((EEPROM_ui8ReadByteFromAddress(0x0000) == Check_UserName[0])&&(EEPROM_ui8ReadByteFromAddress(0x0001) == Check_UserName[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0002) == Check_UserName[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0003) == Check_UserName[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0004) == Check_UserName[4]) )
		{
			if ((EEPROM_ui8ReadByteFromAddress(0x0005) == Check_Password[0])&&(EEPROM_ui8ReadByteFromAddress(0x0006) == Check_Password[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0007) == Check_Password[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0008) == Check_Password[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0009) == Check_Password[4]) )
			{
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
				EEPROM_vWriteByteToAddress(0x001E,0);
				return true ;
			}
		}
		
		
		break;  //optional
		
		case 2 :
		if ((EEPROM_ui8ReadByteFromAddress(0x0000) == Check_UserName[0])&&(EEPROM_ui8ReadByteFromAddress(0x0001) == Check_UserName[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0002) == Check_UserName[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0003) == Check_UserName[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0004) == Check_UserName[4]) )
		{
			if ((EEPROM_ui8ReadByteFromAddress(0x0005) == Check_Password[0])&&(EEPROM_ui8ReadByteFromAddress(0x0006) == Check_Password[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0007) == Check_Password[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0008) == Check_Password[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0009) == Check_Password[4]) )
			{   
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
				return true ;
				
			}
		}
		
		if ((EEPROM_ui8ReadByteFromAddress(0x000A) == Check_UserName[0])&&(EEPROM_ui8ReadByteFromAddress(0x000B) == Check_UserName[1]) &&(EEPROM_ui8ReadByteFromAddress(0x000C) == Check_UserName[2]) &&(EEPROM_ui8ReadByteFromAddress(0x000D) == Check_UserName[3]) &&(EEPROM_ui8ReadByteFromAddress(0x000E) == Check_UserName[4]) )
		{
			if ((EEPROM_ui8ReadByteFromAddress(0x000F) == Check_Password[0])&&(EEPROM_ui8ReadByteFromAddress(0x0010) == Check_Password[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0011) == Check_Password[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0012) == Check_Password[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0013) == Check_Password[4]) )
			{   
				EEPROM_vWriteByteToAddress(0x000A,1);
				EEPROM_vWriteByteToAddress(0x000B,1);
				EEPROM_vWriteByteToAddress(0x000C,1);
				EEPROM_vWriteByteToAddress(0x000D,1);
				EEPROM_vWriteByteToAddress(0x000E,1);
												  
				EEPROM_vWriteByteToAddress(0x000F,1);
				EEPROM_vWriteByteToAddress(0x0010,1);
				EEPROM_vWriteByteToAddress(0x0011,1);
				EEPROM_vWriteByteToAddress(0x0012,1);
				EEPROM_vWriteByteToAddress(0x0013,1);
				
				EEPROM_vWriteByteToAddress(0x001E,1);
				return true ;
			}
		}
		

		break;  //optional
		
		case 3 :
		if ((EEPROM_ui8ReadByteFromAddress(0x0000) == Check_UserName[0])&&(EEPROM_ui8ReadByteFromAddress(0x0001) == Check_UserName[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0002) == Check_UserName[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0003) == Check_UserName[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0004) == Check_UserName[4]) )
		{
			if ((EEPROM_ui8ReadByteFromAddress(0x0005) == Check_Password[0])&&(EEPROM_ui8ReadByteFromAddress(0x0006) == Check_Password[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0007) == Check_Password[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0008) == Check_Password[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0009) == Check_Password[4]) )
			{
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
				EEPROM_vWriteByteToAddress(0x001E,2);
				return true ;
				
			}
		}
		
		if ((EEPROM_ui8ReadByteFromAddress(0x000A) == Check_UserName[0])&&(EEPROM_ui8ReadByteFromAddress(0x000B) == Check_UserName[1]) &&(EEPROM_ui8ReadByteFromAddress(0x000C) == Check_UserName[2]) &&(EEPROM_ui8ReadByteFromAddress(0x000D) == Check_UserName[3]) &&(EEPROM_ui8ReadByteFromAddress(0x000E) == Check_UserName[4]) )
		{
			if ((EEPROM_ui8ReadByteFromAddress(0x000F) == Check_Password[0])&&(EEPROM_ui8ReadByteFromAddress(0x0010) == Check_Password[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0011) == Check_Password[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0012) == Check_Password[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0013) == Check_Password[4]) )
			{
				EEPROM_vWriteByteToAddress(0x000A,1);
				EEPROM_vWriteByteToAddress(0x000B,1);
				EEPROM_vWriteByteToAddress(0x000C,1);
				EEPROM_vWriteByteToAddress(0x000D,1);
				EEPROM_vWriteByteToAddress(0x000E,1);
				
				EEPROM_vWriteByteToAddress(0x000F,1);
				EEPROM_vWriteByteToAddress(0x0010,1);
				EEPROM_vWriteByteToAddress(0x0011,1);
				EEPROM_vWriteByteToAddress(0x0012,1);
				EEPROM_vWriteByteToAddress(0x0013,1);
				
				EEPROM_vWriteByteToAddress(0x001E,2);
				return true ;
			}
		}
		
		if ((EEPROM_ui8ReadByteFromAddress(0x0014) == Check_UserName[0])&&(EEPROM_ui8ReadByteFromAddress(0x0015) == Check_UserName[1]) &&(EEPROM_ui8ReadByteFromAddress(0x0016) == Check_UserName[2]) &&(EEPROM_ui8ReadByteFromAddress(0x0017) == Check_UserName[3]) &&(EEPROM_ui8ReadByteFromAddress(0x0018) == Check_UserName[4]) )
		{
			if ((EEPROM_ui8ReadByteFromAddress(0x0019) == Check_Password[0])&&(EEPROM_ui8ReadByteFromAddress(0x001A) == Check_Password[1]) &&(EEPROM_ui8ReadByteFromAddress(0x001B) == Check_Password[2]) &&(EEPROM_ui8ReadByteFromAddress(0x001C) == Check_Password[3]) &&(EEPROM_ui8ReadByteFromAddress(0x001D) == Check_Password[4]) )
			{  
			    EEPROM_vWriteByteToAddress(0x0014,1);
				EEPROM_vWriteByteToAddress(0x0015,1);
				EEPROM_vWriteByteToAddress(0x0016,1);
				EEPROM_vWriteByteToAddress(0x0017,1);
				EEPROM_vWriteByteToAddress(0x0018,1);
												  
				EEPROM_vWriteByteToAddress(0x0019,1);
				EEPROM_vWriteByteToAddress(0x001A,1);
				EEPROM_vWriteByteToAddress(0x001B,1);
				EEPROM_vWriteByteToAddress(0x001C,1);
				EEPROM_vWriteByteToAddress(0x001D,1);
				EEPROM_vWriteByteToAddress(0x001E,2);
				return true ;
			}
		}
		

		break;  //optional
		
		default:
		return false ;
	}
	return false ;

}
int SBD_GetUsedSize(void){
	return length ;

}
u8 Sys_Contole(void){
	
	LCD_voidSendString("Led Controle:1 ");
	LCD_voidSetCursor(LCD_U8_ROW_2 , LCD_u8_COLUMN_1);
	
	LCD_voidSendString("Dimmer Controle :2  ");
	LCD_voidSetCursor(LCD_U8_ROW_1 , LCD_u8_COLUMN_16);
	LCD_voidSendString("Door Controle :3 ");
	while (KEYPAD_u8GetPressedButton()=='\0');
	return KEYPAD_u8GetPressedButton() ;
	
}
u8 Sys_Contole_For_User(void){
	
	LCD_voidSendString("Led Controle:1 ");
	LCD_voidSetCursor(LCD_U8_ROW_2 , LCD_u8_COLUMN_1);
	
	LCD_voidSendString("Dimmer Controle :2  ");
	LCD_voidSetCursor(LCD_U8_ROW_1 , LCD_u8_COLUMN_16);
	while (KEYPAD_u8GetPressedButton()=='\0');
	return KEYPAD_u8GetPressedButton() ;
	
}