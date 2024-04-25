#include<stdio.h>
#include "utils.h"
void main()
{
	float epsilon=0.0,PresentValue=1.0,n=0.0,r=0.0,t=0.0;
	scanf("%f",&epsilon);
	while(PresentValue>0)
	{
	scanf("%f%f%f%f",&PresentValue,&n,&r,&t);
	printf("%f %f",compounded_value(PresentValue,n,r,t),inf_compounded_value(PresentValue,r,t,epsilon));
	printf("\n");
	}
}
	
