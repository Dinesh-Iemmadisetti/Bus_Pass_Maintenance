#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<unistd.h>
#include"main_header.h"
void allBuses()
{
	FILE *fp;
	char *p;
	char r[1000];
	fp=fopen("bus.txt","r");
	if(fp!=NULL)
	{
		
		printf("Bus route type capacity.\n");
		while(!feof(fp))
		{
			
			p=fgets(r,1000,fp);
			if(p!=NULL)
				printf("%s\n",r);
		}
	fclose(fp);
	}
	else
	{
		printf("file not found\n");	
	}
}

void allRoutes()
{
	FILE *fp;
	char *p;
	char r[1000];
	fp=fopen("route.txt","r");
	if(fp!=NULL)
	{
		printf("Route_ID Start_Point Via_Point End_Point.\n");
		while(!feof(fp))
		{
			p=fgets(r,1000,fp);
			if(p!=NULL)
				printf("%s\n",r);
		}
		fclose(fp);
	}
	else
	{
		printf("file not found\n");	
	}
}

void noOfVehiclesinEachRoute()
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
		printf("Routes \n %s \n",j);
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

void busandRouteInfo()
{
	int choice;
	while(1)
	{
	printf("*****  BUSES and ROUTES  *****\n");
	printf("\n\t 1. View all buses. \n\t 2. View all Routes. \n\t 3. Number of vehicles on each route. \n\t 0. EXIT. \n");
	printf("\n Enter your Choice :  ");
	scanf("%d",&choice);
	__fpurge(stdin);
		switch(choice)
		{
			case 1:
				allBuses();
				break;
			case 2:
				allRoutes();
				break;
			case 3:
				noOfVehiclesinEachRoute();
				break;
			case 0:
				printf("Application is closing\n");
				break;
			default:
				printf("Wrong option\n");
		}
	if(choice==0)
		break;
	}
}
				

