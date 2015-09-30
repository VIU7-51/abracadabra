#ifndef SORTING_H
#define SORTING_H
//#pragma once
#include "targetver.h"
#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>

//namespace Massive {
	
	class Array
	{
	protected:
		int *arr;
	public:
		Array();
		~Array();
		void Print();
		void SelectSort();
		//void BubbleSort();
		//void InsertSort();
		//void ShellSort();
	};

//} //namespace Massive

#endif
