#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal& operator=(const WrongAnimal &other);
	void makeSound() const;

protected:
	std::string type;
private:
	// fields
};

#endif // WRONGANIMAL_HPP
