#include <typedefs.h>
#include <ll_phone.h>

void pu_main_set_powerup_reason( int8 pwrp_reason )
{
    port_write_b( 0x8100000, pwrp_reason );
}

void port_write_l( uint32 port, int32 data )
{
    ( ( int32 * )port )[ 0 ] = data;
}

void port_write_w( uint32 port, int16 data )
{
    ( ( int16 * )port )[ 0 ] = data;
}

void port_write_b( uint32 port, int8 data )
{
    ( ( int8 * )port )[ 0 ] = data;
}

int32 port_read_l( uint32 port )
{
    return ( ( int32 * )port )[ 0 ];
}

int16 port_read_w( uint32 port )
{
    return ( ( int16 * )port )[ 0 ];
}

int8 port_read_b( uint32 port )
{
    return ( ( int8 * )port )[ 0 ];
}

void jump_blank( void )
{
    asm
    (
        "lrw    r1, 0x7804000       \n"
        "mov    sp, r1              \n"
        "jmpi   0x6DC               \n"
    );
}

void jump_motorola_boot( void )
{
    __asm__
    (
        "lrw    r7, 0x10000000      \n"
        "ld.w   r7, (r7, 0x18)      \n"
        "jsr    r7                  \n"
    );
}
