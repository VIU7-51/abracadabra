#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T>
struct Node {
	T item;
	Node<T> *prev;
	Node<T> *next;
};

template <typename T>
class DoublyLinkedList {
public:
	DoublyLinkedList();
    int size() {
        return Size;
    }
    void append(T elem) {
        Size++;
        node->item = elem;
        Node<T> *oldNode = node;
        node = new Node<T>();
        oldNode->next = node;
        node->prev = oldNode;
        tail->prev = node;
    }
    void insert(T elem, int index) {
        Size++;
        Node<T> *newNode = new Node<T>;
        newNode->item = elem;
        if (index == 0) {
            cursor = head->next;
            cursor->prev = newNode;
            newNode->next = cursor;
            newNode->prev = head;
            head->next = newNode;
        }
        else if (index<Size/2 or index==1) {
            cursor = head->next;
            for(int i = 0; i != index; i++)
                cursor = cursor->next;
            newNode->next = cursor;
            newNode->prev = cursor->prev;
            cursor->prev = newNode;
        }
        else {
            cursor = tail->prev;
            for(int i = Size; i != index; i--)
                cursor = cursor->prev;
            newNode->next = cursor;
            newNode->prev = cursor->prev;
            cursor->prev->next = newNode;
            cursor->prev = newNode;
        }
    }
    void print() {
        cursor = head->next;
        for (int i = 0; i<Size; i++) {
            cout<<cursor->item<<"\n";
        cursor = cursor->next;
        }
    }
    T pop(int index);
    void remove(T elem);
    bool isEmpty();
private:
    Node<T> *head, *tail, *node, *cursor;
    int Size;
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    Size = 0;
    node = new Node<T>;
    cursor = new Node<T>;
    tail = new Node<T>;
    head = new Node<T>;
    head->next = node;
    tail->prev = node;
    cursor = node;
}

int main() {
    DoublyLinkedList<int> d;
    d.append(7);
    d.append(8);
    d.append(9);
    d.append(10);
    d.insert(1,0);
    d.insert(12,d.size());
    d.insert(3,3);
    d.print();
    cout<<"Size = "<<d.size()<<"\n";
    return 0;
}
