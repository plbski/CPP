#pragma once

#include<iostream>

template<typename T, int N>
class Array{
	public:
		Array();
		Array(unsigned int N);
		Array(const Array &other);
		~Array();
		Array& operator=(const Array &other);

	private:

};