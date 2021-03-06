#ifndef EXMOD_PTZCTRL_H
#define EXMOD_PTZCTRL_H


#ifdef __cplusplus
extern "C" {
#endif


#ifndef HPTZ 
#define HPTZ  void*
#endif
#ifndef UCHAR 
#define UCHAR unsigned char 
#endif
#ifndef CHAR 
#define CHAR char
#endif
#ifndef INT
#define INT int
#endif
#ifndef ULONG
#define ULONG unsigned long
#endif
#ifndef BOOL 
#define BOOL unsigned int
#endif
#ifndef NULL
#define NULL (void *) 0
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

//// 云台控制命令
typedef enum
{
	PTZ_COMMAND_UNKNOWN = 0,	//// 未知的命令
	PTZ_STOP			= 1,	//// 停止所有云台动作


	UP_START			=2,		//// 向上开始
	UP_STOP,					//// 向上停止
	DOWN_START,					//// 向下开始
	DOWN_STOP,					//// 向下停止

	LEFT_START,				//// 向左开始
	LEFT_STOP,					//// 向左停止
	RIGHT_START,				//// 向右开始
	RIGHT_STOP,					//// 向右停止

	LEFT_UP_START,				//// 左上开始
	LEFT_UP_STOP,				//// 左上停止
	RIGHT_UP_START,				//// 右上开始
	RIGHT_UP_STOP,				//// 右上停止
	LEFT_DOWN_START,			//// 左下开始
	LEFT_DOWN_STOP,				//// 左下停止
	RIGHT_DOWN_START,			//// 右下开始
	RIGHT_DOWN_STOP,			//// 右下停�

	SCAN_ON,					//// 线扫描开
	SCAN_OFF,					//// 线扫描关

	IRIS_OPEN_START,			//// 开光圈开始
	IRIS_OPEN_STOP,				//// 开光圈停止
	IRIS_CLOSE_START,			//// 关光圈开始
	IRIS_CLOSE_STOP,			//// 关光圈停

	FOCUS_NEAR_START,			//// 焦距近开始
	FOCUS_NEAR_STOP,			//// 焦距近停止
	FOCUS_FAR_START,			//// 焦距远开始
	FOCUS_FAR_STOP,				//// 焦距远停止

	ZOOM_WIDE_START,			//// 图象变小开始
	ZOOM_WIDE_STOP,				//// 图象变小停止
	ZOOM_TELE_START,			//// 图象变大开始
	ZOOM_TELE_STOP,				//// 图象变大停止

	CAMERA_ON,					//// 摄像机电源开
	CAMERA_OFF,					//// 摄像机电源关
	LAMP_ON,					//// 灯光开
	LAMP_OFF,					//// 灯光关
	WIPER_ON,					//// 雨刷开
	WIPER_OFF,					//// 雨刷关

	PRESET_POINT,				//// 设置预置位
	SET_POINT,					//// 调用预置位
	//// 其他命令待续.....
} X_PTZ_COMMAND;


typedef struct {
CHAR    protocolName[20];     //云台协议名称
ULONG   baudRate;             //波特率
CHAR    dataSize;             //数据位
CHAR    parity;               //奇偶校验
CHAR    stopBit;              //停止位
CHAR    flowControl;          //流控
}IPCAM_PTZINFO;


HPTZ  PTZM_Init           (CHAR *filePath);
BOOL  PTZM_DeInit         (HPTZ hPtz);
BOOL  PTZM_GetPtzProParam (HPTZ hPtz,IPCAM_PTZINFO *ptzInfo);
BOOL  PTZM_SetPtzProParam (HPTZ hPtz,UCHAR address,UCHAR speed);
BOOL  PTZM_GetPtzCommand  (HPTZ hPtz,X_PTZ_COMMAND command,UCHAR *param,UCHAR * buffer,INT *nSize);//param：部分命令带有参数


#ifdef __cplusplus
}  /* End of the 'extern "C"' block */
#endif

#endif

