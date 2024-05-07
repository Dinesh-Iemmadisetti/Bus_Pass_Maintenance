#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
#include<unistd.h>
void newUser()
{	
	char ch;
	char name[30];
	char r[1000];
	char *p;
	printf("\n Enter UserName  : ");
	scanf("%s",name);
	char pass[10];
	a:printf("\n Enter Password (length should be 6 character only) : \n");
	scanf("%s",pass);
	if(strlen(pass)!=6)
	{
		goto a;
	}
	int age=0;
	printf("\n Enter age : ");
	scanf("%d",&age);
	fflush(stdin);
	char mobile[11];
	b:printf("\n Enter mobile no : ");
	scanf("%s",mobile);
	if(strlen(mobile)!=10)
	{
		goto b;
	}
	fflush(stdin);
	FILE *fp;
	fp=fopen("newUser.txt","a+");
	if(fp!=NULL)
	{
	
//		fgets(r,1000,fp);
//		r[strlen(r)-1]='\0''
		for(int i=0;!feof(fp);i++)
		{
			ch=fgetc(fp);
			r[i]=ch;
		}

		p=strstr(r,name);
//		printf("%p\n",p);
		
//		printf("%s\n",r);

//		printf("%p\n",p);
		if(p)
		{
			
			if(*p=='\n')
			{
				p=p+1;
			}
			while(1)
			{
				printf(" User name alreay there use another one\n");
				printf("\n Enter User name : ");
				scanf("%s",name);
				p=strstr(r,name);
				if(p)
				{	
					printf("User name alreay there use another one\n");
				}
				else
					break;
			}
		}

//		printf("%s\n",r);
//		printf("1%s",mobile);
		p=strstr(r,mobile);
		printf("%p\n",p);
		if(p)
		{
			while(1)
			{
				printf("Moblie number already exists\n");
				printf("\n Enter Mobile NUmber : ");
				scanf("%s",mobile);
				p=strstr(r,mobile);
				if(p)
				{	
					printf("mobile number already there.Use another one\n");
				}
				else
					break;
			}
		}
		fprintf(fp,"%s %s %d %s.",name,pass,age,mobile);
		fclose(fp);
		printf("\n\t^^^^^ User registration Success ^^^^^ \n ");
	}
	else
	{
		printf("File not found\n");
	}
}

	
		
	
