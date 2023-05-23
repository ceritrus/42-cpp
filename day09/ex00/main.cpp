#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc [file]" << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange exchange("data.csv");

		std::ifstream file(argv[1]);
		if (!file.is_open())
		{
			throw std::runtime_error("Error: could not open file -> " + std::string(argv[1]));
		}

		std::string line;
		while (std::getline(file, line))
		{
			if (line == "date | value")
				continue;
			std::stringstream ss(line);
			std::string date;
			std::getline(ss, date, ' ');

			try
			{
				BitcoinEntry entry = exchange.inputParser(line);
				float rate = exchange.getRate(date);
				std::cout << entry.year << "-";
				if (entry.month < 10)
					std::cout << "0";
				std::cout << entry.month << "-";
				if (entry.day < 10)
					std::cout << "0";
				std::cout << entry.day << " => " << entry.rate << " = " << entry.rate * rate << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
				continue;
			}
			
			// exchange.getRate(date);
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
}