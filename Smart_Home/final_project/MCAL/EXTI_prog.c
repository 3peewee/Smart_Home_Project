/****************************************/
/*          Author: Khaled Mohsen       */        
/*          Date: 10-9-2022             */
/*          Version: 1.0                */
/*          Module: EXTI                */
/****************************************/

#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\Service\STD_types.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\Service\BIT_math.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\MCAL\DIO_int.h"
#include "EXTI_int.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void EXTI_voidInit(void)
{
	#if EXTI_U8_INT0_MODE == EXTI_U8_RISING
		SET_BIT(MCUCR , 0);
		SET_BIT(MCUCR , 1);
	#elif EXTI_U8_INT0_MODE == EXTI_U8_FALLING
		CLEAR_BIT(MCUCR , 0);
		SET_BIT(MCUCR , 1);	
	#elif EXTI_U8_INT0_MODE == EXTI_U8_ANY_CHANGE
		SET_BIT(MCUCR , 0);
		CLEAR_BIT(MCUCR , 1);	
	#elif EXTI_U8_INT0_MODE == EXTI_U8_LOW
		CLEAR_BIT(MCUCR , 0);
		CLEAR_BIT(MCUCR , 1);	
	#endif
	
}
void EXTI_voidEnable_INT0(void)
{
	SET_BIT(GICR , 6);
}
void EXTI_voidDisable_INT0(void)
{
	CLEAR_BIT(GICR , 6);
}