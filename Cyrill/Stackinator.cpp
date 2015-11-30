#include "stdafx.h"
#include <iostream>

using namespace std;

template <typename Item>
class Stackinator
{
protected:
	Item item;
	Stackinator *next;
public:
	Stackinator(Item, Stackinator *);
	~Stackinator() {};
};

template <class Item>
Stackinator<Item>::Stackinator(Item i, Stackinator<Item> *n) : item(i), next(n) {}

template <class Item>
class Stack : public Stackinator<Item>
{
private:
	Stackinator<Item> *head;
public:
	Stack() { head = 0 };
	~Stack() {};
	bool empty() { return head == 0 };
	void push(Item i) { head = new Stackinator(i, head) };
	Item pop() {
		Item i = head->item; Stackinator *s = head->next;
		delete head; head = s; return i;
	}
};
