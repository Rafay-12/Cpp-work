#include<iostream>
#include "one.h"
using namespace std;

Shape::Shape(double l,double b,double h){
    length = l;
    breadth = b;
    height = h;
}

Painting::Painting (double cost) {
    paintcost = cost;
}

double Painting::getcost (double area) {
    return paintcost * area;
}

Square::Square (double l, double cost) : Shape (l, l, 0), Painting (cost) {}

double Square::getarea () {
    return length * length;
}

Rectangle::Rectangle (double l, double b, double cost) : Shape (l, b, 0), Painting (cost) {}

double Rectangle::getarea () {
    return length * breadth;
}

Triangle::Triangle (double b, double h, double cost) : Shape (0, b, h), Painting (cost) {}

double Triangle::getarea () {
    return 0.5 * breadth * height;
}

int main(){
    double a,b,c;
    cout<<"Enter length of square: ";
    cin>>a;
    cout<<"Enter paint cost of square: ";
    cin>>b;
    Square s(a,b);
    cout<<"Enter length of recatangle: ";
    cin>>a;
    cout<<"Enter breadth of rectangle: ";
    cin>>c;
    cout<<"Enter paint cost of rectangle: ";
    cin>>b;
    Rectangle r(a,c,b);
    cout<<"Enter breadth of triangle: ";
    cin>>a;
    cout<<"Enter height of triangle: ";
    cin>>c;
    cout<<"Enter paint cost of triangle: ";
    cin>>b;
    Triangle t(a,c,b);

    cout << "Square Area: " << s.getarea () << " Cost: $" << s.getcost (s.getarea ()) << endl;
    cout << "Rectangle Area: " << r.getarea () << " Cost: $" << r.getcost (r.getarea ()) << endl;
    cout << "Triangle Area: " << t.getarea () << " Cost: $" << t.getcost (t.getarea ()) << endl;
    system("pause");
    return 0;
}