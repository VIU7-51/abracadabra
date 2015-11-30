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
