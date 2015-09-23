// tst1.cpp: главный файл проекта.


#include "iostream"
using namespace System;
using namespace std;

const double PI = 3.14159265;
class Shape
{
protected : 
	double area;
public :
	void print_Area() const;
};
void Shape::print_Area()const{ cout << area << endl; }
class Triangle : public Shape
{
private:
	double base, height;
public :
Triangle ( double, double);
};
Triangle::Triangle(double b, double h) : base(b), height(h)
{ area = 0.5 * b * h ; }
class Circle : public Shape
{
private :
	double radius;
public:
	Circle(double);
};
Circle::Circle(double r):radius(r) { area = PI * radius*radius ;}
	
int main(array<System::String ^> ^args)
{
	int n ;
    Console::WriteLine(L"Здравствуй, мир!");
	Triangle t(2.5, 6.0);
	Circle r(3.5);
	r.print_Area();
	//Console::ReadLine();
	system("pause");
    return 0;
}
