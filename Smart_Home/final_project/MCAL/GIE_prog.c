/*****************************************/
/*	Author : Khaled Mohsen				 */
/*	Date   : 1-7-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : GIE_prog.c	                 */
/*****************************************/
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\Service\STD_types.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\Service\BIT_math.h"
#include "D:\AMIT_KHALED_MOHSEN\TASks\Finaaaal\Final_ofThe_Final\Smart_Home\final_project\MCAL\DIO_int.h"
#include "GIE_int.h"
#include "GIE_private.h"
#include "GIE_config.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG , 7);
}
void GIE_voidDisable(void)
{
	CLEAR_BIT(SREG , 7);
}