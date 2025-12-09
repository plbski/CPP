#pragma once

#include<iostream>
#include "../../color.hpp"

template<typename T>
class Array{
	public:
		Array() : data(new T[0]), size(0) {};
		Array(unsigned int N) : data(new T[N]), size(N) {};
		Array(const Array &other) : data(new T[other.size]), size(other.size) {
				*this = other;
		};
		~Array(){};
		Array& operator=(const Array &other)
		{
			for (unsigned int i = 0; i < other.size &&  i < size; i ++)
				data[i] = other.data[i];
			return(*this);
		};
		T& operator[](const unsigned int i)
		{
			if (i >= size)
				throw(std::out_of_range("out of range"));
			return(data[i]);
		}
		const T& operator[](const unsigned int i) const
		{
			if (i >= size)
				throw(std::out_of_range("out of range"));
			return(data[i]);
		}

	private:
		T *data;
		unsigned int size;
};