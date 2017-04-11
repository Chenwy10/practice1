#include<stdio.h>
#include"System.h"
extern FILE *fp ;
void System_Initialize()
{
	fp=fopen("output.txt","w");
	fprintf(fp,"System:Initialize\n");
}

void System_Exit()
{
	fprintf(fp,"System:Exit\n");
	fclose(fp);
	fp=NULL;
}