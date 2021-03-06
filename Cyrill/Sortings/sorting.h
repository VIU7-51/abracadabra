//заголовочный (хэдер) файл для определения класса массива и различные сортировки, функции класса;

#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <tchar.h>
#include "targetver.h"
#include "stdafx.h"


//namespace Massive {
	
	class Array
	{
	protected:
		int *arr;
	public:
		Array();
		~Array();
		void Print();
		void SelectSort();  //сортировка выборкой
		void BubbleSort();  //сортировка пузырьком
		void ShakerSort();  //шейрек-сортировка
		void InsertSort();  //сортировка простыми вставками
		//void ShellSort();   //сортировка Шелла
	};

//} //namespace Massive

#endif
