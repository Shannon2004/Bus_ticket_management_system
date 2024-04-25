#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>

//function declaration
void purchase_tickets();
void begin();
void create_account();
void login();
void home_page();
void view_booking();
bool check_password(char *pass);
int check_username(char *name);
int check_phonenumber(char *phone);

struct customer
{
	char name[30];
	char password[30];
	char *phone;
	char *destination;
	char *bustype;
	char *passengers[10];
	char *seattype[10];
	int date;
	int cost;
	int num_of_tickets;
	char *status;
	char *crno;
};

struct customer p[20];
int c, current=0, total=0, i=0;
//c stores the choice for user to traverse between pages
//current stores the position of <p> and indicates which account is logged into
//total stores the total number of accounts created so far
//i is a variable used in <for> loops

void begin()
{
	//the starting page
	printf("*****************************************************************************************\n");	
	printf("                                   WELCOME TO BUSTLERS                                   \n\n");
	printf("Enter 1 to create an account\n");	
	if(total>0)
		printf("Enter 2 to login\n");
	printf("Enter any other number to exit\n");
	scanf("%d",&c);
	printf("\n*****************************************************************************************\n");	
	switch(c)
	{
		case 1: create_account();
			break;
		case 2: if(total>0)
				login();
			else
				exit(0);
			break;
		default: exit(0);
			 break;
	}
}


void create_account()
{
	char *name,*pass,*pass2,*phone;
	name=(char *)malloc(30);
	pass2=(char *)malloc(30);
	pass=(char *)malloc(30);
	phone=(char *)malloc(10);
	printf("                                         SIGN UP                                         \n\n");
	printf("Create a username: ");
	scanf("%s",name);
	for(i=0; i<total; i++)
	{
		//checking if an account with the same username is already stored in the database
		if(strcmp(p[i].name,name)==0)
		{
			printf("\nUsername is already taken! Please try again.\n");
			create_account();
			return;
		}
	}
	if(check_username(name)==0)
	{
		printf("\nUsername must start with a letter. Please try again.\n");
		create_account();
		return;
	}
	strcpy(p[total].name,name);
	printf("\nEnter your phone number: ");
	scanf("%s",phone);
	while(check_phonenumber(phone)==0)
	{
		printf("\nInvalid phone number. Please try again.\n");
		printf("\nEnter your phone number: ");
		scanf("%s",phone);
	}
	p[total].phone=(char *)malloc(10);
	strcpy(p[total].phone,phone);
	while(true)
	{
		printf("\nCreate a password: ");
		scanf("%s",pass);
		if(check_password(pass))
			break;
		else
			printf("\nInvalid Password! Password must be at least 8 characters long and must contain \na lowercase letter, an uppercase letter, a number and a special character.\n");
	}
	strcpy(p[total].password,pass);
	while(true)
	{
		printf("\nRe-enter password: ");
		scanf("%s",pass2);
		if(strcmp(p[total].password,pass2)==0)
		{
			current=total;
			total++;
			printf("\nAccount successfully created! Enter any number to continue\n");
			scanf("%d",&c);
			printf("\n");
			home_page();
			break;
		}
		printf("\nIncorrect password entered! Please try again.\n");
		printf("Enter 1 to re-try\n");
		printf("Enter any other number to return to the previous page\n");
		scanf("%d",&c);
		printf("\n");
		if(c==1)
			continue;
		else
		{
			begin();
			break;
		}

	}
}

bool check_password(char *pass)
{
	//to check if the password meets the safety conditions
	int l=strlen(pass);
	int i;
	bool check1=false, check2=false, check3=false, check4=false;
	if(l<8)
		return false;
	for(i=0;i<l;i++)
	{
		//checking for a special character in the password
		if((pass[i]>=32 && pass[i]<=47) || (pass[i]>=58 && pass[i]<=64) || (pass[i]>=91 && pass[i]<=96) || (pass[i]>=123 && pass[i]<=126))
			check1=true;
		//checking for a digit
		else if(isdigit(pass[i]))
			check2=true;
		//checking for an uppercase letter
		else if(pass[i]>=65 && pass[i]<=90)
			check3=true;
		//checking for a lowercase letter
		else if(pass[i]>=97 && pass[i]<=122)
			check4=true;
	}
	if(check1 && check2 && check3 && check4)
		return true;
	else
		return false;
}



int check_username(char *name)
{
	//username must start with an alphabet
	if(isalpha(name[0]) == 0)
		return 0;
	return 1;
}

int check_phonenumber(char *phone)
{
	//phonenumber must be ten characters long and made up of digits
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

void login()
{
	//login page
	char *name,*pass2;
	name=(char *)malloc(20);
	pass2=(char *)malloc(20);	
	printf("                                          LOGIN                                          \n\n");
	printf("Enter your username: ");
	scanf("%s",name);
	for(i=0; i<total; i++)
	{
		if(strcmp(name,p[i].name)==0)
		{
			current=i;
			while(true)
			{
				printf("\nEnter your password: ");
				scanf("%s",pass2);
				if(strcmp(pass2,p[i].password)==0)
				{
					printf("\nLogin sucessful! Enter any number to continue\n");
					scanf("%d",&c);
					printf("\n");
					home_page();
					break;
				}
				printf("\nIncorrect password entered!\n");
				printf("Enter 1 to re-try\n");
				printf("Enter any other number to return to the previous page\n");
				scanf("%d",&c);
				printf("\n");
				if(c==1)
					continue;
				else
				{
					begin();
					break;
				}		
			}
			break;
		}
		else
		{
			printf("\nThis username does not exist!\n");
			printf("Enter 1 to re-try login\n");
			printf("Enter 2 to create an account\n");
			printf("Enter any other number to exit\n");
			scanf("%d",&c);
			printf("\n");
			switch(c)
			{
				case 1:	printf("*****************************************************************************************\n");	
					login();
					  break;
				case 2: printf("*****************************************************************************************\n");	
					create_account();
					  break;
				default: exit(0);
					 break;
			}
			break;
		}
	}
}

void cancel_booking()
{

	printf("                                  BOOKING CANCELLATION                                   \n\n");	
	printf("Hey %s!\n",p[current].name);
	if(p[current].status=="Cancelled" || p[current].num_of_tickets==0)
	{
		printf("You don't have any tickets to cancel.\n");
		printf("Enter any number to go back to the homepage\n");
		scanf("%d",&c);
		home_page();
	}
	else
	{
		printf("Are you sure you want to cancel your tickets?\n");
		printf("Enter 1 to confirm cancellation\n");
		printf("Enter any other number to go back to the homepage\n");
		scanf("%d",&c);
		if(c==1)
		{
			p[current].status="Cancelled";
			printf("Returning your money........\n");
			printf("Rs.%d returned to Credit Card Number %s\n",p[current].cost,p[current].crno);
			printf("\nEnter any number to continue\n");
			scanf("%d",&c);
			printf("\n");
			home_page();
		}
		else
		{
			home_page();
		}
	}
}

void home_page()
{
	printf("*****************************************************************************************\n");	
	printf("                                        HOME PAGE                                        \n\n");
	printf("Hello %s! What would you like to do?\n",p[current].name);
	printf("Enter 1 to purchase tickets\n");
	printf("Enter 2 to view last booking\n");
	printf("Enter 3 to cancel a booking\n");
	printf("Enter any other number to logout\n");
	scanf("%d",&c);
	printf("\n*****************************************************************************************\n");
	switch(c)
	{
		case 1: purchase_tickets();
			break;
		case 2: view_booking();
			break;
		case 3: cancel_booking();
			break;	
		default: begin();
			break;
	}
}

void view_booking()
{
	printf("                                     BOOKING HISTORY                                     \n\n");	
	printf("Hey %s!\n",p[current].name);
	if(p[current].num_of_tickets==0)
	{
		printf("You have not purchased any tickets.\n");
	}
	else
	{
		printf("Here are the details of your booking:\n");
	printf("Destination:%s \nDate:%d/3/23 \nNumber of Tickets:%d \nStatus:%s \nBus_Type:%s\n",p[current].destination,p[current].date,p[current].num_of_tickets,p[current].status,p[current].bustype); 
	}
	printf("\nEnter any number to go back to the home page\n");
	scanf("%d",&c);
	printf("\n");
	home_page();
}

int checkusername(char *name)
{
	//checking validity of a name (valid names are solely made up of letters)
	int check = 1;
	for(int i=0;i<strlen(name);i++)
	{
		 if(isalpha(name[i]) == 0)
		{
			check = 0;
			break;
		}
	}
	return check;
}

int valid_cvv(char cvv[])
{
	//checking validity of cvv (must be made up of 3 digits)
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

int valid_credit_card_no(char crno[])
{
	//checking validity of credit card number (must be made up of 16 digits)
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

//storing the dates on which the buses ply
int ACS[4][3]={1,3,4,2,3,4,1,5,6,2,6,7};
int NACS[4][3]={2,3,4,1,3,4,1,5,6,2,6,7};
int ACSeater[4][3]={1,3,5,2,3,4,1,2,6,2,6,7};
int NACSeater[4][3]={2,3,4,1,3,4,1,4,6,2,4,7};
//storing the prices of each type of bus
int price_AC_Sleeper[4]={1500,2500,1300,1500};
int price_Non_AC_Sleeper[4]={1100,2100,1000,1000};
int price_AC_Seater[4]={900,1700,900,900};
int price_Non_AC_Seater[4]={800,1500,850,850};
//storing the seats available on each bus
int seats_AC_Sleeper[4][3]={20,20,20,20,20,20,20,20,20,20,20,20};
int seats_Non_AC_Sleeper[4][3]={20,20,20,20,20,20,20,20,20,20,20,20};
int seats_AC_Seater[4][3]={20,20,20,20,20,20,20,20,20,20,20,20};
int seats_Non_AC_Seater[4][3]={20,20,20,20,20,20,20,20,20,20,20,20};

void AC_Sleeper(char ch)
{
	if(ch=='C')
	{
		printf("Bengaluru->Coorg	AC Sleeper		Dates:1/3/4 March	Price:Rs.1500\n");
	}
	else if(ch=='G')
	{
		printf("Bengaluru->Goa		AC Sleeper		Dates:2/3/4 March	Price:Rs.2500\n");
	}
	else if(ch=='H')
	{
		printf("Bengaluru->Hubli	AC Sleeper		Dates:1/5/6 March 	Price:Rs.1300\n");
	}
	else
	{
		printf("Bengaluru->Udupi	AC Sleeper		Dates:1/3/4 March	Price:Rs.1500\n");
	}
}

void Non_AC_Sleeper(char ch)
{
	if(ch=='C')
	{
		printf("Bengaluru->Coorg	Non AC Sleeper		Dates:2/3/4 March	Price:Rs.1100\n");
	}
	else if(ch=='G')
	{
		printf("Bengaluru->Goa		Non AC Sleeper		Dates:1/3/4 March	Price:Rs.2100\n");
	}
	else if(ch=='H')
	{
		printf("Bengaluru->Hubli	Non AC Sleeper		Dates:1/5/6 March	Price:Rs.1000\n");
	}
	else
	{
		printf("Bengaluru->Udupi	Non AC Sleeper		Dates:2/6/7 March	Price:Rs.1000\n");
	}
}

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

void Non_AC_Seater(char ch)
{
	if(ch=='C')
	{
		printf("Bengaluru->Coorg	Non AC Seater		Dates:2/3/4 March	Price:Rs.800\n");
	}
	else if(ch=='G')
	{
		printf("Bengaluru->Goa		Non AC Seater		Dates:1/3/4 March	Price:Rs.1500\n");
	}
	else if(ch=='H')
	{
		printf("Bengaluru->Hubli	Non AC Seater		Dates:1/4/6 March	Price:Rs.850\n");
	}
	else
	{
		printf("Bengaluru->Udupi	Non AC Seater		Dates:2/4/7 March	Price:Rs.850\n");
	}
}
	
void AC_Sleeper_Booking(char *des)
{
	//to handle AC Sleeper Buses
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
					p[current].bustype="AC Sleeper";
					printf("Choose the Day you would like to travel on.\n");
					printf("Available Dates are:");
					for(int i=0;i<3;i++)
					{
						printf("%d/3/23 ",ACS[j][i]);
					}
					printf("\n");
					int s;
					scanf("%d",&s);
					while(true)
					{
						if((s==ACS[j][0])||(s==ACS[j][1])||(s==ACS[j][2]))
						{
							break;
						}
						else
						{
							printf("Please select from mentioned dates.\n");
							printf("Available Dates are:");
							for(int i=0;i<3;i++)
							{
								printf("%d/3/23 ",ACS[j][i]);
							}
							printf("\n");
							scanf("%d",&s);
						}
					}
					int seats_left;
					p[current].date=s;
					if(s==ACS[j][0])
					{
						seats_left=seats_AC_Sleeper[j][0];
					}
					else if(s==ACS[j][1])
					{
						seats_left=seats_AC_Sleeper[j][1];
					}
					else
					{
						seats_left=seats_AC_Sleeper[j][2];
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
					if(s==ACS[j][0])
					{
						seats_AC_Sleeper[j][0]-=tickets;
					}
					else if(s==ACS[j][1])
					{
						seats_AC_Sleeper[j][1]-=tickets;
					}
					else
					{
						seats_AC_Sleeper[j][2]-=tickets;
					}
					char st;
					p[current].num_of_tickets=tickets;
					printf("Please enter the name(s) of the traveler(s) with their preferred seat choice:\n");
					for(int i=0;i<tickets;i++)
					{
						printf("Enter the name of the passenger:\n");
						char names[20];
						scanf("%s",names);
						p[current].passengers[i]=(char *)malloc(strlen(names)+1);
						strcpy(p[current].passengers[i],names);
						while(true)
						{
							if(checkusername(p[current].passengers[i]))
								break;
							else
							{
								printf("Please enter a valid name\n");
								scanf("%s",names);
								p[current].passengers[i]=(char *)malloc(strlen(names)+1);
								strcpy(p[current].passengers[i],names);
							}
						}
							printf("Please enter U for Upper-Berth,L for Lower-Berth\n");
							scanf(" %c",&st);
						while(true)
						{
							if(st=='U')
							{	
								p[current].seattype[i]="Upper Berth";
								break;
							}
							else if(st=='L')
							{
								p[current].seattype[i]="Lower Berth";
								break;
							}
							else
							{
								printf("Please enter U for Upper-Berth,L for Lower-Berth\n");
								scanf(" %c",&st);
							}
						}
					}
					int pr=price_AC_Sleeper[j];
					int tc=pr*tickets;
					int check;
					p[current].cost=tc;
					printf("\nThe total cost of the tickets will be Rs.%d\n",tc);
					printf("Enter any number to proceed to payment\n");
					scanf("%d",&check);
					FILE *ACSLEEPER;
					ACSLEEPER=fopen("ACSleeper.txt","a");
					fprintf(ACSLEEPER,"USERNAME:%s Bangalore->%s DATE:%d/3/23 TICKETS:%d PRICE:Rs.%d  PASSENGERS: ",p[current].name,des,p[current].date,tickets,p[current].cost);	
					for(int i=0;i<tickets;i++)
					{
						fprintf(ACSLEEPER,"%s ",p[current].passengers[i]);
						fprintf(ACSLEEPER,"(%s) ",p[current].seattype[i]);
					}
					fprintf(ACSLEEPER,"\n");
					fclose(ACSLEEPER);	
					transaction(tc);
}

void Non_AC_Sleeper_Booking(char *des)
{
	//to handle NON AC Sleeper Buses
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
					p[current].bustype="NON AC Sleeper";
					printf("Choose the Day you would like to travel on.\n");
					printf("Available Dates are:");
					for(int i=0;i<3;i++)
					{
						printf("%d/3/23 ",NACS[j][i]);
					}
					int s;
					printf("\n");
					scanf("%d",&s);
					while(true)
					{
						if((s==NACS[j][0])||(s==NACS[j][1])||(s==NACS[j][2]))
						{
							break;
						}
						else
						{
							printf("Please select from mentioned dates.\n");
							printf("Available Dates are:");
							for(int i=0;i<3;i++)
							{
								printf("%d/3/23 ",NACS[j][i]);
							}
							printf("\n");
							scanf("%d",&s);
						}
					}
					int seats_left;
					p[current].date=s;
					if(s==NACS[j][0])
					{
						seats_left=seats_Non_AC_Sleeper[j][0];
					}
					else if(s==NACS[j][1])
					{
						seats_left=seats_Non_AC_Sleeper[j][1];
					}
					else
					{
						seats_left=seats_Non_AC_Sleeper[j][2];
					}
					printf("The number of seats available are:%d\n",seats_left);	
					printf("Enter the number of tickets you would like to purchase:\n");
					int tickets;
					char names[20];
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
					if(s==NACS[j][0])
					{
						seats_Non_AC_Sleeper[j][0]-=tickets;
					}
					else if(s==NACS[j][1])
					{
						seats_Non_AC_Sleeper[j][1]-=tickets;
					}
					else
					{
						seats_Non_AC_Sleeper[j][2]-=tickets;
					}
					char st;
					p[current].num_of_tickets=tickets;
					printf("Please enter the name(s) of the traveler(s) with their preferred seat choice:\n");
					for(int i=0;i<tickets;i++)
					{	
						printf("Enter the name of the passenger:\n");
						scanf("%s",names);
						p[current].passengers[i]=(char *)malloc(strlen(names)+1);
						strcpy(p[current].passengers[i],names);
						while(true)
						{
							if(checkusername(p[current].passengers[i]))
								break;
							else
							{
								printf("Please enter a valid name\n");
								scanf("%s",names);
								p[current].passengers[i]=(char *)malloc(strlen(names)+1);
								strcpy(p[current].passengers[i],names);
							}
						}
						printf("Please enter U for Upper-Berth,L for Lower-Berth\n");
						scanf(" %c",&st);
						while(true)
						{
							if(st=='U')
							{	
								p[current].seattype[i]="Upper Berth";
								break;
							}
							else if(st=='L')
							{
								p[current].seattype[i]="Lower Berth";
								break;
							}
							else
							{
								printf("Please enter U for Upper-Berth,L for Lower-Berth\n");
								scanf(" %c",&st);
							}
						}
					}
					int pr=price_Non_AC_Sleeper[j];
					int tc=pr*tickets;
					p[current].cost=tc;
					int check;
					printf("\nThe total cost of the tickets will be Rs.%d\n",tc);
					printf("Enter any number to proceed to payment\n");
					scanf("%d",&check);
					FILE *NONACSLEEPER;
					NONACSLEEPER=fopen("NONACSleeper.txt","a");
					fprintf(NONACSLEEPER,"USERNAME:%s Bangalore->%s DATE:%d/3/23 TICKETS:%d PRICE:Rs.%d  PASSENGERS: ",p[current].name,des,p[current].date,tickets,p[current].cost);	
					for(int i=0;i<tickets;i++)
					{
						fprintf(NONACSLEEPER,"%s ",p[current].passengers[i]);
						fprintf(NONACSLEEPER,"(%s) ",p[current].seattype[i]);
					}
					fprintf(NONACSLEEPER,"\n");
					fclose(NONACSLEEPER);	
					transaction(tc);
}

void AC_Seater_Booking(char *des)
{
	// to handle AC Seater Buses
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
							if(checkusername(p[current].passengers[i]))
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

void Non_AC_Seater_Booking(char *des)
{
	//to handle NON AC Seater Buses
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
					p[current].bustype="NON AC Seater";
					printf("Choose the Day you would like to travel on.\n");
					printf("Available Dates are:");
					for(int i=0;i<3;i++)
					{
						printf("%d/3/23 ",NACSeater[j][i]);
					}
					printf("\n");
					int s;
					scanf("%d",&s);
					while(true)
					{
						if((s==NACSeater[j][0])||(s==NACSeater[j][1])||(s==NACSeater[j][2]))
						{
							break;
						}
						else
						{
							printf("Please select from mentioned dates.\n");
							printf("Available Dates are:");
							for(int i=0;i<3;i++)
							{
								printf("%d/3/23 ",NACSeater[j][i]);
							}
							printf("\n");
							scanf("%d",&s);
						}
					}
					char names[20];
					char st[10];
					int seats_left;
					p[current].date=s;
					if(s==NACSeater[j][0])
					{
						seats_left=seats_Non_AC_Seater[j][0];
					}
					else if(s==NACSeater[j][1])
					{
						seats_left=seats_Non_AC_Seater[j][1];
					}
					else
					{
						seats_left=seats_Non_AC_Seater[j][2];
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
					if(s==NACSeater[j][0])
					{
						seats_Non_AC_Seater[j][0]-=tickets;
					}
					else if(s==NACSeater[j][1])
					{
						seats_Non_AC_Seater[j][1]-=tickets;
					}
					else
					{
						seats_Non_AC_Seater[j][2]-=tickets;
					}
					p[current].num_of_tickets=tickets;
					printf("Please enter the name(s) of the traveler(s):\n");
					for(int i=0;i<tickets;i++)
					{
						printf("Enter the name of the passenger:\n");
						scanf("%s",names);
						p[current].passengers[i]=(char *)malloc(strlen(names)+1);
						strcpy(p[current].passengers[i],names);
						while(true)
						{
							if(checkusername(p[current].passengers[i]))
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
					int pr=price_Non_AC_Seater[j];
					int tc=pr*tickets;
					int check;
					p[current].cost=tc;
					printf("\nThe total cost of the tickets will be Rs.%d\n",tc);
					printf("Enter any number to proceed to payment\n");	
					scanf("%d",&check);
					FILE *NONACSEATER;
					NONACSEATER=fopen("NONACSeater.txt","a");
					fprintf(NONACSEATER,"USERNAME:%s Bangalore->%s DATE:%d/3/23 TICKETS:%d PRICE:Rs.%d  PASSENGERS: ",p[current].name,des,p[current].date,tickets,p[current].cost);	
					for(int i=0;i<tickets;i++)
					{
						fprintf(NONACSEATER,"%s ",p[current].passengers[i]);
					}
					fprintf(NONACSEATER,"\n");
					fclose(NONACSEATER);	
					transaction(tc);
}		

void purchase_tickets()
{
	//for purchasing tickets
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
			
					if(ch=='B')
				{
					Non_AC_Sleeper_Booking(p[current].destination);
					break;
				}
		
				if(ch=='C')
				{
					AC_Seater_Booking(p[current].destination);
					break;
				}
			
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
				
					if(ch=='B')
				{
					Non_AC_Sleeper_Booking(p[current].destination);
					break;
				}
		
				if(ch=='C')
				{
					AC_Seater_Booking(p[current].destination);
					break;
				}
			
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
					if(ch=='B')
				{
					Non_AC_Sleeper_Booking(p[current].destination);
					break;
				}
				if(ch=='C')
				{
					AC_Seater_Booking(p[current].destination);
					break;
				}
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
			}//end of udupi
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

void main()
{
	//program starts from begin()	
	begin();
}	

		
			
	
		
