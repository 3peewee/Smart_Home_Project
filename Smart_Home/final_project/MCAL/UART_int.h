/************************************************/
/* Title       : USART Interface file           */
/* Author      : Khaled Mohsen                  */
/* Release     : 1.0                            */
/* Last Update : Aug 16, 2021                   */
/************************************************/


#ifndef UART_INT_H_
#define UART_INT_H_


void UART_voidInit(void);

void UART_voidSendByte(u8 Byte);

u8 UART_u8ReceiveByte(void);
void UART_voidReieveString(u8 *Ptr);
void UART_voidSendString(u8 *Ptr);
/*
void UART_void_SetCBReceive( void (*ptr) (void) );
void UART_void_SetCBSend( void (*ptr) (void) );
u8 UART_u8_ReturnUDRValue(void);
*/

#endif /* UART_INT_H_ */
