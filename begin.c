
#include "library.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>






void begin()
{
	printf("*****************************************************************************************\n");	
	printf("                                   WELCOME TO BUSTLERS                                   \n\n");
	printf("Enter 1 to create an account\n");	
	if(total>0)
		printf("Enter 2 to login\n");
	printf("Enter any other number to exit\n");
	scanf("%d",&c);
	printf("\n*****************************************************************************************\n");	
	switch(c)
	{
		case 1: create_account();
			break;
		case 2: if(total>0)
				login();
			else
				exit(0);
			break;
		default: exit(0);
			 break;
	}
}
