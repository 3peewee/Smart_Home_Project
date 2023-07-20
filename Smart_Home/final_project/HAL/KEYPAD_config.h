/****************************************/
/*          Author: Khaled Mohsen       */        
/*          Date: 9-9-2022              */
/*          Version: 1.0                */
/*          Module: KEYPAD              */
/****************************************/
#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_




#define KEYPAD_U8_R1    DIO_U8_PIN12  // the output pins  , i write on it
#define KEYPAD_U8_R2    DIO_U8_PIN13
#define KEYPAD_U8_R3    DIO_U8_PIN14
#define KEYPAD_U8_R4    DIO_U8_PIN15
                        
#define KEYPAD_U8_C1   DIO_U8_PIN19    // input pins , where i scan to see what is pressed .
#define KEYPAD_U8_C2   DIO_U8_PIN20
#define KEYPAD_U8_C3   DIO_U8_PIN21
#define KEYPAD_U8_C4   DIO_U8_PIN22



#define KEYPAD_U8_R1C1   '7'
#define KEYPAD_U8_R1C2   '8'
#define KEYPAD_U8_R1C3   '9'    
#define KEYPAD_U8_R1C4   '/'        
      
#define KEYPAD_U8_R2C1   '4'
#define KEYPAD_U8_R2C2   '5'
#define KEYPAD_U8_R2C3   '6'
#define KEYPAD_U8_R2C4   '*'
      
#define KEYPAD_U8_R3C1    '1'
#define KEYPAD_U8_R3C2   '2' 
#define KEYPAD_U8_R3C3   '3' 
#define KEYPAD_U8_R3C4    '-'
      
#define KEYPAD_U8_R4C1   '*'
#define KEYPAD_U8_R4C2    '0'
#define KEYPAD_U8_R4C3   '='
#define KEYPAD_U8_R4C4   '+'

/*

options:
KEYPAD_U8_INTERNAL_RES
KEYPAD_U8_EXTERNAL_RES

*/
#define KEYPAD_U8_MODE   KEYPAD_U8_INTERNAL_RES

#endif