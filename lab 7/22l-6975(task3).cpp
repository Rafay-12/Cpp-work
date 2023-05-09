#include <iostream>
using namespace std;
class A
{
    int number1;

public:
    A(int l = 0)
    {
        number1 = l;
    }
    friend class C;
};
class C
{
    int number3;

public:
    C(int l = 0)
    {
        number3 = l;
    }
    void ADD(const A& s, const C& s1){
        cout<<"Sum is "<<s1.number3 + s.number1;
    };
};
int main(){
    A s(10);
    C In(10);
    In.ADD(s,In);
    return 0;
}