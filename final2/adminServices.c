#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
#include"main_header.h"
void adminServices()
{
	int choice=0;
	printf("\n Administartion Services \n--------------------------------\n");
	while(1)
	{
		printf("\n  1. Add / Remove Buses.\n  2. Add / Remove Routes.\n  3. Bus Pass functions.\n  4. Bus Manager.\n  5. New route Applications.\n  6. User Feedback.\n  7. View all Buses routes and Buspass Id's.\n  0. Exit \n");
		printf("Enter your choice :  ");
		scanf("%d",&choice);
		__fpurge(stdin);
		switch(choice)
		{
			case 1:
				addRemoveBus();
				break;
			case 2:
				addRemoveRoute();
				break;
			case 3:
				approveRejectBusPassMain();
				break;
			case 4:
				busManager();
				break;
			case 5:
				requestNewRouteApplications();
				break;
			case 6:
				userFeedBack();
				break;
			case 7:
				viewAll();
				break;
			case 0:
				break;
			default:
				printf("\n  Wrong option\n");
		}
	if(choice==0)
		break;
	}
}
