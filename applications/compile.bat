REM Example compile file

mcore-elf-gcc -fshort-wchar -mbig-endian -nostdinc -m340 -I..\SDK -fomit-frame-pointer -nostdlib -c -o GetMyPDS\GetMyPDS.o GetMyPDS\GetMyPDS.c
mcore-elf-ld -dn -r -no-bss-init -TGetMyPDS\linker.ld -oGetMyPDS.elf
mcore-elf-gcc -fshort-wchar -mbig-endian -nostdinc -m340 -I..\SDK -fomit-frame-pointer -nostdlib -fno-builtin -c -o FlexEditor\FlexEditor.o FlexEditor\FlexEditor.c
mcore-elf-ld -dn -r -no-bss-init -TFlexEditor\linker.ld -oFlexEditor.elf
mcore-elf-gcc -fshort-wchar -mbig-endian -nostdinc -m340 -I..\SDK -fomit-frame-pointer -nostdlib -fno-builtin -c -o Info\Info.o Info\Info.c
mcore-elf-ld -dn -r -no-bss-init -TInfo\linker.ld -oInfo.elf
mcore-elf-gcc -fshort-wchar -mbig-endian -nostdinc -m340 -I..\SDK -fomit-frame-pointer -nostdlib -fno-builtin -c -o MultiBkg\MultiBkg.o MultiBkg\MultiBkg.c
mcore-elf-ld -dn -r -no-bss-init -TMultiBkg\linker.ld -oMultiBkg.elf
mcore-elf-gcc -fshort-wchar -mbig-endian -nostdinc -m340 -I..\SDK -fomit-frame-pointer -nostdlib -fno-builtin -c -o SwitchToBoot\SwitchToBoot.o SwitchToBoot\SwitchToBoot.c
mcore-elf-ld -dn -r -no-bss-init -TSwitchToBoot\linker.ld -oSwitchToBoot.elf
mcore-elf-gcc -fshort-wchar -mbig-endian -nostdinc -m340 -I..\SDK -fomit-frame-pointer -nostdlib -fno-builtin -c -o FunL\FunL.o FunL\FunL.c
mcore-elf-ld -dn -r -no-bss-init -TFunL\linker.ld -oFunLights.elf
mcore-elf-gcc -fshort-wchar -mbig-endian -nostdinc -m340 -I..\SDK -fomit-frame-pointer -nostdlib -fno-builtin -c -o FontServ\FontServ.o FontServ\FontServ.c
mcore-elf-ld -dn -r -no-bss-init -TFontServ\linker.ld -oFontServ.elf

del /S *.o
pause
