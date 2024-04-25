#include "library.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>


void home_page()
{
	printf("*****************************************************************************************\n");	
	printf("                                        HOME PAGE                                        \n\n");
	printf("Hello %s! What would you like to do?\n",p[current].name);
	printf("Enter 1 to purchase tickets\n");
	printf("Enter 2 to view last booking\n");
	printf("Enter 3 to cancel a booking\n");
	printf("Enter any other number to logout\n");
	scanf("%d",&c);
	printf("\n*****************************************************************************************\n");
	switch(c)
	{
		case 1: purchase_tickets();
			break;
		case 2: view_booking();
			break;
		case 3: cancel_booking();
			break;	
		default: begin();
			break;
	}
}
