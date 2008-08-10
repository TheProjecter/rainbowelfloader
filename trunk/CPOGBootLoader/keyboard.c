#include <typedefs.h>
#include <devs.h>
#include <ll_phone.h>

void pu_keyboard_init( )
{
    port_write_w( 0x219000 + 0, 0x00FF );
    port_write_w( 0x219000 + 2, 0x0105 ); 
    port_write_w( 0x219000 + 4, 0x0F00 );
    port_write_w( 0x219000 + 6, 0x0000 );
    
    port_write_l( 0x209000 + 0,     0x0F54D018 );
    port_write_l( 0x209000 + 4,     0xFFFFFFFF ); 
    port_write_l( 0x209000 + 8,     0xFFCFFFFF );
    port_write_l( 0x209000 + 0xC,   0xEEFFEAAF );
    port_write_l( 0x209000 + 0x10,  0xFFAAAEEA );
    port_write_l( 0x209000 + 0x14,  0xEFFFEAAF ); 
    port_write_l( 0x209000 + 0x18,  0xFFAAAFFF );
    port_write_l( 0x209000 + 0x1C,  0x00408000 );
    port_write_l( 0x209000 + 0x20,  0x0FD0D07C );
    port_write_l( 0x209000 + 0x38,  0x00000000 ); 
    port_write_l( 0x209000 + 0x3C,  0x00000000 );
    
    port_write_l( 0x20A000 + 0,     0x0162EC00 );
    port_write_l( 0x20A000 + 4,     0xFFFFFFFF ); 
    port_write_l( 0x20A000 + 8,     0xFFFFFFFF );
    port_write_l( 0x20A000 + 0xC,   0xBFFAAAA5 );
    port_write_l( 0x20A000 + 0x10,  0xAABAAEBB );
    port_write_l( 0x20A000 + 0x14,  0xFFFFAAAA ); 
    port_write_l( 0x20A000 + 0x18,  0xF5EAAEBF );
    port_write_l( 0x20A000 + 0x1C,  0x00008000 );
    port_write_l( 0x20A000 + 0x20,  0xDFF283C3 );
    port_write_l( 0x20A000 + 0x38,  0x00000000 ); 
    port_write_l( 0x20A000 + 0x3C,  0x00000000 );
}

//probably wrong :)
int32 pu_keyboard_get_keys( )
{
    int16 u1 = -0x801;

    int32 t;
    int32 i;
    
    int32 key = 0;

    for( i = 0; i < 4; i++ )
    {
        port_write_w( 0x219000 + 6, u1 );
        t = port_read_w( 0x219000 + 6 );
        
        key <<= 8;
        key |= t;
        
        u1 >>= 1;
    }
    
    port_write_w( 0x219000 + 6, 0xF0FF );

    return key;
}

void keyboard_set_light_top( bool state )
{
    int32 c_state = port_read_l( 0x20F01C );
    if( state )
        c_state |= 0x200;
    else
        c_state &= ~0x200;
        
    port_write_l( 0x20F01C, c_state );
}

void keyboard_set_light_bot( bool state )
{
    int32 c_state = port_read_l( 0x20A01C );

    if( state )
        c_state |= ( ( state & 1 ) << 0x16 );
    else
        c_state = 0x80000000;
    
    port_write_l( 0x20A01C, c_state );
}

void keyboard_set_light( bool state )
{
    keyboard_set_light_top( state );
    keyboard_set_light_bot( state );
}

