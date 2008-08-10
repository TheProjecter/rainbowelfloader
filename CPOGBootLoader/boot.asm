glo: .macro fn
    .global \fn
    \fn:
.endm

MOVI: .macro reg, val
    lrw \reg, \val
.endm

.extern __stdc_main

    jsri    __stdc_main
