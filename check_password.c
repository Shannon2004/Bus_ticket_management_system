#include "library.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>


bool check_password(char *pass)
{
	int l=strlen(pass);
	int i;
	bool check1=false, check2=false, check3=false, check4=false;
	if(l<8)
		return false;
	for(i=0;i<l;i++)
	{
		if((pass[i]>=32 && pass[i]<=47) || (pass[i]>=58 && pass[i]<=64) || (pass[i]>=91 && pass[i]<=96) || (pass[i]>=123 && pass[i]<=126))
			check1=true;
		else if(isdigit(pass[i]))
			check2=true;
		else if(pass[i]>=65 && pass[i]<=90)
			check3=true;
		else if(pass[i]>=97 && pass[i]<=122)
			check4=true;
	}
	if(check1 && check2 && check3 && check4)
		return true;
	else
		return false;
}
