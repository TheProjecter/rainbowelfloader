#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

    void pu_keyboard_init( );
    int32 pu_keyboard_get_keys( );
    
    void keyboard_set_light( bool state );
    
    #define KEY_0       0xFFFBFFFF
    #define KEY_1       0xFDFFFFFF
    #define KEY_2       0xFFFFFFDF
    #define KEY_3       0xFBFFFFFF
    #define KEY_4       0xFFFFFFBF
    #define KEY_5       0xFFFEFFFF
    #define KEY_6       0xFFFFFF7F
    #define KEY_7       0xFFFFFEFF
    #define KEY_8       0xFFFFFFEF
    #define KEY_9       0xFFFFFFFE
    #define KEY_STAR    0xFFFFFFF7
    #define KEY_POUND   0xFFFFFFFB
    #define KEY_GREEN   0xFFFFFBFF
    #define KEY_RED     -1 //??
    #define KEY_C       0xFFFFBFFF
    #define KEY_SKLEFT  0xFFFF7FFF
    #define KEY_SKRIGHT 0xFFFFDFFF
    #define KEY_OK      0x7FFFFFFF
    #define KEY_LEFT    0xEFFFFFFF
    #define KEY_RIGHT   0xF7FFFFFF
    #define KEY_UP      0xBFFFFFFF
    #define KEY_DOWN    0xDFFFFFFF
    #define KEY_VIDEOC  0xFFFFF7FF
    #define KEY_WEB     0xFFFFEFFF
    #define KEY_SOFT    0xFF7FFFFF
    #define KEY_SOFTUP  0xFFDFFFFF
    #define KEY_SOFTDW  0xFFBFFFFF
    #define KEY_SOFTCAM 0xFFEFFFFF
    #define KEY_SOFTVOI 0xFFF7FFFF

#endif
