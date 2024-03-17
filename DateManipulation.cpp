#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
	private:
		int month;
		int day;
		int year;
	public:
		Date();
		Date(int, int, int);
		void setMonth(int);
		void setDay(int);
		void setYear(int);
		void setDate();
		void isLeap(int);
		int daysPassed(int,int,int);
		int remainingDays(int,int,int);
		int daysMonth(int, int);
		int getDay(int, int, int);
};
//Default constructor sets date to 1, 1, 1500.
Date::Date()
{
	month = 1;
	day = 1;
	year = 1500;
}
//Constructor sets month to m,day to d, and year to y.
Date::Date(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}
//Setter for month.
void Date::setMonth(int m)
{
	month = m;
}
//Setter for day.
void Date::setDay(int d)
{
	day = d;
}
//Setter for year.
void Date::setYear(int y)
{
	year = y;
}
//Setter for the date forms.
void Date::setDate()
{
	cout << month << " /" << day << " /" << year << "\n";

	string monthName[] = { "January", "February", "March",
		"April", "May", "June", "July",
		"August", "September", "October",
		"November", "December" };
	cout << monthName[month - 1] << "  " << day << "  " 
		 << year << "\n";
}
//Find if it is a leap year.
void Date::isLeap(int y)
{
	if (year % 100 == 0)
	{
		if (year % 400 == 0)
			cout << year << " is a leap year\n";
	}
	else if (year % 4 == 0)
	{
		cout << year << " is a leap year\n";
	}
	else
	{
		cout << year << " is not a leap year";
	}
}
//Determines how many days a month has
int Date::daysMonth(int m, int y)
{
	//leap year condition, if month is 2
	if (month == 2)
	{
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
			return 29;
		else
			return 28;
	}
	//months which has 31 days
	else if (month == 1 || month == 3 || month == 5 || month == 7 || 
		     month == 8 || month == 10 || month == 12)
		return 31;
	else
		return 30;
}
//It tells you what day of the year
int Date::getDay(int m, int d, int y)
{
	int days = 0;
	for (int i = 1; i < month; i++)
		days += daysMonth(y, m);
	return days + day;
}
//Find how many days are left is the year
int Date::remainingDays(int m, int d, int y)
{	
	int regYear = 0;
	for (int i = 1; i <= 12; i++)
		regYear += daysMonth(y, m);
	cout << "\nThe remaining days of this year are: " << regYear - getDay(m, d, y) << endl;
	return 0;
}
//Finds how many days has pass in the year - current date
int Date::daysPassed(int m, int d, int y)
{
	int totalP = 0;
	for (int i = 1; i < m -  1; i++)
		totalP += daysMonth(y, m);
	cout << totalP + getDay(m, d, y) << " days passed. " << endl;
	return 0;
}

//Main function
int main()
{
	int month;
	int day;
	int year;

	string monthName[] = { "January", "February", "March",
		"April", "May", "June", "July",
		"August", "September", "October",
		"November", "December" };

	cout << "\nPlease enter a month, it must be betwwen 1 - 12 " 
		 << "\n";
	cin >> month;

	//validation for the month
	while (month < 1 || month > 12)
	{
		cout << "\nERROR insert a valid month: \n";
		cin >> month;
	}

	cout << "\nPlease enter a day, it must be between 1 - 31 " 
		 << "\n";
	cin >> day;

	//validation for the day
	while (day < 1 || day > 31)
	{
		cout << "\nERROR insert a valid day: \n";
		cin >> day;
	}

	cout << "\nPlease enter a year, it must be between 1500 - 2050 " 
		 << "\n";
	cin >> year;
	cout << endl;

	//validation for the year
	while (year < 1500 || year > 2050)
	{
		cout << "\nERROR insert a valid year: \n\n";
		cin >> year;
		cout << endl;
	}

	//calls the class and gives perimeters to the functions of
	//that class. 
	Date newDate(month, day, year);
	newDate.setDate();

	Date leap(month,day,year);
	leap.isLeap(year);

	Date remaining(month, day, year);
	remaining.remainingDays(month,day,year);

	Date daysP(month, day, year);
	daysP.daysPassed(month,day,year);

	cin.get();
	return 0;
}
