#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#include<malloc.h>
void addRoute()
{
	char route[10];
	printf("Enter route : ");
	scanf("%s",route);
	__fpurge(stdin);
	char start[20];
	printf("Enter the starting point : ");
	scanf("%s",start);
	__fpurge(stdin);
	char via[10];
	printf(" Enter via : ");
	scanf("%s",via);
	__fpurge(stdin);
	char dest[20];
	printf("Enter the destination : ");
	scanf("%s",dest);
	__fpurge(stdin);
	printf("\n *****  Route Added Successfully  ***** ");
	FILE *fp;
	fp=fopen("route.txt","a+");
	if(fp!=NULL)
	{
		fprintf(fp,"\n%s %s %s %s.\n",route,start,via,dest);
		fclose(fp);
	}
	else
		printf("File not able to open\n");
}
void removeRoute()
{
	char route[20];
	char *p;
	printf("Enter the route no : ");
	scanf("%s",route);
	__fpurge(stdin);
	char r[1000];
	char *tok;
	char d[]=".";
	char q[20];
	char ch;
	FILE *fp,*fp1;
	fp=fopen("route.txt","r");
	if(fp!=NULL)
	{
		for(int i=0;!feof(fp);i++)
		{
			ch=fgetc(fp);
			r[i]=ch;
		}
		fclose(fp);
		fp1=fopen("route.txt","w");
		printf("%s\n",r);
		printf("==========================================================\n");
		tok=strtok(r,".");
		while(tok!=NULL)
		{
		
			while(1)
			{
				if(*tok=='\n')
				{
					tok=tok+1;
				}
				else
					break;
			}
			printf("%s\n",tok);
			p=strstr(tok,route);
			if(p)
			{
			printf(" *****  Data deleted  *****\n");
			}
			else
			{
				strcpy(q,tok);
				strcat(q,d);
		//		printf("%s",q);
				if(strlen(q)>8)
				{
					fprintf(fp1,"%s\n",q);
			//		fputs(q,fp1);
				}
		//		tok=strtok(NULL,".");
			}
		
			tok=strtok(NULL,".");	
		}
	fclose(fp1);		
	}
	else
	{
		printf("File not opened\n");
	}					
}

void addRemoveRoute()
{
	int choice=0;
	while(1)
	{
		printf("\n--------------  ADD / REMOVE Route  -----------------\n");
		printf("\n\t 1. Add Route\n\t 2. Remove Route \n\t 0. Exit \n");
		printf("\n Enter your Choice :  ");
		scanf("%d",&choice);
		__fpurge(stdin);
		switch(choice)
		{
			case 1:
				addRoute();
				break;
			case 2:
				removeRoute();
				break;
			case 0:
				break;
			default:
				printf("Wrong Option\n");
		}
	if(choice==0)
		break;
	}
}
	
		
	
