#pragma once 

#include "array.h"

template <typename T>
class Array2D {
public:
	explicit Array2D(size_t a, size_t b) : a(a), b(b), arr_(a * b) {
	}
	
	T & get_item_2D(size_t i, size_t j) {
		return arr_.get_item(i * b + j);
	}
	
	T get_item_2D(size_t i, size_t j) const {
		return arr_.get_item(i * b + j);
	}
	
	void resize(size_t new_a, size_t new_b) {
		a = new_a;
		b = new_b;
		arr_.resize(a * b);
	}

	size_t rows() const {
		return a;
	}
	
	size_t cols() const {
		return b;
	}
	

private:
	size_t a;
	size_t b;
	Array<T> arr_;
};
