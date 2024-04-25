
#include "library.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>


int check_phonenumber(char *phone)
{
	if(strlen(phone) == 10)
	{
		for(int i=0;i<strlen(phone);i++)
		{
			if(isdigit(phone[i]) == 0)
			{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

