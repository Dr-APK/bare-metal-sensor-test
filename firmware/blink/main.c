#include <stdint.h>
#define RCC_AHB1ENR (*(volatile uint32_t *)0x40023830)
#define GPIOD_MODER (*(volatile uint32_t *)0x40020C00)
#define GPIOD_ODR   (*(volatile uint32_t *)0x40020C14)

int main(void) {
    RCC_AHB1ENR |= (1u << 3);        /* clock GPIOD */
    GPIOD_MODER &= ~(3u << 24);
    GPIOD_MODER |=  (1u << 24);      /* PD12 as output */
    while (1) {
        GPIOD_ODR ^= (1u << 12);     /* toggle LED */
        for (volatile int i = 0; i < 200000; i++);
    }
}