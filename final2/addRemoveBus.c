#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#include<malloc.h>
void addBus()
{
	char bno[10];
	printf("Enter Bus number : ");
	scanf("%s",bno);
	__fpurge(stdin);
	char route[10];
	printf("Enter Route      : ");
	scanf("%s",route);
	__fpurge(stdin);
	char type[10];
	printf("Enter  Bus Type  : ");
	scanf("%s",type);
	__fpurge(stdin);
	char count[10];
	printf("Empolyee count   : ");
	scanf("%s",count);
	__fpurge(stdin);
	printf("\n ***** Added Successfully  *****\n");
	FILE *fp;
	fp=fopen("bus.txt","a");
	if(fp!=NULL)
	{
		fprintf(fp,"\n%s %s %s %s.\n",bno,route,type,count);
		fclose(fp);

	}
	else
		printf("file not able to open\n");
}

void removeBus()
{
	char bno[10];
	char *p=NULL;
	printf("Enter the Bus no : ");
	scanf("%s",bno);
	__fpurge(stdin);
	char r[1000];
	char *tok=NULL;
	char d[]=".";
	char q[20];
	char ch;
	FILE *fp,*fp1;
	fp=fopen("bus.txt","r");
	if(fp!=NULL)
	{
		for(int i=0;!feof(fp);i++)
		{
			ch=fgetc(fp);
			r[i]=ch;
		}
		rewind(fp);
		fclose(fp);
		fp1=fopen("bus.txt","w");
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
			p=strstr(tok,bno);
			if(p)
			{
			printf("\n *****  Data deleted  *****\n");
			}
			else
			{
				strcpy(q,tok);
				strcat(q,d);
				if(strlen(q)>8)
				{
					fprintf(fp1,"%s\n",q);
				}
			//	tok=strtok(NULL,".");
			}
		tok=strtok(NULL,".");	
		}
	fclose(fp1);		
	}
	else
	{
		printf("file not opened\n");
	}

}
void addRemoveBus()
{
	int choice=0;
	while(1)
	{
		printf("\t ADD / REMOVE BUS\n");
		printf("\n\t 1. Add Bus \n\t 2. Remove Bus \n\t 0. Exit \n");
		printf("\n Enter your Choice :  ");
		scanf("%d",&choice);
		__fpurge(stdin);
		switch(choice)
		{
			case 1:
				addBus();
				break;
			case 2:
				removeBus();
				break;
			case 0:
				break;
			default:
				printf(" Wrong option selected\n");
		}
	if(choice==0)
		break;
	}
}
	
		
	
