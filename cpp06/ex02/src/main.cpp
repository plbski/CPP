#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <typeinfo>

Base *generate(void)
{
	std::srand(time(0));
	switch (std::rand()%3)
	{
	case 0:
		return(new A);
		break;
	case 1:
		return(new B);
		break;
	case 2:
		return(new C);
		break;
	default:
		break;
	}
	return(NULL);
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if(dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if(dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try{
		A a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (const std::bad_cast& e) {
		try
		{
			B b =dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(const std::bad_cast& e)
		{
			try
			{
				C c =dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch(const std::bad_cast& e)
			{
				std::cout << "no class match" << std::endl;
			}
		}
	}
}

int main()
{
	Base *test = generate();
	std::cout << typeid(*test).name() << std::endl;
	identify(test);
	Base &tes = *generate();
	std::cout << typeid(tes).name() << std::endl;
	identify(tes);
	delete(test);
	return(0);
}