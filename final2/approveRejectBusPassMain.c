#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<unistd.h>
void approveRejectBusPass()
{
	char r[1000];
	char *q;
	char *b;
//	char b[20];
	char ch;
	char *tok;
	FILE *fp,*fp1,*fp2;	
	fp=fopen("request.txt","r");
	fp1=fopen("status.txt","a");
	fp2=fopen("buspass.txt","a");
	if(fp!=NULL)
	{
		for(int i=0;!feof(fp);i++)
		{
			ch=fgetc(fp);
			r[i]=ch;
		}
		printf("Request list:\n%s\n",r);
		tok=strtok(r,".");
		while(tok)
		{
			
			while(1)
			{
				if(*tok=='\n')
				{
					tok=tok+1;
				}
				else
					break;
			}
	//		printf("tok %s\n",tok);
			q=malloc(30);
			b=malloc(30);
			char *result;
			result=malloc(10);
			strcpy(q,tok);
			strcpy(b,q);
			strcat(q," ");
			if(strlen(q)>8)
			{
				printf("%s\n",q);
				printf("Enter status : ");
				scanf("%s",result);
				strcat(q,result);
				if(strlen(q)>8)
				{
					fprintf(fp1,"%s.\n",q);
				//	fputs(q,fp1);
					printf("done\n");
					free(q);
				}
	//			printf("result %s\n",result);
//				printf("%d\n",(strcmp(result,"approve")));
				if(strcmp(result,"approve")==0)
				{
					
					char *id;
					id=malloc(30);
					printf("Enter Id number for %s ",b);
					scanf("%s",id);
					strcat(id," ");
			//
					if(*b=='\n')
					{	
						char *c;
						c=b+1;
						strcat(id,c);
						fprintf(fp2,"%s.\n",id);
						free(id);
						
					}
					else
					{
			//
					strcat(id,b);
					fprintf(fp2,"%s.\n",id);
					printf("%s\n",id);
				//	fputs(id,fp2);
					free(id);
					}
					free(b);
				}
			}
			free(result);
			tok=strtok(NULL,".");
		}
		remove("request.txt");
		fclose(fp);
		fclose(fp1);
		fclose(fp2);
	}
	else
		printf("file not found or no new requests\n");
	
}

void cancelBusPass()
{
	char *tok;
	char status[10];
	char r[1000];
	char j[1000];
	char *q;
	char *p;
	char *p1;
	char ch;
	char ch1;
	FILE *fp,*fp1,*fp2;
	fp=fopen("cancelbuspass.txt","r");
	fp1=fopen("buspass.txt","r");
	if(fp!=NULL && fp1!=NULL)
	{
		for(int i=0;!feof(fp);i++)
		{
			ch=fgetc(fp);
			r[i]=ch;
		}
		fclose(fp);
	 	printf("cancel buspass list:\n%s\n",r);
		
		for(int i=0;!feof(fp1);i++)
		{
			ch1=fgetc(fp1);
			j[i]=ch1;
		}
		printf("buspass list:\n%s\n",j);
		fclose(fp1);
		fp2=fopen("buspass.txt","w+");
		tok=strtok(r,".");
//		printf("tok %s\n",tok);
		while(tok)
		{
			if(strlen(tok)>=4)
			{
				while(1)
				{
					if(*tok=='\n')
					{
						tok=tok+1;
					}
					else
						break;
				}
//				printf("tok%s\n",tok);
				p=strstr(j,tok);
//				printf("p %s\n",p);
				if(p)
				{		
					printf("%s\n",tok);
					printf("Enter status : ");
					scanf("%s",status);
					if(strcmp(status,"approve")==0)
					{
						p1=strchr(p,'.');
						p1=p1+1;
						strcpy(p,p1);	
		//				printf("p ->%s\n",p);
		//				printf("=============================\n");
		//				printf("j ->%s\n",j);
						tok=strtok(NULL,".");
		//				printf("++++++++++++++++++++\n");
		//				printf("%s\n",tok);
					}
				}
				else
					tok=strtok(NULL,".");
			}
			else
			{
				tok=strtok(NULL,".");
			//	break;
			}
		}
		tok=strtok(j,".");
		while(tok)
		{
			q=malloc(100);
			strcpy(q,tok);
		//	strcat(q,".");
			if(strlen(q)>12)
			{
				fprintf(fp2,"%s.\n",q);
			//	fputs(q,fp2);
			}
			free(q);
			tok=strtok(NULL,".");
		}
	
	fclose(fp2);
	remove("cancelbuspass.txt");
	}
	else
	{
		printf("file not found or cancel list is empty\n");
	}
	
}	

void suspendBusPass()
{
	FILE *fp,*fp1,*fp2;
	char k[300];
	k[0]='\0';
	char ch;
	char ch1;
	char status[10];
	char *q;
	char *tok;
	char *e;
	char r[1000];
	char j[1000];
	char *p;
	char *p1;
	fp=fopen("suspendbuspass.txt","r");
	fp1=fopen("buspass.txt","r");
	if( fp!=NULL && fp1!=NULL)
	{
		for(int i=0;!feof(fp);i++)
		{
			ch=fgetc(fp);
			r[i]=ch;
		}
		fclose(fp);
		for(int i=0;!feof(fp1);i++)
		{
			ch1=fgetc(fp1);
			j[i]=ch1;
		}
		fclose(fp1);
		printf("suspend buspass list\n %s\n",r);
		printf("buspass list\n %s\n",j);
		fp2=fopen("buspass.txt","w+");
		tok=strtok(r," ");
	//	printf("%s\n",tok);
		while(tok)
		{
			if(strlen(tok)>=4)
			{	
				while(1)
				{
					if(*tok=='\n')
					{
						tok=tok+1;
					}
					else
						break;
				}
	//			printf("tok %s\n",tok);
				p=strstr(j,tok);
				if(p)
				{
					printf("%s\n",tok);
					printf("Enter status : ");
					scanf("%s",status);
					if(strcmp(status,"approve")==0)
					{
						e=malloc(50);
						tok=strtok(NULL,".");
				//		printf("tok initial %s\n",tok);	
						p1=strchr(p,'.');
						*(p1)='\0';
						strcpy(e,p);
				//		printf("e->%s\n",e);
						strcat(k,e);
						strcat(k," ");
				//		printf("k %s\n",k);
						p1=p1+1;
				//		printf("%s\n",p1);
						strcpy(p,p1);
				//		printf("j->%s\n",j);
				//		printf("tok in j%s\n",tok);
						strcat(k,tok);
				//		printf("tok %s\n",tok);
				//		printf("%s\n",k);
						strcat(k,".");
						printf("final %s\n",k);
						free(e);
					}
				}
				else
				{
			//		printf(" Hello \n");
					tok=strtok(NULL,".");
			//		printf("tok else %s\n",tok);
				}
			}
			else
			{ 
				tok=strtok(NULL,".");
			//	break;
			}
			tok=strtok(NULL," ");
		}
//		printf("j->%s\n",j);
//		printf("k->%s\n",k);
		tok=strtok(j,".");
		printf(" name->%s\n",tok);
		while(tok)
		{
			printf(" name->%s\n",tok);	
			q=malloc(50);
			strcpy(q,tok);
		//	strcat(q,".");
			if(strlen(q)>8)
			{
				fprintf(fp2,"%s.\n",q);
				//fputs(q,fp2);
			}
			free(q);
			tok=strtok(NULL,".");
		}
		tok=strtok(k,".");
		while(tok)
		{
			q=malloc(30);
			strcpy(q,tok);
	//		strcat(q,".");
			if(strlen(q)>11)
			{
				fprintf(fp2,"%s.\n",q);
			
				//	puts(q,fp2);
			}
			free(q);
			tok=strtok(NULL,".");	
		
		}
		remove("suspendbuspass.txt");
		fclose(fp2);
	}
	else
	{
		printf("file not found or suspend list is empty\n");
	}
}


void changeTheRoute()
{	
	printf(" Hello ");
	char r[1000];
	char j[1000];
//	char k[50];
//	k[0]='\0';
	char status[10];
	char w[50];
	char *tok;
	char *q;
	FILE *fp,*fp1,*fp2;
	char *p,*p1;
	char ch;
	char ch1;
	fp=fopen("requestChange.txt","r");
	fp1=fopen("buspass.txt","r");
	if(fp!=NULL && fp1!=NULL)
	{
		for(int i=0;!feof(fp);i++)
		{
			ch=fgetc(fp);
			r[i]=ch;
		}
		fclose(fp);
		printf("Request route change list \n%s\n",r);
		for(int i=0;!feof(fp1);i++)
		{
			
			ch1=fgetc(fp1);
			j[i]=ch1;
		}
		fclose(fp1);
		printf("Buspass list\n%s\n",j);
		fp2=fopen("buspass.txt","w");
		tok=strtok(r," ");
	//	printf("%s\n",tok);
		while(tok)	
		{
	//		printf("1.%s\n",tok);
			if(strlen(tok)>=4)
			{
				
				while(1)
				{
					if(*tok=='\n')
					{
						tok=tok+1;
					}
					else
						break;
				}
	//			printf("tok %s\n",tok);
				p=strstr(j,tok);
				if(p)
				{				
					printf("%s\n",tok);
					printf("Enter status\n");
					scanf("%s",status);
					if(strcmp(status,"approve")==0)
					{
						q=malloc(100);
						tok=strtok(NULL,".");
						p1=strchr(p,'.');
						*(p1)='\0';
						strcpy(q,p);
					//	strcat(k,q);
					//	strcat(k,".");
						strcat(q,".");
						p1=p1+1;
						strcpy(p,p1);		
						char *start;
						char *end;
						int count=0;
				//		printf("Q=%p\n",q);
						for(int i=0;q[i];i++)
						{
						//	printf("%c\n=",q[i]);
					//		printf("count in %d\n",count);
					//		printf("i=%d\n",i);
							if(q[i]==' ')
							{
								++count;
							}
							if(count==3 && q[i]==' ')
							{
								start=q+i;
							}
							if(count==4 && q[i]==' ')
							{
								end=q+i;
							}
						}
					//	printf("count=%d\n",count);
					//	printf("start=%p\n",start);
	
						*start='\0';
				//		printf("Q=%s\n",q);
						strcpy(w,q);
						strcat(w," ");
						strcat(w,tok);
						strcat(w,end);
						printf("%s\n",w);
						if(strlen(w)>8)
						{
							fprintf(fp2,"%s\n",w);
						}
						free(q);
					}
				}
	
				else
				{
					tok=strtok(NULL,".");
				}

			}
			else
				tok=strtok(NULL,".");
				//break;
			tok=strtok(NULL," ");
		}
			
		tok=strtok(j,".");
		while(tok)
		{
			q=malloc(30);
			strcpy(q,tok);
			if(strlen(q)>8)
			{
				fprintf(fp2,"%s.",q);
			}
			free(q);
			tok=strtok(NULL,".");
		}
		remove("requestChange.txt");
		fclose(fp2);
	}
	else
	{
		printf("file not found\n");
	}
}

void approveRejectBusPassMain()
{
	int choice=0;
	printf("****** APPROVE / REJECT BUS PASS MAIN ******\n        ------------------------------        \n");
	while(1)
	{
		printf("\n 1. Approve / reject BusPass. \n 2. Cancel BusPass. \n 3. Suspend BusPass. \n 4. Change to another route. \n 0. Exit \n");
		printf("\n Enter your Choice :  ");
		scanf("%d",&choice);
		__fpurge(stdin);
		switch(choice)
		{
			case 1:
				approveRejectBusPass();
				break;
			case 2:
				cancelBusPass();
				break;
			case 3:
				suspendBusPass();
				break;
			case 4:
				changeTheRoute();
				break;
			case 0:
				break;
			default:
				printf("Wrong option\n");
		}
		if(choice==0)
			break;
	}
}




















