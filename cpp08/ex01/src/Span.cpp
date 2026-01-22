#include "../include/Span.hpp"

Span::Span(int N): i_max(N){
	_span.reserve(N);
	std::cout << "Span default constructor called"<< std::endl;
}

Span::~Span() {
	std::cout << "Span destructor called" << std::endl;
}

Span::Span(const Span &other) {
	std::cout << "Span copy constructor called" << std::endl;
	*this = other;
}

Span& Span::operator=(const Span &other) {
	std::cout << "Span copy assignment operator called" << std::endl;
	if (this != &other) {
		(void)other;
	}
	return *this;
}

void Span::addNumber(int n)
{
	// std::cout << _span.size() << std::endl;
	if (_span.size() >= i_max )
		throw(SpanException("Span is full"));
	_span.push_back(n);
}

int Span::shortestSpan()
{
	if (_span.size() < 2)
		throw(SpanException("too few numbers stored"));
	int shortest = std::numeric_limits<int>::max();
	int test;
	std::vector<int> _sort = _span;
	std::sort(_sort.begin(), _sort.end());
	for (size_t i = 1; i < _sort.size(); ++i)
	{
		test = _sort[i] - _sort[i -1];
		if (test < shortest)
			shortest = test;
	}
	return(shortest);
}

int Span::longestSpan()
{
	if (_span.size() < 2)
		throw(SpanException("too few numbers stored"));
	std::vector<int> _sort = _span;
	std::sort(_sort.begin(), _sort.end());
	return(_sort[_sort.size() - 1] - _sort[0]);
}