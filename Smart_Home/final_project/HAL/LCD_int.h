/****************************************/
/*          Author: Moaaz Refaat       */
/*          Date: 2-9-2022              */
/*          Version: 1.0                */
/*          Module: LCD                 */
/****************************************/
#ifndef LCD_int_H_
#define LCD_int_H_

#define   LCD_U8_ROW_1  0
#define   LCD_U8_ROW_2  1


#define   LCD_u8_COLUMN_1      0
#define   LCD_u8_COLUMN_2      1
#define   LCD_u8_COLUMN_3 	   2
#define   LCD_u8_COLUMN_4 	   3
#define   LCD_u8_COLUMN_5 	   4
#define   LCD_u8_COLUMN_6 	   5
#define   LCD_u8_COLUMN_7 	   6
#define   LCD_u8_COLUMN_8 	   7
#define   LCD_u8_COLUMN_9 	   8
#define   LCD_u8_COLUMN_10 	   9
#define   LCD_u8_COLUMN_11	   10
#define   LCD_u8_COLUMN_12	   11
#define   LCD_u8_COLUMN_13	   12
#define   LCD_u8_COLUMN_14	   13
#define   LCD_u8_COLUMN_15	   14
#define   LCD_u8_COLUMN_16	   15

void LCD_voidInit(void);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendString(s8 * p_s8Command); 
void LCD_voidSetCursor(u8 Copy_u8Row ,u8 Copy_u8Column );
void LCD_voidCustomChar(u8 Copy_u8Loc, s8 * p_s8Char );
void LCD_voidClearDisplay(void);

#endif