.include "macros.asm"

.extern __stdc_main

    jsri    __stdc_main

glo HAPI_GPIO_config
                 subi    sp, 0x20
                 stm     r8 - r15, (sp)
                 mov     r6, r3
                 lrw     r12, gpio_pin_option_tbl
                 ixh     r6, r6
                 addu    r6, r6
                 addu    r12, r6
                 subi    sp, 0x20
                 mov     r6, r2
                 mov     r14, sp
                 ixh     r6, r6
                 st.h    r4, (r14, 0xC)
                 addu    r12, r6
                 ld.b    r7, (r12, 0)
                 mov     r9, sp
                 st.b    r7, (sp, 0x40+var_40)
                 ld.b    r7, (r12, 1)
                 mov     r11, sp
                 st.b    r7, (r9, 4)
                 ld.b    r7, (r12, 2)
                 cmplti  r3, 0x10
                 mov     r8, r2
                 mov     r10, r3
                 addi    r14, 0xC
                 addi    r9, 4
                 st.b    r7, (r11, 8)
                 addi    r11, 8
                 jbf     loc_10006C64
                 movi    r7, 0
                 st.w    r7, (sp, 0x40+var_2C)
                 mov     r7, r10
                 jbr     loc_10006C70

loc_10006C64:
                 movi    r7, 1
                 st.w    r7, (sp, 0x40+var_2C)
                 movi    r6, 0x70
                 mov     r7, r10
                 ORI     r6, 0x80
                 addu    r7, r6

loc_10006C70:
                 zextb   r7
                 st.w    r7, (sp, 0x40+var_30)
                 jsri    suIntDisableAllInt
                 st.w    r2, (sp, 0x40+var_28)
                 lrw     r7, gius_ptr_array
                 ld.h    r12, (r14, 0)
                 ixw     r7, r8
                 btsti   r12, 0
                 ld.w    r14, (r7, 0)
                 jbf     loc_10006C8E
                 ld.w    r7, (r14, 0)
                 bgenr   r6, r10
                 or      r7, r6
                 st.w    r7, (r14, 0)
                 jbr     loc_10006C96

loc_10006C8E:
                 ld.w    r6, (r14, 0)
                 bgenr   r7, r10
                 andn    r6, r7
                 st.w    r6, (r14, 0)

loc_10006C96:
                 ld.b    r14, (sp, 0x40+var_40)
                 movi    r7, 0x20
                 mov     r13, r14
                 lsli    r13, 0x1A
                 lsri    r13, 0x1A
                 cmphs   r13, r7
                 jbt     loc_10006CC4
                 lrw     r7, gpr_ptr_array
                 lsri    r14, 6
                 andi    r14, 3
                 ixw     r7, r14
                 btsti   r12, 1
                 ld.w    r1, (r7, 0)
                 jbf     loc_10006CBC
                 ld.w    r6, (r1, 0)
                 bgenr   r5, r13
                 or      r6, r5
                 st.w    r6, (r1, 0)
                 jbr     loc_10006CC4

loc_10006CBC:
                 ld.w    r5, (r1, 0)
                 bgenr   r6, r13
                 andn    r5, r6
                 st.w    r5, (r1, 0)

loc_10006CC4:
                 ld.b    r13, (r9, 0)
                 movi    r7, 0x20
                 mov     r9, r13
                 lsli    r9, 0x1A
                 lsri    r9, 0x1A
                 cmphs   r9, r7
                 jbt     loc_10006CF2
                 lrw     r7, gpr_ptr_array
                 lsri    r13, 6
                 andi    r13, 3
                 ixw     r7, r13
                 btsti   r12, 2
                 ld.w    r14, (r7, 0)
                 jbf     loc_10006CEA
                 ld.w    r7, (r14, 0)
                 bgenr   r6, r9
                 or      r7, r6
                 st.w    r7, (r14, 0)
                 jbr     loc_10006CF2

loc_10006CEA:
                 ld.w    r6, (r14, 0)
                 bgenr   r7, r9
                 andn    r6, r7
                 st.w    r6, (r14, 0)

loc_10006CF2:
                 ld.b    r9, (r11, 0)
                 movi    r7, 0x20
                 mov     r11, r9
                 lsli    r11, 0x1A
                 lsri    r11, 0x1A
                 cmphs   r11, r7
                 jbt     loc_10006D20
                 lrw     r7, gpr_ptr_array
                 lsri    r9, 6
                 andi    r9, 3
                 ixw     r7, r9
                 btsti   r12, 3
                 ld.w    r13, (r7, 0)
                 jbf     loc_10006D18
                 ld.w    r7, (r13, 0)
                 bgenr   r6, r11
                 or      r7, r6
                 st.w    r7, (r13, 0)
                 jbr     loc_10006D20

loc_10006D18:
                 ld.w    r6, (r13, 0)
                 bgenr   r7, r11
                 andn    r6, r7
                 st.w    r6, (r13, 0)

loc_10006D20:
                 lrw     r7, ddir_ptr_array
                 btsti   r12, 0xA
                 ixw     r7, r8
                 ld.w    r11, (r7, 0)
                 jbf     loc_10006D34
                 ld.w    r7, (r11, 0)
                 bgenr   r6, r10
                 or      r7, r6
                 st.w    r7, (r11, 0)
                 jbr     loc_10006D3C

loc_10006D34:
                 ld.w    r6, (r11, 0)
                 bgenr   r7, r10
                 andn    r6, r7
                 st.w    r6, (r11, 0)

loc_10006D3C:
                 mov     r10, r8
                 ld.w    r8, (sp, 0x40+var_2C)
                 lrw     r7, iconfa_ptr_array
                 lsli    r10, 3
                 lsli    r8, 2
                 addu    r7, r10
                 addu    r7, r8
                 ld.w    r2, (r7, 0)
                 mov     r3, r12
                 lsri    r3, 4
                 ld.w    r4, (sp, 0x40+var_30)
                 andi    r3, 3
                 jbsr    prog_ioconf_reg
                 lrw     r7, iconfb_ptr_array
                 mov     r3, r12
                 addu    r7, r10
                 addu    r7, r8
                 ld.w    r2, (r7, 0)
                 lsri    r3, 6
                 ld.w    r4, (sp, 0x40+var_30)
                 andi    r3, 3
                 jbsr    prog_ioconf_reg
                 lrw     r7, ocr_ptr_array
                 mov     r3, r12
                 addu    r7, r10
                 addu    r7, r8
                 ld.w    r2, (r7, 0)
                 lsri    r3, 8
                 ld.w    r4, (sp, 0x40+var_30)
                 andi    r3, 3
                 jbsr    prog_ioconf_reg
                 ld.w    r2, (sp, 0x40+var_28)
                 addi    sp, 0x20
                 ldm     r8 - r15, (sp)
                 addi    sp, 0x20
                 jmpi    susetInt

prog_ioconf_reg:
                 ld.w    r1, (r2, 0)
                 lsli    r4, 1
                 movi    r7, 3
                 lsl     r7, r4
                 andn    r1, r7
                 lsl     r3, r4
                 or      r1, r3
                 st.w    r1, (r2, 0)
                 jmp     r15

nl_f susetInt
nl_f suIntDisableAllInt

ddir_ptr_array:  .long 0x209000
                 .long 0x20A000
ocr_ptr_array:   .long 0x209004
                 .long 0x209008
                 .long 0x20A004
                 .long 0x20A008
iconfa_ptr_array:.long 0x20900C
                 .long 0x209010
                 .long 0x20A00C
                 .long 0x20A010
iconfb_ptr_array:.long 0x209014
                 .long 0x209018
                 .long 0x20A014
                 .long 0x20A018
dr_ptr_array:    .long 0x20901C
                 .long 0x20A01C
                 .long 0x20F01C
ssr_ptr_array:   .long 0x209024
                 .long 0x20A024
gius_ptr_array:  .long 0x209020
                 .long 0x20A020
gpr_ptr_array:   .long 0x209038
                 .long 0x20903C
                 .long 0x20A038
                 .long 0x20A03C
gpio_pin_option_tbl:
                 .byte 0, 0x20, 0x20, 0x20, 0xC1, 0x20
                 .byte 1, 0x20, 0x20, 0x20, 0xC1, 0x20
                 .byte 2, 0x20, 0x20, 0x20, 0xCA, 0x20
                 .byte 3, 0x20, 0x20, 0x20, 0xC9, 0x20
                 .byte 4, 0x42, 0x20, 0x20, 0xCA, 0x20
                 .byte 5, 0x42, 0x20, 0x20, 0xC9, 0x20
                 .byte 6, 0x42, 0x20, 0x20, 0xC9, 0x20
                 .byte 7, 0x42, 0x20, 0x20, 0xC9, 0x20
                 .byte 8, 0x41, 0x20, 0x20, 0xC9, 0x20
                 .byte 9, 0x41, 0x20, 0x20, 0xC9, 0x20
                 .byte 0x11, 0x40, 0x20, 0x80, 0xC7, 0x20
                 .byte 0xE, 0x40, 0x20, 0x80, 0xC7, 0x20
                 .byte 0xE, 0x40, 0x20, 0x80, 0xC7, 0x20
                 .byte 0xE, 0x40, 0x20, 0x80, 0xC7, 0x20
                 .byte 0xD, 0x20, 0x20, 0x80, 0xC7, 0x20
                 .byte 0xC, 0x20, 0x20, 0x80, 0xCF, 0x20
                 .byte 0x20, 0x20, 0x20, 0x80, 0xD0, 0x20
                 .byte 0x20, 0x20, 0x20, 0x80, 0xD0, 0x20
                 .byte 0x20, 0x20, 0x20, 0x80, 0xD0, 0x20
                 .byte 0x20, 0x20, 0x20, 0x1F, 0xD3, 0x20
                 .byte 0x20, 0x11, 0x51, 0x19, 0xD3, 0x8E
                 .byte 0x20, 0xC2, 0x20, 0x17, 0xD3, 0x8C
                 .byte 0x50, 0x40, 0x20, 0x16, 0xD3, 0x8B
                 .byte 0x20, 0xC3, 0x20, 0x15, 0xD3, 0x20
                 .byte 0x20, 0x20, 0x20, 0x14, 0xD3, 0x20
                 .byte 0x20, 0x20, 0x20, 0x20, 0xD3, 0x88
                 .byte 0x20, 0x20, 0x20, 0x20, 0xD3, 0x88
                 .byte 0x20, 0x20, 0x20, 0x20, 0xDD, 0x88
                 .byte 0x20, 0x11, 0x20, 0x10, 0xDD, 0x88
                 .byte 0x20, 0x11, 0x20, 0xF, 0xDD, 0x20
                 .byte 0x20, 0x11, 0x20, 0xB, 0x20, 0x20
                 .byte 0x20, 0x11, 0x20, 0xA, 0x48, 0x86

glo suPanic
                subi    sp, 0x10
                stq     r4 - r7, (sp)
                subi    sp, 8
                st.w    r2, (sp, 0)
                st.w    r3, (sp, 4)
                addi    sp, 0x18
                jmp     r15
