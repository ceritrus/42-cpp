#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _path("data.csv")
{
	std::ifstream file(_path.c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("Error: could not open file -> " + _path);
	}
	std::string line;
	while (std::getline(file, line))
	{
		if (line == "date,exchange_rate")
			continue;
		std::stringstream ss(line);
		std::string date;
		std::getline(ss, date, ',');
		BitcoinEntry entry;
		entry = parser(line);
		ss >> entry.rate;
		// if (entry.rate < 0 || entry.rate > 1000)
		// 	throw std::runtime_error("Error: bad input (rate) -> " + line);
		_data[date] = entry;
	}
}

BitcoinExchange::BitcoinExchange(std::string const & path) : _path(path)
{
	std::ifstream file(_path.c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("Error: could not open file -> " + _path);
	}
	std::string line;
	while (std::getline(file, line))
	{
		if (line == "date,exchange_rate")
			continue;
		std::stringstream ss(line);
		std::string date;
		std::getline(ss, date, ',');
		BitcoinEntry entry;
		entry = parser(line);
		ss >> entry.rate;
		// if (entry.rate < 0 || entry.rate > 1000)
		// 	throw std::runtime_error("Error: bad input (rate) -> " + line);
		_data[date] = entry;
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{
	_data.clear();
	_path.clear();
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	if (this != &rhs)
	{
		_path = rhs._path;
		_data = rhs._data;
	}
	return *this;
}

float BitcoinExchange::getRate(std::string const & date) const
{
	if (_data.find(date) == _data.end())
	{
		// iterate over map to find closest date
		for (std::map<std::string, BitcoinEntry>::const_iterator it = _data.begin(); it != _data.end(); ++it)
		{
			if (it->first > date)
			{
				if (it != _data.begin())
					it--;
				return it->second.rate;
			}
		}
	}
	return _data.at(date).rate;
}

BitcoinEntry BitcoinExchange::parser(std::string const & line) const
{
	BitcoinEntry entry;
	std::string temp;

	std::stringstream ss(line);
	std::getline(ss, temp, '-');
	if (temp.empty() || temp.size() != 4)
	{
		throw std::runtime_error("Error: bad input (year) -> " + line);
	}
	entry.year = std::atoi(temp.c_str());
	temp = "";

	std::getline(ss, temp, '-');
	if (temp.empty() || temp.size() != 2)
	{
		throw std::runtime_error("Error: bad input (month) -> " + line);
	}
	entry.month = std::atoi(temp.c_str());
	if (entry.month < 1 || entry.month > 12)
		throw std::runtime_error("Error: bad input (month) -> " + line);
	temp = "";

	std::getline(ss, temp, ',');
	if (temp.empty()  || temp.size() != 2)
	{
		throw std::runtime_error("Error: bad input (day) -> " + line);
	}
	entry.day = std::atoi(temp.c_str());
	if (entry.day < 1 || entry.day > 31)
		throw std::runtime_error("Error: bad input (day) -> " + line);
	temp = "";

	std::getline(ss, temp);
	if (temp.empty())
	{
		throw std::runtime_error("Error: bad input (rate) -> " + line);
	}
	entry.rate = std::atof(temp.c_str());
	temp = "";

	return entry;
}

BitcoinEntry BitcoinExchange::inputParser(std::string const & line) const
{
	BitcoinEntry entry;
	std::string temp;

	std::stringstream ss(line);
	std::getline(ss, temp, '-');
	if (temp.empty() || temp.size() != 4)
	{
		throw std::runtime_error("Error: bad input (year) -> " + line);
	}
	entry.year = std::atoi(temp.c_str());
	temp = "";

	std::getline(ss, temp, '-');
	if (temp.empty() || temp.size() != 2)
	{
		throw std::runtime_error("Error: bad input (month) -> " + line);
	}
	entry.month = std::atoi(temp.c_str());
	if (entry.month < 1 || entry.month > 12)
		throw std::runtime_error("Error: bad input => " + line);
	temp = "";

	std::getline(ss, temp, ' ');
	if (temp.empty()  || temp.size() != 2)
	{
		throw std::runtime_error("Error: bad input => " + line);
	}
	entry.day = std::atoi(temp.c_str());
	std::getline(ss, temp, ' ');
	if (entry.day < 1 || entry.day > 31)
		throw std::runtime_error("Error: bad input => " + line);
	temp = "";

	std::getline(ss, temp);
	if (temp.empty())
	{
		throw std::runtime_error("Error: bad input => " + line);
	}
	entry.rate = std::atof(temp.c_str());
	if (entry.rate < 0)
		throw std::runtime_error("Error: not a positive number.");
	else if (entry.rate > 1000)
		throw std::runtime_error("Error: too large a number.");
	temp = "";

	return entry;
}
