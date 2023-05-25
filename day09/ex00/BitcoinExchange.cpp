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
		float entry;
		ss >> entry;
		_data[dateToInt(date)] = entry;
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
		float entry;
		ss >> entry;

		_data[dateToInt(date)] = entry;
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
	int dateInt = dateToInt(date);
	if (_data.find(dateInt) == _data.end())
	{
		std::map<int, float>::const_iterator closest = _data.lower_bound(dateInt);
		if (closest == _data.begin())
			return -1;
		closest--;
		return (closest)->second;
	}
	else
		return _data.at(dateInt);
}

float BitcoinExchange::extractRate(std::string const & line) const
{
	float entry;
	std::string temp;

	std::stringstream ss(line);
	std::getline(ss, temp, '-');
	if (temp.empty() || temp.size() != 4)
	{
		throw std::runtime_error("Error: bad input (year) -> " + line);
	}
	temp = "";

	std::getline(ss, temp, '-');
	if (temp.empty() || temp.size() != 2)
	{
		throw std::runtime_error("Error: bad input (month) -> " + line);
	}
	int month = std::atoi(temp.c_str());
	if (month < 1 || month > 12)
		throw std::runtime_error("Error: bad input (month) -> " + line);
	temp = "";

	std::getline(ss, temp, ',');
	if (temp.empty()  || temp.size() != 2)
	{
		throw std::runtime_error("Error: bad input (day) -> " + line);
	}
	int day = std::atoi(temp.c_str());
	if (day < 1 || day > 31)
		throw std::runtime_error("Error: bad input (day) -> " + line);
	temp = "";

	std::getline(ss, temp);
	if (temp.empty())
	{
		throw std::runtime_error("Error: bad input (rate) -> " + line);
	}
	if (temp.find_first_not_of("0123456789.") != std::string::npos)
		throw std::runtime_error("Error: bad input => " + line);
	entry = std::atof(temp.c_str());
	temp = "";

	return entry;
}

int BitcoinExchange::dateToInt(std::string const & date) const
{
	std::string temp;
	std::stringstream ss(date);
	std::getline(ss, temp, '-');
	int year = std::atoi(temp.c_str());
	temp = "";
	std::getline(ss, temp, '-');
	int month = std::atoi(temp.c_str());
	temp = "";
	std::getline(ss, temp);
	int day = std::atoi(temp.c_str());
	return (year * 10000 + month * 100 + day);
}

float BitcoinExchange::extractValue(std::string const & line) const
{
	float entry;
	std::string temp;

	std::stringstream ss(line);
	std::getline(ss, temp, '-');
	if (temp.empty() || temp.size() != 4)
	{
		throw std::runtime_error("Error: bad input (year) -> " + line);
	}
	temp = "";

	std::getline(ss, temp, '-');
	if (temp.empty() || temp.size() != 2)
	{
		throw std::runtime_error("Error: bad input (month) -> " + line);
	}
	int month = std::atoi(temp.c_str());
	if (month < 1 || month > 12)
		throw std::runtime_error("Error: bad input => " + line);
	temp = "";

	std::getline(ss, temp, ' ');
	if (temp.empty()  || temp.size() != 2)
	{
		throw std::runtime_error("Error: bad input => " + line);
	}
	int day = std::atoi(temp.c_str());
	std::getline(ss, temp, ' ');
	if (day < 1 || day > 31)
		throw std::runtime_error("Error: bad input => " + line);
	temp = "";

	std::getline(ss, temp);
	if (temp.empty())
	{
		throw std::runtime_error("Error: bad input => " + line);
	}
	if (temp.find_first_not_of("0123456789.") != std::string::npos)
		throw std::runtime_error("Error: bad input => " + line);
	entry = std::atof(temp.c_str());
	if (entry < 0)
		throw std::runtime_error("Error: not a positive number.");
	else if (entry > 1000)
		throw std::runtime_error("Error: too large a number.");
	temp = "";

	return entry;
}
