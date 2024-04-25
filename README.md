Bus-Ticket management system

How to run the program?
Store all the files of the program in a folder
Open the linux terminal to the folder
Enter the following commands
"make bustlers"
"./bustlers"
If this doesn't work, compile "bustlers.c" and run the program

Project Description
The project is a bus ticketing software. It has the following capabilities.
User can:
1.Create a booking:The user can book buses to different routes on different types of buses depending on his convinience
2.View a booking: The user can view his booking
3.Cancel his booking:The user can cancel his booking
The program uses many concepts of the C-programming language such as structures, file input/output, arrays, pointers, dynamic-memory allocation
to name a few.
The work among the functions is divided among many functions each called as and when required.

How the project works?
The main() calls the begin() function. The function asks the user to create
an account by entering 1 or login into his/her account by entering 2, if
the account exists. On entering 1, the create_account() fucntion is called.
The create account function asks the user, username,phone-number, and
create a password. It also validates if the inputs are in their proper format
If 2 is entered,the login() function is called. The login() function asks the
user to enter username and password. If the username and password are 
matched, it calls the home_page() function.If there is no match, then it
prompts the user to retry. In the home_page() function it asks the user
what he wants to do, i.e. whether to buy tickets,view last booking, or cancel
ticket and logout. If he chooses to buy a ticket, then the purchase_tickets()
function, if he chooses to view his last booking then view_booking() function
is called, if he chooses to cancel a booking then cancel_booking() is called.
If any other input is chosen then, again begin() function is called.

If purchase_tickets() is chosen, the user has to enter his destination, type
of bus. Depending on that he has to enter the date he wants to travel from
the dates available. He then has to enter the number of tickets he wants to book.
He has to enter the names of the passengers.The user also has to specify seat selection i.e. Upper
berth of lower berth.The user is then taken to the payment and a ticket is printed

If view_booking() is chosen, then first it is checked whether there are a valid
number of tickets. If there are none, the user is prompted. If there are 
the user is shown his travel details

If cancel_booking() is chosen, then it is seen as to whether there are any tickets
to cancel. If there are none the user is prompted to that effect. If there are 
then user is asked for confirmation to cancel the ticket and upon confirmation
the ticket is cancelled. Refund is processed. The user can go back to home page
whenever he wants.

CONTRIBUTIONS
Aayush Bhargav: purchase_tickets(), AC_Sleeper_Booking(), Non_AC_Sleeper_Booking(), AC_Seater_Booking, Non_AC_Seater_Booking()
Praveen Peter Jay: begin(), create_account(), login(), home_page(), check_password()
Shannon Muthanna: check_username(), check_phone_number(), valid_cvv(), valid_credit_card_no(), transaction()
Pranav Kulkarni: view_booking(), cancel_booking(), structure creation, README
Aryan Singhal: AC_Sleeper(), Non_AC_Sleeper(), AC_Seater(), Non_AC_Seater()
Madhav Sanjay Patil: Modularization, Global Variables Declaration, Comments, Makefile
