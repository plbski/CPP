#pragma once

#include <iostream>
#include <vector>
#include <limits>
#include <cstring>
#include <cmath>
#include <exception>
#include <algorithm>

class Span {
public:
	Span(int N);
	~Span();
	Span(const Span &other);
	Span& operator=(const Span &other);
	void addNumber(int n);
	int shortestSpan();
	int longestSpan();
	std::vector<int> _range();
	void addRange(std::vector<int> range);

	class SpanException : public std::exception
	{
		public:
			SpanException(const std::string &_message): message(_message){};
			~SpanException() throw() {};
			const char* what() const throw(){
				return(message.c_str());
			}
		private:
			std::string message;
	};

private:
	std::vector<int> _span;
	size_t i_max;
};

