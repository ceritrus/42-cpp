#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phonebook;
	std::string input;
	while (1)
	{
		std::cout << "-- MENU --" << std::endl;
		std::cout << "PhoneBook: ";
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			std::cout << std::endl;
			phonebook.add();
		}
		else if (input == "SEARCH")
		{
			phonebook.search();
			std::cout << std::endl;
		}
		else if (input == "EXIT")
		{
			std::cout << "-- EXIT --" << std::endl << "Bye!" << std::endl;
			return 0;
		}
		else
		{
			std::cout << "Error: invalid input" << std::endl;
			std::cout << std::endl;
		}
	}
}