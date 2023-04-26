#ifndef one_h
#define one_h
class Shape{
    protected:
    double length,breadth,height;
    public:
    Shape(double l,double b,double h);
};
class Painting{
    protected:
    double paintcost;
    public:
    Painting(double cost);
    double getcost(double area);
};
class Square:public Shape, public Painting{
    public:
    Square(double l,double cost);
    double getarea();
};
class Triangle:public Shape, public Painting{
    public:
    Triangle(double b,double h,double cost);
    double getarea();
};
class Rectangle:public Shape, public Painting{
    public:
    Rectangle(double l,double b, double cost);
    double getarea();
};
#endif