#include "Span.hpp"
#include <limits>

Span::Span()
{
	#ifdef DEBUG
		std::cout << "\033[33m[Span]\033[0m Default constructor called" << std::endl;
	#endif 
	this->_size = 0;
	this->_vec = std::vector<int>();
}

Span::Span(unsigned int size) : _size(size)
{
	#ifdef DEBUG
		std::cout << "\033[33m[Span]\033[0m Constructor called" << std::endl;
	#endif 
	this->_vec = std::vector<int>();
}

Span::Span(const Span & copy)
{
	#ifdef DEBUG
		std::cout << "\033[33m[Span]\033[0m Copy constructor called" << std::endl;
	#endif 
	this->_size = copy._size;
	this->_vec = copy._vec;
}

Span::~Span()
{
	#ifdef DEBUG
		std::cout << "\033[33m[Span]\033[0m Destructor called" << std::endl;
	#endif 
}

void Span::addNumber(int num)
{
	if (this->_vec.size() < this->_size)
		this->_vec.push_back(num);
	else
		throw SpanException("\033[31m[Span]\033[0m Cannot add to span - it is already full");
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int>::iterator cur = begin;
    while (cur != end)
    {
        this->addNumber(*cur);
        cur++;
    }
}

void Span::fillRandom()
{
	std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float>dist(-4096.0f, 4096.0f);
	while (this->_vec.size() != this->_size)
		this->addNumber(static_cast<int>(dist(mt)));
}

int Span::shortestSpan()
{
	if (this->_vec.size() < 2)
		throw SpanException("\033[31m[Span]\033[0m Not enough elements in span to calculate the shortest");
	std::vector<int> sorted = this->_vec;
	std::sort(sorted.begin(), sorted.end());
	int shortest = INT_MAX;
	for (std::vector<int>::iterator it = this->_vec.begin(); it != this->_vec.end() - 1; it++)
		shortest = std::abs((*(it + 1)) - *it) < shortest ? std::abs((*(it + 1)) - *it) : shortest;
	return shortest;
}

int Span::longestSpan()
{
	if (this->_vec.size() < 2)
		throw SpanException("\033[31m[Span]\033[0m Not enough elements in span to calculate the longest");
	std::vector<int> sorted = this->_vec;
	std::sort(sorted.begin(), sorted.end());
	return sorted.back() - sorted.front();
}

Span & Span::operator=(const Span & rhs)
{
	#ifdef DEBUG
		std::cout << "\033[33m[Span]\033[0m Copy assignment operator called" << std::endl;
	#endif 
	this->_size = rhs._size;
	this->_vec = rhs._vec;
	return *this;
}