#include "library.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>


int check_username(char *name)
{
	for(int i=0;i<strlen(name);i++)
	{
		if(isalpha(name[0]) == 0)
		{
			return 0;
		}
	}
	return 1;
}

