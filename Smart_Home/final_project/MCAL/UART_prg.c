/************************************************/
/* Title       : USART Program file             */
/* Author      : Khaled Mohsen                  */
/* Release     : 1.0                            */
/* Last Update : Aug 16, 2021                   */
/************************************************/



#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\Service\STD_types.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\Service\BIT_math.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\MCAL\DIO_int.h"

#include "UART_int.h"
#include "UART_priv.h"
#include "UART_config.h"
/*
void (*CallBackReceive) (void) ;
void (*CallBackSend) (void) ;


void UART_void_SetCBReceive( void (*ptr) (void) )
{
	CallBackReceive = ptr ;
}

void UART_void_SetCBSend( void (*ptr) (void) )
{
	CallBackSend = ptr ;
}

u8 UART_u8_ReturnUDRValue(void)
{
	return UDR ;
}

*/
void UART_voidInit(void)
{
	/*Select 8-bit data frame*/
	CLEAR_BIT(UCSRB , UCSZ2) ;
	SET_BIT(UCSRC , UCSZ1) ;
	SET_BIT(UCSRC , UCSZ0) ;
	/*Select asynchronous mode*/
	CLEAR_BIT(UCSRC , UMSEL);
	/*disable parity bit*/
	CLEAR_BIT(UCSRC,UPM1);
	CLEAR_BIT(UCSRC,UPM0);
	/*Choose one stop bit */
	CLEAR_BIT(UCSRC , USBS);
	/*clear clock polarity */ // in the data sheet when using asynch mode , we write this bit to zero 
	CLEAR_BIT(UCSRC , UCPOL);
	/* select 9600 baud rate 16 Mhz*/
	UBRRH = 0 ; // write zero on the last bit to choose UBRRH
	UBRRL =   12 ;
	
	/*Enable rx and tx*/
	SET_BIT(UCSRB , RXEN) ;
	SET_BIT(UCSRB , TXEN) ;
	/*disable interrupt*/
	SET_BIT(UCSRB , RXCIE);
	CLEAR_BIT(UCSRB , UDRIE);
	SET_BIT(UCSRB , TXCIE);


}

void UART_voidSendByte(u8 Byte)
{
	
	while(GET_BIT(UCSRA , UDRE) == 0); // stuck here to check if flag is not yet equal to one to make  sure the UDR is empty, and know it is ready to be written on it 
	UDR = Byte ;

}

void UART_voidSendString(u8 *Ptr)
{
	int i =0 ;
	while (Ptr[i] != '\0')
	{
		UART_voidSendByte(Ptr[i]);
		i++ ;
	}
  UART_voidSendByte(Ptr[i]);
}


void UART_voidReieveString(u8 *Ptr)
{
	int i =0 ;
	Ptr[i]=UART_u8ReceiveByte();
	while (Ptr[i] != '#')
	{
		i++ ;
		Ptr[i]=UART_u8ReceiveByte();
	}
	//Ptr[i] != '\0';
}

u8 UART_u8ReceiveByte(void)
{

	while(GET_BIT(UCSRA , RXC) == 0);
	return UDR ;

}
/*

void __vector_13(void) __attribute__((signal , used));
void __vector_13(void)
{
	CallBackReceive();
}

void __vector_14(void) __attribute__((signal , used));
void __vector_14(void)
{
	CallBackSend();
}
*/