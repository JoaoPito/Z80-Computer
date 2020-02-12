# Z80 Computer
 A simple Z80-based homebrew computer I made around 2017. The biggest reason I wanted to start this project was to learn about computer architecture and electrical engineering but at the end it became a experiment where I could do (almost)anything i want to it(I guess would be a bit easier to use an Arduino or something...).

**Architecture**
The Z80 runs at 2.5Mhz, it was made with perfboard and wire-wrap wires soldered on the underside of the board. The glue logic was made entirely with 74LSxx ICs but its design is very simple.

 It has 32Kb of SRAM(62256 RAM Chips), 8Kb of ROM(28HC256) and 3 expansion slots mapped to free 8Kb (Memory Space).

        ____________ 0xFFFF
        |          |
        |          |        
        |          |
        | RAM(32K) |
        |          |
        |          |
        |          |
        |          |
        |----------| 0x8000
        |  Slot 2  |
        |----------|
        |  Slot 1  |
        |----------|
        |  Slot 0  |
        |----------|
        |   ROM    |
        ¯¯¯¯¯¯¯¯¯¯¯¯ 0x0000



 Its native communication is RS232(62500Bps@2.5Mhz - 16uS) mapped to IO address 00h without any specialized hardware for it but a 74xx 4 bit register, I had to do it all by software. Not pretty, but works(i guess).
 I was also planning a SD Card storage and a Arduino-based composite video card but never finished those.
Later I added some logic to invert the upper 32Kb Memory map with software so I could run CP/M so the ROM and the Expansion Slots would be mapped to 0000h - 7FFFh and the RAM to 8000h - FFFFh.

**Software**
At first I developed a memory monitor similar to those found in 70's home computers that evolved to something similar to a operating system but not quite haha.
This monitor/OS was capable of dump/edit/copy memory addresses, load programs into memory from RS232, run a program from a given address, output stuff to I/O and (Never finished) Communicate with SD Card and Boot CP/M 2.2;
At some point I merged the CP/M BIOS with my monitor program so I could use the same routines but I never managed to 100% boot CP/M.

