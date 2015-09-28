//Для создания классов Rectangle & Square используются наследование и делегирование конструкторов 
//из стандарта C++11

#include "stdafx.h"
#include "iostream"
//using namespace system; //почему-то отказывается работать пространство имен
using namespace std;

const double PI = 3.14159265;
class Shape //класс площадь для распечатки площади, ваш к.о.
{
protected:
	double area;
public:
	void print_Area() const;
};
void Shape::print_Area()const { cout << area << endl; }

class Triangle : public Shape //класс Треугольник
{
private:
	double base, height;
public:
	Triangle(double, double);
};
Triangle::Triangle(double b, double h) : base(b), height(h)
{
	area = 0.5 * b * h;
}

class Circle : public Shape //класс Круг
{
private:
	double radius;
public:
	Circle(double);
};
Circle::Circle(double r) :radius(r) { area = PI * radius*radius; }

class Rectangle : public Shape //класс Прямоугольник, здесь начинаются танцы с бубном (интереса ради)
{
protected:  //протектед делаю для класса Квадрат, чтобы тот брал данные heigh и lenght отсюда
	double heigh;  
	double lenght;
public:
	
	Rectangle(double, double);   //конструктор при двух различных высот и длин
	Rectangle(double);  //конструктор, для одинаковых высоты и длины (он же квадрат),
	                    //создан для делегирования конструктора
};
Rectangle::Rectangle(double h, double l) : heigh(h), lenght(l) {
	area = heigh * lenght;
}
Rectangle::Rectangle(double h) : Rectangle(h, h) {}; //делегирование конструктора собственной персоной

class Square : public Rectangle //ну и класс Квадрат с наследуемым конструктором от Прямоугольника
                                //и никаких конструкторов по умолчанию в Прямоугольнике
{
public:
		using Rectangle::Rectangle;   // начинаем наследование констурктора, используем класс Прямоугольник для создания
		Square(double h) : Rectangle(h, h) {};  //наследование конструктора, и никакого тела внутри.
};


int main()
{
	Triangle t(2.5, 6.0); //создаем треугольник
	Circle r(3.5); //создаем круг
	Rectangle rect(2.0, 4.0); //создаем прямоугольник 
	Rectangle rectos(5.0); //создаем квадратный прямоугольник
	Square s(4.0); //создаем квадратный квадрат
	
	r.print_Area(); //печатаем площадь круга
	rect.print_Area(); //площадь прямоугольника
	s.print_Area(); //площадь квадрата
	rectos.print_Area(); //площадь прямоугольника, который квадрат
	//Console::ReadLine();
	//system("pause");
	cin.get(); //вместо систем-паузы, мне показалось более симпатичным
	return 0;
}
