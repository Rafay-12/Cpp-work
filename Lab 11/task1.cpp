#include <iostream>
using namespace std;
template <class T>
void performOperation(T a, T b, T op)
{
    if (op == '+')
    {
        cout << "Sum is " << a + b << endl;
    }
    else if (op == '-')
    {
        cout << "differnce is " << a - b << endl;
    }
    else if (op == '/')
    {
        cout << "division is " << (float)a / b << endl;
    }
    else if (op == '*')
    {
        cout << "Multiplication is: " << a * b << endl;
    }
}

int main()
{
    int a, b; // this can be float, int or double too
    char op;
    cout << "Enter first operand: ";
    cin >> a;
    cout << "Enter second operand: ";
    cin >> b;
    cout << "Enter operation: ";
    cin >> op; // op can be +, -, * or /
    if (op == '+' || op == '-' || op == '/' || op == '*')
    {
        performOperation<int>(a, b, op);
    }
    else
    {
        cout << "Wrong operation" << endl;
    }
    system("pause");
    return 0;
}