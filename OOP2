// tst1.cpp: главный файл проекта.


#include "iostream"
using namespace System;
using namespace std;

const double PI = 3.14159265;
class Shape
{
public :
virtual double Calculate_Area()const =0;	
};

class Triangle : public Shape
{
private:
	double base, height;
public :
Triangle ( double, double);
double Calculate_Area() const;
};

Triangle::Triangle(double b, double h) : base(b), height(h)
{  }
double Triangle::Calculate_Area() const {return 0.5*base*height;}
class Circle : public Shape
{
private :
	double radius;
public:
	Circle(double);
double Calculate_Area() const;
};
Circle::Circle(double r):radius(r) { }
double Circle::Calculate_Area() const {return PI*radius*radius;}
	
int main()
{
	int n ;
   
	Shape *s;
	Circle c(5);
	Triangle t(3,8);
	s = &c;
	cout << "s->Calculate_Area" << s->Calculate_Area()<< endl;  
	s = &t;
	cout << s->Calculate_Area() << endl;
	system("pause");
	return 0;
}
