#ifndef TIME_DATE_H
#define TIME_DATE_H

#include <typedefs.h>

typedef struct
{
    UINT8     day;
    UINT8     month;
    UINT16    year;
} CLK_DATE_T;

typedef struct
{
    UINT8     hour;
    UINT8     minute;
    UINT8     second;
} CLK_TIME_T;

// �������� ��������� ����
typedef BOOL ( *f_DL_ClkGetDate )( CLK_DATE_T * );
f_DL_ClkGetDate DL_ClkGetDate = ( f_DL_ClkGetDate )0x10711850;//0x10711866;
// �������� ��������� ����� 
typedef BOOL ( *f_DL_ClkGetTime )( CLK_TIME_T * );
f_DL_ClkGetTime DL_ClkGetTime = ( f_DL_ClkGetTime )0x10711898;

//�������� ��������� ����� � ����� 
typedef UINT64 ( *f_suPalReadTime )( void );
f_suPalReadTime suPalReadTime = ( f_suPalReadTime )0x1028B0E4;
// ��������� ����� �� ����� � ������������  
typedef UINT64 ( *f_suPalTicksToMsec )( UINT64 ticks );
f_suPalTicksToMsec suPalTicksToMsec = ( f_suPalTicksToMsec )0x1028B194;

/***************************************
   ������� ������� 
****************************************/

/* ����� ������ �����������, �� ������ ����� EV_TIMER_EXPIRED, attachment �������� ��������� �� DL_TIMER_DATA_T */

typedef struct
{
	UINT32		time;
	UINT32		ID;
} DL_TIMER_DATA_T;

typedef UINT32 ( *f_APP_UtilStartTimer )( UINT32 time,  UINT32 ID,  void *app ); // ID ����� � DL_TIMER_DATA_T ��� ��������� ������
f_APP_UtilStartTimer APP_UtilStartTimer = ( f_APP_UtilStartTimer )0x105D0D20;

/*  ��������� ������, ������� ����� ���������� ����� ������ time �� */
typedef UINT32 ( *f_APP_UtilStartCyclicalTimer )( UINT32 time,  UINT32 ID,  void *app );
f_APP_UtilStartCyclicalTimer APP_UtilStartCyclicalTimer = ( f_APP_UtilStartCyclicalTimer )0x105D0D56;

/* ���������� ������ */
typedef UINT32 ( *f_APP_UtilStopTimer )( void *app );
f_APP_UtilStopTimer APP_UtilStopTimer = ( f_APP_UtilStopTimer )0x105D0DA0;

#endif
