\# Day 1: Toolchain and Renode setup



\## Tools

\- Arm GNU Toolchain 15.3.rel2 (arm-none-eabi-gcc 15.3.1)

\- Git 2.56.0 (Windows)

\- GNU Make (via winget)

\- Renode 1.17.0 (portable)



\## Commands run (Renode console)

\- include @scripts/single-node/stm32f4\_discovery.resc

\- start



\## Result

Simulated STM32F4 Discovery booted a prebuilt Contiki 3.x demo. UART showed the startup log (clock, rtimer, buttons, Ethernet, DHCP, LED process, UDP server).

Screenshot: day1-renode-uart.png



\## Problem and fix

arm-none-eabi-gcc was not recognized. Fixed by adding the toolchain's bin folder to PATH and opening a new PowerShell.



\## Next

Day 2: bare-metal GPIO blink with own startup code, linker script and Makefile.

