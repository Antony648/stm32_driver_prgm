#ifndef MY_STM32F4XX_GPIO_H__
#define MY_STM32F4XX_GPIO_H__


#include <stdint.h>

#define PERIPHERAL_BASE (0x40000000u)
//0x4000 0000
#define AHB1_BASE  (PERIPHERAL_BASE +0x20000u)
//0x4002 0000
#define RCC_BASE (AHB1_BASE + 0x3800u)
//0x4002 3800
#define GPIOA_BASE  AHB1_BASE
//the starting(lowest)address of AHB1 is same as the the lowest address in GPIOA
//because the first pheripheral to be allocated with address in AHB1 is GPIOA
//0x4002 0000
#define GPIOB_BASE  (AHB1_BASE+ 0x400u)
//0x4002 0400
#define GPIOC_BASE  (AHB1_BASE+0x800u)
//0x4002 0800
#define GPIOD_BASE  (AHB1_BASE+0xc00u)
//0x4002 0c00
#define GPIOE_BASE  (AHB1_BASE+0x1000u)
//0x4002 1000
#define GPIOH_BASE  (AHB1_BASE+0X1C00u)
//0x4002 1c00

#define __IO  volatile
	
typedef struct
{
	__IO uint32_t  MODER;
	__IO uint32_t  OTYPER;
	__IO uint32_t  OSPEEDR;
	__IO uint32_t  PUPDR;
	__IO uint32_t	 IDR;
	__IO uint32_t  ODR;
	__IO uint32_t  BSRR;
	__IO uint32_t  LCKR;
	__IO uint32_t  AFRL[2];
}GPIO_Typedef;

typedef struct
{
	__IO uint32_t CR;
	__IO uint32_t PLLCFGR;
	__IO uint32_t CFGR;
	__IO uint32_t CIR;
	__IO uint32_t AHB1RSTR;
	__IO uint32_t AHB2RSTR;
			 uint32_t ahb2rstr_dummy1;
			 uint32_t ahb2rstr_dummy2;
	__IO uint32_t APB1RSTR;
	__IO uint32_t APB2RSTR;
			 uint32_t apb2rstr_dummy1;
			 uint32_t apb2rstr_dummy2;
	__IO uint32_t AHB1ENR;
	__IO uint32_t AHB2ENR;
			 uint32_t ahb2enr_dummy1;
			 uint32_t ahb2enr_dummy2;
	__IO uint32_t APB1ENR;
	__IO uint32_t APB2ENR;
			 uint32_t apb2enr_dummy1;
			 uint32_t apb2enr_dummy2;
	__IO uint32_t AHB1LPENR;
	__IO uint32_t AHB2LPENR;
			 uint32_t ahb2lpenr_dummy1;
			 uint32_t ahb2lpenr_dummy2;
	__IO uint32_t APB1LPENR;
	__IO uint32_t APB2LPENR;
			 uint32_t apb2lpenr_dummy1;
			 uint32_t apb2lpenr_dummy2;
			 
	__IO uint32_t BDCR;
	__IO uint32_t CSR;
	__IO uint32_t SSCGR;
	__IO uint32_t PLL12SCFGR;
			 uint32_t dummy;
	__IO uint32_t DCKCFGR;
}RCC_Typedef;

#define RCC ((RCC_Typedef*)RCC_BASE)

#define GPIOA ((GPIO_Typedef*)GPIOA_BASE)
#define GPIOB ((GPIO_Typedef*)GPIOB_BASE)
#define GPIOC ((GPIO_Typedef*)GPIOC_BASE)
#define GPIOD ((GPIO_Typedef*)GPIOD_BASE)
#define GPIOE ((GPIO_Typedef*)GPIOE_BASE)
#define GPIOH ((GPIO_Typedef*)GPIOH_BASE)

#define GPIOA_EN (1U<<0)
#define GPIOB_EN (1U<<1)
#define GPIOC_EN (1u<<2)
#define GPIOD_EN (1u<<3)
#define GPIOE_EN (1U<<4)
#define GPIOH_EN (1U<<7)

#define PIN5_OUT_MOD (1U<<10)
#define LED_PIN (1U<<5)

#endif