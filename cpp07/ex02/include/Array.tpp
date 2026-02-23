#pragma once

#include<iostream>
#include <cstdlib>
#include <ctime>

template<typename T>
class Array{
	public:
		Array() : data(new T()), _size(0) {};
		Array(unsigned int N) : data(new T[N]), _size(N) {};
		Array(const Array &other) : data(new T[other._size]), _size(other._size) {
				*this = other;
		};
		~Array(){};
		Array& operator=(const Array &other)
		{
			for (int i = 0; i < other._size &&  i < _size; i ++)
				data[i] = other.data[i];
			return(*this);
		};
		T& operator[](const int i)
		{
			if (i >= _size || i < 0)
				throw(std::out_of_range("out of range"));
			return(data[i]);
		}
		const T& operator[](const int i) const
		{
			if (i >= _size || i < 0)
				throw(std::out_of_range("out of range"));
			return(data[i]);
		}
		T& operator*(){return(*data);};
		int size(){return(_size);};
	private:
		T *data;
		int _size;
};