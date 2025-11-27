#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>

struct Data{
	int x;
};


class Serializer {
public:
	Serializer();
	~Serializer();
	Serializer(const Serializer &other);
	Serializer& operator=(const Serializer &other);
	uintptr_t	serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);

private:
	// fields
};

#endif // SERIALIZER_HPP
