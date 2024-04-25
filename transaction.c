
#include "library.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>

void transaction(int price)
{
	printf("\n*****************************************************************************************\n");
	printf("                                     PAYMENT GATEWAY                                     \n");
	printf("\nAmount to be paid: Rs.%d\n",price);
	printf("\nEnter your credit card number: ");
	char *det;
	det=(char *)malloc(30);
	scanf("%s",det);
	p[current].crno=(char *)malloc(strlen(det)+1);
	strcpy(p[current].crno,det);
	while(true)
	{
		if(strlen(p[current].crno) == 16)
		{
			if(valid_credit_card_no(p[current].crno))
			{
				break;
			}
			else
			{printf("Invalid credit card number.\n");
			printf("\nEnter your credit card number: ");
			scanf("%s",p[current].crno);}
		}
		else
		{printf("\nCredit card number should be 16 digits.\n");
		printf("Please enter your credit card number: ");	
		scanf("%s",p[current].crno);}
	}
	printf("\nEnter CVV of the credit card: ");
	while(true)
	{
		char cvv[7];
		scanf("%s",cvv);
		if(strlen(cvv) == 3)
		{
			if(valid_cvv(cvv))
			{break;}
			else
			{printf("\nInvalid CVV\n");
			printf("Enter CVV of the credit card: ");}
		}
		else
		{printf("\nCVV should have 3 digits.\n");
		printf("Enter CC of the credit card: ");}
	}
	int otp=(rand()%(999999-100000+1))+100000;
	int otp2;
	printf("\nOTP for the transaction: %d",otp);
	printf("\nEnter OTP: ");
	scanf("%d",&otp2);
	while(otp!=otp2)
	{
		printf("\nIncorrect OTP entered");
		printf("\nEnter OTP: ");
		scanf("%d",&otp2);
	}
	printf("\nTransaction complete! Ticket booked successfully.\n");
	p[current].status="Booked";
	printf("\nEnter any number to continue\n");
	scanf("%d",&c);
	printf("\n");
	home_page();
}
