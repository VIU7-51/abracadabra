#include <iostream>
#include <time.h> //для функции time()
#include <iomanip> //для функции setw()

#define WRONG_SIZE -101 


//using namespace std;

class Array {
private:
  int *arr;
  int size;
  int searchItem (int,int,int); //для бинарного поиска используются рекурсивные функции возвращающие
                                //значение запрашиваемого элемента либо эту же функцию, при иных результатах
                                //выполнения
  int searchIndex (int,int,int);//аналогичная функция для поиска индекса элемента, в этом нет необходимости
                                //с конструктивной точки зрения.
public:
  Array(int); //конструктор класса массива
  ~Array();   //деструктор
 void Print(void); //печатает в поток cout элементы массива
 void InsertionSort(void); //сортировка методом простых вставок
 void BinarySearch(int); //бинарный поиск, функция внутри себя содержит две приватные функции, описанные выше
// int getSize(void); //оставил здесь закомменченные функции, как черновые варианты для бинарного поиска
// int BinSrc(int, int, int); // ---/---
};

Array::Array(int s) : size(s) {  //коструктор с передаваемым значением размера массива
  arr = new int[size];   
  srand(time(NULL));
  for (int i=0;i<size;i++) { arr[i]=rand() % size; };
}

Array::~Array() {
  delete [] arr;
}

void Array::Print(void) {
  for (int i=0;i<size;i++) {
      std::cout << std::setw(4) << arr[i];
    }
  std::cout << std::endl;
  return;
}

int Array::searchItem(int left, int right, int src) {
  if (left > right) exit(EXIT_FAILURE);  //первое необходимое условие - левые границы должны быть меньше правых на входе в функцию
  int median  = (left + right) / 2; //создаем индекс для среднего элемента массива
  if (arr[median] == src) return arr[median]; //сравниваем элемент с запросом поиска
  if(left == right) exit(EXIT_FAILURE); //второе необходимое условие - после ненахождения среднего элемента
                                        //границы не должны быть установлены на одном значении
  if (src < arr[median]) return searchItem(left, median - 1, src); //вызов рекурсивной функции поиска
                                                                   //при условии что искомый элемент меньше серединного
  else return searchItem(median + 1, right, src); //иначе вызов с противоположным условием
}

int Array::searchIndex(int left, int right, int src) { //идентичная функция для поиска индекса
  if (left > right) exit(EXIT_FAILURE);
  int median  = (left + right) / 2;
  if (arr[median] == src) return median;
  if (src < arr[median]) return searchIndex(left, median - 1, src);
  else return searchIndex(median + 1, right, src);
}

void Array::InsertionSort(void) { //поиск методом вставки
  for (int temp, j, i=0; i<size; i++) {
      temp = arr[i];
      for (j=i-1;j>=0 && arr[j]>temp;j--) arr[j+1] = arr[j]; //в себе имеет идею, что элементы до i-го порядка уже отсортированы
      arr[j+1]=temp;
    }
  return;
}

void Array::BinarySearch(int src) { //бинарный поиск
 std::cout << "Found: " << Array::searchItem(0, size-1, src) << " at "
             << "A[" << Array::searchIndex(0, size - 1, src) << "] position" << std::endl;
 return;
}


//ниже неудачная попытка вызова бинарного поиска в самого себя как функцию класса
//int Array::getSize(void) {
//  return size;
//}

//int Array::BinSrc(int src, int l = 0, int r = Array::getSize()-1) {
//  if (l>r) return -101;
//  int m = (l+r) / 2;
//  if (arr[m] == src) return arr[m];
//  if (l==r) return -101;
//  if (arr[m] < src) return Array::BinSrc(src, l, m-1);
//  if (arr[m] > src) return Array::BinSrc(src, m+1, r);
//}*/

int main()
{
  Array mass(10);
  mass.Print();
  mass.InsertionSort();
  mass.Print();
  mass.BinarySearch(4);
//  mass.BinSrc(4);

  return 0;
}

