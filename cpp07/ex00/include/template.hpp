#pragma once

#include<iostream>

template<typename T>
	void swap(T& a, T& b)
	{
		T c = a;
		a = b;
		b = c;
	}

template<typename T>
T max(T x, T y)
{
	if (x <= y)
		return(y);
	return(x);
}

template<typename T>
T min(T x, T y)
{
	if (x >= y)
		return(y);
	return(x);
}

