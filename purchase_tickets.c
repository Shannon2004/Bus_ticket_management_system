
#include "library.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>


void purchase_tickets()
{
	printf("                                      TRAVEL PORTAL                                      \n\n");	
	printf("Hi %s! Where would you like to travel with us?\n",p[current].name);
	printf("Enter 'C' for Coorg,'G' for Goa,'H' for Hubli,'U' for Udupi\n");
	printf("Enter 'R' to go back to the home page\n");
	char choice; char ch; int s; int tickets; int pr; int tc; int check;
	char names[10];
	scanf(" %c",&choice);
	while(true)
	{
		//for coorg
		if(choice=='C')
		{
			p[current].destination="Coorg";
			AC_Sleeper(choice);
			Non_AC_Sleeper(choice);
			AC_Seater(choice);
			Non_AC_Seater(choice);
			printf("Please select the bus you would like to travel in.\n");
			printf("Enter 'A' for AC Sleeper, 'B' for Non AC Sleeper, 'C' for AC Seater,'D' for Non AC Seater\n");
			scanf(" %c",&ch);
			while(true)
			{
				if(ch=='A')
				{
					AC_Sleeper_Booking(p[current].destination);
					break;
				}
					//hi
					if(ch=='B')
				{
					Non_AC_Sleeper_Booking(p[current].destination);
					break;
				}
				//hi again.
				if(ch=='C')
				{
					AC_Seater_Booking(p[current].destination);
					break;
				}
				//hi once again.
				if(ch=='D')
				{
					Non_AC_Seater_Booking(p[current].destination);
					break;
				}
				printf("Invalid Choice\n");
				printf("Enter 'A' for AC Sleeper, 'B' for Non AC Sleeper, 'C' for AC Seater,'D' for Non AC Seater\n");
				scanf(" %c",&ch);
				}
				break;
			}//end of coorg block
			//start of hubli
		if(choice=='H')
			{
			p[current].destination="Hubli";
			AC_Sleeper(choice);
			Non_AC_Sleeper(choice);
			AC_Seater(choice);
			Non_AC_Seater(choice);
			printf("Please select the bus you would like to travel in.\n");
			printf("Enter 'A' for AC Sleeper, 'B' for Non AC Sleeper, 'C' for AC Seater,'D' for Non AC Seater\n");
			scanf(" %c",&ch);
			while(true)
			{
				if(ch=='A')
				{
					AC_Sleeper_Booking(p[current].destination);
					break;
				}
					//hi
					if(ch=='B')
				{
					Non_AC_Sleeper_Booking(p[current].destination);
					break;
				}
				//hi again.
				if(ch=='C')
				{
					AC_Seater_Booking(p[current].destination);
					break;
				}
				//hi once again.
				if(ch=='D')
				{
					Non_AC_Seater_Booking(p[current].destination);
					break;
				}
				printf("Invalid Choice\n");
				printf("Enter 'A' for AC Sleeper, 'B' for Non AC Sleeper, 'C' for AC Seater,'D' for Non AC Seater\n");
				scanf(" %c",&ch);
				}
				break;
			}//end of hubli
			//start of goa
		if(choice=='G')
			{
			p[current].destination="Goa";
			AC_Sleeper(choice);
			Non_AC_Sleeper(choice);
			AC_Seater(choice);
			Non_AC_Seater(choice);
			printf("Please select the bus you would like to travel in.\n");
			printf("Enter 'A' for AC Sleeper, 'B' for Non AC Sleeper, 'C' for AC Seater,'D' for Non AC Seater\n");
			scanf(" %c",&ch);
			while(true)
			{
				if(ch=='A')
				{
					AC_Sleeper_Booking(p[current].destination);
					break;
				}
					//hi
					if(ch=='B')
				{
					Non_AC_Sleeper_Booking(p[current].destination);
					break;
				}
				//hi again.
				if(ch=='C')
				{
					AC_Seater_Booking(p[current].destination);
					break;
				}
				//hi once again.
				if(ch=='D')
				{
					Non_AC_Seater_Booking(p[current].destination);
					break;
				}
				printf("Invalid Choice\n");
				printf("Enter 'A' for AC Sleeper, 'B' for Non AC Sleeper, 'C' for AC Seater,'D' for Non AC Seater\n");
				scanf(" %c",&ch);
			}
				break;
			}//end of goa
			//start of udupi
		if(choice=='U')
			{
			p[current].destination="Udupi";
			AC_Sleeper(choice);
			Non_AC_Sleeper(choice);
			AC_Seater(choice);
			Non_AC_Seater(choice);
			printf("Please select the bus you would like to travel in.\n");
			printf("Enter 'A' for AC Sleeper, 'B' for Non AC Sleeper, 'C' for AC Seater,'D' for Non AC Seater\n");
			scanf(" %c",&ch);
			while(true)
			{
				if(ch=='A')
				{
					AC_Sleeper_Booking(p[current].destination);
					break;
				}
					//hi
					if(ch=='B')
				{
					Non_AC_Sleeper_Booking(p[current].destination);
					break;
				}
				//hi again.
				if(ch=='C')
				{
					AC_Seater_Booking(p[current].destination);
					break;
				}
				//hi once again.
				if(ch=='D')
				{
					Non_AC_Seater_Booking(p[current].destination);
					break;
				}
				printf("Invalid Choice\n");
				printf("Enter 'A' for AC Sleeper, 'B' for Non AC Sleeper, 'C' for AC Seater,'D' for Non AC Seater\n");
				scanf(" %c",&ch);
				}
				break;
			}//udupi okay
		if(choice=='R')
			{
				home_page();
				break;
			}
				printf("Invalid Choice\n");
				printf("Enter 'C' for Coorg,'G' for Goa,'H' for Hubli,'U' for Udupi,'R' to return to home page\n");
				scanf(" %c",&choice);
		}
	}		
			
