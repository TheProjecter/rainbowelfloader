
#ifndef APPS_H
#define APPS_H

#include <loader.h>
#include <events.h>
#include <dl.h>
#include <filesystem.h>
#include <util.h>

typedef UINT16      REG_ID_T;

#define APP_NAME_LEN              13
#define STATE_HANDLERS_END        ((UINT32)(-1))
#define STATE_HANDLERS_RESERVED	  ((UINT32)(-2))


typedef enum
{
    ENTER_STATE_ENTER,
    ENTER_STATE_RESUME
} ENTER_STATE_TYPE_T;

typedef enum
{
    EXIT_STATE_EXIT,
    EXIT_STATE_SUSPEND
} EXIT_STATE_TYPE_T;

typedef UINT16    APP_ID_T;

typedef UINT32    EVENT_HANDLER_T( EVENT_STACK_T *ev_st,  void *app );
typedef UINT32    ENTER_STATE_FUNC_T( EVENT_STACK_T *ev_st,  void *app,  ENTER_STATE_TYPE_T type );
typedef UINT32    EXIT_STATE_FUNC_T( EVENT_STACK_T *ev_st,  void *app,  EXIT_STATE_TYPE_T type );


typedef struct
{
    EVENT_CODE_T      code;
    EVENT_HANDLER_T   *hfunc;
} EVENT_HANDLER_ENTRY_T;

typedef struct
{
    UINT8                     		  state;
    ENTER_STATE_FUNC_T        		  *enter_fn;
    EXIT_STATE_FUNC_T         		  *exit_fn;
    const EVENT_HANDLER_ENTRY_T     *htable;
} STATE_HANDLERS_ENTRY_T;

typedef struct
{
    UINT8                      unk1[20];
    UINT32                     unk2;
    UINT32                     unk3;
    UIS_DIALOG_T               dialog;
    UINT32                     unk4;
    SU_PORT_T                  port;
    void                       *unk5;
    EVENT_HANDLER_T            *exit_fn;
    STATE_HANDLERS_ENTRY_T     *handlers_tbl;
    UINT32                     unk6; // always 0
    //56
    UINT8                      pad1[16];
    //72
    UINT8                      token_status;
	UINT8					   unk7;
	BOOL					   focused;
	UINT8					   state;	
        
    UINT8                      pad2[4];
    //UINT8                      pad[23+1];
} APPLICATION_T; //size = 80


/* Зарегистрировать Application */
typedef UINT32 ( * f_APP_Register ) ( EVENT_CODE_T                   *registry_table,
                     UINT8                          reg_count,
                     const STATE_HANDLERS_ENTRY_T   *state_handlers,
                     UINT8                          state_count,
                     void                           *start_fn );

f_APP_Register APP_Register = ( f_APP_Register )0x1040AFEA;

typedef APPLICATION_T* (* f_APP_InitAppData ) ( void             *main_event_handler,
                                UINT32            sizeof_app,
                                REG_ID_T          reg_id,
                                UINT32            param3,
                                UINT16            history_size,
	                              UINT32            priority,
    	                          UINT16            param6,
        	                      UINT8             type,
            	                  UINT8             param8 );
f_APP_InitAppData APP_InitAppData = ( f_APP_InitAppData )0x1040ABD0;


/* Стандартная функция управления ивентами для нефоновых приложений */
typedef void ( * f_APP_HandleEvent )( EVENT_STACK_T           *ev_st,
                      APPLICATION_T           *app,
                      APP_ID_T                app_id,
                      REG_ID_T                reg_id );
f_APP_HandleEvent APP_HandleEvent = ( f_APP_HandleEvent )0x1040A7B4;

/* Стандартная функция управления ивентами для фоновых приложений */
typedef void ( *f_APP_HandleEventPrepost )( EVENT_STACK_T           *ev_st,
                             APPLICATION_T           *app,
                             APP_ID_T                app_id,
                             REG_ID_T                reg_id );
f_APP_HandleEventPrepost APP_HandleEventPrepost = ( f_APP_HandleEventPrepost )0x1040A9D0;

typedef UINT32 ( *f_APP_Start ) ( EVENT_STACK_T                     *ev_st,
                  APPLICATION_T                     *app,
                  UINT8                             start_state,
                  const STATE_HANDLERS_ENTRY_T     *state_handlers,
                  EVENT_HANDLER_T                   *exit_fn,
                  const char                       *app_name,
                  UINT32                            param6 );

f_APP_Start APP_Start = ( f_APP_Start )0x1040B084;

typedef UINT32 (* f_APP_Exit )( EVENT_STACK_T        *ev_st,
                 APPLICATION_T        *app,
                 UINT32               param2 );

f_APP_Exit APP_Exit = ( f_APP_Exit )0x1040A54C;

/* Сменить текущий state
   При этом будет вызвана функция выхода из текущего state и ф-я входа в новый */
  
typedef UINT32 ( *f_APP_UtilChangeState )( UINT8 new_state,  EVENT_STACK_T *ev_st,  void *app );
f_APP_UtilChangeState APP_UtilChangeState = ( f_APP_UtilChangeState )0x105D0076;

/* Сменить текущий state с сохранением текущего состояния приложения (в стек) */
typedef UINT32 ( *f_APP_UtilHistSaveAndChangeState )( void *data,  EVENT_STACK_T *ev_st,  void *app,  UINT8 new_state ); //data - unknown
f_APP_UtilHistSaveAndChangeState APP_UtilHistSaveAndChangeState = ( f_APP_UtilHistSaveAndChangeState )0x105D0410;

/* Вернуть предыдущий state, сохранённый функцией APP_UtilHistSaveAndChangeState*/
typedef UINT32 ( *f_APP_UtilHistGoToPrevState )( void *data,  EVENT_STACK_T *ev_st,  void *app );
f_APP_UtilHistGoToPrevState APP_UtilHistGoToPrevState = ( f_APP_UtilHistGoToPrevState )0x105D0318;

typedef UINT32 ( *f_AFW_InquireRoutingStackByRegId )( REG_ID_T reg_id );
f_AFW_InquireRoutingStackByRegId AFW_InquireRoutingStackByRegId = ( f_AFW_InquireRoutingStackByRegId )0x102F6668;

#endif


