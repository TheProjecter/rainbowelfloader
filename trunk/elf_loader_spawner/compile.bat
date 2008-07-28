mcore-elf-gcc -mbig-endian -nostdinc -I../SDK -fomit-frame-pointer -nostdlib -fno-builtin -c -o main.o main.c
mcore-elf-as -EB functions.asm
mcore-elf-ld -o functions.elf -EB a.out
mcore-elf-ld -Bstatic -Tlinker.ld -oout.bin

del *.out
del *.o
pause
