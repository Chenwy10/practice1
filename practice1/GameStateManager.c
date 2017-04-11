#include <stdio.h>
#include"System.h"
#include"GameStateManager.h"
#include"Level1.h"
#include"Level2.h"
#include"GameStateList.h"
//GSM初始化
extern FILE *fp ;
extern int Current;
extern int Previous;
extern int Next;
void GSM_Initialize(int level)
{
	Current = Previous = Next = level;
	fprintf(fp,"GSM:Initialize\n");
}

//GSM更新
void GSM_Update(int level)
{
	fprintf(fp,"GSM：Update\n");
	switch(level)
	{
		case GS_L1:
			{
				pLoad = Level1_Load;
				pIni = Level1_Initialize;
				pUpdate = Level1_Update;
				pDraw = Level1_Draw;
				pFree = Level1_Free;
				pUnload = Level1_Unload;
				break;
			}
		case GS_L2:
			{
				pLoad = Level2_Load;
				pIni = Level2_Initialize;
				pUpdate = Level2_Update;
				pDraw = Level2_Draw;
				pFree = Level2_Free;
				pUnload = Level2_Unload;
				break;
			}
	}
}