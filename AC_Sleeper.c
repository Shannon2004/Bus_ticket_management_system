
#include "library.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>



void AC_Sleeper(char ch)
{
	if(ch=='C')
	{
		printf("Bengaluru->Coorg	AC Sleeper		Dates:1/3/4 March	Price:Rs.1500\n");
	}
	else if(ch=='G')
	{
		printf("Bengaluru->Goa		AC Sleeper		Dates:2/3/4 March	Price:Rs.2500\n");
	}
	else if(ch=='H')
	{
		printf("Bengaluru->Hubli	AC Sleeper		Dates:1/5/6 March 	Price:Rs.1300\n");
	}
	else
	{
		printf("Bengaluru->Udupi	AC Sleeper		Dates:1/3/4 March	Price:Rs.1500\n");
	}
}
