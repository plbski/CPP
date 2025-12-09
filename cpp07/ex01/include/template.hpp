#pragma once

#include<iostream>

template<typename T>
void iter(T *c, int size, void (*f)(T))
{
	for(int i = 0; i < size; i ++)
	{
		f(c[i]);
	}
}

template<typename T>
void iter(T const *c, int size, void (*f)(const T))
{
	for(int i = 0; i < size; i ++)
	{
		f(c[i]);
	}
}
