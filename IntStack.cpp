
#include <iostream>
#include <locale>
#include <iomanip>
#include <cassert>
#include <string>

using namespace std;

class StackElement {
public:
    StackElement* next;
    int value;

    StackElement(StackElement *, int);
};

StackElement::StackElement(StackElement *n, int v) {
    next = n;
    value = v;
}

class IntStack {
public:
    StackElement *currentElement;

    IntStack();

    void push(int); // поместить элемент в стек
    int pop(); // удалить из стека элемент
    int length;

    void printStack();
};

IntStack::IntStack() {
    length = 0;
    currentElement = NULL;
}

int main() {
    setlocale(LC_ALL, "");
    string command;
    IntStack myStack;

    cout << "Помещаем элементы в стек. Вывод стека: 'print', взять элемент: 'pop', выход: 'quit'. " << endl;

    while (command != "quit") {
        cin >> command;
        if (command == "print") {
            myStack.printStack();
        } else if (command == "pop") {
            cout << myStack.pop() << endl;
        } else {

            myStack.push(std::stoi(command));
        }
    }

    system("pause");

    return 0;
}

void IntStack::push(int value) {

    StackElement* newElement = new StackElement(this->currentElement, value);
    this->currentElement = newElement;
    this->length++;

}

int IntStack::pop() {

    if(this->length!=0){
        length--;

        StackElement element = *this->currentElement;
        int value = element.value;
        this->currentElement = element.next;

        return value;
    } else {
        return NULL;
    }
}

void IntStack::printStack() {
    StackElement* elementPtr = this->currentElement;

    if(length == 0){
        cout << "Пусто" << endl;
        return;
    }

    while (elementPtr){
        StackElement element = *elementPtr;
        cout << "|" << setw(4) << element.value;
        elementPtr = element.next;
    }

    cout << endl;
}
