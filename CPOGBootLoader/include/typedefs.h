#ifndef TYPEDEFS_H
#define TYPEDEFS_H

    typedef signed char			int8;
    typedef unsigned char			uint8;
    typedef signed short			int16;
    typedef unsigned short		uint16;
    typedef signed long			int32;
    typedef unsigned long			uint32; 
    typedef signed long long		int64;
    typedef unsigned long long	uint64;

    typedef uint8					bool;
    typedef uint16					wchar;

    #define TRUE					(bool)(1)
    #define FALSE					(bool)(0)

    #define true					(bool)(1)
    #define false					(bool)(0)

    #define NULL					(0)

    #define CHAR_BIT 8
    #define BITMASK(b) (1 << ((b) % CHAR_BIT))
    #define BITSLOT(b) ((b) / CHAR_BIT)
    #define BITSET(a, b) ((a)[BITSLOT(b)] |= BITMASK(b))
    #define BITTEST(a, b) ((a)[BITSLOT(b)] & BITMASK(b))

#endif
