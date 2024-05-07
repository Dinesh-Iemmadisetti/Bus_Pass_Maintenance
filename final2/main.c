#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<unistd.h>
#include"main_header.h"
int main()
{
	int choice;
	while(1)
	{
	printf("\n\t          Welcome to AMAZON TRANSPORT SERVICE.\n\t--------------------------------------------------------\n");
	printf("\n\t 1. Admin. \n\t 2. User. \n\t 0. EXIT. \n");
	printf("\n  Enter your choice :  ");
	scanf("%d",&choice);
	__fpurge(stdin);
		switch(choice)
		{
			case 1:
				printf("\n*** Admin Page ***\n--------------------\n");
				adminLogin();
				break;
			case 2:
				printf("\n*** User Page ***\n---------------------\n");
				userLogin();
				break;
			case 0:
				printf("\n*** Application is closing ***\n");
				break;
			default:
				printf("\n*** Wrong option ***\n");
		}
	if(choice==0)
		break;
	}
	return 0;
}
				

