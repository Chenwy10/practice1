#include<stdio.h>
#include"Level1.h"
#include"System.h"
#include"GameStateManager.h"
#include"GameStateList.h"
extern FILE *fp ;
extern int Current;
extern int Previous;
extern int Next;
void Level1_Load()
{
	FILE*fp_Level1=NULL;
	fp_Level1=fopen("Level1_Counter.txt","r");
	fread(&Level1_Counter,sizeof(char),1,fp_Level1);
	fclose(fp_Level1);
	fp_Level1=NULL;
	Level1_Counter=Level1_Counter - 48;
	fprintf(fp,"Level1:Load\n");

}

void Level1_Initialize()
{
	fprintf(fp,"Level1:Initialize\n");
}

void Level1_Update()
{
	Level1_Counter --;
	if(Level1_Counter == 0)
	{
		Next = GS_L2;
	}
	fprintf(fp,"Level1:Update\n");
}

void Level1_Draw()
{
	fprintf(fp,"Level1:Draw\n");
}

void Level1_Free()
{
	fprintf(fp,"Level1:Free\n");
}

void Level1_Unload()
{
	fprintf(fp,"Level1:Unload\n");
}