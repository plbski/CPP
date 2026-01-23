#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include "../../color.hpp"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstring>
#include <cmath>
#include <exception>

class ScalarConvert {
public:

	static void	convert(std::string string);
private:
	ScalarConvert();
};

void cInt(std::string string,int *i,float *f,double *d);
void cFloat(std::string string,int *i,float *f,double *d);
void cDouble(std::string string,int *i,float *f,double *d);
void cChar(std::string string, int *i, float *f, double *d, char *c);

#endif // SCALARCONVERT_HPP
