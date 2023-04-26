#include <iostream>
using namespace std;
class Time
{
	int hr;
	int min;

public:
	Time();
	Time(int, int);
	void setTime(int, int);
	void getTime(int &, int &);
	void printTime();
	void incrementHours();
	void incrementMinutes();
};

class Date
{
	int month;
	int day;
	int year;

public:
	Date();
	Date(int, int, int);
	void setDate(int, int, int);
	void getDate(int &, int &, int &);
	void printDate();
};

class Event
{
	string eventName;
	Time eventTime;
	Date eventDay;

public:
	Event(int hours = 0, int minutes = 0, int m = 1, int d = 1, int y = 1900, string name = "Christmas");
	void setEventData(int, int, int, int, int, string name);
	void printEventData();
};

int main()
{
	// instantiate an object and set data for Christmas
	Event object;
	object.setEventData(6, 0, 12, 25, 2010, "Christmas");
	// print out the data for object
	cout<<"\n\t\t"<<"Event data of first object: "<<endl;
	object.printEventData();
	// instantiate the second object and set date for the fourth of July
	Event object2;
	object2.setEventData(1, 15, 7, 4, 2010, "Fourth of July");
	// print out the data for the second object
	cout<<"\n\t\t"<<"Event data of second object: "<<endl;
	object2.printEventData();
	cout<<"\n\n";
	system("pause");
	return 0;
}

Time::Time()
{
	hr = 0;
	min = 0;
}

Time::Time(int a, int b)
{
	hr = a;
	min = b;
}

void Time::setTime(int a, int b)
{
	hr = a;
	min = b;
}

void Time::getTime(int &a, int &b)
{
	a = hr;
	b = min;
}

void Time::printTime()
{
	cout << hr << ":" << min << endl;
}

void Time::incrementHours()
{
	hr++;
}

void Time::incrementMinutes()
{
	min++;
}

Date::Date()
{
	month = 0;
	day = 0;
	year = 0;
}

Date::Date(int a, int b, int c)
{
	month = a;
	day = b;
	year = c;
}

void Date::setDate(int a, int b, int c)
{
	month = a;
	day = b;
	year = c;
}

void Date::getDate(int &a, int &b, int &c)
{
	a = month;
	b = day;
	c = year;
}

void Date::printDate()
{
	cout << day << "-" << month << "-" << year << endl;
}

Event::Event(int hours, int minutes, int m, int d, int y, string name)
{
	eventTime.setTime(hours, minutes);
	eventDay.setDate(m, d, y);
	eventName = name;
}
void Event::setEventData(int hours, int minutes, int m, int d, int y, string name)
{
	eventTime.setTime(hours, minutes);
	eventDay.setDate(m, d, y);
	eventName = name;
}

void Event::printEventData()
{
	cout << "Event time: ";
	eventTime.printTime();
	cout << "Event date: ";
	eventDay.printDate();
	cout << eventName <<endl;
}