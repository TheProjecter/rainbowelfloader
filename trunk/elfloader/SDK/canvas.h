#ifndef CANVAS_H
#define CANVAS_H

#include <typedefs.h>
#include <util.h>
#include <resources.h>


/*******************************/
// для определения нажатия на клавиши ловим эти ивенты
#define EV_INK_KEY_PRESS 		  0x2034 //  EVENT_DATA_T
#define EV_INK_KEY_RELEASE		  0x2035 //  EVENT_DATA_T

/*******************************/

// Точка привязки для текста и картинок
// вертикальная						
#define ANCHOR_BASELINE               64 // только текст
#define ANCHOR_BOTTOM                 32 
#define ANCHOR_TOP                    16 
#define ANCHOR_VCENTER                2  // только картинка

// горизонтальная
#define ANCHOR_RIGHT                  8 
#define ANCHOR_LEFT                   4  
#define ANCHOR_HCENTER                1  

//  использовать знак "или". Например: ANCHOR_LEFT | ANCHOR_TOP

/*******************************/

// стиль шрифта ... font_style
#define FONT_STYLE_PLAIN		0xFF
#define FONT_STYLE_ITALIC		0x01
#define FONT_STYLE_BOLD			0x02
#define FONT_STYLE_BOLD_ITALIC	(FONT_STYLE_ITALIC | FONT_STYLE_BOLD)

/*******************************/
typedef enum
{
	// изображения
	MIME_TYPE_IMAGE_GIF = 0,
	MIME_TYPE_IMAGE_BMP,
	MIME_TYPE_IMAGE_WBMP,
	MIME_TYPE_IMAGE_PNG,
	MIME_TYPE_IMAGE_JPEG,

	// аудио 
	MIME_TYPE_AUDIO_MID = 11,
	MIME_TYPE_AUDIO_MIDI,
	MIME_TYPE_AUDIO_MIX,
	MIME_TYPE_AUDIO_BAS,
	MIME_TYPE_AUDIO_MP3,
	MIME_TYPE_AUDIO_AAC,
	MIME_TYPE_AUDIO_AMR = 24,
	MIME_TYPE_AUDIO_MP4 = 26,
	MIME_TYPE_AUDIO_M4A,

	// видео
	MIME_TYPE_VIDEO_ASF = 34,
	MIME_TYPE_VIDEO_MP4 = 36,
	MIME_TYPE_VIDEO_MPEG4,
	MIME_TYPE_VIDEO_H263
    
} MIME_TYPE_T;

typedef struct
{
   UINT8 *buf;     // буфер для рисования. Должен быть NULL
   UINT16 w;       // ширина
   UINT16 h;       // высота
} DRAWING_BUFFER_T;

typedef struct
{
	UINT8 red;
	UINT8 green;
	UINT8 blue;
	UINT8 transparent; // прозрачность
} COLOR_T;

#define COLOR_RED		(COLOR_T)(0xFF000000)
#define COLOR_GREEN		(COLOR_T)(0x00FF0000)
#define COLOR_BLUE		(COLOR_T)(0x0000FF00)
#define RGB(r,g,b)		(COLOR_T)((BYTE)(r)<<24 | (BYTE)(g)<<16 | (BYTE)(b)<<8)
#define RGBT(r,g,b,t)	(COLOR_T)((BYTE)(r)<<24 | (BYTE)(g)<<16 | (BYTE)(b)<<8 | (BYTE)(t))
#define RGB_getr(c)		(BYTE)((UINT32)(c) >> 24 & 0xFF)// RED
#define RGB_getg(c)		(BYTE)((UINT32)(c) >> 16 & 0xFF)// GREEN
#define RGB_getb(c)		(BYTE)((UINT32)(c) >>  8 & 0xFF)// BLUE
#define RGB_gett(c)		(BYTE)((UINT32)(c)       & 0xFF)// TRANSPARENT

typedef struct 
{
    INT16 x;   // горизонтальная координата x
    INT16 y;   // вертикальная координата
} GRAPHIC_POINT_T;

typedef struct 
{
    GRAPHIC_POINT_T ulc;  // верхний левый угол
    GRAPHIC_POINT_T lrc;  // нижний правый угол   
} GRAPHIC_REGION_T;	

enum  // drawOp
{
	AlphaBlend,
	Copy,
        NotUsed1,
	Invert,
	NotCopy,
    Resize,
	Xor,
		NotUsed2,
    Move
}; 

enum  //тип картинки ... picture_type 
{
    DRM_PICTURE_TYPE,
    IMAGE_PATH_TYPE,
    STORED_IN_MEMORY_TYPE,
    FILE_HANDLE_TYPE,
    IMAGE_PATH_WITH_OFFSET
};

typedef WCHAR *IMAGE_PATH_T; // путь к картинке

typedef struct 
{
	void *resourcePicturePointerValue;  // Местоположение указателя в памяти
    UINT32 imageSize;                   // размер изображения
} PICTURE_POINTER_T;

typedef struct 
{
    FILE_HANDLE_T fileHandle;
    UINT32 imageOffset;
    UINT32 imageSize;
} UIS_FILE_HANDLE_T;

typedef struct 
{
    IMAGE_PATH_T  	  PathValue;
    MIME_TYPE_T       mimeFormat; // тип картинки
    UINT32            imageOffset;
    UINT32            imageSize;
} FILE_PATH_WITH_OFFSET_T;

typedef union
{
    RESOURCE_ID           		DrmValue;
    IMAGE_PATH_T            	PathValue;
    PICTURE_POINTER_T       	PointerValue;
	UIS_FILE_HANDLE_T           FileHandleValue;  
    FILE_PATH_WITH_OFFSET_T 	PathWithOffsetValue;
} PICTURE_TYPE_UNION_T; 

typedef UINT8 CANVAS_IMAGE_HANDLE_T;

typedef struct 
{
    UINT16 height;
    UINT16 width;
} GRAPHIC_METRIC_T;

typedef enum
{
    WALLPAPER_LAYOUT_CURRENT = 0,           
    WALLPAPER_LAYOUT_CENTERED,          
    WALLPAPER_LAYOUT_TILED
	
} WALLPAPER_LAYOUT_T;	

typedef struct
{
    GRAPHIC_REGION_T offset_region;
    UINT8*  background_buffer;
    UINT16 width;
    UINT16 height;
} IMAGE_BACKGROUND_BUFFER;

typedef struct
{
    COLOR_T begin_color;
    COLOR_T end_color;
} GRADIENT_T;


typedef enum
{
    IA_STILL_IMAGE=4, // первый кадр анимации
    IA_BACKGROUND_TRANSPARENT_IMAGE, // IMAGE_BACKGROUND_BUFFER
    IA_BACKGROUND_TRANSPARENT_COLOR, // COLOR_T
    IA_BACKGROUND_TRANSPARENT_GRADIENT, // GRADIENT_T
	
    IA_BACKGROUND_TRANSPARENT_TILED_IMAGE,
    IA_BACKGROUND_WALLPAPER_NEEDED,
 
    IA_START_ANIMATION=10, // старт анимации
    IA_BACKGROUND_EXCLUDING_IMAGE, // COLOR_T

    IA_NO_PAINT_WHITE=13,  // не рисовать белый
    IA_NO_PAINT_WHITE_WITH_CROSS,
    IA_PAINT_WHITE_AND_PAINT_WHITE_WITH_CROSS,
    IA_NO_OF_CYCLES_OF_ANIMATION, // UINT8 номер цикла
    IA_DECODE_WALLPAPER_GRAYSCALE,
    IA_PRESERVE_BACKGROUND_GRAYSCALE,

    IA_OBEY_TRANSPARENCY=23,

} IMAGE_ATTRIBUTE_TYPE_T;


/*******************************/

//создать Canvas
typedef UIS_DIALOG_T ( *f_UIS_CreateColorCanvas )( SU_PORT_T  *port,
                                    DRAWING_BUFFER_T * drawing_buffer,
                                    BOOL use_soft_icon_area );

f_UIS_CreateColorCanvas UIS_CreateColorCanvas = ( f_UIS_CreateColorCanvas )0x108C8DC0;
/*	Цвета поумолчанию				   
BackgroundColor - white
FillColor  - white
ForegroundColor  - blue
*/								
					   
/*******************************/		

// рисует точку
typedef void ( *f_UIS_CanvasDrawPixel )(GRAPHIC_POINT_T point, UIS_DIALOG_T handle);		
f_UIS_CanvasDrawPixel UIS_CanvasDrawPixel = ( f_UIS_CanvasDrawPixel )0x108CC69C;

//  рисует  линию						
typedef void ( *f_UIS_CanvasDrawLine )(GRAPHIC_POINT_T begin,
                        GRAPHIC_POINT_T end,
						UIS_DIALOG_T handle);	   
f_UIS_CanvasDrawLine UIS_CanvasDrawLine = ( f_UIS_CanvasDrawLine )0x108CC80C;

// рисует закрашенный прямоугольник
typedef void ( *f_UIS_CanvasFillRect )(GRAPHIC_REGION_T region,
                        UIS_DIALOG_T handle);
f_UIS_CanvasFillRect UIS_CanvasFillRect = ( f_UIS_CanvasFillRect )0x108CCABC;

//  рисует прямоугольник					
typedef void ( *f_UIS_CanvasDrawRect )(GRAPHIC_REGION_T region,
                        BOOL fill, //  заливка
                        UIS_DIALOG_T handle);
f_UIS_CanvasDrawRect UIS_CanvasDrawRect = ( f_UIS_CanvasDrawRect )0x108CC978;

// рисует закруглённый прямоугольник					
typedef void ( *f_UIS_CanvasDrawRoundRect )(GRAPHIC_REGION_T region,  
							UINT16 arcW, // горизонтальный диаметр скругления
							UINT16 arcH, // вертикальный диаметр скругления
							BOOL fill,
							UIS_DIALOG_T handle);						
f_UIS_CanvasDrawRoundRect UIS_CanvasDrawRoundRect = ( f_UIS_CanvasDrawRoundRect )0x108CCF40;

// рисует дугу окружности или эллипса	
typedef void ( *f_UIS_CanvasDrawArc )(GRAPHIC_REGION_T region,
						UINT16 startAngle,    // начальный угол.
						UINT16 arcAngle,	  // конечный угол
						BOOL fill,
						UIS_DIALOG_T handle);
f_UIS_CanvasDrawArc UIS_CanvasDrawArc = ( f_UIS_CanvasDrawArc )0x108CCC78;
					
// рисует многоугольник					
typedef void ( *f_UIS_CanvasDrawPoly )(UINT16 number_of_vertices,
						GRAPHIC_POINT_T  *array,
						BOOL fill,
						UIS_DIALOG_T handle);	
f_UIS_CanvasDrawPoly UIS_CanvasDrawPoly = ( f_UIS_CanvasDrawPoly )0x108CCDB0;

/*******************************/

// рисует строку						
typedef void ( *f_UIS_CanvasDrawColorText )( WCHAR *str,
							  UINT16 offset,
							  UINT16 str_len,  			   // длинна строки
							  GRAPHIC_POINT_T anchor_point, // координаты точки привязки
							  UINT16 anchor_value,		   // значение точки привязки. Например: ANCHOR_LEFT | ANCHOR_TOP
							  UIS_DIALOG_T handle);	
f_UIS_CanvasDrawColorText UIS_CanvasDrawColorText = ( f_UIS_CanvasDrawColorText )0x108CBE84;

// задаёт шрифт
typedef UINT32 ( *f_UIS_CanvasSetFont )( UINT8 font_id, // 0 - NetMonitor, 1- General Font... загляните в MotoLangEditor
						  UIS_DIALOG_T handle);
f_UIS_CanvasSetFont UIS_CanvasSetFont = ( f_UIS_CanvasSetFont )0x108CB440;
	
//возвращает стиль шрифта
typedef UINT8 ( *f_UIS_CanvasGetFontStyle )(UIS_DIALOG_T handle);
f_UIS_CanvasGetFontStyle UIS_CanvasGetFontStyle = ( f_UIS_CanvasGetFontStyle )0x108CFBCC;

// задает стиль	шрифта					  
typedef UINT32 ( *f_UIS_CanvasSetFontStyle )(UINT8 font_style, UIS_DIALOG_T handle);		  
f_UIS_CanvasSetFontStyle UIS_CanvasSetFontStyle = ( f_UIS_CanvasSetFontStyle )0x108CFAFC;

// возвращает размер строки
typedef UINT32 ( *f_UIS_CanvasGetStringSize )( WCHAR * str,
								GRAPHIC_METRIC_T * string_size, // размер строки
								UINT8 font_id );	
f_UIS_CanvasGetStringSize UIS_CanvasGetStringSize = ( f_UIS_CanvasGetStringSize )0x108C99C8;

// размер шрифта								
typedef UINT32 ( *f_UIS_CanvasGetFontSize )( UINT8 font_id, GRAPHIC_METRIC_T * font_size);								
f_UIS_CanvasGetFontSize UIS_CanvasGetFontSize = ( f_UIS_CanvasGetFontSize )0x108C9698;

/*******************************/

// рисует картику					
typedef UINT32 ( *f_UIS_CanvasDrawImage )(UINT8 picture_type,			// тип. откуда будем брать картинку. DRM, файл....
						   PICTURE_TYPE_UNION_T picture_data,
						   GRAPHIC_POINT_T anchor_point,
						   UINT16 anchor_value,
						   UINT8 drawOp,
						   UIS_DIALOG_T handle);	
f_UIS_CanvasDrawImage UIS_CanvasDrawImage = ( f_UIS_CanvasDrawImage )0x108CD87E;

typedef UINT32 ( *f_UIS_CanvasDrawWallpaper )(CANVAS_IMAGE_HANDLE_T image_handle,
							   GRAPHIC_REGION_T src_area,
							   GRAPHIC_REGION_T dest_region,
							   UINT8 drawOp,
							   WALLPAPER_LAYOUT_T layout,
							   UIS_DIALOG_T handle);		
f_UIS_CanvasDrawWallpaper UIS_CanvasDrawWallpaper = ( f_UIS_CanvasDrawWallpaper )0x108CE710;
							   
typedef UINT32 ( *f_UIS_CanvasDrawColorBitmap )( void*         picture_bytes,  // первый байт - ширина, второй байт высота
																	   // остальное 8-bpp(RGB332)  или  16-bpp(RGB565) 
								GRAPHIC_POINT_T  ulc_anchor_point,
								UIS_DIALOG_T  handle );		
f_UIS_CanvasDrawColorBitmap UIS_CanvasDrawColorBitmap = ( f_UIS_CanvasDrawColorBitmap )0x108D1048;
 
// открывает картинку					 
typedef CANVAS_IMAGE_HANDLE_T ( *f_UIS_CanvasOpenImage )(UINT8 picture_type,
										  PICTURE_TYPE_UNION_T picture_data);
f_UIS_CanvasOpenImage UIS_CanvasOpenImage = ( f_UIS_CanvasOpenImage )0x108CDB98;
										  
// открывает картинку	 и получает её размер										  
typedef CANVAS_IMAGE_HANDLE_T ( *f_UIS_CanvasOpenImageAndGetSize )(UINT8 picture_type,
													PICTURE_TYPE_UNION_T picture_data,
													GRAPHIC_POINT_T *attributes);
f_UIS_CanvasOpenImageAndGetSize UIS_CanvasOpenImageAndGetSize = ( f_UIS_CanvasOpenImageAndGetSize )0x108CDC38;

// закрывает картинку										  
typedef UINT32 ( *f_UIS_CanvasCloseImage )(CANVAS_IMAGE_HANDLE_T image_handle);	

f_UIS_CanvasCloseImage UIS_CanvasCloseImage = ( f_UIS_CanvasCloseImage )0x108CE4DC;

// изменение размера 
typedef UINT32 ( *f_UIS_CanvasResizeImage )(CANVAS_IMAGE_HANDLE_T image_handle,
							 UINT16 percent, // zoom в процентах
							 GRAPHIC_REGION_T src_area, // Исходный размер изображения
							 GRAPHIC_REGION_T dest_region,// новый размер
							 UINT8 drawOp, 
							 UIS_DIALOG_T handle);
f_UIS_CanvasResizeImage UIS_CanvasResizeImage = ( f_UIS_CanvasResizeImage )0x108CDFFE;

// возвращает размер изображения							 
typedef GRAPHIC_POINT_T ( *f_UIS_CanvasGetImageSize )(UINT8 picture_type,
									   PICTURE_TYPE_UNION_T picture_data);

f_UIS_CanvasGetImageSize UIS_CanvasGetImageSize = ( f_UIS_CanvasGetImageSize )0x108CE540;

// устанавливает аттрибут
typedef UINT32 ( *f_UIS_CanvasSetImageAttribute )(CANVAS_IMAGE_HANDLE_T image_handle,
                                    IMAGE_ATTRIBUTE_TYPE_T attribute_type,
							        void* attribute_value);
f_UIS_CanvasSetImageAttribute UIS_CanvasSetImageAttribute = ( f_UIS_CanvasSetImageAttribute )0x108CE5BC;

// получает аттрибут									
typedef UINT32 ( *f_UIS_CanvasGetImageAttribute )(CANVAS_IMAGE_HANDLE_T image_handle,
                                    IMAGE_ATTRIBUTE_TYPE_T attribute_type,
							        void* attribute_value);
f_UIS_CanvasGetImageAttribute UIS_CanvasGetImageAttribute = ( f_UIS_CanvasGetImageAttribute )0x108CE624;

// вставляет изображение в буфер									
typedef UINT32 ( *f_UIS_CanvasRenderImageToBuffer )(CANVAS_IMAGE_HANDLE_T image_handle,
                                     GRAPHIC_POINT_T image_size,
                                     GRAPHIC_POINT_T anchorpoint,
                                     UINT16 anchor_value,
                                     GRAPHIC_REGION_T * image_region,
                                     UINT8 drawOp,
                                     UIS_DIALOG_T handle);
f_UIS_CanvasRenderImageToBuffer UIS_CanvasRenderImageToBuffer = ( f_UIS_CanvasRenderImageToBuffer )0x108CDD18;

// преобразует картинку в буфер pointer
typedef UINT32 ( *f_UIS_CanvasDecodeImageToPointer )(CANVAS_IMAGE_HANDLE_T image_handle, void* pointer);									
f_UIS_CanvasDecodeImageToPointer UIS_CanvasDecodeImageToPointer = ( f_UIS_CanvasDecodeImageToPointer )0x108CF6B0;

// вставляет буфер pointer					
typedef UINT32 ( *f_UIS_CanvasInsert )(UIS_DIALOG_T handle,void* pointer, GRAPHIC_POINT_T point);	
f_UIS_CanvasInsert UIS_CanvasInsert = ( f_UIS_CanvasInsert )0x108CF730;

// перемещает регион
typedef UINT32 ( *f_UIS_CanvasMoveRegion )(GRAPHIC_REGION_T source_region,
                            GRAPHIC_REGION_T dest_region,
                            UIS_DIALOG_T handle);					
f_UIS_CanvasMoveRegion UIS_CanvasMoveRegion = ( f_UIS_CanvasMoveRegion )0x108D02C8;	
						
/*******************************/	

// задает цвет заливки 
typedef void ( *f_UIS_CanvasSetFillColor )(COLOR_T color);
f_UIS_CanvasSetFillColor UIS_CanvasSetFillColor = ( f_UIS_CanvasSetFillColor )0x108CBB58;

// возвращает цвет заливки 
typedef COLOR_T ( *f_UIS_CanvasGetFillColor )(void);
f_UIS_CanvasGetFillColor UIS_CanvasGetFillColor = ( f_UIS_CanvasGetFillColor )0x108CBB08;

// задает цвет для линий, прямоугольников, текста.....
typedef void ( *f_UIS_CanvasSetForegroundColor )(COLOR_T color);
f_UIS_CanvasSetForegroundColor UIS_CanvasSetForegroundColor = ( f_UIS_CanvasSetForegroundColor )0x108CB9E6;
// возвращает цвет для линий, прямоугольников, текста.....
typedef COLOR_T ( *f_UIS_CanvasGetForegroundColor )(void);
f_UIS_CanvasGetForegroundColor UIS_CanvasGetForegroundColor = ( f_UIS_CanvasGetForegroundColor )0x108CB998;

// цвет фона
typedef void ( *f_UIS_CanvasSetBackgroundColor )(COLOR_T color);
f_UIS_CanvasSetBackgroundColor UIS_CanvasSetBackgroundColor = ( f_UIS_CanvasSetBackgroundColor )0x108CBA7E;

typedef COLOR_T ( *f_UIS_CanvasGetBackgroundColor )(void);
f_UIS_CanvasGetBackgroundColor UIS_CanvasGetBackgroundColor = ( f_UIS_CanvasGetBackgroundColor )0x108CBA2E;

// ширина линии
typedef void ( *f_UIS_CanvasSetLineWidth )(UINT16 width);
f_UIS_CanvasSetLineWidth UIS_CanvasSetLineWidth = ( f_UIS_CanvasSetLineWidth )0x108CBC50;

typedef UINT16 ( *f_UIS_CanvasGetLineWidth )(void);
f_UIS_CanvasGetLineWidth UIS_CanvasGetLineWidth = ( f_UIS_CanvasGetLineWidth )0x108CBC24;

/*******************************/	

// обновление экрана
typedef void ( *f_UIS_CanvasRefreshDisplayRegion )(UIS_DIALOG_T handle, GRAPHIC_REGION_T region);
f_UIS_CanvasRefreshDisplayRegion UIS_CanvasRefreshDisplayRegion = ( f_UIS_CanvasRefreshDisplayRegion )0x108C9064;

typedef void ( *f_UIS_CanvasRefreshDisplayBuffer )(UIS_DIALOG_T handle);	
f_UIS_CanvasRefreshDisplayBuffer UIS_CanvasRefreshDisplayBuffer = ( f_UIS_CanvasRefreshDisplayBuffer )0x108C9034;

/*******************************/
				   
//возвращает  возможную глубину цвета в битах 
typedef UINT32 ( *f_UIS_CanvasGetColorDepth )(void);
f_UIS_CanvasGetColorDepth UIS_CanvasGetColorDepth = ( f_UIS_CanvasGetColorDepth )0x108CB408;

// возвращает размер дисплея
typedef GRAPHIC_POINT_T ( *f_UIS_CanvasGetDisplaySize )(void);
f_UIS_CanvasGetDisplaySize UIS_CanvasGetDisplaySize = ( f_UIS_CanvasGetDisplaySize )0x108CB904;

// включает выключает подсветку
typedef UINT32 ( *f_UIS_CanvasSetBackLight )(BOOL state);
f_UIS_CanvasSetBackLight UIS_CanvasSetBackLight = ( f_UIS_CanvasSetBackLight )0x108CB956;

#endif
