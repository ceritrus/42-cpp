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
				float value = exchange.extractValue(line);

				if (value <= -1)
					std::cout << "Error: " << std::endl;
				else
				{
					float rate = exchange.getRate(date);
					if (rate < 0)
						std::cout << "Error: date is older than data" << std::endl;
					else
						std::cout << date << " => " << value << " = " << value * rate << std::endl;
				}
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
				continue;
			}
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
}