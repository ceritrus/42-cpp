#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>
int main(void)
{
	PhoneBook phonebook;
	std::string input;
	while (1)
	{
		std::cout << "-- MENU --" << std::endl;
		std::cout << "PhoneBook: ";
		std::getline(std::cin, input);
		std::cout << std::endl;
		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
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