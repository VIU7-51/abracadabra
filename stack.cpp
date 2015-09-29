#include "stdafx.h"
#include <iostream>
#include <locale>
#include "conio.h"
using namespace std;
struct stack
{
	int data;
	stack *next;
};
class Stack
{
protected:
	stack *sp;
	public:
		Stack();
		void PushStack(int);
		
		void  DisplayStack();
		

};
Stack::Stack(){sp=NULL;}
void Stack::PushStack(int pdata)
{
	stack* newstack = new stack();
	newstack->data = pdata;
	newstack->next = sp;
	sp = newstack;

}
void Stack::DisplayStack()
{
	stack* current = sp;
	while(current)
	{
		std::cout << current->data<<std::endl;

		sp = current->next;
		delete current;
		current = sp;
	}
}
int _tmain()
{
	setlocale(LC_ALL,"");
	std::cout <<"Работа со стеком"<<std::endl;
	Stack s;
	s.PushStack(1);
	s.PushStack(2);
	s.PushStack(3);
	s.DisplayStack();
	_getch();
	return 0;
}
int main()
{
	setlocale(LC_ALL,"");
	std::cout <<"Работа со стеком"<<std::endl;
	Stack s;
	s.PushStack(1);
	s.PushStack(2);
	s.PushStack(3);
	s.DisplayStack();
	getch();
	return 0;
}
