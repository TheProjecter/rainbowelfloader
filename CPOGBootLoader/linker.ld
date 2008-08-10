INPUT("boot.o")
INPUT("main.o")
INPUT("keyboard.o")
INPUT("ll_phone.o")
OUTPUT_FORMAT("binary")
SECTIONS
{
    .text 0x118DA4C8:
    {
    *(.text)
    *(.data)
    }
}
