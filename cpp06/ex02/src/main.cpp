#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

Base *generate(void)
{
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
	std::srand(time(0));
	for (int i = 0; i < 20; ++i) {
    Base *p = generate();
    identify(p);
    delete p;
	}
	for (int i = 0; i < 20; ++i) {
    	Base *p = generate();
    	Base &r = *p;
    	identify(r);
    	delete p;
}
	return(0);
}