#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class invalidDay
{
    int day;
public:
    invalidDay(int day) : day(day) {}

    string what() const
    {
        return "Invalid day: " + to_string(day);
    }    
};

class invalidMonth
{
    int month;
public:
    invalidMonth(int month) : month(month) {}

    string what() const
    {
        return "Invalid month: " + to_string(month);
    }    
};

class invalidYear
{
    int year;
public:
    invalidYear(int year) : year(year) {}

    string what() const
    {
        return "Invalid year: " + to_string(year);
    }
};

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

string getMonthName(int month)
{
    string monthNames[] = {"January", "February", "March", "April", "May", "June",
                           "July", "August", "September", "October", "November", "December"};

    return monthNames[month - 1];
}

void printDateOfBirth(const string &dateOfBirth)
{
    int month, day, year;
    char discard;
    istringstream iss(dateOfBirth);

    if (!(iss >> month >> discard >> day >> discard >> year))
    {

        cout << "Invalid date format. Please enter the date in numeric form such as MM-DD-YYYY. " << endl;
        return;
    }

    try
    {
        if (month < 1 || month > 12)
        {
            throw invalidMonth(month);
        }

        if (day < 1 || day > 31)
        {
            throw invalidDay(day);
        }

        if (year < 1 || year > 2023)
        {
            throw invalidYear(year);
        }

        if (month == 2 && day > 28)
        {
            if (!isLeapYear(year))
            {
                throw invalidDay(day);
            }
            else if (isLeapYear(year) && day>29)
            {
                throw invalidDay(day);
            }
            
        }

        else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        {
            throw invalidDay(day);
        }

        string monthName = getMonthName(month);
        cout << monthName << " " << day << ", " << year << endl;
    }
    catch (const invalidDay &e)
    {
        cout << "Error: " << e.what() << ". Please enter a valid day." << endl;
    }
    catch (const invalidMonth &e)
    {
        cout << "Error: " << e.what() << ". Please enter a valid month." << endl;
    }
    catch (const invalidYear &e)
    {
        cout << "Error: " << e.what() << ". Please enter a valid year." << endl;
    }
}

int main()
{
    string dateOfBirth;

    cout << "Enter a date of birth (numeric form, MM-DD-YYYY): ";
    cin >> dateOfBirth;

    printDateOfBirth(dateOfBirth);

    return 0;
}
