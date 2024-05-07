#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
void userFeedBack()
{
	FILE *fp,*fp1;
	printf("=============FEED BACK========================\n");
	char responce[100];
	char ch;
	char r[1000];
	fp=fopen("feedback.txt","r+");
	if(fp!=NULL)
	{
		for(int i=0;!feof(fp);i++)
		{
			ch=fgetc(fp);
			r[i]=ch;
		}
		fclose(fp);
		fp1=fopen("feedback.txt","a");
		printf("%s\n",r);
		printf(" Write Admin Responce.  \n");
		fgets(responce,50,stdin);
		responce[strlen(responce)-1]='\0';
		__fpurge(stdin);
		fprintf(fp1," ADMIN : %s \n",responce);
		fclose(fp1);
	}
	else
	{
		printf("file not found\n");
	}
}
	
		
		
