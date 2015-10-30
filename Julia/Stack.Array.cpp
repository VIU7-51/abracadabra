#include <iostream>
using namespace std;

template<typename T>
class Stack {
public:
    Stack();
    void push(T item) {
        stack[topIndex++] = item;
        if (topIndex == size) resize(2*size);
    }
    T pop() {
        T temp = stack[topIndex-1];
        stack[--topIndex] = NULL;
        if (topIndex>0 && topIndex == size/4) resize(size/2);
        return temp;
    }
    void print() {
        for (int i = 0; i<topIndex; i++) cout<<stack[i]<<endl;
    }
private:
    T *stack;
    int size;
    int topIndex;
    void resize(int newSize) {
        T *temp = new T[newSize];
        for(int i = 0; i<newSize/2; i++) temp[i] = stack[i];
        delete []stack;
        stack = temp;
        size = newSize;
    }
};

template<typename T>
Stack<T>::Stack() {
    stack = new T[1];
    size = 1;
    topIndex = 0;
}

int main() {
    Stack<int> s;
    s.push(5);
    s.pop();
    return 0;
}
