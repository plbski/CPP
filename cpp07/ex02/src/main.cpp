#include <iostream>
#include "../include/Array.tpp"

#define MAX_VAL 25
int main()
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	Array<int> b;
	int * a = new int();
	std::cout << "\n/////EMPTY ARRAY/////\n" << std::endl;
	std::cout << "b : " << *b << std::endl;
	std::cout << "a : " << *a << std::endl;
	std::cout << "\n/////FILE OUT TABLE/////\n" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		std::cout << value << ' ';
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << numbers[i] << ' ';
	}
	std::cout << std::endl;
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	std::cout << "\n/////CHECK VALUE/////\n" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << ">>>>>OK" << std::endl;
	std::cout << "\n/////OUT RANGE TEST/////\n" << std::endl;
	std::cout << "\n--negative index" << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n--max value" << std::endl;
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}