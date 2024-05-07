#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#include<malloc.h>
void requestNewRoute(char *ch1)
{
	printf("=============REQUEST FOR NEW ROUTE========================\n");
	FILE *fp;
	char r[1000];
	fp=fopen("requestnewroute.txt","a+");
	if(fp!=NULL)
	{
		printf(" Enter the new Route details:\n");
		fgets(r,100,stdin);
		r[strlen(r)-1]='\0';
		fprintf(fp,"\n %s  :  %s \n",ch1,r);
		printf("User request sent\n");
		fclose(fp);
	}
	else
	{
		printf("There are no request for new routes\n");
	}
}
