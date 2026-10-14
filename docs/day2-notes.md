\# Day 2: Bare-metal GPIO blink (Cortex-M4, Renode)



\## Files

\- startup.c: vector table plus Reset\_Handler. The vector table sits in the .isr\_vector section. Reset\_Handler copies .data from flash to RAM, zeroes .bss, then calls main().

\- linker.ld: memory map. FLASH at 0x08000000 (1M) holds the vector table, .text and the load image of .data. RAM at 0x20000000 (128K) holds .data and .bss.

\- main.c: enables the GPIOD clock (RCC\_AHB1ENR), sets PD12 as output (GPIOD\_MODER), and toggles it through GPIOD\_ODR in a delay loop.

\- Makefile: builds blink.elf with arm-none-eabi-gcc (-mcpu=cortex-m4 -mthumb -ffreestanding -nostdlib) and prints section sizes.

\- blink.resc: Renode script that loads the STM32F4 Discovery platform and blink.elf.



\## How boot works

\- On reset the Cortex-M reads two words from the start of flash: word 0 is the initial stack pointer, word 1 is the reset vector.

\- \_estack is the first vector entry because the CPU loads SP from it before running any code. It is set to the top of RAM (stack grows down).

\- Reset\_Handler copies .data (initialised globals) from its flash load address (\_sidata) to RAM, and zeroes .bss, because there is no C runtime in a bare-metal build.



\## Result

\- Build: text 208, data 0, bss 0 (no global variables).

\- Renode log: GPIOD OutputData read 0x1000 then

