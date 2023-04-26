#include<iostream>
#include<string>
using namespace std;
class Person{
protected:
	string fname;
	string lname;
	int id;
	int age;
public:
	Person(int ID, string firstname, string lastname, int Age): fname(firstname), id(ID), lname(lastname), age(Age){
		cout << "In Constructor of class person"<<endl;
	}
	~Person(){
		cout << "In destructor of class person"<<endl;
	}
	void print(){
		cout << "Name: "<<fname<<" "<< lname<< endl;
	}
};
class Student : public Person{
protected:
	float cgpa;
	string rollNumber;
public:
	Student(int id, string fname, string lname, int age, string rollNumber, float cgpa) : Person(id, fname, lname, age){
		this->cgpa = cgpa;
		this->rollNumber = rollNumber;
		cout << "In Constructor of class student"<<endl;
	}
	~Student(){
		cout << "In destructor of class sudent"<<endl;
	}
	virtual void print(){
		cout << fname << " " << lname << " is " << age << "years old,his cgpa is " << cgpa<<endl;
	}
	virtual void input(){
	}
};
class Undergraduate : public Student{
	string Fyp_name;
public:
	Undergraduate(int id, string fname, string lname, int age, string rollNumber, float cgpa, string fyp_name) :Student(id, fname, lname, age, rollNumber, cgpa), Fyp_name(fyp_name){
		cout << "In Constructor of class Undergraduate"<<endl;
	}
	~Undergraduate(){
		cout << "In destructor of class Undergraduate"<<endl;
	}
	void print(){
		cout << fname << " " << lname << " is an undergradute student, his cgp is "<< cgpa << " and his final year project is "<<Fyp_name<<endl;
	}
	void input(){
		cout << "enter Final year project: ";
		getline(cin, Fyp_name);
	}
};
class Graduate : public Student{
	string thesis;
	string supervisor;
public:
	Graduate(int id, string fname, string lname, int age, string rollNumber, float cgpa,string thesis, string supervisor) :Student(id, fname, lname, age, rollNumber, cgpa),thesis(thesis),supervisor(supervisor){
		cout << "In Constructor of class graduate"<<endl;
	}
	~Graduate(){
		cout << "In destructor of class graduate"<<endl;
	}
	void print(){
		cout << fname << " " << lname << " is a graduate student, his cgpa is "<< cgpa << " and his thesis topic is " << thesis << " under supervision of " << supervisor<<endl;
	}
	void input(){
		cout << "enter thesis topic: ";
		getline(cin, thesis);
		cout << "Enter Spervisor name: ";
		getline(cin, supervisor);
	}
};
int main(){
	Student * s = new Undergraduate(1, "Ted", "Thompson", 22,"14L - 4171", 3.91, "The Event Locator");
	Student * s2 = new Graduate(2, "Arnold", "Gates", 25, "17L - 6171", 3.01, "Distributed Algorithms","Kashif Zafar");
	s->print();
	s->input();
	s2->print();
	s2->print();
	s->print();
	s2->print();
	system("pause");
	return 0;
}