
#include "library.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>

void view_booking()
{
	printf("                                     BOOKING HISTORY                                     \n\n");	
	printf("Hey %s!\n",p[current].name);
	if(p[current].num_of_tickets==0)
	{
		printf("You have not purchased any tickets.\n");
	}
	else
	{
		printf("Here are the details of your booking:\n");
	printf("Destination:%s \nDate:%d/3/23 \nNumber of Tickets:%d \nStatus:%s \nBus_Type:%s\n",p[current].destination,p[current].date,p[current].num_of_tickets,p[current].status,p[current].bustype); 
	}
	printf("\nEnter any number to go back to the home page\n");
	scanf("%d",&c);
	printf("\n");
	home_page();
}
