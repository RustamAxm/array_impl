//============================================================================
// Name        : array_impl.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Array2D.h"

using namespace std;

template <typename T>
void Print(Array<T> const & a) {
	const size_t n =  a.size();
	for (size_t i = 0; i < n; i++) {
		cout << a.get_item(i) << " ";
	}
	cout << endl;
}

void test_1D() {
	Array<double> test(10);
	Print(test);
	test.resize(20);
	Print(test);
	test.get_item(0) = 1;
	Print(test);
	Array<double> new_t = test;
	Print(new_t);
	cout << new_t.get_item(0) << endl;
}

template <typename T>
void Print2D(Array2D<T> & arr) {
	const size_t a = arr.rows();
	const size_t b = arr.cols();
	for(size_t i = 0; i < a; i++) {
		for(size_t j = 0; j < b; j++) {
			cout << arr.get_item_2D(i, j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void test_2D() {
	size_t a = 10;
	size_t b = 5;
	Array2D<int> test(a, b);
	Print2D(test);
	test.get_item_2D(0, 3) = 2;
	Print2D(test);
	Array2D<int> copy = test;
	Print2D(copy);
	copy.resize(5, 10);
	Print2D(copy);
	copy.resize(10, 6);
	Print2D(copy);
}

int main() {
	test_1D();
	test_2D();
	return 0;
}
