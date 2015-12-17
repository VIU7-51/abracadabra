#include <iostream>

using namespace std;

template <typename T>
class LinkedList {
    struct Item {
        T data;         //Данные
        Item* prev;     //Предыдущий элемент
        Item* next;     //Следующий элемент
        Item(T t, Item* p, Item* n): data(t), prev(p), next(n) {} //Конструктор элемента
    };

    Item* start;        //Начальный элемент
    Item* end;          //Конечный элемент


public:
    int count;          //Кол-во элементов
    LinkedList() : start(NULL), end(NULL), count(0) {} //Конструктор списка

    void pushStart(T);  //Добавить в начало
    void pushEnd(T);    //Добавить в конец
    void push(T, int);  //Добавить в произвольное место

    T popStart();       //Взять элемент с начала
    T popEnd();         //Взять элемент с конца
    T pop(int);         //Взять элемент в произвольном месте

    void printAll(bool forward);    //Напечатать список (с начала / с конца)

    ~LinkedList() {     //Деструктор
        while (start){  //Пока есть ссылка на начальный элемент...
            Item* temp = start;
            start = temp->next;
            delete temp;    //...Удаляем элементы
        }
    }
};

template <typename T>
void LinkedList<T>::pushStart(T data) {
    if(count == 0) {
        /*
         * Если список пустой - добавляем элемент и замыкаем список на этот элемент
         */
        Item* newStartItem = new Item(data, end, start);
        newStartItem->next = newStartItem;
        newStartItem->prev = newStartItem;
        start = newStartItem;
        end = newStartItem;
    } else {
        /*
         * Создаем элемент и переназначаем адрес начального элемента на адрес нового элемента
         */
        Item* startItem = start;
        Item* endItem = end;
        Item* newStartItem = new Item(data, endItem, startItem);
        start = newStartItem;
        endItem->next = newStartItem;
        startItem->prev = newStartItem;
    }
    count++;
}


template <typename T>
void LinkedList<T>::pushEnd(T data) {
    //То же самое. Если пустой, замыкаем список
    if(count == 0) {
        Item* newEndItem = new Item(data, end, start);
        newEndItem->next = newEndItem;
        newEndItem->prev = newEndItem;
        start = newEndItem;
        end = newEndItem;
    } else {
        //Если не пустой, обновляем адрес конца на адрес нового элемента + обновляем адреса prev и next у соседних элементов
        Item* startItem = start;
        Item* endItem = end;
        Item* newEndItem = new Item(data, endItem, startItem);
        end = newEndItem;
        endItem->next = newEndItem;
        startItem->prev = newEndItem;
    }
    count++;
}

template <typename T>
void LinkedList<T>::push(T data, int place) {
    //если вставляем в начало или конец, то переиспользуем уже существующие функции, чтобы не тратить время
    if (place == 0) {
        pushStart(data);
    } else if (place == count){
        pushEnd(data);
    } else {
        //тут аналогично, если список путой...
        if(count == 0) {
            Item* newEndItem = new Item(data, end, start);
            newEndItem->next = newEndItem;
            newEndItem->prev = newEndItem;
            start = newEndItem;
            end = newEndItem;
        } else {
            //Создаем новый элемент и переменные для хранения адресов соседних элементов
            Item* newItem = new Item(data, end, start);
            Item* currentItem;
            Item* prevItem;
            bool forward = count / 2 > place ? true : false;    //как будем обходить - от начала или конца. Если искомое место - до середины места, то с начала, иначе - с конца
            int currentPlace = forward? 0 : count-1;            //счетчик обхода - устанавливается на 0 если обходим с начала или на номер последнего эл-та, если с конца
            currentItem = forward ? start : end;                //то же самое с адресом текущего элемента

            while (currentPlace != place){                      //пока не достигнем нужного места...
                currentItem = forward ? currentItem->next : currentItem->prev;  //обновляем адрес текущего элемента
                currentPlace = forward ? currentPlace + 1 : currentPlace - 1;   //и счетчик
            }

            //вставляем элемент и обновляем адреса prev и next у соседних элементов
            prevItem = currentItem->prev;

            newItem->next = currentItem;
            newItem->prev = prevItem;

            prevItem->next = newItem;
            currentItem->prev = newItem;
        }
        count++;
    }
    cout << "Inserted value " << data << " at place " << place << "\n";
}

/*
 * Удаляем элемент с начала
 */
template <typename T>
T LinkedList<T>::popStart() {
    Item* item = start;                 //Записываем начальный элемент
    start = item->next;                 //Переназначаем начальный элемент на следующий в списке
    end->next = start;                  //у последнего элемента обновляем адрес следующего элемента
    start->prev = end;                  //у нового начального элемента обновляем адрес предыдущего элемента
    count--;
    T returnValue = item->data;         //сохраняем данные для возврата
    delete item;                        //удаляем элемент
    return returnValue;
}

/*
 * Удаляем элемент с конца
 * Здесь все аналогично
 */
template <typename T>
T LinkedList<T>::popEnd() {
    Item* item = end;
    end = item->prev;
    end->next = start;
    start->prev = end;
    count--;
    T returnValue = item->data;
    delete item;
    return returnValue;
}

/*
 * Удаляем элемент в произвольном месте
 * Тоже все аналогично вставке
 */
template <typename T>
T LinkedList<T>::pop(int place) {
    if(count == 0) {
        return NULL;
    } else if (place == 0) {
        return popStart();
    } else if (place == count-1){
        return popEnd();
    } else {
        Item* nextItem;
        Item* currentItem;
        Item* prevItem;
        T value;

        bool forward = count / 2 > place ? true : false; //как будем обходить - от начала или конца. Если искомое место - до середины места, то с начала, иначе - с конца
        int currentPlace = forward? 0 : count-1;
        currentItem = forward ? start : end;

        while (currentPlace != place){
            currentItem = forward ? currentItem->next : currentItem->prev;
            currentPlace = forward ? currentPlace + 1 : currentPlace - 1;
        }

        //соединяем 2 окружающих элемента друг с другом
        prevItem = currentItem->prev;
        nextItem = currentItem->next;
        prevItem->next = nextItem;
        nextItem->prev = prevItem;

        count--;
        value = currentItem->data;
        delete(currentItem);    //удаляем элемент
        return value;
    }

}

/*
 * Печать списка
 */
template <typename T>
void LinkedList<T>::printAll(bool forward) {
    if(count > 0) {     //Сразу отлавливаем ситуацию, когда список пустой
        if (forward) {    //Печатать с начала
            Item *item = start;
            for (int i = 0; i < count; i++) {
                cout << item->data << " ";
                item = item->next;

            }
        } else {        //Печатать с конца
            Item *item = end;
            for (int i = 0; i < count; i++) {
                cout << item->data << " ";
                item = item->prev;

            }

        }
    } else {
        cout << "(empty)";
    }
    cout << "\n";
}

int main() {
    //инициализация рандомайзера
    srand(time(NULL));

    LinkedList<int> *list = new LinkedList<int>();

    //последовательно проходим все операции
    cout << "-----------------------------------------------\n";
    cout << "Creating list by pushing to start\n";
    for (int i=0; i<3; i++)
        list->pushStart(i);

    cout << "Printing list forward:\n";
    list->printAll(true);
    cout << "Printing list backward:\n";
    list->printAll(false);

    cout << "-----------------------------------------------\n";
    cout << "Adding items to the list by pushing to end\n";
    for (int i=10; i<15; i++)
        list->pushEnd(i);

    cout << "Printing list forward:\n";
    list->printAll(true);
    cout << "Printing list backward:\n";
    list->printAll(false);

    cout << "-----------------------------------------------\n";
    cout << "Inserting items into random places\n";
    for(int i=20;i<22;i++){
        list->push(i, rand() % list->count);
    }
    cout << "Printing list forward:\n";
    list->printAll(true);
    cout << "Printing list backward:\n";
    list->printAll(false);

    cout << "-----------------------------------------------\n";
    cout << "Popping items from random places\n";
    for(int i=0;i<2;i++){
        int place = rand() % list->count;
        cout << "Popped value " << list->pop(place) << "at place " << place << "\n";
    }
    cout << "Printing list forward:\n";
    list->printAll(true);
    cout << "Printing list backward:\n";
    list->printAll(false);

    cout << "-----------------------------------------------\n";
    cout << "Popping items from the front\n";
    for(int i=0;i<2;i++){
        cout << "Got value " << list->popStart() << "\n";
    }
    cout << "Printing list forward:\n";
    list->printAll(true);
    cout << "Printing list backward:\n";
    list->printAll(false);

    cout << "-----------------------------------------------\n";
    cout << "Popping items from the back\n";
    for(int i=0;i<2;i++){
        cout << "Got value " << list->popEnd() << "\n";
    }
    cout << "Printing list forward:\n";
    list->printAll(true);
    cout << "Printing list backward:\n";
    list->printAll(false);

    cout << "-----------------------------------------------\n";
    cout << "Emptying the list\n";
    while(list->count>0){
        cout << "Got value " << list->popEnd() << "\n";
        cout << "The list: ";
        list->printAll(true);
    }

    return 0;
}