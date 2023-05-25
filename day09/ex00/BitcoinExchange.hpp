#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(std::string const & path);
	BitcoinExchange(BitcoinExchange const & src);
	~BitcoinExchange();

	BitcoinExchange & operator=(BitcoinExchange const & rhs);
	
	float getRate(std::string const & date) const;
	float extractRate(std::string const & line) const;
	float extractValue(std::string const & line) const;
	size_t getDataSize() const;
	int dateToInt(std::string const & date) const;

private:
	std::string 							_path;
	std::map<int, float> 	_data;
};