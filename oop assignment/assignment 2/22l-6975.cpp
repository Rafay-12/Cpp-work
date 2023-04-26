#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
private:
    char *str;
    int length;

    void GetStringFromBuffer(const char *buffer)
    {
        length = strlen(buffer) + 1;
        str = new char[length];
        strcpy(str, buffer);
    }

    void Concatenate(const char *str1, const char *str2)
    {
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        length = len1 + len2 + 1;
        str = new char[length];
        strcpy(str, str1);
        strcat(str, str2);
    }

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
        length = 1;
        str = new char[length];
        str[0] = '\0';
    }

    MyString(const MyString &other)
    {
        length = other.length;
        str = new char[length];
        strcpy(str, other.str);
    }

    MyString operator+(const MyString rhs)
    {
        MyString result;
        result.Concatenate(str, rhs.str);
        return result;
    }

    MyString &operator=(const MyString &rhs)
    {
        if (this != &rhs)
        {
            delete[] str;
            GetStringFromBuffer(rhs.str);
        }
        return *this;
    }

    bool operator<(MyString rhs)
    {
        return strcmp(str, rhs.str) < 0;
    }

    char &operator[](const int index)
    {
        return str[index];
    }

    char *operator()(const int start, const int len)
    {
        char *result = new char[len + 1]; 
        strncpy(result, &str[start], len); 
        result[len] = '\0';
        return result;
    }

    friend ostream &operator<<(ostream &os, const MyString &myString);
    friend istream &operator>>(istream &is, MyString &myString);

    ~MyString()
    {
        delete[] str;
    }
};

ostream &operator<<(ostream &os, const MyString &myString)
{
    os << myString.str;
    return os;
}

istream &operator>>(istream &is, MyString &myString)
{
    char buffer[1024];
    is >> buffer;
    myString.GetStringFromBuffer(buffer);
    return is;
}

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