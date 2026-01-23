#include "../include/Span.hpp"

int main(){
	Span test(20);
	// TEST1 one number stored
	std::cout << "\n--------TEST 1--------\n" << std::endl;
	try{
		test.addNumber(1);
		std::cout << test.longestSpan() << std::endl;
	}
	catch(std::exception &e){
		std::cout << "exception catch int Test 1: " << e.what() << std::endl;
	}

	// TEST2 Too many number add
	std::cout << "\n--------TEST 2--------\n" << std::endl;
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
	std::cout << "\n--------TEST 3--------\n" << std::endl;
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
	std::cout << "\n--------TEST 4--------\n" << std::endl;
	Span mega(10000);
	try{
		
		mega.addNumber(-10);
		mega.addNumber(-20);
		for(int i = 0; i < 9995 ;++i)
		{
			mega.addNumber(i + i);
			mega.longestSpan();
			mega.shortestSpan();
		}
		std::cout << mega.longestSpan() << std::endl;
		std::cout << mega.shortestSpan() << std::endl;
	}
	catch(std::exception &e){
		std::cout << "exception catch in test 4 : " << e.what() << std::endl;
	}

	//TEST5 burn my computer
	std::cout << "\n--------TEST 5--------\n" << std::endl;
	try{
		Span copy(30);
		copy.addRange(test._range());
		std::cout << mega.longestSpan() << std::endl;
		std::cout << mega.shortestSpan() << std::endl;
		copy.addRange(test._range());
		
	}
	catch(std::exception &e){
		std::cout << "exception catch in test 4 : " << e.what() << std::endl;
	}
	return(0);


}