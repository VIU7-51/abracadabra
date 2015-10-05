#include <conio.h>
#include <iomanip>
#include <iostream>
#include <time.h>
#include "Sorting.h"
#include "stdafx.h"

	
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
			for (j = i + 1; j < 10; j++) if (arr[j] < temp)
							{
								k = j;
								temp = arr[j];
							}
			arr[k] = arr[i];
			arr[i] = temp;
		}
		return;
	}
	
	void Array::BubbleSort() {
		int temp;
		for (int j, i = 0; i < SIZE; i++) {
			for ( j = SIZE - 1; j > 0; j--) {
				if (arr[j] < arr[j - 1]) {
					temp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = temp;
				}
			}
		}
		return;
	}
	
	void Array::ShakerSort() {
		int i, j = SIZE-1;
  		int left = 1, right = SIZE-1;
  		int temp;
  		do {
		    for( i = right; i > 0; i-- ) {
      			if ( arr[i - 1] > arr[i] ) {
        		    temp = arr[i - 1]; arr[i - 1] = arr[i]; arr[i]=temp;
        		    j = i;
      		    	}
    	   	    }
		    left = j + 1;
		    for (i = 1; i <= right; j++) {
      			if ( arr[i - 1] > arr[i] ) {
			    temp = arr[i - 1]; arr[i - 1] = arr[i];
			    arr[i] = temp;
        		    j = i;
			}
    		    }
		    right = j - 1;
  		} while ( left < right );
	}
	
	void Array::InsertSort() {
		int temp;
		for (int j, i = 0, i < SIZE, i++) {
			for (j = i  -1, j >= 0 && arr[j] > x, j-- ) arr[j + 1] = arr[j];
			arr[j + 1] = temp;
		}
	}
