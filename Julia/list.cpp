#include <iostream>
#include <string>

template <typename T>
struct Node {
	T item;
	Node *next;
};

template <typename T>
class LinkedList {
public:
    LinkedList() {
        node = NULL;
        _size = 0;
    }
	bool isEmpty(){
		return node == NULL;
	}
	int size(){
	    return _size;
	}
	void insert(T item){
		Node<T>* old = node; 
		node = new Node<T>();
		node->item = item;
		node->next = old;
		_size++;
	}
	void remove(){
		node = node->next;
	}
	void print(){
	    Node<T> *cursor = node;
	    while(cursor != NULL){
	        std::cout << cursor->item << std::endl;
	        cursor = cursor->next;
	    }
	}
private:
	Node<T> *node;
	int _size;
};


int main()
{
    LinkedList<char> s;
	int choice;
	while(1) {
	    std::cout<<"1-Insert element; 2-Delete last element; 3-Print list; 4-Size; 5-Exit"<<"\n";
	    std::cin>>choice;
		switch(choice) {
			case 1: { 
			    char elem; 
			    std::cout<<"Input element: "; 
			    std::cin>>elem;
			    s.insert(elem);
			    break;
			}
			case 2: { 
			    if (!s.isEmpty()) 
			    	s.remove();
			    break;
			}
			case 3: {
			    s.print();
			    break;
			}
			case 4: {
			    std::cout<<s.size()<<std::endl;
			    break;
			}
			case 5: 
			    return 0;
			default: 
			    std::cout<<"Wrong input"<<"\n";
		}
	}
}
