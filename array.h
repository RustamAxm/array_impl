#pragma once

#include <cstdlib>
#include <algorithm>


template <typename T>
class Array {
public:
	explicit Array(size_t size) :
	size_(size), arr(new T [size]) {
		for (size_t i = 0; i < size; i++) {
			arr[i] = 0;
		}
	}

	Array(Array const & other_a) :
		size_(other_a.size_), arr(new T [size_]) {
		for (size_t i = 0; i < size_; i++) {
			arr[i] = other_a.arr[i];
		}
	}

	Array & operator=(Array const & other_a) {
		if (this != & other_a) {
			Array(other_a).swap(*this);
		}
		return *this;
	}

	size_t size() const noexcept {
		return size_;
	}

	T get_item(size_t i) const {
		return arr[i];
	}

	T & get_item(size_t i) {
		return arr[i];
	}

	void resize(size_t new_size) {
		Array tmp(new_size);
		size_t n = new_size > size_ ? size_ : new_size;
		for (size_t i = 0; i < n; i++) {
			tmp.arr[i] = arr[i];
		}
		swap(tmp);
	}

	~Array() {
		delete [] arr;
	}

private:
	size_t size_= 0;
	T * arr;

	void swap(Array & other_a) {
		std::swap(size_, other_a.size_);
		std::swap(arr, other_a.arr);
	}
};
