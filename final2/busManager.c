#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#include<malloc.h>
void changeBusType()
{	
	char ch;
	char r[1000];
	char bno[30];
	char *p;
//	char q[30];
	char type[30];
	char w[50];
	FILE *fp,*fp1;
	char *tok;
	fp=fopen("bus.txt","r");
	if(fp!=NULL)
	{
		for(int i=0;!feof(fp);i++)
		{
			ch=fgetc(fp);
			r[i]=ch;
		}
		fclose(fp);
		printf("\n ^^^^^^  Buses  ^^^^^^\n %s \n",r);
		printf("Enter the bus number : ");
		scanf("%s",bno);
		__fpurge(stdin);
		printf("Enter new Type       : ");
		scanf("%s",type);
		__fpurge(stdin);
		fp1=fopen("bus.txt","w+");
		tok=strtok(r,".");
//		printf("tok %s\n",tok);
		while(tok)
		{
//			printf("tok %s\n",tok);
//			while(*tok!='\n')
//			{
//				printf("hello");
//				tok+=1;
//			
//			}
//			printf("tokmp %s\n",tok);
//			printf("bno %s\n",bno);	
			p=strstr(tok,bno);
//			printf("p=%s\n",p);
			if(p)
			{
				printf("p->%s\n",p);
				
				char *start;
				char *end;
				int count=0;
//				printf("Q=%p\n",q);
				for(int i=0;tok[i];i++)
				{
		//			printf("%c\n=",q[i]);
		//			printf("count in %d\n",count);
		//			printf("i=%d\n",i);
					if(tok[i]==' ')
					{
						++count;
					}
					if(count==2 && tok[i]==' ')
					{
						start=tok+i;
					}
					if(count==3 && tok[i]==' ')
					{
						end=tok+i;
					}
				}
		//		printf("count=%d\n",count);
		//		printf("start=%p\n",start);
				*start='\0';
		//		printf("Q=%s\n",q);
				strcpy(w,tok);
				strcat(w," ");
				strcat(w,type);
				strcat(w,end);
		//		printf(" result %s\n",w);
				if(strlen(w)>8)
				{
				printf("\tBus Type Changed\n");
					fprintf(fp1,"%s.",w);
				}
		
			}
			else
			{	
				
					
				if(strlen(tok)>8)
					fprintf(fp1,"%s.",tok);
			}
		tok=strtok(NULL,".");
		}
	fclose(fp1);
	}	
	else
	{
		printf("File not found\n");
	}
}


void numberofBusesEachRoute()
{

	char route[10];
	int count=0;
	char r[1000];
	char j[1000];
	FILE *fp,*fp1;
	char *p;
	char *p1;
	char ch;
	fp1=fopen("route.txt","r");
	fp=fopen("bus.txt","r");
	if(fp!=NULL && fp1!=NULL)
	{
		for(int i=0;!feof(fp1);i++)
		{
			ch=fgetc(fp1);
			j[i]=ch;
		}
		fclose(fp1);
		printf("^^^^^^  routes  ^^^^^^ \n %s \n",j);
		for(int i=0;!feof(fp);i++)
		{
			ch=fgetc(fp);
			r[i]=ch;
		}
		fclose(fp);
	//	printf("%s\n",r);
		printf("=====================\n");
		printf("Enter the route : ");
		scanf("%s",route);
		p=strstr(r,route);
		while(p)
		{
			count++;
			p1=strchr(p,'.');
			strcpy(p,p1);
			p=strstr(p,route);
		}
	}
	else
	{
		printf("File not found\n");
	}
	printf("Number of buses in the Route %s is %d.\n",route,count++);
}

void busManager()
{
	int choice=0;
	while(1)
	{
		printf(" BUS MANAGER\n");
		printf("\n 1. Change type of bus. \n 2. Number of buses in each route. \n 0. Exit. \n");
		printf("\n Enter your Choice : ");
		scanf("%d",&choice);
		__fpurge(stdin);
		switch(choice)
		{
			case 1:
				changeBusType();
				break;
			case 2:
				numberofBusesEachRoute();
				break;
			case 0:
				break;
			default:
				printf("Wrong option.\n");
		}
	if(choice==0)
		break;
	}
}
	
		
	

