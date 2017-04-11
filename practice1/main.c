#include <stdio.h>
#include"GameStateList.h"
#include"System.h"
#include"GameStateManager.h"
#include"input.h"
#include"Level1.h"
#include"Level2.h"
FILE *fp = NULL;
int Current;
int Previous;
int Next;

int main()
{
	System_Initialize();
	GSM_Initialize(GS_L1);
	while(Current != GS_Quit)
	{
		if(Current == GS_Restart)
		{
			Current = Previous;
			Next = Previous;
		}
		else
		{
			GSM_Update(Current);
			(*pLoad)();
		}
		(*pIni)();
		while(Current == Next)
		{
			Input_Handle();
			(*pUpdate)();
			(*pDraw)();
		}
		(*pFree)();
		if(Next != GS_Restart)
		{
			(*pUnload)();
		}
		Previous = Current;
		Current = Next;
	}
	System_Exit();
}