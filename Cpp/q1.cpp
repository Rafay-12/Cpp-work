#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
private:
    char *str;
    int length; // change "lenght" to "length"
public:
    bool operator!()
    {
        if (*str == '\0')
        {
            return true;
        }
        return false;
    }

    MyString()
    {
        str = new char[1]; // allocate memory for null character
        str[0] = '\0';     // set null character
        length = 1;
    }
    // destructor
    ~MyString()
    {
        delete[] str; // free memory
    }
    // copy constructor
    MyString(const MyString &other)
    {
        length = other.length;
        str = new char[length];
        strcpy(str, other.str);
    }
    // assignment operator
    MyString &operator=(const MyString &other)
    {
        if (this != &other)
        {                 // check for self-assignment
            delete[] str; // free old memory
            length = other.length;
            str = new char[length];
            strcpy(str, other.str);
        }
        return *this;
    }
    // concatenation operator
    MyString operator+(const MyString other)
    {
        MyString result;
        result.length = length + other.length - 1; // subtract 1 to avoid double null character
        delete[] result.str;                       // free old memory
        result.str = new char[result.length];
        strcpy(result.str, str);
        strcat(result.str, other.str);
        return result;
    }
    // less than operator for string comparison based on ascii values
    bool operator<(const MyString other)
    {
        int result = strcmp(str, other.str);
        if (result < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // stream insertion operator for output
    friend ostream &operator<<(ostream &os, const MyString &obj)
    {
        os << obj.str;
        return os;
    }
    // stream extraction operator for input
    friend istream &operator>>(istream &is, MyString &obj)
    {
        char buffer[100];
        is >> buffer;
        obj.str = buffer;
        return is;
    }
    // index operator for accessing individual characters
    char &operator[](const int index)
    {
        return str[index];
    }
    // function call operator for getting a substring
    char *operator()(const int start, const int len)
    {
        char *result = new char[len + 1];  // allocate memory for substring
        strncpy(result, &str[start], len); // copy substring
        result[len] = '\0';                // add null character
        return result;
    }
};

int main()
{
    MyString str1, str2, str3, str4;
    if (!str1)
    {
        cout << "String 1 is Empty.\n";
        cout << "Str 1 = " << str1 << endl
             << endl
             << endl;
    }
    cout << "Enter String 1:\t";
    cin >> str1;
    cout << "Enter String 2:\t";
    cin >> str2;
    cout << "\n\n\nUser Entered:\n";
    cout << "String 1 = " << str1 << endl;
    cout << "String 2 = " << str2 << endl
         << endl
         << endl;
    // What is following code testing?
    cout << "Before str1 = str1; str1 = " << str1 << endl;
    str1 = str1;
    cout << "After str1 = str1, str1 = " << str1 << endl
         << endl
         << endl;
    cout << "Before str4 = str3 = str1+str2\n";
    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;
    cout << "str3 = " << str3 << endl;

    cout << "str4 = " << str4 << endl;
    str4 = str3 = str1 + str2;
    cout << "\n\n\nAfter str4 = str3 = str1+str2\n";
    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;
    cout << "str3 = " << str3 << endl;
    cout << "str4 = " << str4 << endl;
    cout << "\n\n\nEnter String 3:\t";
    cin >> str3;
    cout << "\n\n\nEnter String 4:\t";
    cin >> str4;
    cout << "\n\n\nstr3 = " << str3 << endl;
    cout << "str4 = " << str4 << endl;
    if (str3 < str4)
        cout << "String 3 is Less than String 4.\n";
    else
        cout << "String 3 is NOT Less than String 4.\n";
    MyString str5 = str1 + str2;
    cout << "\n\n\nStr5:\t" << str5 << endl;
    cout << "Str5[7]:\t" << str5[7] << endl; // Function Call: str5.operator[](7).
    str5[7] = '$';
    cout << "\n\nStr5:\t" << str5 << endl;
    cout << "\n\n\nstr5(5, 10):\t" << str5(5, 10) << endl;
    return 0;
}