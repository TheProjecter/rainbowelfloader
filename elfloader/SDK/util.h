#ifndef UTIL_H
#define UTIL_H

#include <typedefs.h>


UINT32 strlen( char *str)
{
    int retval;
    for(retval = 0; *str != '\0'; str++) retval++;
    return retval;
}
/* Unicode strings routines */

/* Convert ascii string to unicode */
typedef WCHAR* ( *f_u_atou )( char* astr,  WCHAR* ustr );
f_u_atou u_atou = ( f_u_atou )0x108D5EB0;

typedef WCHAR* ( *f_u_strcpy )( WCHAR* dst,  WCHAR* src );
f_u_strcpy u_strcpy = ( f_u_strcpy )0x108D4C6A;

typedef WCHAR* ( *f_u_strcat )( WCHAR* dst,  WCHAR* src );
f_u_strcat u_strcat = ( f_u_strcat )0x108D4B80;

typedef UINT32 ( *f_u_strlen )( WCHAR* str );
f_u_strlen u_strlen = ( f_u_strlen )0x108D4CB6;

typedef INT32 ( *f_u_strcmp )( WCHAR* str1,  WCHAR* str2 );
f_u_strcmp u_strcmp = ( f_u_strcmp )0x108D4C04;

INT32 u_strncmp( WCHAR* str1,  WCHAR* str2,  UINT32 n );

WCHAR* u_strmakelower( WCHAR* str );

typedef WCHAR* ( *f_u_strmakeupper )( WCHAR* str );
f_u_strmakeupper u_strmakeupper = ( f_u_strmakeupper )0x108D5A74;

WCHAR* u_ltou( INT32 value,  WCHAR* str );

INT32 u_atol( WCHAR* str );

/* Convert unicode string to ascii (valid only for ascii-range symbols) */
//char* u_utoa( const WCHAR* ustr,  char* astr );
char* u_utoa( WCHAR* ustr,  char* astr )
{
    int i, h = 1;
    for( i = 0; i < u_strlen( ustr ); i++ )
    {
        astr[ i ] = ( ( char * )ustr )[ h ];
        h += 2;
    }
    astr[ i ] = 0;
}

/* ANSI strings routines */

/* Quick compare strings */
UINT32 namecmp( char* str1,  char* str2 ); //returns 1 if equal

typedef char * ( *f_strncpy )(char *dst, char *src, int n);
f_strncpy strncpy = ( f_strncpy )0x10284B0C;

char *strcpy(char *s1, const char *s2)
{
    char *s1_p = s1;
    while (*s1++ = *s2++)
      ;
    return s1_p;
}

typedef char* ( *f_strcat )( char* dst,  char* src );
f_strcat strcat = ( f_strcat )0x10284944;

typedef INT32 ( *f_strcmp )( char* str1,  char* str2 );
f_strcmp strcmp = ( f_strcmp )0x10284984;

typedef INT32 ( *f_strncmp )( char* str1,  char* str2,  UINT32 n ); 
f_strncmp strncmp = ( f_strncmp )0x10284ADC;

INT32 strtol( char* str,  char** endstr,  int radix );
UINT32 strtoul( char* str,  char** endstr,  int radix );

typedef void * ( *f_suAllocMem )( UINT32 size, INT32 *result ); //result can be NULL
f_suAllocMem suAllocMem = ( f_suAllocMem )0x10040310;

typedef void ( *f_suFreeMem )( void *ptr );
f_suFreeMem suFreeMem = ( f_suFreeMem )0x10040338;

char * memcpy(void *dest, void *src, int count)
{
    char *sp = (char *)src;
    char *dp = (char *)dest;
    for(; count != 0; count--) *dp++ = *sp++;
    return dest;
}

void uu_strcpy(WCHAR *dst, char *src)
{
	int i=0;
	while (*src != 0)
		dst[i++] = *src++;
	dst[i] = 0;
}

void memset(char *dest, char val, UINT32 len)
{
    char *temp = (char *)dest;
    for ( ; len != 0; len--) *temp++ = val;
}

typedef int ( *f_sprintf )(char *str, const char *format, ...); 
f_sprintf sprintf = ( f_sprintf )0x10283154;

#endif
