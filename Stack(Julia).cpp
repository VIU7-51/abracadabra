#include <iostream>
#include <stdlib.h>

template <typename T>
struct Node {
	T item;
	Node *next;
};

template <typename T>
class Stack {
public:
	bool isEmpty(){
		return first == NULL;
	}
	void push(T item){
		Node<T>* old = first; 
		first = new Node<T>();
		first->item = item;
		first->next = old;
	}
	T pop(){
		Node<T> current = *first;
		delete first;
		T item = current.item;
		first = current.next;
		return item;
	}
private:
	Node<T> *first = NULL;
};

int main() {
	Stack<char> s;
	for (char i = 'a'; i <= 'f'; i++) 
		s.push(i);
	for (;!s.isEmpty();)
		std::cout<<s.pop()<<"\n";
	return 0;
}
