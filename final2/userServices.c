#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
#include"main_header.h"
void userServices(char *ch1)
{
	int choice=0;
	printf("\n\tUser Services\n");
	while(1)
	{
		printf("\n  1. Buses routes Information.\n  2. Apply / Cancel / Suspend for Bus Pass.\n  3. Request for new route. \n  4. Feedback.\n  0. Exit \n");
		printf("\n Enter your Choice : ");
		scanf("%d",&choice);
		printf("*************************\n");
		__fpurge(stdin);
		switch(choice)
		{
			case 1:
				busandRouteInfo();
				break;
			case 2:
				busPass(ch1);
				break;
			case 3:
				requestNewRoute(ch1);
				break;
			case 4:
				feedBack(ch1);
				break;
			case 0:
				printf("\n Exiting application \n_______________________\n");
				break;
			default:
				printf("\n Wrong option\n");
		}
	if(choice==0)
		break;
	}
}
