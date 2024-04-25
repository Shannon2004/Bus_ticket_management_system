#include "library.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>

void cancel_booking()
{
	printf("                                  BOOKING CANCELLATION                                   \n\n");	
	printf("Hey %s!\n",p[current].name);
	if(p[current].status=="Cancelled" || p[current].num_of_tickets==0)
	{
		printf("You don't have any tickets to cancel.\n");
		printf("Enter any number to go back to the homepage\n");
		scanf("%d",&c);
		home_page();
	}
	else
	{
		printf("Are you sure you want to cancel your tickets?\n");
		printf("Enter 1 to confirm cancellation\n");
		printf("Enter any other number to go back to the homepage\n");
		scanf("%d",&c);
		if(c==1)
		{
			p[current].status="Cancelled";
			printf("Returning your money........\n");
			printf("Rs.%d returned to Credit Card Number %s\n",p[current].cost,p[current].crno);
			printf("\nEnter any number to continue\n");
			scanf("%d",&c);
			printf("\n");
			home_page();
		}
		else
		{
			home_page();
		}
	}
}


