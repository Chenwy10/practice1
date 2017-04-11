#ifndef _GameStateManager
#define _GameStateManager

void(*pLoad)();
void(*pIni)();
void(*pUpdate)();
void(*pDraw)();
void(*pFree)();
void(*pUnload)();
void GSM_Initialize(int level);
void GSM_Update(int level);
#endif