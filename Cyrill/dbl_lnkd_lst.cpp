//класс неотремонтированный и не рабочий, считать черновым вариантом

template <class item>
class dualink {
private:
	struct node
	{
		item item_value;
		node *next;
		node *prev;
	};

	long position;
	node *slider;
	node *head;
	node *tail;

public:
	explicit dualink();
	~dualink();
	//pushes
	void push_head(item);
	void push_tail(item);
	//pops
	item pop_head(void);
	item pop_tail(void);
	//inserters
	//void insert(item, long);
	//removers
	//item remove(long);
	//deleters
	//void delete(long);
	//accesors $ mutators
	//item get_item(long);
	//void set_item(item , long);
};



template <class item>
dualink<item>::dualink() {
	slider = tail = head = NULL;
}

template <class item>
dualink<item>::~dualink() {
	/*node *front = head;
	node *back = tail;
	for ( ; head != tail; ) {
		front = head->prev;
		delete head;
		head = front;
		back = tail->next;
		delete tail;
		tail = back;
	}
	delete head;*/
}

template <class item>
void dualink<item>::push_head(item value)
{
	struct node *newnode = new node;
	newnode.item_value = value;
	newnode->next = NULL;
	newnode->prev = head;
	head = newnode;
	position++;
}

template <class item>
void dualink<item>::push_tail(item)
{
	struct node *newnode = new node;
	newnode.item_value = value;
	newnode->next = tail;
	newnode->prev = NULL;
	tail = newnode;
	position++;
}

template <class item>
item dualink<item>::pop_head(void)
{
	if (head) {
	item value = head.item_value;
	node *temp = head->prev;
	delete head;
	head = temp;
	position--;
	return value;
	}
	else {
		std::cout << "no more elements" << std::endl;
		return item(exit(EXIT_FAILURE));
	}
}

template<class item>
item dualink<item>::pop_tail(void)
{
	if (tail) {
		item value = tail.item_value;
		node *temp = tail->next;
		delete tail;
		tail = temp;
		position--;
		return value;
	}
	else {
		std::cout << "no more elements" << std::endl;
		return item(exit(EXIT_FAILURE));
	}
}


int main()
{
	dualink<int> dll;
	dll.push_head(5);
	dll.push_head(10);
	dll.push_tail(15);
	dll.pop_head();
	dll.pop_tail();

    return 0;
}




// double.cpp: определяет точку входа для консольного приложения.
//

// double.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

template <typename item>
class node {
public:
	item value;
	node<item> *next;
	node<item> *prev;
public:
	node() { value = NULL, prev = next = NULL; }
	node(item v, node* n, node* p) : value(v), next(n), prev(p) {}
};

template <typename item>
class DoubleList : public node<item> {
private:
	node<item> *head;
	node<item> *tail;
	//int const lsize = 0;
public:
	DoubleList();
	void push_head(item);
	void push_tail(item);
	item pop_head(void);
	item pop_tail(void);
	void print(void);
};

template <class item>
DoubleList<item>::DoubleList() {
	head = tail = NULL;
	//node<item> *nod = new node<item>(NULL, NULL, NULL);
	//head = tail;
	//tail->prev = head;
	//head->next = tail;
}

template <class item>
void DoubleList<item>::push_head(item value) {
	if (head != NULL) {
		head = new node<item>(value, head, NULL);
	}
	else {
		node<item> *nod = new node<item>(value, NULL, NULL);
		head = tail = nod;
	}
}

template <class item>
void DoubleList<item>::push_tail(item value) {
	if (tail != NULL) {
		tail = new node<item>(value, NULL, tail);
	}
	else {
		node<item> *nod = new node<item>(value, NULL, NULL);
		head = tail = nod;
	}
}

template <class item>
item DoubleList<item>::pop_head(void) {
	item val = head->value;
	node<item> *tmpn = head->next;
	delete head;
	head = tmpn;
	return val;
}

template <class item>
item DoubleList<item>::pop_tail(void) {
	item val = tail->value;
	node<item> *tmpn = tail->prev;
	delete tail;
	tail = tmpn;
	return val;
}

template <class item>
void DoubleList<item>::print(void) {
	for (node<item> *curr = head; curr; curr = curr->next) {
	}
	std::cout << std::endl;
}



int main()
{
	DoubleList<int> dl;
	dl.push_head(1);
	dl.push_head(2);
	dl.print();
	dl.push_tail(3);
	dl.push_tail(4);
	dl.print();
	dl.push_head(5);
	dl.push_tail(6);
	dl.print();
	//int poph = dl.pop_head();
	//int popt = dl.pop_tail();
	std::cout << dl.pop_tail() << dl.pop_tail() << dl.pop_tail() << dl.pop_tail() << std::endl;
	dl.print();
	std::cin.get();
	return 0;
}


