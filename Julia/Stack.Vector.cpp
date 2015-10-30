#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Stack {
public:
    void push(T item);
    T pop();
    void print();
    int size();
private:
    vector<T> stack;
};

template<typename T>
void Stack<T>::push(T item) {
    stack.push_back(item);
}

template<typename T>
T Stack<T>::pop() {
    T temp = stack[stack.size()-1];
    stack.pop_back();
    return temp;
}

template<typename T>
void Stack<T>::print() {
    typename vector<T>::iterator it;
    for(it = stack.begin(); it != stack.end(); it++) cout<<*it<<endl;
}

template<typename T>
int Stack<T>::size() {
    return stack.size();
}

int main() {
    Stack<int> s;
    s.push(5);
    cout<<"Size: "<<s.size()<<endl;
    cout<<s.pop();
    return 0;
}
