#ifndef _LL_PHONE_H_
#define _LL_PHONE_H_

    void jump_blank( );
    void jump_motorola_boot( );

    void port_write_l( uint32 port, int32 data );
    void port_write_w( uint32 port, int16 data );
    void port_write_b( uint32 port, int8 data );

    int32 port_read_l( uint32 port );
    int16 port_read_w( uint32 port );
    int8 port_read_b( uint32 port );
    
    void HAPI_GPIO_config( int8, int16, int16 );

    void pu_main_set_powerup_reason( int8 );

#endif
