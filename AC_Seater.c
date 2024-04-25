
#include "library.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>




void AC_Seater(char ch)
{
	if(ch=='C')
	{
		printf("Bengaluru->Coorg	AC Seater		Dates:1/3/5 March	Price:Rs.900\n");
	}
	else if(ch=='G')
	{
		printf("Bengaluru->Goa		AC Seater		Dates:2/3/4 March	Price:Rs.1700\n");
	}
	else if(ch=='H')
	{
		printf("Bengaluru->Hubli	AC Seater		Dates:1/2/6 March	Price:Rs.900\n");
	}
	else
	{
		printf("Bengaluru->Udupi	AC Seater		Dates:2/3/7 March	Price:Rs.900\n");
	}
}
