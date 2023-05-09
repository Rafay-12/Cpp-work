#include<iostream>
using namespace std;
class Faculty
{
public:
	 virtual void print(){
		cout << "Faculty";
	}
};

class Administrator : public virtual Faculty{
public:
	void print(){
		cout << "Administrator";
	}
};

class Teacher :  public virtual Faculty{
public:
	void print(){
		cout << "Teacher";
	}
};
class AdministratorTeacher : public Administrator, public Teacher{
public:
	void print(){
		Teacher::print();
	}
};

int main(){
	Administrator f1;
	Teacher f2;
	AdministratorTeacher f3;
	Faculty* fac[3];
	fac[0] = &f1;
	fac[1] = &f2;
	fac[2] = &f3;
	for (int i = 0; i < 3; i++)
	{
		fac[i]->print();
		cout << endl;
	}
	system("pause");
	return 0;
}