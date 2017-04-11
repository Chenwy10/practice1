#include<stdio.h>
#include"Level2.h"
#include"System.h"
#include"GameStateManager.h"
#include"GameStateList.h"
extern FILE *fp ;
extern int Current;
extern int Previous;
extern int Next;

void Level2_Load()
{
    FILE*fp_Level2=NULL;
	fp_Level2=fopen("Level2_Lives.txt","r");
	fread(&Level2_lives,sizeof(int),1,fp_Level2);
	fclose(fp_Level2);
	fp_Level2=NULL;
	Level2_lives = Level2_lives - 48;
	fprintf(fp,"Level2:Load\n");

}

void Level2_Initialize()
{
	FILE*fp_Level2=NULL;
	fp_Level2=fopen("Level2_Counter.txt","r");
	fread(&Level2_Counter,sizeof(int),1,fp_Level2);
	fclose(fp_Level2);
	fp_Level2=NULL;
	Level2_Counter = Level2_Counter - 48;
	fprintf(fp,"Level2:Initialize\n");
}

void Level2_Update()
{
	if(Level2_Counter>0)
	{
		Level2_Counter --;
	}
	if(Level2_lives>0 && Level2_Counter==0)
	{
		Level2_lives--;
		Next = GS_Restart;
	}
	if((Level2_lives ==0) && (Level2_Counter == 0))
	{
		Next = GS_Quit;
	}
	fprintf(fp,"Level2:Update\n");
}

void Level2_Draw()
{
	fprintf(fp,"Level2:Draw\n");
}

void Level2_Free()
{
	fprintf(fp,"Level2:Free\n");
}

void Level2_Unload()
{
	fprintf(fp,"Level2:Unload\n");
}