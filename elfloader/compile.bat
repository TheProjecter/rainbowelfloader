mcore-elf-gcc -fshort-wchar -mbig-endian -nostdinc -I../SDK -fomit-frame-pointer -nostdlib -fno-builtin -c -o loader.o loader.c
mcore-elf-as -EB functions.asm
mcore-elf-ld -o functions.elf -EB a.out
mcore-elf-ld -Bstatic -Tlinker.ld -oldr.bin

del *.out
del *.elf
del *.o
pause
