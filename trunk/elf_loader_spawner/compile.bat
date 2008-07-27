mcore-elf-gcc -mbig-endian -ISDK -nostdinc -fomit-frame-pointer -nostdlib -fno-builtin -c -o main.o main.c 
mcore-elf-ld -Bstatic -Tlinker.ld -oout.bin 

pause
