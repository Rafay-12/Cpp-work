#include <iostream>
using namespace std;
class A;
class B
{
    int number2;

public:
    B(int l = 0)
    {
        number2 = l;
    }
    friend int sum(const A &S, const B &S1);
};
class A
{
    int number1;

public:
    A(int l = 0)
    {
        number1 = l;
    }
    friend int sum(const A &S, const B &S1);
};
int sum(const A& S, const B &S1)
{
    return S.number1 + S1.number2;
}
int main(){
    A s(10);
    B In(10);
    cout<<"Sum is "<<sum(s,In);
    return 0;
}
