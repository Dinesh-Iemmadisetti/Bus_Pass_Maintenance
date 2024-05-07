#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
#include<malloc.h>
#include"main_header.h"
void existingUser()
{
	char name[30];
	char r[1000];
	char *tok,*p;
	char ch;
	char password[10];
	FILE *fp;
	fp=fopen("newUser.txt","r");
	if(fp!=NULL)
	{
		for(int i=0;!feof(fp);i++)
		{
			ch=fgetc(fp);
			r[i]=ch;
		}
		fclose(fp);
		a:printf("Enter UserName : ");
		scanf("%s",name);
		__fpurge(stdin);
		b:printf("Enter Password : ");
		scanf("%s",password);
		if(strlen(password)!=6)
		{
			goto b;
		}
		__fpurge(stdin);

		p=strstr(r,name);
		if(p)
		{
			tok=strtok(p,".");
			p=strstr(tok,password);
			if(p)
			{
				strcat(tok,".");
				printf("%s\n",tok);
				if(*tok=='\n')
				{
					tok+=1;
				}
				printf("***  WELCOME  ***\n");
				tok=strtok(tok," ");
				userServices(tok);
			}
			else
			{
				printf("Wrong password\n");
				goto b;
			
			}
		}
		else
		{
			printf("Wrong username\n");
			goto a;
		}
			
	}
	else
	{
		printf("Cant find the file  \n");
	}
}	
