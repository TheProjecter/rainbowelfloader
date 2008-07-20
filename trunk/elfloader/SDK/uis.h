
#ifndef UIS_H
#define UIS_H

#include <apps.h>
#include <typedefs.h>
#include <stdarg.h>
#include <resources.h>

enum
{
    ACTION_OP_ADD = 0,
    ACTION_OP_DELETE,
    ACTION_OP_UPDATE
};

typedef struct
{
    UINT8             operation;        // Что делать с текущим пунктом (ACTION_OP_*)
    EVENT_CODE_T      event;            // Ивент, который создаётся при выборе этого действия
    RESOURCE_ID       action_res;       // Ресурс, описывающий действие (см. RES_ACTION_LIST_ITEM_T)

} ACTION_ENTRY_T;

typedef struct
{
    UINT8             count;            // Кол-во элементов
    ACTION_ENTRY_T    action[16];       // Список команд дл работы со списком действий

} ACTIONS_T;

typedef struct
{
    char             format[40];
    UINT32            count;
    UINT32            data[40];
} CONTENT_T;


typedef enum
{
	LIST_IMAGE_MEDIA_PATH_T = 0,
	LIST_IMAGE_RESOURCE_ID_T,
    LIST_IMAGE_DL_FS_MID_T, 			// именно это и юзает список яваприложений
	LIST_IMAGE_MEDIA_PATH_WITH_OFFSET_T,
	LIST_IMAGE_POINTER
} LIST_IMAGE_TYPE_T;


typedef struct				        
{
    WCHAR 	*file_name;		// имя файла
    UINT32   offset;	    // оффсет
    UINT32   size;	        // размер
    UINT8    mime_type;		// тип
} LIST_IMAGE_FILE_T ;

typedef struct
{
    void * file_name;		// указатель на картинку
    UINT32 image_size;		// размер
} LIST_IMAGE_POINTER_T;

      
/* Создаёт контент */
typedef UINT32 ( *f_UIS_MakeContentFromString )( char *format,  CONTENT_T *dst,  ... );
f_UIS_MakeContentFromString UIS_MakeContentFromString = ( f_UIS_MakeContentFromString )0x108C55BA;
/* More information about the string format: 
    The line consists of pointers to incoming parameters 
    specifiers and alignment. 
    Pointers are the type and number of function parameters, 
    possible types: 
    q - a pointer to a string WCHAR 
    s - resource line 
    i - int 
    g - hex int 
    p - resource picture 
    r - CONTENT_T 
    f - pointer to the file 
    Specificators alignment: 
    N - new line 
    S - distribution of text 
    C - text in the center 
    L - with the crop "...", trimmed with a string is too long
    M -  text on middle (vertical alignment)
    T - text on top 
    B - text from the bottom

    For example: "MCq0p1" = "Bring the middle and at the center first 
    dst option after a string, and the second - as a picture" */

/* Стандартный обработчик EV_GRANT_TOKEN */

typedef UINT32 ( *f_APP_HandleUITokenGranted) ( EVENT_STACK_T *ev_st,  void *app );
const f_APP_HandleUITokenGranted APP_HandleUITokenGranted = ( f_APP_HandleUITokenGranted )0x1040AAA8;

/* Стандартный обработчик EV_REVOKE_TOKEN */

typedef UINT32 ( *f_APP_HandleUITokenRevoked )( EVENT_STACK_T *ev_st,  void *app );
const f_APP_HandleUITokenRevoked sAPP_HandleUITokenRevoked = ( f_APP_HandleUITokenRevoked )0x1040AB18;

UINT32 APP_HandleUITokenRevoked( EVENT_STACK_T *ev_st,  void *app )
{
    return sAPP_HandleUITokenRevoked( ev_st, app );
}

/* То же, что APP_UtilChangeState, но при этом ещё будет извлечён(consumed) event */
typedef UINT32 ( *f_APP_UtilConsumeEvChangeState )( UINT8 new_state,  EVENT_STACK_T *ev_st,  void *app );
f_APP_UtilConsumeEvChangeState APP_UtilConsumeEvChangeState = ( f_APP_UtilConsumeEvChangeState )0x105D00C6;

/* Передаёт ивент диалогу */
typedef UINT32 ( *f_UIS_HandleEvent )( UIS_DIALOG_T dialog,  EVENT_STACK_T *ev_st );
f_UIS_HandleEvent UIS_HandleEvent = ( f_UIS_HandleEvent )0x108C4FA2;

/* Вызвать полную перерисовку UI */
typedef UINT32 ( * f_UIS_Refresh )( void );
f_UIS_Refresh UIS_Refresh = ( f_UIS_Refresh )0x108C5B0C;

typedef UINT32 ( *f_UIS_ForceRefresh )( void );
f_UIS_ForceRefresh UIS_ForceRefresh = ( f_UIS_ForceRefresh )0x108C5B4A;

/* Удаляет диалог и выставляет его в NULL */
typedef UINT32 ( *f_APP_UtilUISDialogDelete )( UIS_DIALOG_T  *pdialog );
f_APP_UtilUISDialogDelete APP_UtilUISDialogDelete = ( f_APP_UtilUISDialogDelete )0x105D164E;

typedef UINT32 ( *f_UIS_Delete )( UIS_DIALOG_T dialog );
f_UIS_Delete UIS_Delete = ( f_UIS_Delete )0x108C4B9E;

// установить новый список действий
typedef UINT32 ( * f_UIS_SetActionList )(UIS_DIALOG_T dialog, ACTIONS_T *action_list);     
f_UIS_SetActionList UIS_SetActionList = ( f_UIS_SetActionList )0x108C5B7C;

// устанавливает ивент на джойстик в центр	  
typedef UINT32 ( *f_UIS_SetCenterSelectAction )(UIS_DIALOG_T dialog, EVENT_CODE_T center_select_action);
f_UIS_SetCenterSelectAction UIS_SetCenterSelectAction = ( f_UIS_SetCenterSelectAction )0x108C5C00;

#define DialogType_Dialling 0x05 //dial-up window 
#define DialogType_EnterName 0x08 //input names. . .
#define DialogType_SetDate 0x0B //Set Date 
#define DialogType_SetTime 0x0D //set-up time 
#define DialogType_Homescreen 0x0E //desktop standby 
#define DialogType_list 0x10 //Item List 
#define DialogType_SelectionList 0x13 //options
#define DialogType_BatteryandMemory 0x15 //power, memory usage information, such as window howed that the grid 
#define DialogType_JumpOut 0x17 //pop-up window, such as "keyboard is locked, unlocked by XX", "please wait" category 
#define DialogType_MessageBox 0x1B //information inbox
#define DialogType_GameAni 0x1D //games and applications when they enter the animation 
#define DialogType_WapMenu 0x1E //Wap browser-related menu 
#define DialogType_VideoCamera 0x25 //Camera viewfinder window 
#define DialogType_Password 0x26 //Password window 
#define DialogType_PB_SC_Other 0x28 //phone book, Shortcuts like, a lot of this state 
#define DialogType_Menu 0x2D //Main Menu 
#define DialogType_SecondLevelMenu 0x2E //2 of the three menu and the menu
#define DialogType_WriteText 0x32 //input text 
#define DialogType_Brightness 0x37 //Settings - brightness - highlighted regulation
#define DialogType_Picture 0x39 //Multimedia - picture

      /* Функции создания диалогов */

typedef UINT32 ( *f_UIS_GetActiveDialogType )(UINT8* res);
f_UIS_GetActiveDialogType UIS_GetActiveDialogType = ( f_UIS_GetActiveDialogType )0x108C4C08;

enum
{
    NOTICE_TYPE_DEFAULT = 0,
    NOTICE_TYPE_OK,
    NOTICE_TYPE_FAIL,
    NOTICE_TYPE_WAIT
  /* На самом деле их больше, попробуйте перебрать
     варианты - тем самым вы поможете развитию этого SDK */
};


/* Создаёт окошко с сообщением. type = NOTICE_TYPE_* */
typedef UIS_DIALOG_T ( *f_UIS_CreateTransientNotice )( SU_PORT_T *port,  CONTENT_T *content,  UINT8 type );
f_UIS_CreateTransientNotice UIS_CreateTransientNotice = ( f_UIS_CreateTransientNotice )0x108C4846;

/* Создаёт диалог-запрос */
typedef UIS_DIALOG_T ( *f_UIS_CreateConfirmation )( SU_PORT_T *port,  CONTENT_T *content );
f_UIS_CreateConfirmation UIS_CreateConfirmation = ( f_UIS_CreateConfirmation )0x108C2E18;

/* Создаёт диалог-список */
typedef UIS_DIALOG_T ( *f_UIS_CreateList )( SU_PORT_T       *port,
                             UINT32          param1,          // = 0  ID?
                             UINT32          count,           // Количество пунктов в списке
                             UINT32          marks,           // Что-то связанное с пометками
                             UINT32          *starting_num,   // Сколько пунктов требуется передать для инициализации
                             UINT8           param5,          // = 0
                             UINT8           param6,          // = 2
                             ACTIONS_T       *actions,        // Список действий
                             RESOURCE_ID     caption );       // Заголовок списка
f_UIS_CreateList UIS_CreateList = ( f_UIS_CreateList )0x108C332C;

typedef struct
{
    UINT16	            type;
    RESOURCE_ID	        label;
    BOOL	              readonly;
    BOOL	              show;
    BOOL	              unk5;
    UINT32	            maxlen;
    RESOURCE_ID	        resource;
    UINT32	            unk8;
} FIELD_DESCR_T;

typedef struct
{
    RESOURCE_ID       descr_res;    // Ресурс с FIELD_DESCR_T
	union {								// значение поля
		UINT32		u0;		// 0
		UINT32		u1;		// 1
		UINT32		u2;		// 2
		WCHAR *		str;	// 3
		struct {			// 4
			INT16		num;
			UINT8		text_type;	// 0="дней", 1="сообщений", 2="Нет"(без вариантов), 3=""
		} meter;	// счетчик (сообщений/дней и т.п.)
	} data;
	BOOL              unk3;     
    BOOL              unk4;
    BOOL              unk5;         // = 0
} FIELD_T; 


typedef struct
{
    CONTENT_T           text;
    UINT32              unk1;
    RESOURCE_ID         marks[2];
    RESOURCE_ID         unk3[2];
    RESOURCE_ID         unk4[2];
    UINT8               unk5;
    UINT8               unk6; // = 1
} STATIC_LIST_ENTRY_T;  

typedef union
{
    STATIC_LIST_ENTRY_T     static_entry;     // Используется, когда editable == FALSE
    FIELD_T                 editable_entry;   // Используется, когда editable == TRUE
    UINT8                   pad[0xEC];
} LIST_CONTENT_T;


typedef struct
{
    BOOL                    editable;   // Возможно ли изменять содержимое
    UINT32                  unk1;       // ??
    LIST_CONTENT_T          content;
    
    UINT8                   pad[0xF8-0xEC]; //fixed, no more -0x8
} LIST_ENTRY_T;


/* Создаёт статичекий диалог-список */
typedef UIS_DIALOG_T ( *f_UIS_CreateStaticList )( SU_PORT_T  *port,
                                   UINT32          param1,          // = 0 ID?
                                   UINT32          count,
                                   UINT32          marks,
                                   void           *entries, 
                                   UINT8           param5,          // = 0
                                   UINT8           param6,          // = 2
                                   ACTIONS_T       *actions,
                                   RESOURCE_ID     caption );
f_UIS_CreateStaticList UIS_CreateStaticList = ( f_UIS_CreateStaticList )0x108C3516;                        

typedef UIS_DIALOG_T ( *f_UIS_CreateCharacterEditor )( SU_PORT_T  *port,
                                        WCHAR           *text,
                                        UINT8           edit_type,
                                        UINT32          maxlen,
                                        BOOL            masked, //?
                                        ACTIONS_T       *actions, 
                                        RESOURCE_ID     dlgres ); 
f_UIS_CreateCharacterEditor UIS_CreateCharacterEditor = ( f_UIS_CreateCharacterEditor )0x108C2D1E;
                        
typedef UIS_DIALOG_T ( *f_UIS_CreateViewer )( SU_PORT_T  *port,
                               CONTENT_T       *contents,
                               ACTIONS_T       *actions );
f_UIS_CreateViewer UIS_CreateViewer = ( f_UIS_CreateViewer )0x108C48C8;
                        
typedef UIS_DIALOG_T ( *f_UIS_CreatePictureAndTextList )( SU_PORT_T  *port,
                                           UINT32          param1,
                                           UINT32          count, 
                                           UINT32          *starting_num, 
                                           UINT8           param4, // = 2
                                           UINT8           param5, // = 0
                                           UINT8           param6, // = 1, try 0,2,...
                                           ACTIONS_T       *actions, 
                                           RESOURCE_ID     dlgres );
f_UIS_CreatePictureAndTextList UIS_CreatePictureAndTextList = ( f_UIS_CreatePictureAndTextList )0x108C6EAC;

// создаёт заставку 										   
typedef UIS_DIALOG_T ( *f_UIS_CreateSplashScreenFs )( SU_PORT_T * port, WCHAR * uri, UINT32 unk );	// unk = 0x7D0
f_UIS_CreateSplashScreenFs UIS_CreateSplashScreenFs = ( f_UIS_CreateSplashScreenFs )0x108C4052;

typedef UIS_DIALOG_T ( *f_UIS_CreateSplashScreen )( SU_PORT_T * port, RESOURCE_ID img, UINT32 unk );	// unk = 0xD3 , 0x7D0
f_UIS_CreateSplashScreen UIS_CreateSplashScreen = ( f_UIS_CreateSplashScreen )0x108C3FF0;

// Создаёт прогрессбар
typedef UIS_DIALOG_T ( *f_UIS_CreateProgressBar )( SU_PORT_T *	port,
									RESOURCE_ID	res_img,	// 0x12000055
									CONTENT_T *	content,
									UINT8		u3,				// =0
									UINT8		perc,			// точно? я не уверен!	// &(app) + 0x4d
									UINT32		u6,				// =0
									WCHAR *		str,			// ?
									ACTIONS_T *	actions,
									RESOURCE_ID	caption );		// can be =0

f_UIS_CreateProgressBar UIS_CreateProgressBar = ( f_UIS_CreateProgressBar )0x108C3ADC;
					
#define EV_PROGRESS_UPDATE  0x213F

typedef struct {
	UINT32		u1;
	WCHAR *		str;
	UINT8		pad[0x5C];
} PROGRESS_UPDATE_DATA_T ;										   


/******************************************
Изменение элементов  рабочего стола 
******************************************/

#define BATTERY_STRENGTH_STATUS		0  //батарея: значения integer от 0 до 3
#define SIGNAL_STRENGTH_STATUS		3  //сигнал сети: значения integer от 0 до 5
#define AUDIO_STATUS 				0x69
#define GPRS_STATUS					0x1D // строка в поле даты
#define NETWORK_STATUS  			0x27 // строка в поле оператора 
#define READY_STATUS 				47
#define PROVIDER_NAME_STATUS 		55


typedef union
{
    INT32                            integer;
    BOOL                             boolean;
    WCHAR                            *quoted_string;
    UINT64                      	 unk;
} STATUS_VALUE_T;

// запись инфы на рабочий стол
typedef UINT32 ( *f_UIS_SetStatus )(UINT8 status_id, STATUS_VALUE_T value);
f_UIS_SetStatus UIS_SetStatus = ( f_UIS_SetStatus )0x108C5EF6;

// чтение инфы с рабочего стола
typedef UINT32 ( *f_UIS_GetCurrentStatusValue )(UINT8 status_id,  STATUS_VALUE_T *value);
f_UIS_GetCurrentStatusValue UIS_GetCurrentStatusValue = ( f_UIS_GetCurrentStatusValue )0x108C5FD0;

typedef struct
{
    WCHAR            *url;           
    UINT32           unk;    
} SETWALLPAPER_SETTINGS_T;  

// установить картинку на рабочий стол
typedef UINT32 ( *f_UIS_SetWallpaper )(SETWALLPAPER_SETTINGS_T * );  
f_UIS_SetWallpaper UIS_SetWallpaper = ( f_UIS_SetWallpaper )0x108C6232;

typedef void * ( *f_uisAllocateMemory )( UINT32 size, INT32 *result ); //result can be NULL
f_uisAllocateMemory uisAllocateMemory = ( f_uisAllocateMemory )0x1086D4D8;

typedef void ( *f_uisFreeMemory )( void *ptr );
f_uisFreeMemory uisFreeMemory = ( f_uisFreeMemory )0x1086DA6C;

typedef UINT32 ( *f_UIS_SetBacklight )( UINT8 P1 );
f_UIS_SetBacklight UIS_SetBacklight = ( f_UIS_SetBacklight )0x108C5CD6;

#endif
