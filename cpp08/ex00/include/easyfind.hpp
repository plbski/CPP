#pragma once

#include<string>
#include<iostream>
#include<vector>



template <typename T>
int finder(T a, int b)
{
	int i = 0;
	while (a[i] && a[i] != b ){i ++;}
	if (a[i] == b)
		return(i);
	return(-1);
}