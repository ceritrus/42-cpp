#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
	: m_index(0)
{
	m_contacts = new Contact[8];
}

PhoneBook::~PhoneBook()
{
	delete[] m_contacts;
}

void PhoneBook::add()
{
	m_contacts[m_index].assign();
	m_index = (m_index + 1) % 8;
}

void PhoneBook::search()
{
	std::cout << "-- SEARCH CONTACT --" << std::endl;
	// Protect empty list
	if (m_contacts[0].isAssigned() == false)
	{
		std::cout << "No contacts in phonebook" << std::endl;
		return ;
	}

	// Display the contact list
	Contact nameless;
	nameless.formatDisplay(-1);
	int i = 0;
	while (m_contacts[i].isAssigned() && i < 8)
	{
		m_contacts[i].formatDisplay(i);
		i++;
	}
	std::cout << std::endl;

	// Request the contact index to display
	int index = 8;
	while (index >= i)
	{
		std::string input;
		std::cout << "Insert the index of the contact you want to display: ";
		std::getline(std::cin, input);
		if (input == "0" || input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "7")
			index = input[0] - '0';
		else
			input = 8;
		if (index >= i)
			std::cout << "Error: index out of range" << std::endl;
	}
	std::cout << std::endl;

	// Display the contact
	m_contacts[index].display();
}