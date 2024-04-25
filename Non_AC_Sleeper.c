
#include "library.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>


void Non_AC_Sleeper(char ch)
{
	if(ch=='C')
	{
		printf("Bengaluru->Coorg	Non AC Sleeper		Dates:2/3/4 March	Price:Rs.1100\n");
	}
	else if(ch=='G')
	{
		printf("Bengaluru->Goa		Non AC Sleeper		Dates:1/3/4 March	Price:Rs.2100\n");
	}
	else if(ch=='H')
	{
		printf("Bengaluru->Hubli	Non AC Sleeper		Dates:1/5/6 March	Price:Rs.1000\n");
	}
	else
	{
		printf("Bengaluru->Udupi	Non AC Sleeper		Dates:2/6/7 March	Price:Rs.1000\n");
	}
}
