#pragma  once

#include "utils/HKDataBase.h"

#define SOCKET_ERROR    -1
#define INVALID_SOCKET  -1
//---sys

bool    CreateMUL( struct  _CLINetInfo *pcliNetInfo,HKHOSTInfo *pLocalInfo );

void    DestroyMUL( struct  _CLINetInfo *pcliNetInfo );

int     MULSendNetDataA( struct  _CLINetInfo *pcliNetInfo,unsigned int nDstID,unsigned short nLevel,RTSHead *rtsHead,char *pData,unsigned short nLen,bool bBlock ) ;

int     MULSendNetDataB( struct  _CLINetInfo *pcliNetInfo,unsigned int nDstID,unsigned short nLevel,char *pData,unsigned short nLen,bool bBlock );

bool    MULRun( struct  _CLINetInfo *pcliNetInfo );


