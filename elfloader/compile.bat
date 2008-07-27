mcore-elf-gcc -mbig-endian -nostdinc -ISDK -fomit-frame-pointer -nostdlib -fno-builtin -c -o loader.o loader.c
mcore-elf-ld -Bstatic -Tlinker.ld -oldr.bin

del *.o
pause
