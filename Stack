#include "stdafx.h"
#include <iostream>
#include <locale>
#include <iomanip>
#include <cassert>
using namespace std;
 

 
template <typename T>
class Stack
{
private:
    T *stackPtr; // указатель на стек
    int size; // размер стека
    T top; // вершина стека
public:
    Stack(int = 10);// по умолчанию размер стека равен 10 элементам
    ~Stack(); // деструктор
    bool push(const T  ); // поместить элемент в стек
    bool pop(); // удалить из стека элемент
    void printStack();
};
 
int _tmain()
{
	setlocale(LC_ALL,"");
	int n;
	cout << "Введите число элементов в стеке 0 < n <= 10";
	cin >> n;
	assert(n>0);
	assert(n<=10);
    Stack <int> myStack(n);
	setlocale(LC_ALL,"");
    // заполняем стек
    cout << "Помещаем элементы в стек: ";
    int ct = 0;
    while (ct++ != n)
    {
        int temp;
        cin >> temp;
        myStack.push(temp);
    }
 
    myStack.printStack(); // вывод стека на экран
 
    cout << "\nУдаляем два элемента из стека:\n";
 
    myStack.pop(); // удаляем элемент из стека
    myStack.pop(); // удаляем элемент из стека
    myStack.printStack(); // вывод стека на экран
	system("pause");
 
    return 0;
}
 
// конструктор
template <typename T>
Stack<T>::Stack(int s)
{
	assert(s>=1);
	assert(s<=10);
    size = s > 0 ? s: 10;   // инициализировать размер стека
	
    stackPtr = new T[size]; // выделить память под стек
    top = -1; // значение -1 говорит о том, что стек пуст
}
 
// деструктор
template <typename T>
Stack<T>::~Stack()
{
    delete [] stackPtr; // удаляем стек
}
 
// элемент функция класса  Stack для помещения элемента в стек
// возвращаемое значение - true, операция успешно завершена
//                                    false, элемент в стек не добавлен
template <typename T>
bool Stack<T>::push(const T value)
{
    if (top == size - 1)
        return false; // стек полон
 
    top++;
    stackPtr[top] = value; // помещаем элемент в стек
 
    return true; // успешное выполнение операции
}
 
// элемент функция класса  Stack для удаления элемента из стек
// возвращаемое значение - true, операция успешно завершена
//                                    false, стек пуст
template <typename T>
bool Stack<T>::pop()
{
    if (top == - 1)
        return false; // стек пуст
 
    stackPtr[top] = 0; // удаляем элемент из стека
    top--;
 
    return true; // успешное выполнение операции
}
 
// вывод стека на экран
template <typename T>
void Stack<T>::printStack()
{
    for (int ix = size -1; ix >= 0; ix--)
        cout << "|" << setw(4) << stackPtr[ix] << endl;
}
