.RECIPEPREFIX = >
CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m4 -mthumb -O0 -g -Wall -ffreestanding
LDFLAGS = -T linker.ld -nostdlib -Wl,-Map=blink.map

blink.elf: main.c startup.c linker.ld
> $(CC) $(CFLAGS) main.c startup.c $(LDFLAGS) -o $@
> arm-none-eabi-size $@

clean:
> -del /Q blink.elf blink.map