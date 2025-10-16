#include "../include/FragTrap.hpp"

FragTrap::FragTrap(std::string n) : ClapTrap(n, 100, 100, 30) {
    std::cout << BOLDMAGENTA << n << " is born !!"<< std
}

FragTrap::~FragTrap() {
    // destructor
}
