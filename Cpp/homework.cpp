#include <iostream>
using namespace std;
class parent
{
public:
    parent()
    {
        cout << "parent constructor\n";
    }
    ~parent()
    {
        cout << "parent destructor\n";
    }
    virtual void display()
    {
        cout << "dispaly inside parent\n";
    }
};
class child : public parent
{
public:
    child()
    {
        cout << "child constructor\n";
    }
    ~child()
    {
        cout << "child destructor\n";
    }
    void display()
    {
        cout << "display inside class\n";
    }
};
void func(parent &obj)
{
    obj.display();
}
void func1(parent obj)
{
    obj.display();
}
int main()
{
    child c;
    func(c);
    func1(c);
    return 0;
}