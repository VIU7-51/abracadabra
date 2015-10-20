// question.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


class Base
{
public:
	Base() {}
	virtual void bar();
	~Base() {}
};

void Base::bar() {
	std::cout << "Base" << std::endl;
}

class Derived : public Base
{
public:
	Derived() {}
	void bar(int);
	~Derived() {}
}

void Derived::bar(int x = 0) {
	std::cout << x << std::endl;
}







int _tmain(int argc, _TCHAR* argv[])
{
	Base arg1;
	Derived arg2;
	arg1.bar();
	//arg1.bar(2);
	arg2.bar();
	arg2.bar(4);
	std::cin.get();

	return 0;
}

