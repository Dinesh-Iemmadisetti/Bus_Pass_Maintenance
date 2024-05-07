#include<stdio.h>
#include<stdio_ext.h>
#include"main_header.h"
void userLogin()
{
	int choice=0;
	printf("=================   USER LOGIN   ========================\n");
	while(1)
	{
		printf("\n\t 1. New User. \n\t 2. Existing user. \n\t 0. Exit. \n");
		printf("\n Enter your Choice :  ");
		scanf("%d",&choice);
		__fpurge(stdin);
		switch(choice)
		{
			case 1:
				newUser();
				break;
			case 2:
				existingUser();
				break;
			case 0:
				printf("exit\n");
				break;
			default:
				printf("wrong option\n");
		}
	if(choice==0)
		break;
	}

}
