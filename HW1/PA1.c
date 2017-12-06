//PA1.c -- Niko Gamarra
#include <stdio.h>
#include <math.h>
int getStartingDay(int);
int isLeapYear(int);
void printCalendar(int, int);
int printMonth(int, int, int);
int printMonthName(int, int);
void printDayHeading(void);
int main(void){
	//set up variables
	int year=2017;
	int startingDay = 0;
	//prompt user for input
	printf("Calandar\n");
	printf("Enter Year: ");
	scanf("%d", &year);
	//calculate result
	startingDay=getStartingDay(year);
	//display result
	printf("  -- %d Calandar --\n\n",year);
	printCalendar(year, startingDay);
	return 0;
}//int main(void)
int getStartingDay(int year){
	int startingDay=0;
	int totalDays;
	if(year>2017){//chose 2017 as test year because it starts on a sunday or 0th day of week.
		for(int i = year; i>2017; i--){
			if(isLeapYear(year)){
				totalDays+=366;
			}else{
				totalDays+=365;
			}
			//loop invariant: at this point the sum of total days is equal to the sum of all days between year i and the given year.
		}
	}else{
		for(int i = year; i<2017; i++){
			if(isLeapYear(year)){
				totalDays+=366;
			}else{
				totalDays+=365;
			}
			//loop invariant: at this point the sum of total days is equal to the sum of all days between i and the given year.
		}
	}
	startingDay = totalDays % 7;
	return startingDay;
}//getStartingDay
int isLeapYear(int year){
	if ( year%400 == 0)
		return 1;
	else if ( year%100 == 0)
		return 0;
	else if ( year%4 == 0 )
		return 1;
	else
		return 0;
}//bool isLeapYear
void printCalendar(int year, int startingDay){
	int day = startingDay;
	for(int month = 1; month<=12; month++){
		day=printMonth(year, month, day);
		//loop invariant: at this point the day is equal to the most reciently printed day in that month.  
	}
}//void printCalendar
int printMonth(int year, int month, int day){
	int dayOfWeek=day;
	int daysInMonth =  printMonthName(year, month);
	printDayHeading();
	for(int blanks=0; blanks<dayOfWeek; blanks++){
		printf("     ");
		//loop invariant: at this point the number of spaces printed is approaching or equal to the number of blanks required to reach starting day.
	}
	for(int days=1; days<=daysInMonth; days++){
		printf("%*d",3,days);
		printf("  ");
		if(dayOfWeek<6){
			dayOfWeek++;
		}else{
			dayOfWeek=0;
			printf("\n");
		}
		//loop invariant: at this point the days printed is approaching or equal to the number of days in the particular month.
	}
	printf("\n\n");
	return dayOfWeek;
}//void printMonth
void printDayHeading(){
	printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
}
int printMonthName(int year, int month){
	int daysInMonth=0;
	switch(month){
		case 1:
			printf("January %d\n", year);
			daysInMonth=31;
			break;
		case 2:
			printf("Febuary %d\n", year);
			if(isLeapYear(year)){
				daysInMonth=29;
			}else{
				daysInMonth=28;
			}
			break;
		case 3:
			printf("March %d\n", year);
			daysInMonth=31;
			break;
		case 4:
			printf("April %d\n", year);
			daysInMonth=30;
			break;
		case 5:
			printf("May %d\n", year);
			daysInMonth=31;
			break;
		case 6:
			printf("June %d\n", year);
			daysInMonth=30;
			break;
		case 7:
			printf("July %d\n", year);
			daysInMonth=31;
			break;
		case 8:
			printf("August %d\n", year);
			daysInMonth=31;
			break;
		case 9:
			printf("September %d\n", year);
			daysInMonth=30;
			break;
		case 10:
			printf("October %d\n", year);
			daysInMonth=31;
			break;
		case 11:
			printf("November %d\n", year);
			daysInMonth=30;
			break;
		case 12:
			printf("December %d\n", year);
			daysInMonth=31;
	}
	return daysInMonth;
}//void printMonthName
