#include <iostream>

int main()
{
	int *a = new int(2);
	a[1] = 2;
	a[5] = 9;
	a[3] = 9;
	a[2] = 0;
	std::cout << a[5] << std::endl;
}