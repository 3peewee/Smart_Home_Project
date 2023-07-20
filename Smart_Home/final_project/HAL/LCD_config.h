



#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
////// here user can choose as  he  wants the pins that he wants to connect to , incase we changed the micro
////// he just need to specify it here 
#define  LCD_U8_D0   DIO_U8_PIN0
#define  LCD_U8_D1   DIO_U8_PIN1
#define  LCD_U8_D2   DIO_U8_PIN2
#define  LCD_U8_D3   DIO_U8_PIN3
#define  LCD_U8_D4   DIO_U8_PIN4
#define  LCD_U8_D5   DIO_U8_PIN5
#define  LCD_U8_D6   DIO_U8_PIN6
#define  LCD_U8_D7   DIO_U8_PIN7
			 
#define  LCD_U8_RS   DIO_U8_PIN9
#define  LCD_U8_RW   DIO_U8_PIN10
#define  LCD_U8_E    DIO_U8_PIN8
  
  /*  
  options 
  LCD_u8_4_BIT     // defined in private.h 
  LCD_u8_8_BIT
  
  */
  //  we  want to make this something configurable 
#define  LCD_U8_DATA_LENGTH     LCD_U8_4_BIT 


#endif