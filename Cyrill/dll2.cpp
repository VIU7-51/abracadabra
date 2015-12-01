// dllklt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class ListNode
{
public:
    int value;
    ListNode *next;
    ListNode *prev;
public:
    ListNode()
    {
        value = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data)
    {
        value = data;
        next = NULL;
        prev = NULL;
    }
};

class List
{
private:
    ListNode* _pBegin;
    ListNode* _pEnd;
    unsigned int _size;
   
    static const int defaultValue = 0;
public:
    List();
    List(int size);
    List(int size, int data);
    void assign(int data); // инициализация всего списка значением data
    ListNode* back(); //указатель на конец
    ListNode* begin(); // указатель на начало
    bool empty(); // проверка на пустоту
    ListNode* erase(ListNode* pWhere); // удалить узел
    ListNode* find(int data); // найти первый узел, содержащий data
    ListNode* insertBefore(ListNode* Where, int data); // вставка до
    ListNode* insertАfter(ListNode* Where, int data); // вставка после
    void output(); // вывод
    bool pop_back(); // удаление с конца
    bool pop_front(); // удаление с начала
    void push_back(int data); // добавление в конец
    void push_front(int data); // добавление в начало
    bool remove(int data); // удалить все узлы, содержащие такую data
    void resize(unsigned int newLen); // изменить размер
    void reverse(); // реверснуть список
    unsigned int size(); // размер списка
    void Swap(ListNode* a, ListNode* b); // обмен двух элементов местами
private:
    inline void Next(ListNode** pCurNode)
    {
        *pCurNode = (*pCurNode)->next;
    }
    inline void Prev(ListNode** pCurNode)
    {
        *pCurNode = (*pCurNode)->prev;
    }
};

#include <list>
List::List():_pBegin(NULL),
             _pEnd(NULL),
             _size(0)
{
}
List::List(int size):_pBegin(NULL),
                     _pEnd(NULL),
                     _size(0)
{
    resize(size);
    assign(defaultValue);
}
List::List(int size, int data):_pBegin(NULL),
                               _pEnd(NULL),
                               _size(0)
{
    resize(size);
    assign(data);
}
void List::assign(int data)
{
    for (ListNode* cur = _pBegin; cur ; Next(&cur))
        cur->value = data;
}
ListNode* List::back()
{
    return _pEnd;
}
ListNode* List::begin()
{
    return _pBegin;
}
bool List::empty()
{
    return _size == 0;
}
ListNode* List::erase(ListNode* pWhere)
{
    if (pWhere == NULL)
        return false;
 
    if (pWhere == _pBegin)
        Next(&_pBegin);
    else if (pWhere == _pEnd)
        Prev(&_pEnd);
 
    ListNode* pPrevNode = pWhere->prev;
    ListNode* pNextNode = pWhere->next;
    if (pNextNode)
        pNextNode->prev = pPrevNode;
    if (pPrevNode)
        pPrevNode->next = pNextNode;
 
    delete pWhere;
    _size--;
    return pNextNode;
}
ListNode* List::find(int data)
{
    ListNode* cur = NULL;
    for (cur = _pBegin; cur; Next(&cur))
        if (cur->value == data)
            break;
    return cur;
}
ListNode* List::insertBefore(ListNode* pWhere, int data)
{
    if (pWhere == NULL && _size != 0) // некорретный указатель
        return NULL;
   
    ListNode* pNewNode = new ListNode(data);
   
    if (pWhere == NULL && _size == 0) // список пуст
    {
        _pBegin = pNewNode;
        _pEnd = pNewNode;
    }
    else
    {
        // Есть предыдущий узел
        if (pWhere->prev)
        {
            ListNode* pPrevNode = pWhere->prev;
            pPrevNode->next = pNewNode;
            pNewNode->prev = pPrevNode;
            pNewNode->next = pWhere;
            pWhere->prev = pNewNode;
        }
        // Where = _pBegin
        else
        {
            _pBegin->prev = pNewNode;
            pNewNode->next = _pBegin;
            _pBegin = pNewNode;
        }
    }
    _size++;
    return pNewNode;
}
ListNode* List::insertАfter(ListNode* Where, int data)
{
    if (Where == NULL && _size != 0) // некорректный указатель
        return NULL;
 
    ListNode* pNewNode = new ListNode(data);
    if (Where == NULL && _size == 0)
    {
        _pBegin = pNewNode;
        _pEnd = pNewNode;
    }
    else
    {
        // Есть следующий элемент
        if (Where->next)
        {
            ListNode* pNextNode = Where->next;
            Where->next = pNewNode;
            pNewNode->prev = Where;
            pNewNode->next = pNextNode;
            pNextNode->prev = pNewNode;
        }
        // Where = _pEnd
        else
        {
            _pEnd->next = pNewNode;
            pNewNode->prev = _pEnd;
            _pEnd = pNewNode;
        }
    }
    _size++;
    return pNewNode;
}
void List::output()
{
    for (ListNode* cur = _pBegin; cur; Next(&cur))
        cout<<cur->value<<' ';
    cout<<endl;
}
bool List::pop_back()
{
    return erase(_pEnd);
}
bool List::pop_front()
{
    return erase(_pBegin);
}
void List::push_back(int data)
{
    insertАfter(_pEnd, data);
}
void List::push_front(int data)
{
    insertBefore(_pBegin, data);
}
bool List::remove(int data)
{
    bool nodesExist = false;;
    for (ListNode* cur = _pBegin; cur;)
        if (cur->value == data)
        {
            cur = erase(cur);
            nodesExist = true;
        }
        else
            Next(&cur);
    return nodesExist;
}
 
void List::resize(unsigned int newLen)
{
    if (_size > newLen)
        while (_size != newLen)
            pop_back();
    else if (_size < newLen)
        while (_size != newLen)
            push_back(defaultValue);
}
 
void List::reverse()
{
    ListNode* l = _pBegin, *r = _pEnd;
    int len = _size/2;
    for (int i=0;i<len;i++)
    {
        Swap(l,r);
        swap(l,r);
 
        Next(&l);
        Prev(&r);
    }
}
unsigned int List::size()
{
    return _size;
}
void List::Swap(ListNode *a, ListNode *b)
{
    if (!a || !b)
        return;
    if (a==b)
        return;
 
    if (b->next == a)
        swap(a,b);
 
    if (a == _pBegin)
        _pBegin = b;
    else if (b == _pBegin)
        _pBegin = a;
    else if (a == _pEnd)
        _pEnd = b;
    else if (b == _pEnd)
        _pEnd = a;
 
    ListNode* prevA = a->prev;
    ListNode* nextA = a->next;
 
    ListNode* prevB = b->prev;
    ListNode* nextB = b->next;
 
    if (a != prevB) // несмежные элементы
    {
        swap(a->prev,b->prev);
        swap(a->next,b->next);
 
        if (prevA)
            prevA->next = b;
        if (nextA)
            nextA->prev = b;
 
        if (prevB)
            prevB->next = a;
        if (nextB)
            nextB->prev = a;
    }
    else // смежные элементы
    {
        b->next = a;
        a->next = nextB;
        a->prev = b;
        b->prev = prevA;
 
        if (prevA)
            prevA->next = b;
        if (nextB)
            nextB->prev = a;
    }
}
