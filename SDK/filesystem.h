
#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <typedefs.h>

#define FILE_HANDLE_INVALID   		0xFFFF

typedef UINT16          		    FILE_HANDLE_T;
typedef	UINT64						DL_FS_MID_T; // ���������� ������������� �����


// ����������� ��������� ������� �������� ����


/* ��� mode � DL_FsOpenFile. �� ������������� - ��. ��������
	����������� ������� C stdio.h  */
enum
{
    FILE_READ_MODE = 0,         // ������� �� ������
    FILE_WRITE_MODE,            // ��� ������
    FILE_WRITE_EXIST_MODE,      // ������, ���� ���� �� ����������
    FILE_APPEND_MODE,           // ������ � ����� �����
    FILE_READ_PLUS_MODE,        // ������� ��� ������ � ������
    FILE_WRITE_PLUS_MODE,       // ������� ��� ������ � ������
    FILE_WRITE_EXIST_PLUS_MODE, // ������� ��� ������ � ������, ���� �� ����������
    FILE_APPEND_PLUS_MODE       // ������� ��� ������� ���� ��� ������/������ � �����
};


FILE_HANDLE_T DL_FsOpenFile( WCHAR* uri,  UINT8 mode,  UINT16 param3 );

UINT8 DL_FsCloseFile( FILE_HANDLE_T handle );

UINT8 DL_FsReadFile( void* buffer,
                     UINT32 size,
                     UINT32 count,
                     FILE_HANDLE_T handle,
                     UINT32* read );

UINT8 DL_FsWriteFile( void* buffer,
                      UINT32 size,
                      UINT32 count, 
                      FILE_HANDLE_T handle,
                      UINT32* written);
					  
typedef enum
{
    SEEK_WHENCE_SET = 0,
    SEEK_WHENCE_CUR,
    SEEK_WHENCE_END
} SEEK_WHENCE_T;					  

UINT8 DL_FsFSeekFile( FILE_HANDLE_T handle,  INT32 off, SEEK_WHENCE_T whence );

UINT32 DL_FsGetFileSize( FILE_HANDLE_T handle );

UINT32 DL_FsSGetFileSize( WCHAR* uri,  UINT16 param1);

BOOL DL_FsDirExist( WCHAR* uri );
BOOL DL_FsFFileExist( WCHAR* uri );

UINT32 DL_FsFGetPosition( FILE_HANDLE_T handle );

UINT8 DL_FsSRenameFile( WCHAR* old_uri,  WCHAR* new_name,  UINT16 param2 );

UINT8 DL_FsRenameFile( FILE_HANDLE_T handle,  WCHAR* new_name );

UINT8 DL_FsDeleteFile( WCHAR* uri,  UINT16 param1 );

UINT32 DL_FsICopyFile( void * r0, WCHAR * uri1, WCHAR * uri2, UINT32 param3, UINT32 uarg_0 );	//r0=0, r3=0

UINT8 DL_FsFMoveFile( WCHAR* src_uri,  WCHAR* dst_uri,  UINT16 param2 );

UINT8 DL_FsMkDir( WCHAR* uri,  UINT16 param1 );

UINT8 DL_FsRmDir( WCHAR* uri,  UINT16 param1,  UINT8 param2 ); //param1=0 param2 = 0|1

UINT8 DL_FsFSetAttr( FILE_HANDLE_T handle,  UINT16 attrib );

UINT16 DL_FsGetAttr( FILE_HANDLE_T handle );

UINT16 DL_FsSGetAttr( WCHAR* uri,  UINT16 param1 );

UINT32 DL_FsGetIDFromURI(WCHAR* uri,  DL_FS_MID_T* id);

void DL_FsFlush( void );

// �������� ������ ������
WCHAR * DL_FsVolumeEnum( WCHAR * result ); // result = {0,'/',0,'a',0xff,0xfe,0,'/', ...}


/**************************
  ����� ������
 **************************/

#define FS_ATTR_DEFAULT    	0x0000
#define FS_ATTR_READONLY   	0x0001
#define FS_ATTR_HIDDEN     	0x0002
#define FS_ATTR_SYSTEM     	0x0004
#define FS_ATTR_VOLUME     	0x0008
#define FS_ATTR_DIRECTORY  	0x0010
#define FS_ATTR_ARCHIVE    	0x0020

typedef struct
{
    UINT8				flags;  // �������� ��� �� ����. � FBrowser �������������� 00011100b(0x1C). ��������, ��� ��� 00000100b(0x4) �������� �� ���������� �� �����
    UINT16				attrib; // ��������, � ��������� �������� �� �����, � ������� ���������&mask==attrib
    UINT16				mask;
} FS_SEARCH_PARAMS_T;

typedef struct
{
    WCHAR			name[259]; // ������ ��� ����� (� ����)
    UINT16			attrib;
   	UINT16			unk1;
} FS_SEARCH_RESULT_T;

typedef UINT8 FS_SEARCH_HANDLE_T;

/* ������� ����������� ������ ������ */
/* search_string ����������� �� uri �����, ��� ������ �����, ����� ����������� 0xFFFE, ����� ��������.
	��������: "file://b/Elf/\xFFFE*.elf" */
UINT16 DL_FsSSearch( FS_SEARCH_PARAMS_T		params,
						  WCHAR					*search_string,
                          FS_SEARCH_HANDLE_T	*handle, 		// out
                          UINT16				*res_count,		// out
                          UINT16 				param4 );

/* ������� ��� ��������� [�����] ������ ����������� ������ */
UINT16 DL_FsSearchResults( FS_SEARCH_HANDLE_T		handle,
                           		 UINT16 				start_index, // 0 based
                                 UINT16					*count,		 // in and out
                                 FS_SEARCH_RESULT_T		*results );

UINT16 DL_FsSearchClose( FS_SEARCH_HANDLE_T handle );



#endif
