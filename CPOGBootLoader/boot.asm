glo: .macro fn
    .global \fn
    \fn:
.endm

.extern __stdc_main

    jsri    __stdc_main
