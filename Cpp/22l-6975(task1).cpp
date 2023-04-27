#include <iostream>
#include <string>
using namespace std;
class str
{
    string a;

public:
    str()
    {
        cout << "Enter the string :" << endl;
        getline(cin, a);
        cout << endl;
    }
    void print()
    {
        cout << a << endl;
    }
    friend bool operator==(const str &obj, const str &obj1)
    {
        if (obj.a == obj1.a)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    str s1;
    str s2;
    cout << "String 1:  ";
    s1.print();
    cout << "String 2:  ";
    s2.print();
    int s = (s1 == s2);
    if (s == 1)
    {
        cout << "Both Strings are equal:" << endl;
    }
    else
    {
        cout << "Both strings are not equal:" << endl;
    }

    system("pause");
}
