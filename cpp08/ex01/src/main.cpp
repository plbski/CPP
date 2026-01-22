#include "../include/Span.hpp"

int main(){
	Span test(20);
	// TEST1 one number stored
	try{
		test.addNumber(1);
		std::cout << test.longestSpan() << std::endl;
	}
	catch(std::exception &e){
		std::cout << "exception catch int Test 1: " << e.what() << std::endl;
	}

	// TEST2 Too many number add
	try{
		for(int i = 0; i < 30 ;++i)
		{
			test.addNumber(8);
		}
		std::cout << test.longestSpan() << std::endl;
	}
	catch(std::exception &e){
		std::cout << "exception catch in test 2 : " << e.what() << std::endl;
	}

	//TEST 3 test global
	try{
		Span mega(10000);
		for(int i = 0; i < 10000 ;++i)
		{
			mega.addNumber(i + i);
		}
		std::cout << mega.longestSpan() << std::endl;
		std::cout << mega.shortestSpan() << std::endl;
	}
	catch(std::exception &e){
		std::cout << "exception catch in test 3 : " << e.what() << std::endl;
	}
	//TEST4 burn my computer
	try{
		Span mega(10000);
		mega.addNumber(-10);
		mega.addNumber(-20);
		for(int i = 0; i < 9995 ;++i)
		{
			mega.addNumber(i + i);
			std::cout << mega.longestSpan() << std::endl;
			std::cout << mega.shortestSpan() << std::endl;
		}
	}
	catch(std::exception &e){
		std::cout << "exception catch in test 3 : " << e.what() << std::endl;
	}
	return(0);
	return(0);


}