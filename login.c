#include "library.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>

void login()
{
	char *name,*pass2;
	name=(char *)malloc(20);
	pass2=(char *)malloc(20);	
	printf("                                          LOGIN                                          \n\n");
	printf("Enter your username: ");
	scanf("%s",name);
	for(i=0; i<total; i++)
	{
		if(strcmp(name,p[i].name)==0)
		{
			current=i;
			while(true)
			{
				printf("\nEnter your password: ");
				scanf("%s",pass2);
				if(strcmp(pass2,p[i].password)==0)
				{
					printf("\nLogin sucessful! Enter any number to continue\n");
					scanf("%d",&c);
					printf("\n");
					home_page();
					break;
				}
				printf("\nIncorrect password entered!\n");
				printf("Enter 1 to re-try\n");
				printf("Enter any other number to return to the previous page\n");
				scanf("%d",&c);
				printf("\n");
				if(c==1)
					continue;
				else
				{
					begin();
					break;
				}		
			}
			break;
		}
		else
		{
			printf("\nThis username does not exist!\n");
			printf("Enter 1 to re-try login\n");
			printf("Enter 2 to create an account\n");
			printf("Enter any other number to exit\n");
			scanf("%d",&c);
			printf("\n");
			switch(c)
			{
				case 1:	printf("*****************************************************************************************\n");	
					login();
					  break;
				case 2: printf("*****************************************************************************************\n");	
					create_account();
					  break;
				default: exit(0);
					 break;
			}
			break;
		}
	}
}
