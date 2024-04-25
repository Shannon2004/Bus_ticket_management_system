CC=gcc

OBJS=begin.o create_account.o login.o home_page.o view_booking.o check_password.o check_username.o check_phonenumber.o cancel_booking.o transaction.o AC_Sleeper.o Non_AC_Sleeper.o AC_Seater.o Non_AC_Seater.o AC_Sleeper_Booking.o Non_AC_Sleeper_Booking.o AC_Seater_Booking.o Non_AC_Seater_Booking.o valid_cvv.o valid_credit_card_no.o

EXECS=bustlers

bustlers: begin.o create_account.o login.o home_page.o view_booking.o check_password.o check_username.o check_phonenumber.o cancel_booking.o transaction.o AC_Sleeper.o Non_AC_Sleeper.o AC_Seater.o Non_AC_Seater.o AC_Sleeper_Booking.o Non_AC_Sleeper_Booking.o AC_Seater_Booking.o Non_AC_Seater_Booking.o valid_cvv.o valid_credit_card_no.o
	gcc global.o begin.o create_account.o login.o home_page.o view_booking.o check_password.o check_username.o check_phonenumber.o cancel_booking.o transaction.o AC_Sleeper.o Non_AC_Sleeper.o AC_Seater.o Non_AC_Seater.o AC_Sleeper_Booking.o Non_AC_Sleeper_Booking.o AC_Seater_Booking.o Non_AC_Seater_Booking.o valid_cvv.o valid_credit_card_no.o -o bustlers

global.o: global.c
	gcc -c global.c
begin.o: begin.c
	gcc -c begin.c 
create_account.o: create_account.c 
	gcc -c create_account.c 
login.o: login.c
	gcc -c login.c
home_page.o: home_page.c
	gcc -c home_page.c
view_booking.o: view_booking.c
	gcc -c view_booking.c
check_password.o: check_password.c
	gcc -c check_password.c
check_username.o: check_username.c
	gcc -c check_username.c
check_phonenumber.o: check_phonenumber.c
	gcc -c check_phonenumber.c
cancel_booking.o: cancel_booking.c
	gcc -c cancel_booking.c
transaction.o: transaction.c
	gcc -c transaction.c
AC_Sleeper.o: AC_Sleeper.c
	gcc -c AC_Sleeper.c
Non_AC_Sleeper.o: Non_AC_Sleeper.c
	gcc -c Non_AC_Sleeper.c
AC_Seater.o: AC_Seater.c
	gcc -c AC_Seater.c
Non_AC_Seater.o: Non_AC_Seater.c
	gcc -c Non_AC_Seater.c
AC_Sleeper_Booking.o: AC_Sleeper_Booking.c
	gcc -c AC_Sleeper_Booking.c
Non_AC_Sleeper_Booking.o: Non_AC_Sleeper_Booking.c
	gcc -c Non_AC_Sleeper_Booking.c
AC_Seater_Booking.o: AC_Seater_Booking.c
	gcc -c AC_Seater_Booking.c
Non_AC_Seater_Booking.o: Non_AC_Seater_Booking.c
	gcc -c Non_AC_Seater_Booking.c
valid_cvv.o: valid_cvv.c
	gcc -c valid_cvv.c
valid_credit_card_no.o: valid_credit_card_no.c
	gcc -c valid_credit_card_no.c

