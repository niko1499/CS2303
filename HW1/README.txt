Write a document called README.txt , README.doc , or README.docx summarizing your pro-
gram, how to run it, and detailing any problems that you had. Also, if you borrowed all or part of the
algorithm for this assignment, be sure to cite your

README for PA1.c by Niko Gamarra 1/19/17

My entire program was origional. 

I did not have any major porblems on thsi assignment. My first compile had many errors and 
warnings but I fixed each one on my first try. 

To run my program simply run the exicutable .out file in the folder after compiling atleast once. 

My program has the 3 main required functions: printCalendar, printMonth, printMonthName, and main.
I altered the number of arguements for the printMonth() function because I though it was more 
elegant to have it supplied with the number of days in that particular month. The number of days
in the month is determined in the switch case for the printMonthName function and then passed on 
print month. 

The main method only gets user input and calls helper functions.

I also added several helper functins: printDayHeading() which simply prints the 
spaced day names, isLeapYear() a funchton that returns 1 or 0 depending on the year inputed,
getStartingDay() which returns the of the weak a year starts on.

In sequence sudo code for the program:
requests user for year
	calls getStartingDay(year)
		calls isLeapYear(year)
	returns startingDay
prints the calandar title
calls printCalendar(year,startingDay)
		loops through months calling
			daysInMonth=PrintMonthName(year,month)//return daysInMonth to know when to quit loop 
			printDayHeading()
			day=printMonth(year,month,day)//where day is the day of the week
				returns day for recursive position tracking

Here are all my loop invariants:
//loop invariant: at this point the sum of total days is equal to the sum of all days between i and the given year.
//loop invariant: at this point the sum of total days is equal to the sum of all days between i and the given year.
//loop invariant: at this point the day is equal to the most reciently printed day in that month.  
//loop invariant: at this point the number of spaces printed is approaching or equal to the number of blanks required to reach starting day.
//loop invariant: at this point the days printed is approaching or equal to the number of days in the particular month.


