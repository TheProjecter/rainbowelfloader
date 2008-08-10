/*
    CPOG Bootloader
*/

//Base address -> 118DA4C8

#include <typedefs.h>
#include <keyboard.h>
#include <ll_phone.h>

void poll_watchdog( void );

int __stdc_main( )
{
    int32 keys;
    
    clock_init( );

    pu_keyboard_init( );
    keys = pu_keyboard_get_keys( );

    while( 1 )
    {
        keyboard_set_light( false );
        switch( keys )
        {
            case KEY_8:
                jump_motorola_boot( );
            break;
            case KEY_9:
                keyboard_set_light( true ); 
            break;
        }

        keys = pu_keyboard_get_keys( );
        watchdog_service( );
    }

    return 0;
}
