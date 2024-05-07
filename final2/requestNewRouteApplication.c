#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#include<malloc.h>
void requestNewRouteApplications()
{
	printf("=============REQUEST FOR NEW ROUTE========================\n");
	FILE *fp;
	char *p;
	char r[1000];
	fp=fopen("requestnewroute.txt","r");
	if(fp!=NULL)
	{
		while(!feof(fp))
		{
			p=fgets(r,1000,fp);
			if(p!=NULL)
			{
				printf("%s\n",r);
			}
		}
		fclose(fp);
	}
	else
	{
		printf("There are no request for new routes\n");
	}
}
