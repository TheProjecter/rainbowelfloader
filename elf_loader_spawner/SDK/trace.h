#ifndef SDK_TRACE_H
#define SDK_TRACE_H

#ifdef __cplusplus
extern "C" {
#endif

extern const char app_name[]; 


/* ��������������� ����� ������ format �� ���� (�������� � ������� MidWay)
	���� �������� ���������� ��� 
	%d - ���������� �����
	%x - �����������������
	%s - ANSI ������
	%i
	%p - ��������� �� ������ (������� ������)
 */
void PFprintf( const char * format, ... ); // %d %x %s, a-la printf

int vsprintf (char *buffer, const char *format, va_list arglist);	

/* ��������������� ����� ������ format �� ���� (�������� � ������� p2k Data loger)
	����������
 */


#ifdef DEBUG

#define TRACE(format, ...)		PFprintf (format, ## __VA_ARGS__)
#define TRACE_STRING(format)	PFprintf (format)

/*

void data_TRACE( char* data, UINT16 size )
{
	UINT16 i = 0;
	char   byte = 0;
	TRACE(" data at 0x%p = [", data);
	for ( i=0; i<size; i++ ) {
		byte = *(data+i);
		TRACE("%02x", byte);
	}
	TRACE_STRING("]\n");
}

*/


#define dbg(format, ...) \
     TRACE("*ELF %s*, line:%d:  " format "\n",app_name, __LINE__ , ## __VA_ARGS__)


#else // #ifndef DEBUG

#define TRACE(format, ...)
#define TRACE_STRING(format)
//#define data_TRACE(data,size)


#define dbg(format, ...)

#endif


#define TRACE2		UtilLogStringData

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // SDK_TRACE_H