#pragma once

#include<iostream>
#include<map>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>

class BitException : public std::exception
{
	public:
		BitException(const std::string &_message): message(_message){};
		~BitException() throw() {};
		const char* what() const throw(){
			return(message.c_str());
		}
	private:
		std::string message;
};

void	reader(std::map<time_t, float>data, char *av);
time_t	convert_date(std::string line);
bool	isfloat(std::string string);
bool	isInt(std::string string);
































