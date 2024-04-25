
#include "library.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>


void create_account()
{
	char *name,*pass,*pass2,*phone;
	name=(char *)malloc(30);
	pass2=(char *)malloc(30);
	pass=(char *)malloc(30);
	phone=(char *)malloc(10);
	printf("                                         SIGN UP                                         \n\n");
	printf("Create a username: ");
	scanf("%s",name);
	for(i=0; i<total; i++)
	{
		if(strcmp(p[i].name,name)==0)
		{
			printf("\nUsername is already taken! Please try again.\n");
			create_account();
			return;
		}
	}
	if(check_username(name)==0)
	{
		printf("\nUsername must start with a letter. Please try again.\n");
		create_account();
		return;
	}
	strcpy(p[total].name,name);
	printf("\nEnter your phone number: ");
	scanf("%s",phone);
	while(check_phonenumber(phone)==0)
	{
		printf("\nInvalid phone number. Please try again.\n");
		printf("\nEnter your phone number: ");
		scanf("%s",phone);
	}
	p[total].phone=(char *)malloc(10);
	strcpy(p[total].phone,phone);
	while(true)
	{
		printf("\nCreate a password: ");
		scanf("%s",pass);
		if(check_password(pass))
			break;
		else
			printf("\nInvalid Password! Password must be at least 8 characters long and must contain \na lowercase letter, an uppercase letter, a number and a special character.\n");
	}
	strcpy(p[total].password,pass);
	while(true)
	{
		printf("\nRe-enter password: ");
		scanf("%s",pass2);
		if(strcmp(p[total].password,pass2)==0)
		{
			current=total;
			total++;
			printf("\nAccount successfully created! Enter any number to continue\n");
			scanf("%d",&c);
			printf("\n");
			home_page();
			break;
		}
		printf("\nIncorrect password entered! Please try again.\n");
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
}

