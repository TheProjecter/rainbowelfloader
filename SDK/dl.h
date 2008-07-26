#ifndef SDK_DL_H
#define SDK_DL_H

#include <typedefs.h>

#define KEY_0       	0
#define KEY_1       	1
#define KEY_2       	2
#define KEY_3       	3
#define KEY_4       	4
#define KEY_5       	5
#define KEY_6       	6
#define KEY_7       	7
#define KEY_8       	8
#define KEY_9       	9
#define KEY_STAR    	10
#define KEY_POUND   	11

#define KEY_RED     	17
#define KEY_GREEN   	18

#define KEY_LSOFT   	14 
#define KEY_RSOFT   	15 
#define KEY_MENU    	20

#define KEY_SMART   	21

#define KEY_VOLUP   	23
#define KEY_VOLDOWN 	24

#define KEY_UP      	44
#define KEY_DOWN    	45
#define KEY_LEFT    	46
#define KEY_RIGHT   	47
#define KEY_CENTER  	61 

#define KEY_CAM    		0x3F

#define KEY_VOICE   	0x2B
#define KEY_HANDSFREE   0x33
#define KEY_ITUNES 		0x42


/******************************
   ���� 
*******************************/

/* ��������� ������ */
void DAL_DisableDisplay( UINT32 p1 ); // p1 = 0

/* �������� ������ */
void DAL_EnableDisplay( UINT32 p1 ); // p1 = 0

void DL_KeyUpdateKeypadBacklight( UINT8 P1 ); // P1 = 1 lighting; P2 = 0

UINT32 UIS_SetBacklight( UINT8 P1 );

// ����������� ������� �������
UINT32 UIS_SetBacklightWithIntensity( UINT8 color, // = 255 
									  UINT8 intensity // = 0...6
									); 



/******************************
   DbFeature
******************************/

#define ID_KEYPAD_LOCK_79              0x86A 
#define ID_KEYPAD_LOCK_49              0x7F3 
#define ID_WORKING_TABLE_49			   0x7F8
#define ID_IMEI                        0x9CE

// ������ 
UINT8 DL_DbFeatureGetCurrentState( UINT16 fstate_ID, UINT8 *state );
// ������ 
UINT8 DL_DbFeatureStoreState(UINT16 fstate_ID, UINT8 state);

UINT8 DL_DbFeatureGetValueString(UINT32 feature_id, WCHAR *feature_string );

/*************************
  ����
*************************/

typedef struct {
  UINT16   seem_element_id;
  UINT16   seem_record_number;
  UINT32   seem_offset;
  UINT32   seem_size;
} SEEM_ELEMENT_DATA_CONTROL_T; 


// ������ �� ����
UINT16   SEEM_ELEMENT_DATA_read 	( 	SEEM_ELEMENT_DATA_CONTROL_T  *data_ctrl_ptr, // ��������� �� ��������� ������, ���������� ���������� � �������
										UINT8  *data_buf, // ��������� �� �����, ���� ����������� ������
										BOOL read_zero_byte_allowed  // ���� true, �� ����� ������ ��������� ����, ����� ������� ������ 255
									);

//  ������ � ���												
UINT16  SEEM_ELEMENT_DATA_write	(  	SEEM_ELEMENT_DATA_CONTROL_T  *data_ctrl_ptr,
									UINT8  *seem_data_ptr // ��������� �� �����, ��� �������� ������������ ������
								);	
													
/* ������ � ����� seem_data count ���� ���� seem, ������ record
	����� ������� ����������� �������� �� ����� count ���� ������! */
UINT32 SEEM_FDI_OUTSIDE_SEEM_ACCESS_read( UINT32 seem,  UINT32 record,  void* seem_data,  UINT32 count );

/* ���������� �� ������ seem_data count ���� � ��� seem, ������ record
	�� ��������� */
#define SEEM_WRITE_METHOD_ADD				0
#define SEEM_WRITE_METHOD_UPDATE			1
UINT32 SEEM_FDI_OUTSIDE_SEEM_ACCESS_write( UINT32 method,  UINT32 seem,  UINT32 record,  void* seem_data,  UINT32 count );
													
													
/****************************
  ������� 
*****************************/													
/* ������� ������ */
void HAPI_WATCHDOG_soft_reset( void );

/* ������� ���������� */
void pu_main_powerdown(UINT32 r0);


/****************************
  ��������� 
****************************/

enum // volume_type
{
    BASE = 0,	// ��������� ������

    PHONE, // ��������� ����������
    VOICE, // ��������� �����������  LTE
    MICROPHONE, // ��������� ���������
    MULTIMEDIA, //  ��������� ����������� LTE2 � V3i
    PTT_TONES,
    MUTABLE_MAX,
    IMMUTABLE_MAX,
    MAX = IMMUTABLE_MAX
};

// ���������� ���������
void DL_AudSetVolumeSetting(UINT8 volume_type, UINT8 volume);
// �������� ������� ���������
void DL_AudGetVolumeSetting(UINT8 volume_type, UINT8 *volume);


/****************************
  ������
****************************/

#define MAX_CALLS                   7

typedef struct
{       
    UINT16            call_id;  
    UINT8             call_state;
} CALL_ID_T;

typedef struct
{
    UINT8  		number_of_calls;
    UINT8 		overall_call_state;
    CALL_ID_T 	call_state_info[MAX_CALLS];
} CALL_STATES_T;


// ���� number_of_calls == 0, �� ������� ���
void DL_SigCallGetCallStates(CALL_STATES_T *call_states);

// TRUE - ������ (��������/���������)
BOOL APP_MMC_Util_IsVoiceCall(void); // ���� FALSE, �� ������� ���

// TRUE - ������ (��������/���������)
BOOL APP_MMC_Util_IsVideoCall(void); // ���� FALSE, �� ������� ���

/*******************************
  �������� ��������� 
*******************************/

typedef struct
{
	WCHAR  address[51];
	UINT8  addr_type; // 0 -SMS, 1 - EMAIL, 2 - No, 3 - Long Msg ??? 
	WCHAR  contents[512]; // ������������ ������ 0x7BFE, ������ ��� SMS, �����, ��� �����
} SEND_TEXT_MESSAGE_T;

UINT32 DL_SigMsgSendTextMsgReq(IFACE_DATA_T *port, SEND_TEXT_MESSAGE_T *msg_ptr);

/********************************
  �����
*********************************/
// ����������� !

#define SC_TYPE_URL		5
#define SC_TYPE_APP		6

typedef UINT8 SC_TYPE_T;

typedef struct
{
    UINT8            	seem_rec;    // seem_rec-1
    UINT8				type;        // ��� ����� 
    UINT8            	index;       // ����� � ������, ������ �� 1. ����� �����
    UINT8            	unk1;        // 0xFE
    UINT32            	ev_code;
    UINT32            	list_index;	 // id ����������� ������ ������
    UINT32            	param1;       
	UINT32            	list2_index; // ���� �����-�� id ������
    UINT32            	param2;       
    UINT32            	data;	     // ������������ ��� ��������� �� ������, �������� ��������� �� URL-����� 
    UINT32		        lang_text;   // RESOURCE_ID
    WCHAR            	text[17];	 // ��� �����
    UINT16            	unk2;        // 0xffbd
    
} SEEM_0002_T;


// �������� �����									
UINT8 DL_DbShortcutCreateRecord( IFACE_DATA_T  *data, SEEM_0002_T  record ); //10726BE4

// ���������� �����
UINT8 DL_DbShortcutUpdateRecord( IFACE_DATA_T  *data, SEEM_0002_T  record ); //10726B4A

// �������� �����
UINT8 DL_DbShortcutDeleteRecord( IFACE_DATA_T  *data, UINT8 seem_rec); //10726B22

// ���������  recordId,   0 - no error
UINT8 DL_DbShortcutGetRecordByRecordId( IFACE_DATA_T  *data, UINT8  seem_rec); //10726ACC

// �������� ����� ��������� ������
UINT16 DL_DbShortcutGetNumOfRecordsAvailable( void ); //10726AF4

// �������� ����� ������������ ������
UINT16 DL_DbShortcutGetNumOfRecordsUsed( BOOL voice_shortcut ); //10726AF8

// �������� ������ ��������� �����
UINT8 DL_DbGetFirstAvailableNumber( void ); //10726B1E

// �������� ����� ������������  ������ URL
UINT16 DL_DbShortcutGetNumOfURLRecordsUsed( void ); //10726C70

// ��������� URLId,   0 - no error
UINT32 DL_DbShortcutGetURLByURLId( IFACE_DATA_T *data, UINT32 URLId); //10726C74

// ��������� ���� ������
SC_TYPE_T DL_DbShortcutGetshortcutType( UINT8 index ); //10726CCA

// �������� ����� ��������� ������ URL
UINT16 DL_DbShortcutGetNumOfURLRecordsAvailable( void ); //10726CD2


/********************************
  ������ 
********************************/

// ��������������� ����
UINT32 DL_AudPlayTone( UINT32 tone,  UINT8 volume ); //Current volume = 0xFF

// �������� ������
void DL_KeyInjectKeyPress( UINT8 key_code, 
						   UINT8 states, // 0 - Press; 1 - Release
						   UINT8 p3 // = 0
						  );

// ��������� �����
UINT32 DL_DbSigNamGetSecurityCode(WCHAR *);
UINT32 DL_DbSigNamGetUnlockCode(WCHAR *);

// ������ PIN
enum {
	SIMPIN_STATUS_SECURED = 2,	// ����� ��� �����
	SIMPIN_STATUS_NO_PIN,
	SIMPIN_STATUS_INVALID
};
UINT8 DL_SimMgrGetPinStatus( UINT8 card );

// ���� ������� ����
typedef struct
{
    UINT8 	percent;
    INT8    dbm;
} SIGNAL_STRENGTH_T;

void DL_SigRegQuerySignalStrength(SIGNAL_STRENGTH_T *signal_strength);


// Cell Id
void DL_SigRegGetCellID(UINT16 *cell_id);

UINT8 DL_PwrGetActiveBatteryPercent( void );	// ����������� �-���

enum
{
    CHARGING_MODE_NONE = 0,
    CHARGING_MODE_NORMAL = 1,
    CHARGING_MODE_PC
};

UINT8 DL_PwrGetChargingMode( void );

UINT32 SetFlashLight( UINT32 status );

#endif
