
#include "library.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>



int valid_cvv(char cvv[])
{
	int check = 1;
	for(int i=0;i<strlen(cvv);i++)
	{
		 if(isdigit(cvv[i]) == 0)
		{
			check = 0;
			break;
		}
	}
	return check;
}
