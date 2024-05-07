#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
void feedBack(char *ch1)
{
	FILE *fp,*fp1;
	printf("=============FEED BACK========================\n");
	char feedback[100];
	char ch;
	char r[1000];
	fp=fopen("feedback.txt","r");
	if(fp!=NULL)
	{
		
		for(int i=0;!feof(fp);i++)
		{
			ch=fgetc(fp);
			r[i]=ch;
		}
		fclose(fp);
		printf("%s\n",r);
		fp1=fopen("feedback.txt","a");
		int choice=0;
		printf("\n \t Welcome to Feedback Services ");	
		printf("\n\t 1.Excellent. \n\t 2. Good. \n\t 3. Average. \n\t 4. Poor. \n\t 5. Worst/comment. ");
		printf("\nEnter your Choice: ");
		scanf("%d",&choice);
		__fpurge(stdin);
		switch(choice)
		{
			case 1:
				printf("Thank you for your feedback.");
				fprintf(fp1,"\n %s : Excellent. \n",ch1);
				fclose(fp1);
				break;
			case 2:
				printf("Thank you for your feedback.");
				fprintf(fp1,"\n %s : Good. \n ",ch1);
				fclose(fp1);
				break;
			case 3:
				printf("Thank you for your feedback.");
				fprintf(fp1,"\n %s : Average. \n",ch1);
				fclose(fp1);
				break;
			case 4:
				printf("Thank you !! We will try Better.");
				fprintf(fp1,"\n %s : Poor. \n",ch1);
				fclose(fp1);
				break;
			case 5:
				printf("\n Apologies for Inconvenience. \n ");
				printf("\n\t**** Feedback ******\n ");
				printf("Write your feedback\n");
				fgets(feedback,100,stdin);
				feedback[strlen(feedback)-1]='\0';
				fprintf(fp1,"\n%s:\n\t %s\n",ch1,feedback);
				fclose(fp1);
				break;
			default:
				printf("Invalid Choice\n");
				fclose(fp1);
		}
	}
	else
	{
		printf("file not found\n");
	}
}
	
		
		
