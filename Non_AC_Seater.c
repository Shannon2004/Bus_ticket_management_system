
#include "library.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>


void Non_AC_Seater(char ch)
{
	if(ch=='C')
	{
		printf("Bengaluru->Coorg	Non AC Seater		Dates:2/3/4 March	Price:Rs.800\n");
	}
	else if(ch=='G')
	{
		printf("Bengaluru->Goa		Non AC Seater		Dates:1/3/4 March	Price:Rs.1500\n");
	}
	else if(ch=='H')
	{
		printf("Bengaluru->Hubli	Non AC Seater		Dates:1/4/6 March	Price:Rs.850\n");
	}
	else
	{
		printf("Bengaluru->Udupi	Non AC Seater		Dates:2/4/7 March	Price:Rs.850\n");
	}
}
