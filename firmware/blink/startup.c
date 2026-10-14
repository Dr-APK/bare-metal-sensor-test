#include <stdint.h>
extern uint32_t _estack, _sidata, _sdata, _edata, _sbss, _ebss;
int main(void);

void Reset_Handler(void) {
    uint32_t *src = &_sidata, *dst = &_sdata;
    while (dst < &_edata) *dst++ = *src++;          /* copy .data from flash */
    for (dst = &_sbss; dst < &_ebss; ) *dst++ = 0;  /* zero .bss */
    main();
    while (1);
}
void Default_Handler(void) { while (1); }

__attribute__((section(".isr_vector"), used))
void (*const vectors[])(void) = {
    (void (*)(void))&_estack,  /* initial stack pointer */
    Reset_Handler,
    Default_Handler,           /* NMI */
    Default_Handler            /* HardFault */
};