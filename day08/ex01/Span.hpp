#pragma once
#include <iostream>
#include <vector>
#include <random>
class Span
{
public:
	Span();
	Span(unsigned int size);
	Span(const Span & copy);
	~Span();

	Span & operator = (const Span & rhs);

private:
	std::vector<int> _vec;
	unsigned int _size;

public:
	void addNumber(int Num);
	void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	void fillRandom();
	int shortestSpan();
	int longestSpan();

	class SpanException : public std::runtime_error
    {
    public:
        SpanException(std::string message) : std::runtime_error(message) {};
    };
};