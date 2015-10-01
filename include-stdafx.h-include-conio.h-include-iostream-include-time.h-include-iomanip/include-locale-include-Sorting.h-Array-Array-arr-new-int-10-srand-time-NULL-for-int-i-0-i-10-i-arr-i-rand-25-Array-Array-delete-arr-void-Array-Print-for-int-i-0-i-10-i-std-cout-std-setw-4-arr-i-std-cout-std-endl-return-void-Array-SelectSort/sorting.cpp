#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <time.h>
#include <iomanip>

//#include <locale>

#include "Sorting.h"

	
	Array::Array() {
		arr = new int[10];
		srand(time(NULL));
		for (int i = 0; i < 10; i++)
		{
			arr[i] = rand() % 25;
		};
	}

	Array::~Array() {
		delete [] arr;
	}

	
	void Array::Print() {
		for (int i = 0; i < 10; i++)
		{
			std::cout << std::setw(4) << arr[i];
		}
		std::cout << std::endl;
		return;
	}



	
	void Array::SelectSort() {
		//setlocale(LC_ALL, "");
		int i, j, k;
		int temp;
		for (i = 0; i < 10; i++)
		{
			k = i;
			temp = arr[i];
			for (j = i + 1; j < 10; j++)
				if (arr[j] < temp)
				{
					k = j;
					temp = arr[j];
					std::cout << "k = " << k << '\t' << "j = " << j << std::endl;
					std::cout << "temp = " << temp << '\t' << "(j)arr[" << j << "] = " << arr[j] << std::endl;
				}
				arr[k] = arr[i];
				arr[i] = temp;
		}
		return;
	}
