mcore-elf-as -cpu=340 -EB boot.asm -o boot.o
mcore-elf-gcc -mbig-endian -Iinclude -Ibootloader -nostdinc -nostdlib -fno-builtin -c -o main.o main.c
mcore-elf-gcc -mbig-endian -Iinclude -Ibootloader -nostdinc -nostdlib -fno-builtin -c -o keyboard.o keyboard.c
mcore-elf-gcc -mbig-endian -Iinclude -Ibootloader -nostdinc -nostdlib -fno-builtin -c -o ll_phone.o ll_phone.c
mcore-elf-ld -O -nostdlib -Bstatic -Tlinker.ld -oCG17.smg

del *.o
pause
