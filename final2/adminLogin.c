#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
#include"main_header.h"
void adminLogin()
	{
		char name[30];
		char password[30];
		char all[30];
		char *p;
		a:printf("Enter admin name : ");
		scanf("%s",name);
		__fpurge(stdin);
		b:printf("Enter  password  : ");
		scanf("%s",password);
		__fpurge(stdin);
		FILE *fp;
		fp=fopen("adminLogin.txt","r");

		fgets(all,30,fp);

		printf("===============================\n");
		all[strlen(all)-1]='\0';
	//	printf("%s\n",all);

		p=strtok(all," ");
//		printf("%s\n",p);
//		while(p!=NULL)
//		{
			if(strcmp(name,p)==0)
			{
				p=strtok(NULL,"\n");
				if(strcmp(password,p)==0)
				{
					adminServices();
					
				}
				else
				{
					printf("Incorrect password\n");
					goto b;
				}
			}
			else
			{
				printf("Incorrect username\n");
				goto a;
			}
			fclose(fp);
			
//		}
			
		
	}
	
