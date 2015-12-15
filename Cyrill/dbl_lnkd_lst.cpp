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
	int size;
public:
	DoubleList();
	~DoubleList();
	void push_head(item);
	void push_tail(item);
	item pop_head(void);
	item pop_tail(void);
	void print(void);
	node<item>* getNode(int);
	void insert(int, item);
	item remove(int);
};

template <class item>
DoubleList<item>::DoubleList() {
		size = 0;
		head = tail = NULL;
		
}

template <class item>
DoubleList<item>::~DoubleList() {
	node<item> *tmp = this->head;
	node<item> *next = NULL;
	while (tmp) {
		next = tmp->next;
		delete tmp;
		tmp = next;
	}
	delete this;
	//this = NULL;
}

template <class item>
void DoubleList<item>::push_head(item value) {
	node<item> *tmp = new node<item>;
	if (tmp == NULL) {
		exit(1);
	}
	tmp->value = value;
	tmp->next = this->head;
	tmp->prev = NULL;
	if (this->head) {
		this->head->prev = tmp;
	}
	this->head = tmp;

	if (this->tail == NULL) {
		this->tail = tmp;
	}
	this->size++;
}

template <class item>
void DoubleList<item>::push_tail(item value) {
	node<item> *tmp = new node<item>;
	if (tmp == NULL) {
		exit(3);
	}
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = this->tail;
	if (this->tail) {
		this->tail->next = tmp;
	}
	this->tail = tmp;

	if (this->head == NULL) {
		this->head = tmp;
	}
	this->size++;
}

template <class item>
item DoubleList<item>::pop_head(void) {
	node<item> *prev;
	item tmp;
	if (this->head == NULL) {
		exit(2);
	}

	prev = this->head;
	this->head = this->head->next;
	if (this->head) {
		this->head->prev = NULL;
	}
	if (prev == this->tail) {
		this->tail = NULL;
	}
	tmp = prev->value;
	delete prev;

	this->size--;
	return tmp;
}

template <class item>
item DoubleList<item>::pop_tail(void) {
	node<item> *next;
	item tmp;
	if (this->tail == NULL) {
		exit(4);
	}

	next = this->tail;
	this->tail = this->tail->prev;
	if (this->tail) {
		this->tail->next = NULL;
	}
	if (next == this->head) {
		this->head = NULL;
	}
	tmp = next->value;
	free(next);

	this->size--;
	return tmp;
}

template <class item>
void DoubleList<item>::print(void) {
	for (node<item> *tmp = this->head; tmp; tmp = tmp->next) {
		std::cout << tmp->value << " ";
	}
	std::cout << std::endl;
}

template <class item>
node<item>* DoubleList<item>::getNode(int index) {
	node<item> *tmp = this->head;
	int i = 0;

	while (tmp && i < index) {
		tmp = tmp->next;
		i++;
	}

	return tmp;
}
template <class item>
void DoubleList<item>::insert(int index, item value) {
	Node *elem = NULL;
	Node *ins = NULL;
	elem = DoubleList<item>::getNode(index);
	if (elem == NULL) {
		exit(5);
	}
	ins = new node<item>;
	ins->value = value;
	ins->prev = elem;
	ins->next = elem->next;
	if (elem->next) {
		elem->next->prev = ins;
	}
	elem->next = ins;

	if (!elem->prev) {
		this->head = elem;
	}
	if (!elem->next) {
		this->tail = elem;
	}

	this->size++;
}
template <class item>
item DoubleList<item>::remove(int index) {
	node<item> *elem = NULL;
	void *tmp = NULL;
	elem = DoubleList<item>::getNode(index);
	if (elem == NULL) {
		exit(5);
	}
	if (elem->prev) {
		elem->prev->next = elem->next;
	}
	if (elem->next) {
		elem->next->prev = elem->prev;
	}
	tmp = elem->value;

	if (!elem->prev) {
		this->head = elem->next;
	}
	if (!elem->next) {
		this->tail = elem->prev;
	}

	delete elem;

	this->size--;

	return tmp->value;
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
	std::cout << dl.pop_tail() << dl.pop_head() << dl.pop_head() << dl.pop_tail() << std::endl;
	dl.print();
	std::cin.get();
	return 0;
}

