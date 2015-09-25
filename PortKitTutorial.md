# Needed things #

First of all, we need:
  * **GCC for M\*Core** (check repository for win32 version, to install GCC extract the archive and add the path to gcc's bin dir to "PATH" environment var)
  * **portkit.php or .exe** (check repository)
  * **functions.pat** (check repository)
  * **RSA free CG1 from the firmware** in which you intend to use the elfloader (named in this tutorial CG1.smg)
  * **ElfLoader source code** (check repository)
  * **ElfLoader Spawner source code** (check repository)

# Let's start #

Put portkit.exe or .php and functions.pat in the same folder of CG1.smg.

Execute one of these commands:
  * `portkit.exe -sf functions.pat CG1.smg` if you are in win
  * `php ./portkit.php -sf functions.pat CG1.smg` if you are in linux

Then run the created file and a file named newlib.sym will be created.

Open the file and check the all functions have been found, if not you will have to look for them.

# Porting ElfLoader Spawner #

In the portkit dir execute:

  * `portkit.exe -fl newlib.sym`
  * `php ./portkit.php -fl newlib.sym`

Copy functions.asm into elf\_loader\_spawner\SDK.

Open CG1.smg and check where the file ends and you want to put the ElfLoader Spawner code, for example, if file end is located at 0x1145AB6F you will have to write into linker.ld this code:

```
INPUT(main.o functions.elf)
OUTPUT_FORMAT("binary")
ENTRY(_main)
SECTIONS
{
  . = 0x1145AB70;
  .text :
  {
    *(.text)
  }
}
```

Now go into elf\_loader\_spawner, compile the elf\_loader\_spawner and paste the content of "out.bin" at the address you wrote in linker.ld.

Copy portkit into elf\_loader\_spawner and run:

`portkit.exe -install cg1.smg ADDRESS_OF_SPWNER (example: 1145AB70)`

# Porting ElfLoader #

As for the spawner copy functions.asm into elfloader\SDK then goto elfloader and compile it, ElfLoader is ported.

# End #

The last thing you have to do is to rename newlib.sym to library.def and upload library.def & ldr.bin to /a/ into your mobile, then flash the modified CG1 and you will have the elf loader running!