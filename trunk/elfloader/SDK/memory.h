#ifndef MEMORY_H
#define MEMORY_H

#include <typedefs.h>


// выделение и освобождение памяти
typedef void * ( *f_suAllocMem )( UINT32 size, INT32 *result );
f_suAllocMem suAllocMem = ( f_suAllocMem )0x10040310;

typedef void ( *f_suFreeMem )( void *ptr );
f_suFreeMem suFreeMem = ( f_suFreeMem )0x10040338;

#define malloc(sz)		suAllocMem(sz, NULL)

//#define free(mb)		suFreeMem(mb);

#define free(p) { \
if(p) { \
suFreeMem(p); \
p=NULL; \
} \
}

void __rt_memclr( void *, UINT32 size );						// Забивает нулями блок памяти
#define memclr(m,s)		__rt_memclr((void *)m,(UINT32)s)	// Копирует блоки памяти
#define memcpy(dst,src,sz)		__rt_memcpy((void *)dst,(const void *)src,(UINT32)sz)
void * __rt_memset( void *, int, UINT32 size );				// Забивает указанным байтом блок памяти
//#define memset(m,v,sz)		__rt_memset((void *)m,(int)v,(UINT32)sz)

#endif 
