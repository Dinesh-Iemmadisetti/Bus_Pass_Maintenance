#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<stdio_ext.h>
void requestForBuspass(char *ch1)
{
  char r[1000];
  char ch;
  char *p;
  char empid[30];
//  char name[29];
  FILE *fp1,*fp2;
  char route_id[30];
  char type[30];
//  printf("enter your name:\n");
 // scanf("%s",name);
 // __fpurge(stdin);
  printf("Enter emp id : ");
  scanf("%s",empid);
  __fpurge(stdin);
  printf("Enter route id : ");
  scanf("%s",route_id);
  __fpurge(stdin);
  printf("Enter bus Type : ");
  scanf("%s",type);
  fp1=fopen("request.txt","a");
  fp2=fopen("buspass.txt","r");
  if(fp1!=NULL)
  {
	for(int i=0;!feof(fp2);i++)
	{
		ch=fgetc(fp2);
		r[i]=ch;
	}
	p=strstr(r,ch1);
	if(p)
	{
		printf("Name already registered use your emploee id in CHECK option\n");
	}
	else	
	{	
      		 fprintf(fp1,"%s %s %s %s.",ch1,empid,route_id,type);
		printf("Request sent..Wait for 2 working days\n");
	}
	fclose(fp1);
	fclose(fp2);
  }
  else
       printf("File not able to open\n");

}       
void check()
{
	char ch;
	char *tok,*p;
	char r[1000];
	char emp_id[10];
	printf("Enter employee ID to check for buss pass : ");
	scanf("%s",emp_id);
	__fpurge(stdin);
	FILE *fp;
	fp=fopen("buspass.txt","r");
	if(fp!=NULL)
	{
		for(int i=0;!feof(fp);i++)
		{
			ch=fgetc(fp);
			r[i]=ch;
		}
		tok=strtok(r,".");
		while(tok)
		{
			if(strlen(tok)>10)
			{
				p=strstr(tok,emp_id);
				if(p)
				{
					printf("bus Pass approved\n");
					printf("\nBusPass_id user emp_id route_id type.\n");
					printf("%s\n",tok);
				}
		//		else
		//		{
		//			printf(" buspass not approved\n");
		//		}
				tok=strtok(NULL,".");
			}
			else
				tok=strtok(NULL,".");
		}
		fclose(fp);
	}
	else
	{	
		printf("file not found\n");
	}
}

void requesttoCancel()
{
   char bus_pass_id[10];
   FILE *fp;
   printf("Enter bus pass Id : ");
   scanf("%s",bus_pass_id);
   printf("Request sent\n");
   fp=fopen("cancelbuspass.txt","a");
   if(fp!=NULL)
   {
	fprintf(fp,"\n%s.",bus_pass_id);
	fclose(fp);
   }
   else
   {
  	 printf("file not found\n");
   }

}

void requesttoSuspend()
{
   char bus_pass_id[10],date[20];
   FILE *fp;
   printf("Enter your bus_pass_id : ");
   scanf("%s",bus_pass_id);
   __fpurge(stdin);	
   printf("Enter date : ");
   scanf("%s",date);
   __fpurge(stdin);
   fp=fopen("suspendbuspass.txt","a");
   if(fp!=NULL)
   {
      fprintf(fp,"\n%s %s.",bus_pass_id,date);
      printf("your request is submitted");
	fclose(fp);
   }
   else
	{
    		 printf("file not able to open\n");
	}
}

void requestChangeTheRoute()
{
   char bus_pass_id[10],route_id[20];
   FILE *fp;
   printf("Enter your bus_pass_id : ");
   scanf("%s",bus_pass_id);
   __fpurge(stdin);	
   printf("Enter new route_id to change : ");
   scanf("%s",route_id);
   __fpurge(stdin);
   fp=fopen("requestChange.txt","a");
   if(fp!=NULL)
   {
      fprintf(fp,"\n%s %s.",bus_pass_id,route_id);
      printf("your request is submitted");
	fclose(fp);
   }
   else
	{
	     printf("file not able to open\n");
	}

}

void busPass(char *ch1)
{
	int choice;
	printf("******  BUSS PASS  *******\n");
	while(1)
	{
		printf("\n\t 1. Request for buspass. \n\t 2. Request to cancel. \n\t 3. Request to suspend. \n\t 4. Request to change route. \n\t 5. Check. \n\t 0. Exit. \n");
		printf("\n Enter your choice : ");
		scanf("%d",&choice);
		__fpurge(stdin);
		switch(choice)
		{
			 case 1:
        			requestForBuspass(ch1);
				break;
			 case 2:
   			        requesttoCancel();
   			        break;
			 case 3:
  			        requesttoSuspend();
       				break;
			 case 5:
				check();
				break;
			 case 4:
				requestChangeTheRoute();
				break;
			 case 0:
   				printf("exit");
			        break;
		}
	if(choice==0)
		break;
	}
}
