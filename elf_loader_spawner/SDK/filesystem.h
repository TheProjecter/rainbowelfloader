
#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <typedefs.h>


typedef UINT16          		    FILE_HANDLE_T;
#define FILE_HANDLE_INVALID   	0xFFFF



/* Для mode в DL_FsOpenFile. За подробностями - см. описание
	стандартных функций C stdio.h  */
enum
{
    FILE_READ_MODE = 0,         // Открыть дл чтения
    FILE_WRITE_MODE,            // Для записи
    FILE_WRITE_EXIST_MODE,      // Запись, если файл не существует
    FILE_APPEND_MODE,           // Запись в конец файла
    FILE_READ_PLUS_MODE,        // Открыть для чтения и записи
    FILE_WRITE_PLUS_MODE,       // Создать для чтения и записи
    FILE_WRITE_EXIST_PLUS_MODE, // Создать для чтения и записи, если не существует
    FILE_APPEND_PLUS_MODE       // Открыть или создать файл для чтения/записи в конец
};

/* Для whence в DL_FsSeekFile */
enum
{
    SEEK_WHENCE_SET = 0,
    SEEK_WHENCE_CUR,
    SEEK_WHENCE_END
};

#define FS_ATTR_DEFAULT    	0x0000
#define FS_ATTR_READONLY   	0x0001
#define FS_ATTR_HIDDEN     	0x0002
#define FS_ATTR_SYSTEM     	0x0004
#define FS_ATTR_VOLUME     	0x0008
#define FS_ATTR_DIRECTORY  	0x0010
#define FS_ATTR_ARCHIVE    	0x0020

typedef struct
{
    UINT8				flags;  // Значения бит не ясны. В FBrowser использовалось 00011100b(0x1C). Известно, что бит 00000100b(0x4) отвечает за сортировку по имени
    UINT16				attrib; // Очевидно, в результат попадают те файлы, у которых аттрибуты&mask==attrib
    UINT16				mask;
} FS_SEARCH_PARAMS_T;


typedef struct
{
    WCHAR			name[259]; // Полное имя фалйа (с путём)
    UINT16			attrib;
   	UINT16			unk1;
} FS_SEARCH_RESULT_T;

typedef FILE_HANDLE_T ( *f_DL_FsOpenFile )( WCHAR* uri,  UINT8 mode,  UINT16 param3 );
f_DL_FsOpenFile DL_FsOpenFile = ( f_DL_FsOpenFile )0x10770800;

typedef UINT8 ( *f_DL_FsCloseFile )( FILE_HANDLE_T handle );
f_DL_FsCloseFile DL_FsCloseFile = ( f_DL_FsCloseFile )0x107708EA;

typedef UINT8 ( *f_DL_FsReadFile )( void* buffer,
                     UINT32 size,
                     UINT32 count,
                     FILE_HANDLE_T handle,
                     UINT32* read );
f_DL_FsReadFile DL_FsReadFile = ( f_DL_FsReadFile )0x10770A70;

typedef UINT8 ( *f_DL_FsWriteFile )( void* buffer,
                      UINT32 size,
                      UINT32 count, 
                      FILE_HANDLE_T handle,
                      UINT32* written);
f_DL_FsWriteFile DL_FsWriteFile = ( f_DL_FsWriteFile )0x10770BB2;

typedef UINT8 ( *f_DL_FsFSeekFile )( FILE_HANDLE_T handle,  INT32 off,  UINT8 whence );
f_DL_FsFSeekFile DL_FsFSeekFile = ( f_DL_FsFSeekFile )0x10770C78;

typedef UINT32 ( *f_DL_FsGetFileSize )( FILE_HANDLE_T handle );
f_DL_FsGetFileSize DL_FsGetFileSize = ( f_DL_FsGetFileSize )0x10770FC2;

typedef UINT32 ( *f_DL_FsSGetFileSize )( WCHAR* uri,  UINT16 param1);
f_DL_FsSGetFileSize DL_FsSGetFileSize = ( f_DL_FsSGetFileSize )0x10771084;

typedef BOOL ( *f_DL_FsDirExist )( WCHAR* uri );
f_DL_FsDirExist DL_FsDirExist = ( f_DL_FsDirExist )0x10773A08;

//10770EC8
typedef BOOL ( *f_DL_FsFFileExist )( WCHAR* uri );
f_DL_FsFFileExist DL_FsFFileExist = ( f_DL_FsFFileExist )0x10770EDC;

typedef UINT32 ( *f_DL_FsFGetPosition )( FILE_HANDLE_T handle );
f_DL_FsFGetPosition DL_FsFGetPosition = ( f_DL_FsFGetPosition )0x10771194;

typedef UINT8 ( *f_DL_FsSRenameFile )( WCHAR* old_uri,  WCHAR* new_name,  UINT16 param2 );
f_DL_FsSRenameFile DL_FsSRenameFile = ( f_DL_FsSRenameFile )0x10771EF0;

typedef UINT8 ( *f_DL_FsRenameFile )( FILE_HANDLE_T handle,  WCHAR* new_name );
f_DL_FsRenameFile DL_FsRenameFile = ( f_DL_FsRenameFile )0x10771E32;

typedef UINT8 ( *f_DL_FsDeleteFile )( WCHAR* uri,  UINT16 param1 );
f_DL_FsDeleteFile DL_FsDeleteFile = ( f_DL_FsDeleteFile )0x10770DA4;

typedef UINT8 ( *f_DL_FsFMoveFile )( WCHAR* src_uri,  WCHAR* dst_uri,  UINT16 param2 );
f_DL_FsFMoveFile DL_FsFMoveFile = ( f_DL_FsFMoveFile )0x10772202;

typedef UINT8 ( *f_DL_FsMkDir )( WCHAR* uri,  UINT16 param1 );
f_DL_FsMkDir DL_FsMkDir = ( f_DL_FsMkDir )0x107737BC;

typedef UINT8 ( *f_DL_FsRmDir )( WCHAR* uri,  UINT16 param1,  UINT8 param2 ); //param1=0 param2 = 0|1
f_DL_FsRmDir DL_FsRmDir = ( f_DL_FsRmDir )0x10773872;

typedef UINT8 ( *f_DL_FsFSetAttr )( FILE_HANDLE_T handle,  UINT16 attrib );
f_DL_FsFSetAttr DL_FsFSetAttr = ( f_DL_FsFSetAttr )0x10771D1C;

typedef UINT16 ( *f_DL_FsGetAttr )( FILE_HANDLE_T handle );
f_DL_FsGetAttr DL_FsGetAttr = ( f_DL_FsGetAttr )0x107718DA;

//10771CFA
typedef UINT16 ( *f_DL_FsSGetAttr )( WCHAR* uri,  UINT16 param1 );
f_DL_FsSGetAttr DL_FsSGetAttr = ( f_DL_FsSGetAttr )0x1077197C;

typedef UINT8 FS_SEARCH_HANDLE_T;

/* Функция синхронного поиска файлов */
/* search_string формируется из uri папки, где ведётся поиск, затем разделитель 0xFFFE, затем паттерны.
	Например: "file://b/Elf/\xFFFE*.elf" */
typedef UINT16 ( *f_DL_FsSSearch )( FS_SEARCH_PARAMS_T		params,
						  WCHAR					*search_string,
                          FS_SEARCH_HANDLE_T	*handle, 		// out
                          UINT16				*res_count,		// out
                          UINT16 				param4 );
f_DL_FsSSearch DL_FsSSearch = ( f_DL_FsSSearch )0x10772410;

/* Функция для получения [части] списка результатов поиска */
typedef UINT16 ( *f_DL_FsSearchResults )( FS_SEARCH_HANDLE_T		handle,
                           		 UINT16 				start_index, // 0 based
                                 UINT16					*count,		 // in and out
                                 FS_SEARCH_RESULT_T		*results );
f_DL_FsSearchResults DL_FsSearchResults = ( f_DL_FsSearchResults )0x1077272C;

typedef UINT16 ( *f_DL_FsSearchClose )( FS_SEARCH_HANDLE_T handle );
f_DL_FsSearchClose DL_FsSearchClose = ( f_DL_FsSearchClose )0x107728AE;

typedef void ( *f_DL_FsFlush )( void );
f_DL_FsFlush DL_FsFlush = ( f_DL_FsFlush )0x10773BBE;

typedef WCHAR * ( *f_DL_FsVolumeEnum )( WCHAR * result ); // result = {0,'/',0,'a',0xff,0xfe,0,'/', ...}
f_DL_FsVolumeEnum DL_FsVolumeEnum = ( f_DL_FsVolumeEnum )0x10772C50;

#endif
