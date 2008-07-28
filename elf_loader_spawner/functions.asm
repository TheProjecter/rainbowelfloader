	.equ APP_Register, 0x1040afea
	.export APP_Register
	.equ APP_InitAppData, 0x1040abd0
	.export APP_InitAppData
	.equ APP_HandleEvent, 0x1040a7b4
	.export APP_HandleEvent
	.equ APP_HandleEventPrepost, 0x1040a9d0
	.export APP_HandleEventPrepost
	.equ APP_Start, 0x1040b084
	.export APP_Start
	.equ APP_Exit, 0x1040a54c
	.export APP_Exit
	.equ APP_UtilChangeState, 0x105d0076
	.export APP_UtilChangeState
	.equ APP_UtilHistSaveAndChangeState, 0x105d0410
	.export APP_UtilHistSaveAndChangeState
	.equ APP_UtilHistGoToPrevState, 0x105d0318
	.export APP_UtilHistGoToPrevState
	.equ AFW_InquireRoutingStackByRegId, 0x1020bd68
	.export AFW_InquireRoutingStackByRegId
	.equ UIS_CreateColorCanvas, 0x108c8dc0
	.export UIS_CreateColorCanvas
	.equ UIS_CanvasDrawPixel, 0x108cc69c
	.export UIS_CanvasDrawPixel
	.equ UIS_CanvasDrawLine, 0x108cc80c
	.export UIS_CanvasDrawLine
	.equ UIS_CanvasFillRect, 0x108ccabc
	.export UIS_CanvasFillRect
	.equ UIS_CanvasDrawRect, 0x108cc978
	.export UIS_CanvasDrawRect
	.equ UIS_CanvasDrawRoundRect, 0x108ccf40
	.export UIS_CanvasDrawRoundRect
	.equ UIS_CanvasDrawArc, 0x108ccc78
	.export UIS_CanvasDrawArc
	.equ UIS_CanvasDrawPoly, 0x108ccdb0
	.export UIS_CanvasDrawPoly
	.equ UIS_CanvasDrawColorText, 0x
	.export UIS_CanvasDrawColorText
	.equ UIS_CanvasSetFont, 0x108cb440
	.export UIS_CanvasSetFont
	.equ UIS_CanvasGetFontStyle, 0x108cfbcc
	.export UIS_CanvasGetFontStyle
	.equ UIS_CanvasSetFontStyle, 0x108cfafc
	.export UIS_CanvasSetFontStyle
	.equ UIS_CanvasGetStringSize, 0x
	.export UIS_CanvasGetStringSize
	.equ UIS_CanvasGetFontSize, 0x108c9698
	.export UIS_CanvasGetFontSize
	.equ UIS_CanvasDrawImage, 0x108cd87e
	.export UIS_CanvasDrawImage
	.equ UIS_CanvasDrawWallpaper, 0x108ce710
	.export UIS_CanvasDrawWallpaper
	.equ UIS_CanvasDrawColorBitmap, 0x108d1048
	.export UIS_CanvasDrawColorBitmap
	.equ UIS_CanvasOpenImage, 0x108cdb98
	.export UIS_CanvasOpenImage
	.equ UIS_CanvasOpenImageAndGetSize, 0x108cdc38
	.export UIS_CanvasOpenImageAndGetSize
	.equ UIS_CanvasCloseImage, 0x108ce4dc
	.export UIS_CanvasCloseImage
	.equ UIS_CanvasResizeImage, 0x108cdffe
	.export UIS_CanvasResizeImage
	.equ UIS_CanvasGetImageSize, 0x108ce540
	.export UIS_CanvasGetImageSize
	.equ UIS_CanvasSetImageAttribute, 0x108ce5bc
	.export UIS_CanvasSetImageAttribute
	.equ UIS_CanvasGetImageAttribute, 0x108ce624
	.export UIS_CanvasGetImageAttribute
	.equ UIS_CanvasRenderImageToBuffer, 0x108cdd18
	.export UIS_CanvasRenderImageToBuffer
	.equ UIS_CanvasDecodeImageToPointer, 0x108cf6b0
	.export UIS_CanvasDecodeImageToPointer
	.equ UIS_CanvasInsert, 0x108cf730
	.export UIS_CanvasInsert
	.equ UIS_CanvasMoveRegion, 0x108d02c8
	.export UIS_CanvasMoveRegion
	.equ UIS_CanvasSetFillColor, 0x108cbb58
	.export UIS_CanvasSetFillColor
	.equ UIS_CanvasGetFillColor, 0x108cbb08
	.export UIS_CanvasGetFillColor
	.equ UIS_CanvasSetForegroundColor, 0x108cb9e6
	.export UIS_CanvasSetForegroundColor
	.equ UIS_CanvasGetForegroundColor, 0x108cb998
	.export UIS_CanvasGetForegroundColor
	.equ UIS_CanvasSetBackgroundColor, 0x108cba7e
	.export UIS_CanvasSetBackgroundColor
	.equ UIS_CanvasGetBackgroundColor, 0x108cba2e
	.export UIS_CanvasGetBackgroundColor
	.equ UIS_CanvasSetLineWidth, 0x108cbc50
	.export UIS_CanvasSetLineWidth
	.equ UIS_CanvasGetLineWidth, 0x108cbc24
	.export UIS_CanvasGetLineWidth
	.equ UIS_CanvasRefreshDisplayRegion, 0x108c9064
	.export UIS_CanvasRefreshDisplayRegion
	.equ UIS_CanvasRefreshDisplayBuffer, 0x
	.export UIS_CanvasRefreshDisplayBuffer
	.equ UIS_CanvasGetColorDepth, 0x108cb408
	.export UIS_CanvasGetColorDepth
	.equ UIS_CanvasGetDisplaySize, 0x108cb904
	.export UIS_CanvasGetDisplaySize
	.equ UIS_CanvasSetBackLight, 0x108cb956
	.export UIS_CanvasSetBackLight
	.equ DL_AudPlayTone, 0x10785b22
	.export DL_AudPlayTone
	.equ PFprintf, 0x1079f912
	.export PFprintf
	.equ DL_DbFeatureGetCurrentState, 0x1071dfd8
	.export DL_DbFeatureGetCurrentState
	.equ DL_DbFeatureStoreState, 0x1071e058
	.export DL_DbFeatureStoreState
	.equ DL_DbFeatureGetValueString, 0x1071e024
	.export DL_DbFeatureGetValueString
	.equ SEEM_ELEMENT_DATA_read, 0x101d1958
	.export SEEM_ELEMENT_DATA_read
	.equ SEEM_ELEMENT_DATA_write, 0x101d1b84
	.export SEEM_ELEMENT_DATA_write
	.equ SEEM_FDI_OUTSIDE_SEEM_ACCESS_read, 0x101d3030
	.export SEEM_FDI_OUTSIDE_SEEM_ACCESS_read
	.equ SEEM_FDI_OUTSIDE_SEEM_ACCESS_write, 0x101d2d22
	.export SEEM_FDI_OUTSIDE_SEEM_ACCESS_write
	.equ DL_AudSetVolumeSetting, 0x10784ec4
	.export DL_AudSetVolumeSetting
	.equ DL_AudGetVolumeSetting, 0x10784fa0
	.export DL_AudGetVolumeSetting
	.equ UIS_SetBacklight, 0x108c5cd6
	.export UIS_SetBacklight
	.equ UIS_SetBacklightWithIntensity, 0x108c5d28
	.export UIS_SetBacklightWithIntensity
	.equ DL_KeyUpdateKeypadBacklight, 0x10730fca
	.export DL_KeyUpdateKeypadBacklight
	.equ DAL_DisableDisplay, 0x108246fa
	.export DAL_DisableDisplay
	.equ DAL_EnableDisplay, 0x10824748
	.export DAL_EnableDisplay
	.equ pu_main_powerdown, 0x101aa68c
	.export pu_main_powerdown
	.equ DL_SigRegQuerySignalStrength, 0x1073edb2
	.export DL_SigRegQuerySignalStrength
	.equ DL_PwrGetActiveBatteryPercent, 0x1070edb2
	.export DL_PwrGetActiveBatteryPercent
	.equ DL_PwrGetChargingMode, 0x1070ecf0
	.export DL_PwrGetChargingMode
	.equ DL_SigCallGetCallStates, 0x1073e3bc
	.export DL_SigCallGetCallStates
	.equ APP_MMC_Util_IsVoiceCall, 0x1049b70c
	.export APP_MMC_Util_IsVoiceCall
	.equ APP_MMC_Util_IsVideoCall, 0x1049b760
	.export APP_MMC_Util_IsVideoCall
	.equ DL_SigMsgSendTextMsgReq, 0x1073e914
	.export DL_SigMsgSendTextMsgReq
	.equ DL_KeyInjectKeyPress, 0x10730f66
	.export DL_KeyInjectKeyPress
	.equ DL_DbShortcutCreateRecord, 0x10726be4
	.export DL_DbShortcutCreateRecord
	.equ DL_DbShortcutUpdateRecord, 0x10726b4a
	.export DL_DbShortcutUpdateRecord
	.equ DL_DbShortcutDeleteRecord, 0x10726b22
	.export DL_DbShortcutDeleteRecord
	.equ DL_DbShortcutGetRecordByRecordId, 0x10726acc
	.export DL_DbShortcutGetRecordByRecordId
	.equ DL_DbShortcutGetNumOfRecordsAvailable, 0x10726af4
	.export DL_DbShortcutGetNumOfRecordsAvailable
	.equ DL_DbShortcutGetNumOfRecordsUsed, 0x10726af8
	.export DL_DbShortcutGetNumOfRecordsUsed
	.equ DL_DbGetFirstAvailableNumber, 0x10726b1e
	.export DL_DbGetFirstAvailableNumber
	.equ DL_DbShortcutGetNumOfURLRecordsUsed, 0x10726c70
	.export DL_DbShortcutGetNumOfURLRecordsUsed
	.equ DL_DbShortcutGetURLByURLId, 0x10726c74
	.export DL_DbShortcutGetURLByURLId
	.equ DL_DbShortcutGetshortcutType, 0x10726cca
	.export DL_DbShortcutGetshortcutType
	.equ DL_DbShortcutGetNumOfURLRecordsAvailable, 0x10726cd2
	.export DL_DbShortcutGetNumOfURLRecordsAvailable
	.equ DL_SimMgrGetPinStatus, 0x1073ffc4
	.export DL_SimMgrGetPinStatus
	.equ DL_SigRegGetCellID, 0x1073edba
	.export DL_SigRegGetCellID
	.equ AFW_GetEv, 0x102f5e7c
	.export AFW_GetEv
	.equ AFW_GetEvSeqn, 0x102f5ea8
	.export AFW_GetEvSeqn
	.equ AFW_AddEvNoD, 0x102f5592
	.export AFW_AddEvNoD
	.equ AFW_AddEvEvD, 0x102f55c4
	.export AFW_AddEvEvD
	.equ AFW_AddEvAux, 0x102f55f6
	.export AFW_AddEvAux
	.equ AFW_AddEvAuxD, 0x102f5624
	.export AFW_AddEvAuxD
	.equ AFW_CreateInternalQueuedEvAux, 0x102f5ac6
	.export AFW_CreateInternalQueuedEvAux
	.equ APP_ConsumeEv, 0x1040a4e8
	.export APP_ConsumeEv
	.equ APP_UtilAddEvUISListData, 0x105cffba
	.export APP_UtilAddEvUISListData
	.equ APP_UtilAddEvUISListChange, 0x105cff40
	.export APP_UtilAddEvUISListChange
	.equ APP_UtilAddEvUISGetDataForItem, 0x1055e368
	.export APP_UtilAddEvUISGetDataForItem
	.equ DL_FsOpenFile, 0x10770800
	.export DL_FsOpenFile
	.equ DL_FsCloseFile, 0x107708ea
	.export DL_FsCloseFile
	.equ DL_FsReadFile, 0x10770a70
	.export DL_FsReadFile
	.equ DL_FsWriteFile, 0x10770bb2
	.export DL_FsWriteFile
	.equ DL_FsFSeekFile, 0x10770c78
	.export DL_FsFSeekFile
	.equ DL_FsGetFileSize, 0x10770fc2
	.export DL_FsGetFileSize
	.equ DL_FsSGetFileSize, 0x10771084
	.export DL_FsSGetFileSize
	.equ DL_FsDirExist, 0x10773a08
	.export DL_FsDirExist
	.equ DL_FsFFileExist, 0x10770edc
	.export DL_FsFFileExist
	.equ DL_FsFGetPosition, 0x10771194
	.export DL_FsFGetPosition
	.equ DL_FsSRenameFile, 0x10771ef0
	.export DL_FsSRenameFile
	.equ DL_FsRenameFile, 0x10771e32
	.export DL_FsRenameFile
	.equ DL_FsDeleteFile, 0x10770da4
	.export DL_FsDeleteFile
	.equ DL_FsFMoveFile, 0x10772202
	.export DL_FsFMoveFile
	.equ DL_FsMkDir, 0x107737bc
	.export DL_FsMkDir
	.equ DL_FsRmDir, 0x10773872
	.export DL_FsRmDir
	.equ DL_FsFSetAttr, 0x10771d1c
	.export DL_FsFSetAttr
	.equ DL_FsGetAttr, 0x107718da
	.export DL_FsGetAttr
	.equ DL_FsSGetAttr, 0x1077197c
	.export DL_FsSGetAttr
	.equ DL_FsSSearch, 0x10772410
	.export DL_FsSSearch
	.equ DL_FsSearchResults, 0x1077272c
	.export DL_FsSearchResults
	.equ DL_FsSearchClose, 0x107728ae
	.export DL_FsSearchClose
	.equ DL_FsFlush, 0x10773bbe
	.export DL_FsFlush
	.equ DRM_CreateResource, 0x102f9bd4
	.export DRM_CreateResource
	.equ DRM_GetResource, 0x102f950c
	.export DRM_GetResource
	.equ DRM_GetResourceLength, 0x102f96ec
	.export DRM_GetResourceLength
	.equ DRM_SetResource, 0x102f9aec
	.export DRM_SetResource
	.equ DRM_ClearResource, 0x102f9c7a
	.export DRM_ClearResource
	.equ DRM_GetCurrentLanguage, 0x102f98a4
	.export DRM_GetCurrentLanguage
	.equ DL_ClkGetDate, 0x10711850
	.export DL_ClkGetDate
	.equ DL_ClkGetTime, 0x10711898
	.export DL_ClkGetTime
	.equ suPalReadTime, 0x1028b0e4
	.export suPalReadTime
	.equ suPalTicksToMsec, 0x1028b194
	.export suPalTicksToMsec
	.equ APP_UtilStartTimer, 0x105d0d20
	.export APP_UtilStartTimer
	.equ APP_UtilStartCyclicalTimer, 0x105d0d56
	.export APP_UtilStartCyclicalTimer
	.equ APP_UtilStopTimer, 0x105d0da0
	.export APP_UtilStopTimer
	.equ UIS_MakeContentFromString, 0x108c55ba
	.export UIS_MakeContentFromString
	.equ APP_HandleUITokenGranted, 0x1040aaa8
	.export APP_HandleUITokenGranted
	.equ APP_HandleUITokenRevoked, 0x1040ab18
	.export APP_HandleUITokenRevoked
	.equ APP_UtilConsumeEvChangeState, 0x105d00c6
	.export APP_UtilConsumeEvChangeState
	.equ UIS_HandleEvent, 0x108c4fa2
	.export UIS_HandleEvent
	.equ UIS_Refresh, 0x108c5b0c
	.export UIS_Refresh
	.equ UIS_ForceRefresh, 0x108c5b4a
	.export UIS_ForceRefresh
	.equ APP_UtilUISDialogDelete, 0x105d164e
	.export APP_UtilUISDialogDelete
	.equ UIS_Delete, 0x108c4b9e
	.export UIS_Delete
	.equ UIS_SetActionList, 0x108c5b7c
	.export UIS_SetActionList
	.equ UIS_SetCenterSelectAction, 0x108c5c00
	.export UIS_SetCenterSelectAction
	.equ UIS_GetActiveDialogType, 0x108c4c08
	.export UIS_GetActiveDialogType
	.equ UIS_CreateTransientNotice, 0x108c4846
	.export UIS_CreateTransientNotice
	.equ UIS_CreateConfirmation, 0x108c2e18
	.export UIS_CreateConfirmation
	.equ UIS_CreateList, 0x108c332c
	.export UIS_CreateList
	.equ UIS_CreateStaticList, 0x108c3516
	.export UIS_CreateStaticList
	.equ UIS_CreateCharacterEditor, 0x108c2d1e
	.export UIS_CreateCharacterEditor
	.equ UIS_CreateViewer, 0x108c48c8
	.export UIS_CreateViewer
	.equ UIS_SetWallpaper, 0x108c6232
	.export UIS_SetWallpaper
	.equ UIS_CreatePictureAndTextList, 0x108c6eac
	.export UIS_CreatePictureAndTextList
	.equ UIS_CreateSplashScreen, 0x108c3ff0
	.export UIS_CreateSplashScreen
	.equ UIS_CreateSplashScreenFs, 0x108c4052
	.export UIS_CreateSplashScreenFs
	.equ UIS_CreateProgressBar, 0x108c3adc
	.export UIS_CreateProgressBar
	.equ UIS_SetStatus, 0x108c5ef6
	.export UIS_SetStatus
	.equ UIS_GetCurrentStatusValue, 0x108c5fd0
	.export UIS_GetCurrentStatusValue
	.equ uis_get_active_dialog, 0x1082c2d2
	.export uis_get_active_dialog
	.equ u_atou, 0x105efb4e
	.export u_atou
	.equ u_strcpy, 0x105ee9b6
	.export u_strcpy
	.equ u_strcat, 0x105ee8cc
	.export u_strcat
	.equ u_strlen, 0x10341ca8
	.export u_strlen
	.equ u_strcmp, 0x105ee950
	.export u_strcmp
	.equ u_strmakeupper, 0x105ef45a
	.export u_strmakeupper
	.equ strcat, 0x10284944
	.export strcat
	.equ strcmp, 0x10284984
	.export strcmp
	.equ strncmp, 0x10284adc
	.export strncmp
	.equ suAllocMem, 0x1004250c
	.export suAllocMem
	.equ suFreeMem, 0x10040338
	.export suFreeMem
	.equ sprintf, 0x10283154
	.export sprintf

