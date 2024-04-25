#include "library.h"

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

struct customer p[10];
int c, current=0, total=0, i=0;

int ACS[4][3]={1,3,4,2,3,4,1,5,6,2,6,7};
int NACS[4][3]={2,3,4,1,3,4,1,5,6,2,6,7};
int ACSeater[4][3]={1,3,5,2,3,4,1,2,6,2,6,7};
int NACSeater[4][3]={2,3,4,1,3,4,1,4,6,2,4,7};
int price_AC_Sleeper[4]={1500,2500,1300,1500};
int price_Non_AC_Sleeper[4]={1100,2100,1000,1000};
int price_AC_Seater[4]={900,1700,900,900};
int price_Non_AC_Seater[4]={800,1500,850,850};
int seats_AC_Sleeper[4][3]={20,20,20,20,20,20,20,20,20,20,20,20};
int seats_Non_AC_Sleeper[4][3]={20,20,20,20,20,20,20,20,20,20,20,20};
int seats_AC_Seater[4][3]={20,20,20,20,20,20,20,20,20,20,20,20};
int seats_Non_AC_Seater[4][3]={20,20,20,20,20,20,20,20,20,20,20,20};

