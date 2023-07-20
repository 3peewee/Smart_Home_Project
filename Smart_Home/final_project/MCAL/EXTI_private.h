/****************************************/
/*          Author: Khaled Mohsen       */        
/*          Date: 10-9-2022             */
/*          Version: 1.0                */
/*          Module: EXTI                */
/****************************************/
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define EXTI_U8_FALLING       0
#define EXTI_U8_RISING        1
#define EXTI_U8_ANY_CHANGE    2
#define EXTI_U8_LOW           3

#define GICR (*((volatile u8*)0x5B))
#define GIFR (*((volatile u8*)0x5A))
#define MCUCR (*((volatile u8*)0x55))
#define MCUCSR (*((volatile u8*)0x54))


#endif
