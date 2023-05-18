#include <iostream>
#include <string>
using namespace std;
class tornadoException
{
    int distance = -1;

public:
    tornadoException() {}

    tornadoException(int m) : distance(m) {}

    string what()
    {
        if (distance == -1)
        {
            return "Tornado: Take cover immediately!";
        }
        else
        {
            return "Tornado: " + to_string(distance) + " miles away; and approaching!";
        }
    }
};

int main()
{
    try
    {
        throw tornadoException();
    }
    catch (tornadoException &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        int distance = 10;
        throw tornadoException(distance);
    }
    catch (tornadoException &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
