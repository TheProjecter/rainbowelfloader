
#ifndef RESOURCES_H
#define RESOURCES_H

#include <typedefs.h>

/* ID ресурса формируется типом ресурса в качестве старшего байта и номером ресурса текущего типа
    Например, 0x01000496 = "Системная ошибка"
    Идентификаторы для строк и картинок берутся, соответственно, из ленгпака и DRM */


#define RES_TYPE_STRING         0x01
#define RES_TYPE_ACTION		    0x06
#define RES_TYPE_GRAPHICS       0x12
#define RES_TYPE_CONTENT 		0x0C
#define RES_TYPE_INTEGER 		0x04
#define RES_TYPE_BITMAP 		0x02

#define ID_FONT 0x15000001


typedef UINT32	RESOURCE_ID;

// Создать ресурс
typedef UINT32 ( * f_DRM_CreateResource )( RESOURCE_ID      *res_id,
                           UINT32           type,       //RES_TYPE_*
                           void             *data,
                           UINT32           size );

f_DRM_CreateResource DRM_CreateResource = ( f_DRM_CreateResource )0x102F9BD4;

// Получить содержимое ресурса
typedef UINT32 ( *f_DRM_GetResource )( RESOURCE_ID     res_id,
                        void            *buf,
                        UINT32          size );
f_DRM_GetResource DRM_GetResource = ( f_DRM_GetResource )0x102F950C;

// Получить размер ресурса
typedef UINT32 ( *f_DRM_GetResourceLength )( RESOURCE_ID res_id,  UINT32 *size );
f_DRM_GetResourceLength DRM_GetResourceLength = ( f_DRM_GetResourceLength )0x102F96EC;

//0xf1120606

// Изменить ресурс
typedef UINT32 ( *f_DRM_SetResource )( RESOURCE_ID     res_id,
                        void            *data,
                        UINT32          size );
f_DRM_SetResource DRM_SetResource = ( f_DRM_SetResource )0x102F9AEC;

// Уничтожить ресурс
typedef UINT32 ( *f_DRM_ClearResource )( RESOURCE_ID res_id );
f_DRM_ClearResource DRM_ClearResource = ( f_DRM_ClearResource )0x102F9C7A;

/* Структура для описания ресурса для Action-а */
typedef struct
{
	RESOURCE_ID			softkey_label;		// Надпись на софт-кнопке
    RESOURCE_ID			list_label;			// Надпись в списке действий
    INT8				softkey_priority;	// Приоритет расположения на софткнопках, отрицательый - 
    										// на левый софт, положительный - на правый
    INT8				list_priority;		// Приоритет расположения в списке действий, два пункта
    										// с наивысшим приоритетом располагаются на софткнопках, и дальше смотрится softkey_priority
    BOOL            	isExit;				// ?? Явлется ли командой выхода из приложения
    BOOL            	sendDlgDone;		// Посылать ли дополнительно ивент EV_DIALOG_DONE
} RES_ACTION_LIST_ITEM_T; 

typedef UINT8 ( *f_DRM_GetCurrentLanguage )(UINT8 * LGID);
f_DRM_GetCurrentLanguage DRM_GetCurrentLanguage = ( f_DRM_GetCurrentLanguage )0x102F98A4;

#endif
