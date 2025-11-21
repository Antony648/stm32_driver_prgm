#ifndef __MY_STM32F411_GPIO_DRIVER
#define __MY_STM32F411_GPIO_DRIVER
#include <stdint.h>

//macros for base addresses
#define PERIPHERAL_BASE 0x40000000u
#define AHB1_BASE				(PERIPHERAL_BASE+0x20000u)
#define RCC_BASE				(AHB1_BASE+0x3800u)
#define GPIOA_BASE 			(AHB1_BASE)
#define GPIOB_BASE 			(GPIOA_BASE+0x0400u)
#define GPIOC_BASE			(GPIOA_BASE+0x0800u)
#define GPIOD_BASE			(GPIOA_BASE+0x0c00u)
#define GPIOE_BASE			(GPIOA_BASE+0x1000u)
#define GPIOH_BASE			(GPIOA_BASE+0x1c00u)

typedef enum
{
	GPIO_A =0,
	GPIO_B,
	GPIO_C,
	GPIO_D,
	GPIO_E,
	GPIO_H =7
}GPIO_port_num;

//structure for a general gpio port class
typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];
}GPIO_port_t;

typedef struct
{
	volatile uint32_t CR;												//0x00
	volatile uint32_t PLLCFGR;									//0x04
	volatile uint32_t CFGR;											//0x08	
	volatile uint32_t CIR;											//0x0c
	volatile uint32_t AHB1RSTR;									//0x10
	volatile uint32_t AHB2RSTR;									//0x14
					 uint32_t offset_AHB2RSTR[2];
	volatile uint32_t APB1RSTR;									//0x20
	volatile uint32_t APB2RSTR;									//0x24
					 uint32_t offset_APB2RSTR[2];
	volatile uint32_t AHB1ENR;									//0x30
	volatile uint32_t AHB2ENR;									//0x34
					 uint32_t offset_AHB2ENR[2];
	volatile uint32_t APB1ENR;									//0x40
	volatile uint32_t APB2ENR;									//0x44
					 uint32_t offset_APB2ENR[2];
	volatile uint32_t AHB1LPENR;								//0x50
	volatile uint32_t AHB2LPENR;								//0x54
					 uint32_t offset_AHB2LPENR[2];
	volatile uint32_t APB1LPENR;								//0x60
	volatile uint32_t APB2LPENR;								//0x64
					 uint32_t offset_APB2LPENR[2];
	volatile uint32_t BDCR;											//0x70
	volatile uint32_t CSR;											//0x74
					 uint32_t offset_CSR[2];
	volatile uint32_t SSCGR;										//0x80
	volatile uint32_t PLLI2SCFGR;								//0x84
					 uint32_t offset_PLLI2SCRGR;
	volatile uint32_t DCKCFGR;									//0x8c				
}RCC_t;

#define RCC 		((RCC_t*)RCC_BASE)
#define GPIOA		((GPIO_port_t*)GPIOA_BASE)
#define GPIOB		((GPIO_port_t*)GPIOB_BASE)
#define GPIOC		((GPIO_port_t*)GPIOC_BASE)
#define GPIOD		((GPIO_port_t*)GPIOD_BASE)
#define GPIOE   ((GPIO_port_t*)GPIOE_BASE)
#define GPIOH		((GPIO_port_t*)GPIOH_BASE)

typedef enum
{
	GPIOA_num=0,
	GPIOB_num,
	GPIOC_num,
	GPIOD_num,
	GPIOE_num,
	GPIOH_num
}GPIO_num;
static void GPIOx_Enable(GPIO_num n)
{

	RCC->AHB1ENR |=  (0X1U<<n);
}


#endif
