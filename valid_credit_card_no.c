#include "library.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>



int valid_credit_card_no(char crno[])
{
	int check = 1;
	for(int i=0;i<strlen(crno);i++)
	{
		if(isdigit(crno[i]) == 0)
		{
			check =0;
			break;
		}
	}
	return check;
}

