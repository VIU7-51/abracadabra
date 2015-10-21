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
		return node == NULL;
	}
	void push(T item){
		Node<T>* old = node; 
		node = new Node<T>();
		node->item = item;
		node->next = old;
	}
	T pop(){
		Node<T> current = *node;
		delete node;
		T item = current.item;
		node = current.next;
		return item;
	}
private:
	Node<T> *node = NULL;
};

int main() {
	Stack<char> s;
	int choice;
	while(1) {
	    std::cout<<"1-Push element; 2-Pop element; 3-Exit"<<"\n";
	    std::cin>>choice;
		switch(choice) {
			case 1: { 
			    char elem; 
			    std::cout<<"Input element: "; 
			    std::cin>>elem;
			    s.push(elem);
			    break;
			}
			case 2: { 
			    if (!s.isEmpty()) 
			    	std::cout<<s.pop()<<"\n";
			    break;
			}
			case 3: return 0;
			default: 
			std::cout<<"Wrong input"<<"\n";
		}
	}
}
