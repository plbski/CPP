#include "../include/Serializer.hpp"

int main()
{
	Data data;
	data.x = 13;
	Serializer test;
	uintptr_t raw = test.serialize(&data);
	std::cout << raw << std::endl;
	Data *c = test.deserialize(raw);
	std::cout << c->x << std::endl;
	return(0);
}
