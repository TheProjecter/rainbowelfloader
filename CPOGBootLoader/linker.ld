INPUT("boot.o")
INPUT("main.o")
INPUT("keyboard.o")
INPUT("ll_phone.o")
INPUT("watchdog.o")
OUTPUT_FORMAT("binary")
SECTIONS
{
    .text 0x118DA4C8:
    {
    *(.text)
    *(.data)
    }
    .bss 0x08000000:
    {
    *(.bss)
    }
}
