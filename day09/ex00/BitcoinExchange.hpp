#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>


typedef struct {
	int year;
	int month;
	int day;
	float rate;
} BitcoinEntry;

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(std::string const & path);
	BitcoinExchange(BitcoinExchange const & src);
	~BitcoinExchange();

	BitcoinExchange & operator=(BitcoinExchange const & rhs);
	
	float getRate(std::string const & date) const;
	BitcoinEntry parser(std::string const & line) const;
	BitcoinEntry inputParser(std::string const & line) const;
	size_t getDataSize() const;
private:
	std::string 							_path;
	std::map<std::string, BitcoinEntry> 	_data;
};