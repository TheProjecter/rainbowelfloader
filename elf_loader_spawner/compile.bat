gcc -ISDK -nostdinc -fomit-frame-pointer -nostdlib -fno-builtin -c -o main.o main.c 
ld -Bstatic -Tlinker.ld -oout.bin 

pause
