#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include "../../color.hpp"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <limits>


class ScalarConvert {
public:
	ScalarConvert();
	~ScalarConvert();
	ScalarConvert(const ScalarConvert &other);
	ScalarConvert& operator=(const ScalarConvert &other);
	static void	convert(std::string string);

private:
	// fields
};

#endif // SCALARCONVERT_HPP
