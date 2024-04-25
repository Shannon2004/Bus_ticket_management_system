
#include "library.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>


void AC_Seater_Booking(char *des)
{
					int j;
					if(des=="Coorg")
					{
						j=0;
					}
					else if(des=="Goa")
					{
						j=1;
					}
					else if(des=="Hubli")
					{
						j=2;
					}
					else
					{
						j=3;
					}
					p[current].bustype="AC Seater";
					printf("Choose the Day you would like to travel on.\n");
					printf("Available Dates are:");
					for(int i=0;i<3;i++)
					{
						printf("%d/3/23 ",ACSeater[j][i]);
					}
					printf("\n");
					int s;
					scanf("%d",&s);
					while(true)
					{
						if((s==ACSeater[j][0])||(s==ACSeater[j][1])||(s==ACSeater[j][2]))
						{
							break;
						}
						else
						{
							printf("Please select from mentioned dates.\n");
							printf("Available Dates are:");
							for(int i=0;i<3;i++)
							{
								printf("%d/3/23 ",ACSeater[j][i]);
							}
							printf("\n");
							scanf("%d",&s);
						}
					}
					char names[20];
					char st[10];
					int seats_left;
					p[current].date=s;
					if(s==ACSeater[j][0])
					{
						seats_left=seats_AC_Seater[j][0];
					}
					else if(s==ACSeater[j][1])
					{
						seats_left=seats_AC_Seater[j][1];
					}
					else
					{
						seats_left=seats_AC_Seater[j][2];
					}
					printf("The number of seats available are:%d\n",seats_left);	
					printf("Enter the number of tickets you would like to purchase:\n");
					int tickets;
					scanf("%d",&tickets);
					while(true)
					{
						if(tickets<=seats_left)
						{
							break;
						}
						else
						{
							printf("Seats left:%d\n",seats_left);
							printf("Not enough tickets available:\n");
							printf("Enter the number of tickets you would like to purchase:\n");
							scanf("%d",&tickets);
						}
					}
					if(s==ACSeater[j][0])
					{
						seats_AC_Seater[j][0]-=tickets;
					}
					else if(s==ACSeater[j][1])
					{
						seats_AC_Seater[j][1]-=tickets;
					}
					else
					{
						seats_AC_Seater[j][2]-=tickets;
					}
					p[current].num_of_tickets=tickets;
					printf("Please enter the name(s) of the traveler(s):\n");
					for(int i=0;i<tickets;i++)
					{	printf("Enter the name of the passenger:\n");
						scanf("%s",names);
						p[current].passengers[i]=(char *)malloc(strlen(names)+1);
						strcpy(p[current].passengers[i],names);
						while(true)
						{
							if(check_username(p[current].passengers[i]))
								break;
							else
							{
								printf("Please enter a valid name\n");
								scanf("%s",names);
								p[current].passengers[i]=(char *)malloc(strlen(names)+1);
								strcpy(p[current].passengers[i],names);
							}
						}
					}
					int pr=price_AC_Seater[j];
					int tc=pr*tickets;
					p[current].cost=tc;
					int check;
					printf("\nThe total cost of the tickets will be Rs.%d\n",tc);
					printf("Enter any number to proceed to payment\n");
					scanf("%d",&check);
					FILE *ACSEATER;
					ACSEATER=fopen("ACSeater.txt","a");
					fprintf(ACSEATER,"USERNAME:%s Bangalore->%s DATE:%d/3/23 TICKETS:%d PRICE:Rs.%d  PASSENGERS: ",p[current].name,des,p[current].date,tickets,p[current].cost);	
					for(int i=0;i<tickets;i++)
					{
						fprintf(ACSEATER,"%s ",p[current].passengers[i]);
					}
					fprintf(ACSEATER,"\n");
					fclose(ACSEATER);	
					transaction(tc);
}

