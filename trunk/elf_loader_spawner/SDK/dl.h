#ifndef SDK_DL_H
#define SDK_DL_H

#include <typedefs.h>

#define KEY_0       0
#define KEY_1       1
#define KEY_2       2
#define KEY_3       3
#define KEY_4       4
#define KEY_5       5
#define KEY_6       6
#define KEY_7       7
#define KEY_8       8
#define KEY_9       9
#define KEY_STAR    10
#define KEY_POUND   11

#define KEY_RED     17
#define KEY_GREEN   18

#define KEY_LSOFT   	14 
#define KEY_RSOFT   	15 

#define KEY_MENU    20
#define KEY_SMART   21

#define KEY_VOLUP   23
#define KEY_VOLDOWN 24

#define KEY_UP      44
#define KEY_DOWN    45
#define KEY_LEFT    46
#define KEY_RIGHT   47
#define KEY_CENTER  	61 

#define KEY_CAM     0x3F

typedef UINT32 ( *f_DL_AudPlayTone )( UINT32 tone,  UINT8 volume ); //Current volume = 0xFF
f_DL_AudPlayTone DL_AudPlayTone = ( f_DL_AudPlayTone )0x10785B22;

				/* Функции таймера - не проверены */

/* Когда таймер срабатывает, он создаёт ивент EV_TIMER_EXPIRED, attachment которого указывает на DL_TIMER_DATA_T */

/* Остановить таймер */

typedef void ( *f_PFprintf )(char* format, ...);
f_PFprintf PFprintf = ( f_PFprintf )0x1079F912;
/******************************
   DbFeature
******************************/

#define ID_KEYPAD_LOCK_79              0x86A 
#define ID_KEYPAD_LOCK_49              0x7F3 
#define ID_WORKING_TABLE_49			   0x7F8

// чтение 
typedef UINT8 ( *f_DL_DbFeatureGetCurrentState )( UINT16 fstate_ID, UINT8 *state );
f_DL_DbFeatureGetCurrentState DL_DbFeatureGetCurrentState = ( f_DL_DbFeatureGetCurrentState )0x1071DFD8;
// запись 
typedef UINT8 ( *f_DL_DbFeatureStoreState )(UINT16 fstate_ID, UINT8 state);
f_DL_DbFeatureStoreState DL_DbFeatureStoreState = ( f_DL_DbFeatureStoreState )0x1071E058;

typedef UINT8 ( *f_DL_DbFeatureGetValueString )(UINT32 feature_id, WCHAR *feature_string );
f_DL_DbFeatureGetValueString DL_DbFeatureGetValueString = ( f_DL_DbFeatureGetValueString )0x1071E024;
/*************************
  seem
*************************/

typedef struct {
  UINT16   seem_element_id;
  UINT16   seem_record_number;
  UINT32   seem_offset;
  UINT32   seem_size;
} SEEM_ELEMENT_DATA_CONTROL_T; 


// чтение из сима
typedef UINT16   ( *f_SEEM_ELEMENT_DATA_read ) 	( 	SEEM_ELEMENT_DATA_CONTROL_T  *data_ctrl_ptr, // указатель на структуру данных, содержащую информацию о запросе
										UINT8  *data_buf, // указатель на буфер, куда прочитаются данные
										BOOL read_zero_byte_allowed  // если true, то можно читать маленькие симы, длина которых меньше 255
									);
f_SEEM_ELEMENT_DATA_read SEEM_ELEMENT_DATA_read = ( f_SEEM_ELEMENT_DATA_read )0x101D1958;

//  запись в сим												
typedef UINT16  ( *f_SEEM_ELEMENT_DATA_write )( SEEM_ELEMENT_DATA_CONTROL_T  *data_ctrl_ptr,
									UINT8  *seem_data_ptr // указатель на буфер, где хранятся записываемые данные
								);	
f_SEEM_ELEMENT_DATA_write SEEM_ELEMENT_DATA_write = ( f_SEEM_ELEMENT_DATA_write )0x101D1B84; //C8
		
/* Читает в буфер seem_data count байт сима seem, записи record
	Перед чтением ОБЯЗАТЕЛЬНО выделить не менее count байт памяти! */
typedef UINT32 ( *f_SEEM_FDI_OUTSIDE_SEEM_ACCESS_read )( UINT32 seem,  UINT32 record,  void* seem_data,  UINT32 count );
f_SEEM_FDI_OUTSIDE_SEEM_ACCESS_read SEEM_FDI_OUTSIDE_SEEM_ACCESS_read = ( f_SEEM_FDI_OUTSIDE_SEEM_ACCESS_read )0x101D3030;

/* Записывает из буфера seem_data count байт в сим seem, запись record
	Не проверено */
#define SEEM_WRITE_METHOD_ADD				0
#define SEEM_WRITE_METHOD_UPDATE			1
typedef UINT32 (*f_SEEM_FDI_OUTSIDE_SEEM_ACCESS_write )( UINT32 method,  UINT32 seem,  UINT32 record,  void* seem_data,  UINT32 count );
f_SEEM_FDI_OUTSIDE_SEEM_ACCESS_write SEEM_FDI_OUTSIDE_SEEM_ACCESS_write = ( f_SEEM_FDI_OUTSIDE_SEEM_ACCESS_write )0x101D2D22;
				
/*AUDIO*/

enum // volume_type
{
    BASE = 0,	// громкость звонка

    PHONE, // громкость клавиатуры
    VOICE, // громкость мультимедия  LTE
    MICROPHONE, // громкость разговора
    MULTIMEDIA, //  громкость мультимедия LTE2 и V3i
    PTT_TONES,
    MUTABLE_MAX,
    IMMUTABLE_MAX,
    MAX = IMMUTABLE_MAX
};


// установить громкость
typedef void ( *f_DL_AudSetVolumeSetting )(UINT8 volume_type, UINT8 volume);
f_DL_AudSetVolumeSetting DL_AudSetVolumeSetting = ( f_DL_AudSetVolumeSetting )0x10784EC4;
// получить текущую громкость
typedef void ( *f_DL_AudGetVolumeSetting )(UINT8 volume_type, UINT8 *volume);
f_DL_AudGetVolumeSetting DL_AudGetVolumeSetting = ( f_DL_AudGetVolumeSetting )0x10784FA0;

/****************************
  Питание 
*****************************/			

typedef UINT32 ( *f_UIS_SetBacklightWithIntensity )( UINT8 color, // = 255 
									  UINT8 intensity // = 0...6
									); 
f_UIS_SetBacklightWithIntensity UIS_SetBacklightWithIntensity = ( f_UIS_SetBacklightWithIntensity )0x108C5D28;

typedef void ( *f_DL_KeyUpdateKeypadBacklight )( UINT8 P1 ); // P1 = 1 lighting; P2 = 0
f_DL_KeyUpdateKeypadBacklight DL_KeyUpdateKeypadBacklight = ( f_DL_KeyUpdateKeypadBacklight )0x10730FCA;

/* Начать мигалку(funlight) под номером fl_id
	 В прошивке функция в одном месте выполняется с p2 = 3,
	 но на тестах это приводит к потуханию дисплея (наверное возможности шире...) 

/* Отключить диспей */
typedef void ( *f_DAL_DisableDisplay )( UINT32 p1 ); // p1 = 0
f_DAL_DisableDisplay DAL_DisableDisplay = ( f_DAL_DisableDisplay )0x108246FA;

/* Включить диспей */
typedef void ( *f_DAL_EnableDisplay )( UINT32 p1 ); // p1 = 0
f_DAL_EnableDisplay DAL_EnableDisplay = ( f_DAL_EnableDisplay )0x10824748;

/* Функция выключения */
typedef void ( *f_pu_main_powerdown )(UINT32 r0);
f_pu_main_powerdown pu_main_powerdown = ( f_pu_main_powerdown )0x101AA68C;

typedef struct
{
    UINT8 	percent;
    INT8    dbm;
} SIGNAL_STRENGTH_T;

typedef void ( *f_DL_SigRegQuerySignalStrength )(SIGNAL_STRENGTH_T *signal_strength);
f_DL_SigRegQuerySignalStrength DL_SigRegQuerySignalStrength = ( f_DL_SigRegQuerySignalStrength )0x1073EDB2;

typedef UINT8 ( *f_DL_PwrGetActiveBatteryPercent )( void );	// бесполезная ф-ция
f_DL_PwrGetActiveBatteryPercent DL_PwrGetActiveBatteryPercent = ( f_DL_PwrGetActiveBatteryPercent )0x1070EDB2;

typedef UINT8 ( *f_DL_PwrGetChargingMode )( void );
f_DL_PwrGetChargingMode DL_PwrGetChargingMode = ( f_DL_PwrGetChargingMode )0x1070ECF0;

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


// если number_of_calls == 0, то вызовов нет
typedef void ( *f_DL_SigCallGetCallStates )(CALL_STATES_T *call_states);
f_DL_SigCallGetCallStates DL_SigCallGetCallStates = ( f_DL_SigCallGetCallStates )0x1073E3BC;

// TRUE - звонок (входящий/исходящий)
typedef BOOL ( *f_APP_MMC_Util_IsVoiceCall )(void); // если FALSE, то вызовов нет
f_APP_MMC_Util_IsVoiceCall APP_MMC_Util_IsVoiceCall = ( f_APP_MMC_Util_IsVoiceCall )0x1049B70C;

typedef BOOL ( *f_APP_MMC_Util_IsVideoCall )(void); // если FALSE, то вызовов нет
f_APP_MMC_Util_IsVideoCall APP_MMC_Util_IsVideoCall = ( f_APP_MMC_Util_IsVideoCall )0x1049B760;

/*******************************
  Отправка сообщений 
*******************************/

typedef struct
{
	WCHAR  address[51];
	UINT8  addr_type; // 0 -SMS, 1 - EMAIL, 2 - No, 3 - Long Msg ??? 
	WCHAR  contents[512]; // максимальный размер 0x7BFE, только для SMS, думаю, это много
} SEND_TEXT_MESSAGE_T;

typedef UINT32 ( *f_DL_SigMsgSendTextMsgReq )(IFACE_DATA_T *port, SEND_TEXT_MESSAGE_T *msg_ptr);
f_DL_SigMsgSendTextMsgReq DL_SigMsgSendTextMsgReq = ( f_DL_SigMsgSendTextMsgReq )0x1073E914;

typedef void ( *f_DL_KeyInjectKeyPress )( UINT8 key_code, 
						   UINT8 states, // 0 - Press; 1 - Release
						   UINT8 p3 // = 0
						  );
f_DL_KeyInjectKeyPress DL_KeyInjectKeyPress = ( f_DL_KeyInjectKeyPress )0x10730F66;


/********************************
  Метки
*********************************/
// непроверено !

#define SC_TYPE_URL		5
#define SC_TYPE_APP		6

typedef UINT8 SC_TYPE_T;

typedef struct
{
    UINT8            	seem_rec;    // seem_rec-1
    UINT8				type;        // тип метки 
    UINT8            	index;       // номер в списке, отсчет от 1. Номер метки
    UINT8            	unk1;        // 0xFE
    UINT32            	ev_code;
    UINT32            	list_index;	 // id выделенного пункта списка
    UINT32            	param1;       
	UINT32            	list2_index; // тоже какой-то id пункта
    UINT32            	param2;       
    UINT32            	data;	     // используется для указателя на данные, например указатель на URL-адрес 
    UINT32		        lang_text;   // RESOURCE_ID
    WCHAR            	text[17];	 // имя метки
    UINT16            	unk2;        // 0xffbd
    
} SEEM_0002_T;


// создание метки									
typedef UINT8 ( *f_DL_DbShortcutCreateRecord )( IFACE_DATA_T  *data, SEEM_0002_T  record ); //
f_DL_DbShortcutCreateRecord DL_DbShortcutCreateRecord = ( f_DL_DbShortcutCreateRecord )0x10726BE4;

// обновление метки
typedef UINT8 ( *f_DL_DbShortcutUpdateRecord )( IFACE_DATA_T  *data, SEEM_0002_T  record ); //
f_DL_DbShortcutUpdateRecord DL_DbShortcutUpdateRecord = ( f_DL_DbShortcutUpdateRecord )0x10726B4A;

// удаление метки
typedef UINT8 ( *f_DL_DbShortcutDeleteRecord )( IFACE_DATA_T  *data, UINT8 seem_rec); //
f_DL_DbShortcutDeleteRecord DL_DbShortcutDeleteRecord = ( f_DL_DbShortcutDeleteRecord )0x10726B22;

// проверяет  recordId,   0 - no error
typedef UINT8 ( *f_DL_DbShortcutGetRecordByRecordId )( IFACE_DATA_T  *data, UINT8  seem_rec); //
f_DL_DbShortcutGetRecordByRecordId DL_DbShortcutGetRecordByRecordId = ( f_DL_DbShortcutGetRecordByRecordId )0x10726ACC;

// получает номер доступной записи
typedef UINT16 ( *f_DL_DbShortcutGetNumOfRecordsAvailable )( void ); //
f_DL_DbShortcutGetNumOfRecordsAvailable DL_DbShortcutGetNumOfRecordsAvailable = ( f_DL_DbShortcutGetNumOfRecordsAvailable )0x10726AF4;

// получает номер используемой записи
typedef UINT16 ( *f_DL_DbShortcutGetNumOfRecordsUsed )( BOOL voice_shortcut ); //
f_DL_DbShortcutGetNumOfRecordsUsed DL_DbShortcutGetNumOfRecordsUsed = ( f_DL_DbShortcutGetNumOfRecordsUsed )0x10726AF8;

// получает первый доступный номер
typedef UINT8 ( *f_DL_DbGetFirstAvailableNumber )( void ); //
f_DL_DbGetFirstAvailableNumber DL_DbGetFirstAvailableNumber = ( f_DL_DbGetFirstAvailableNumber )0x10726B1E;

// получает номер используемой  записи URL
typedef UINT16 ( *f_DL_DbShortcutGetNumOfURLRecordsUsed )( void ); //
f_DL_DbShortcutGetNumOfURLRecordsUsed DL_DbShortcutGetNumOfURLRecordsUsed = ( f_DL_DbShortcutGetNumOfURLRecordsUsed )0x10726C70;

// проверяет URLId,   0 - no error
typedef UINT32 ( *f_DL_DbShortcutGetURLByURLId )( IFACE_DATA_T *data, UINT32 URLId); //
f_DL_DbShortcutGetURLByURLId DL_DbShortcutGetURLByURLId = ( f_DL_DbShortcutGetURLByURLId )0x10726C74;

// получение типа записи
typedef SC_TYPE_T ( *f_DL_DbShortcutGetshortcutType )( UINT8 index ); //
f_DL_DbShortcutGetshortcutType DL_DbShortcutGetshortcutType = ( f_DL_DbShortcutGetshortcutType )0x10726CCA;

// получает номер доступной записи URL
typedef UINT16 ( *f_DL_DbShortcutGetNumOfURLRecordsAvailable )( void ); //
f_DL_DbShortcutGetNumOfURLRecordsAvailable DL_DbShortcutGetNumOfURLRecordsAvailable = ( f_DL_DbShortcutGetNumOfURLRecordsAvailable )0x10726CD2;

// статус PIN
enum {
	SIMPIN_STATUS_SECURED = 2,	// Также без симки
	SIMPIN_STATUS_NO_PIN,
	SIMPIN_STATUS_INVALID
};
typedef UINT8 ( *f_DL_SimMgrGetPinStatus )( UINT8 card );
f_DL_SimMgrGetPinStatus DL_SimMgrGetPinStatus = ( f_DL_SimMgrGetPinStatus )0x1073FFC4;

typedef void ( *f_DL_SigRegGetCellID )(UINT16 *cell_id);
f_DL_SigRegGetCellID DL_SigRegGetCellID = ( f_DL_SigRegGetCellID )0x1073EDBA;

typedef UINT32 ( *f_SetFlashLight )( UINT32 status );
f_SetFlashLight SetFlashLight = ( f_SetFlashLight )0x101A6BB6;


#endif
