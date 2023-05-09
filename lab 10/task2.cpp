#include<iostream>
using namespace std;
class BasicShape{
	double area;
public:
	double getarea(){
		return area;
	}
	void setarea(double a){
		area = a;
	}
	virtual void calcArea() = 0;
};
class Circle : public BasicShape{
	long int centreX;
	long int centreY;
	double radius;
public:
	Circle(long int X = 0,long int Y = 0, double r = 0){
		centreX = X;
		centreY = Y;
		radius = r;

	}
	long int getCentreX(){
		return centreX;
	}
	long int getCentreY(){
		return centreY;
	}
	void calcArea(){
		double area =  3.141159 * radius * radius;
		setarea(area);
	}
};
class Rectangle : public BasicShape{
	long int width;
	long int length;
public:
	Rectangle(long int w = 0,long int l = 0){
		width = w;
		length = l;
	}
	long int getWidth(){
		return width;
	}
	long int getLength(){
		return length;
	}
	void calcArea(){
		double area = length * width;	
		setarea(area);
	}
};
int main(){
	Circle C(3, 4, 2);
	Rectangle R(3, 4);
	cout<<"X of circle is "<<C.getCentreX()<<endl;
	cout << "Y of circle is " << C.getCentreY() << endl;
	C.calcArea();
	cout << "Area of Circle is " << C.getarea() << endl;
	cout << "Length of Rectangle is " << R.getLength() << endl;
	cout << "Width of Rectangle is " << R.getWidth() << endl;
	R.calcArea();
	cout <<"Area of rectangle is "<< R.getarea() << endl;
	system("pause");
	return 0;
}