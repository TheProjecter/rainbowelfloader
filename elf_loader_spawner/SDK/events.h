
#ifndef EVENTS_H
#define EVENTS_H

#include <typedefs.h>

// ��. EVENT_T � EVENT_DATA_T @apps.h

#define EV_GRANT_TOKEN				30
#define EV_REVOKE_TOKEN				31

#define EV_KEY_PRESS				500 	// key_pressed
#define EV_KEY_RELEASE				501 	// key_pressed

// ��������� ��� ���������� ������ �������
#define EV_DIALOG_DONE				0x201C
// ��������� ��� ������� �� ������ "�����", � CharEditor ������ "Ok"
#define EV_DONE						0x2020
// CharEditor ������ "������"
#define EV_CANCEL					0x2008
// ��������� ��� ������� ��������� �����/���� � ������
#define EV_LIST_NAVIGATE			0x2043 // index
// ��������� ��� ������� ��������� � ������ ��� ������ "�����"
#define EV_SELECT					0x2058 // index
// ���������� �������� ����� ��������� ��������� ������ ������
#define EV_REQUEST_LIST_ITEMS		0x202C // list_items_req
#define UIS_EV_LIST_DATA			0x202C
// ���������� ���������
#define EV_NO						0x2046
// ���������� ���������
#define EV_YES						0x2079

// ������� ������
#define EV_DATA						0x200F // EVENT_T::attachment
// ?
#define EV_BROWSE					0x2006

// ��������� ��� ��������� ������������� ������-���� ����
#define EV_DATA_CHANGE				0x2011 // index
// ��������� ������
#define EV_REQUEST_DATA				0x202B // data_req

// �������� ������
#define EV_TIMER_EXPIRED			0x8205A // (DL_TIMER_DATA_T*)EVENT_T::attachment


/* new events */
#define EV_GAIN_FOCUS				0x14
#define EV_POWER_DOWN				0x11
#define EV_USER_ACTIVITY			0x7EE	// �������� ��������
#define EV_UIS_ACTIVITY				0x7ED	// ������������ UIS

#define EV_CREATE_SHORTCUT			0x20C5	// ������� ����
#define EV_SCREENSAVER_START		0xDFC


#define EV_PROGRESS_CANCEL			0x2008
#define EV_PROGRESS_SWAP			0x2041


#define EV_LIST_GREEN_LONG_PRESS	0x205a
#define EV_LIST_ZERO_PRESS			0x203c	// �� �������� =(
#define EV_NAV_DOWN					0x208f
#define EV_NAV_UP					0x2090

#define EV_REG_NETWORK		   	  0x8200B 

#define FREE_BUF_FLAG_T		UINT8
#define FBF_FREE			100		// �� ������ ���������� ������
#define FBF_LEAVE			101		// ���������� ������ ������� �� ������������� �������


typedef struct
{
    UINT32                    bufsize;
    UINT32                    index;
    UINT8                     unk2;
} REQUEST_DATA_T;

typedef struct
{
    UINT32                    ID;           // 4? ������������� ������
    UINT32                    begin_idx;    // 8 ��������� ������ ���������� ������ ���������
    UINT8                     count;        // 9 ������� ��������� ������ ���������
} REQUEST_LIST_ITEMS_T;

typedef struct
{
    char uri[64];
    char params[64];
} ELF_PARAMS_T;
/* ���������, ���������� �� ������, ������������ � �������� */
typedef union
{
    UINT8                           key_pressed; //1
    UINT32                          index; //5
    REQUEST_LIST_ITEMS_T            list_items_req; //14
    REQUEST_DATA_T                  data_req; //23

	//ELF parameters
	ELF_PARAMS_T				start_params;
	//padding to real size
	UINT8						pad[0xFB];
} EVENT_DATA_T;

typedef struct
{
    UINT32                    data_tag;
    EVENT_DATA_T              data;
} ADD_EVENT_DATA_T;

/* ��������� �������� ������� */
typedef struct tagEVENT_T
{
    EVENT_CODE_T              code; //4
    UINT32                    unk1; //8
    UINT32                    ev_port; //12
    UINT8                     unk2; //13
    BOOL                      is_consumed; //14
    BOOL                      is_firstpass; //15
    UINT8                     unk3; //16
    UINT32                    unk4; //20
    UINT32                    unk5; //24
    struct tagEVENT_T        *next; //28
    UINT32                    data_tag; //32
    //UINT8                     pad[8];
    UINT32                    unk6; //36
    UINT32                    unk7; //40
    EVENT_DATA_T              data; //434  
    
    BOOL                      is_attach; //435
    UINT16                    att_size; //437
    
    void                      *attachment; //441
    UINT8                     unk8; //442
    
} EVENT_T; //size = 296

typedef struct
{
    EVENT_CODE_T              code;
    UINT8                     unk1;
    UINT8                     unk2;
    EVENT_T                   *top;
    void                      *unk3;
    UINT8                     unk4[6];
    UINT8                     unk5;
} EVENT_STACK_T;

// �������� ������� event �� ������
typedef EVENT_T* (*f_AFW_GetEv)( EVENT_STACK_T *ev_st );
f_AFW_GetEv AFW_GetEv = ( f_AFW_GetEv )0x102F5E7C;

typedef EVENT_T* (*f_AFW_GetEvSeqn)( EVENT_STACK_T *ev_st );
f_AFW_GetEvSeqn AFW_GetEvSeqn = ( f_AFW_GetEvSeqn )0x102F5EA8;

// ������� ���������� ������ (� ��������� ��������� ������ ��� ������)
typedef UINT32 ( *f_AFW_AddEvNoD )( EVENT_STACK_T    *ev_st,  
                     UINT16           event_code );
f_AFW_AddEvNoD AFW_AddEvNoD = ( f_AFW_AddEvNoD )0x102F5592;

typedef UINT32 ( *f_AFW_AddEvEvD )( EVENT_STACK_T    *ev_st,
                     UINT16           event_code,
                     ADD_EVENT_DATA_T *data );
f_AFW_AddEvEvD AFW_AddEvEvD = ( f_AFW_AddEvEvD )0x102F55C4;

typedef UINT32 ( *f_AFW_AddEvAux )( EVENT_STACK_T    *ev_st,
                     UINT16           event_code,
                     FREE_BUF_FLAG_T  free_buf,
                     UINT32           att_size,
                     void             *attachment );
f_AFW_AddEvAux AFW_AddEvAux = ( f_AFW_AddEvAux )0x102F55F6;

typedef UINT32 ( *f_AFW_AddEvAuxD )( EVENT_STACK_T     *ev_st,
                      UINT16            event_code,
                      ADD_EVENT_DATA_T  *data,
                      FREE_BUF_FLAG_T  free_buf,
                      UINT32           att_size,
                      void             *attachment );
f_AFW_AddEvAuxD AFW_AddEvAuxD = ( f_AFW_AddEvAuxD )0x102F5624;

typedef UINT32 ( *f_AFW_CreateInternalQueuedEvAux )( UINT32 ev_id, 
                                      FREE_BUF_FLAG_T flags,
                                      UINT32 att_size,
                                      const void * att_data );
f_AFW_CreateInternalQueuedEvAux AFW_CreateInternalQueuedEvAux = ( f_AFW_CreateInternalQueuedEvAux )0x102F5AC6;

// ������ ��������� ����� �� ������
typedef UINT32 ( *f_APP_ConsumeEv )( EVENT_STACK_T *ev_st,  void *app );
f_APP_ConsumeEv APP_ConsumeEv = ( f_APP_ConsumeEv )0x1040A4E8;

// ��������� ����� EV_LIST_ITEMS (����� �� EV_REQUEST_LIST_ITEMS)
typedef UINT32 ( *f_APP_UtilAddEvUISListData )( EVENT_STACK_T    *ev_st,
                                 void             *app,
                                 UINT32           param2, // = 0
                                 UINT32           begin_index,
                                 UINT8            count,
                                 FREE_BUF_FLAG_T  free_buf,
                                 UINT32           bufsize,
                                 void             *buffer );
f_APP_UtilAddEvUISListData APP_UtilAddEvUISListData = ( f_APP_UtilAddEvUISListData )0x105CFFBA;

typedef UINT32 ( *f_APP_UtilAddEvUISListChange )( EVENT_STACK_T    *ev_st,
                                   void             *app,
                                   UINT32           param2, // = 0
                                   UINT32           position,
                                   UINT8            size,
                                   BOOL             refresh_data,
                                   UINT8            param6,          // = 2
                                   FREE_BUF_FLAG_T  free_buf,
                                   UINT32           bufsize,	// NULL ?
                                   void             *buffer );	// NULL ?
f_APP_UtilAddEvUISListChange APP_UtilAddEvUISListChange = ( f_APP_UtilAddEvUISListChange )0x105CFF40;

// ��������� ����� EV_REQUEST_DATA ��� ���� � ������ ��������
typedef UINT32 ( *f_APP_UtilAddEvUISGetDataForItem )( EVENT_STACK_T    *ev_st,
                                       void             *app,
                                       UINT32           index ); 

f_APP_UtilAddEvUISGetDataForItem APP_UtilAddEvUISGetDataForItem = ( f_APP_UtilAddEvUISGetDataForItem )0x105CFF1C;

#endif
