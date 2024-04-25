
#include<stdbool.h>

void purchase_tickets();
void begin();
void create_account();
void login();
void home_page();
void view_booking();
bool check_password(char *pass);
int check_username(char *name);
int check_phonenumber(char *phone);
void cancel_booking();
void transaction(int price);
void AC_Sleeper(char ch);
void Non_AC_Sleeper(char ch);
void AC_Seater(char ch);
void Non_AC_Seater(char ch);
void AC_Sleeper_Booking(char *des);
void Non_AC_Sleeper_Booking(char *des);
void AC_Seater_Booking(char *des);
void Non_AC_Seater_Booking(char *des);
void AC_Seater_Booking(char *des);
int valid_cvv(char cvv[]);
int valid_credit_card_no(char crno[]);


extern struct customer p[10];
extern int c, current, total, i;

extern int ACS[4][3];
extern int NACS[4][3];
extern int ACSeater[4][3];
extern int NACSeater[4][3];
extern int price_AC_Sleeper[4];
extern int price_Non_AC_Sleeper[4];
extern int price_AC_Seater[4];
extern int price_Non_AC_Seater[4];
extern int seats_AC_Sleeper[4][3];
extern int seats_Non_AC_Sleeper[4][3];
extern int seats_AC_Seater[4][3];
extern int seats_Non_AC_Seater[4][3];


