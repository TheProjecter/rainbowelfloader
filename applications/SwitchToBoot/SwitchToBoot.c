#include "SwitchToBoot.h"

ElfLoaderApp         SwitchToBoot = { 0, FALSE, 0, 0, NULL, NULL };

const char app_name[APP_NAME_LEN] = "SwitchToBoot"; 

const EVENT_HANDLER_ENTRY_T any_state_handlers[] =
{  
    { EV_REVOKE_TOKEN,              APP_HandleUITokenRevoked },
    { STATE_HANDLERS_END,           NULL           },
};

const EVENT_HANDLER_ENTRY_T init_state_handlers[] =
{
    { EV_GRANT_TOKEN,               HandleUITokenGranted },
    { STATE_HANDLERS_END,           NULL           },
};

const EVENT_HANDLER_ENTRY_T main_state_handlers[] =
{
    { EV_DIALOG_DONE,               SwitchToBootExit },
    { STATE_HANDLERS_END,           NULL           },
};

static const STATE_HANDLERS_ENTRY_T state_handling_table[] =
{
    { HW_STATE_ANY,
      NULL,
      NULL,
      any_state_handlers
    },

    { HW_STATE_INIT,
      NULL,
      NULL,
      init_state_handlers
    },
    
    { HW_STATE_MAIN,
      MainStateEnter,
      NULL,
      main_state_handlers
    }
};

int _main( ElfLoaderApp ela )
{
    UINT32 status = RESULT_OK;

    memcpy( ( void * )&SwitchToBoot, ( void * )&ela, sizeof( ElfLoaderApp ) );

    status = APP_Register( &SwitchToBoot . evcode,
                           1,
                           state_handling_table,
                           HW_STATE_MAX,
                           (void*)SwitchToBootStart );

    LoaderShowApp( &SwitchToBoot );

    return 1;
}

UINT32 SwitchToBootStart( EVENT_STACK_T *ev_st,  REG_ID_T reg_id,  UINT32 param2 )
{
    APP_SWITCHTOBOOT_T     *app = NULL;
    UINT32 status = RESULT_OK;

    app = (APP_SWITCHTOBOOT_T*)APP_InitAppData( (void *)APP_HandleEvent,
                                              sizeof(APP_SWITCHTOBOOT_T),
                                              reg_id,
                                              0, 1,
                                              1,
                                              1, 1, 0 );

    status = APP_Start( ev_st,
                        &app->apt,
                        HW_STATE_INIT,
                        state_handling_table,
                        SwitchToBootExit,
                        app_name,
                        0 );

    return RESULT_OK;
}

UINT32 SwitchToBootExit( EVENT_STACK_T *ev_st,  void *app )
{
    UINT32  status;
    APPLICATION_T           *papp = (APPLICATION_T*) app;

    APP_UtilUISDialogDelete(  &papp->dialog );

    status = APP_Exit( ev_st, app, 0 );
    
    LoaderEndApp( &SwitchToBoot );

    return status;
}

UINT32 MainStateEnter( EVENT_STACK_T *ev_st,  void *app,  ENTER_STATE_TYPE_T type )
{
	
	if( DL_PwrGetChargingMode() == CHARGING_MODE_PC ) {
		pu_main_powerdown( 3 );
	}
	else {
		pu_main_powerdown( 1 );
	}

    return RESULT_OK;
}

UINT32 HandleUITokenGranted( EVENT_STACK_T *ev_st,  void *app )
{
    APPLICATION_T           *papp = (APPLICATION_T*) app;
    UINT32                  status;

    status = APP_HandleUITokenGranted( ev_st, app );

    if( (status == RESULT_OK) && (papp->token_status == 2) )
    {
        status = APP_UtilChangeState( HW_STATE_MAIN, ev_st, app );
    }

    return status;
}

