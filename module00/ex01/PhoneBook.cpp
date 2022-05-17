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
	while (m_contacts[i].isAssigned())
	{
		m_contacts[i].formatDisplay(i);
		i++;
	}
	std::cout << std::endl;

	// Request the contact index to display
	int index = 8;
	while (index >= i)
	{
		std::cout << "Insert the index of the contact you want to display: ";
		std::cin >> index;
		if (index >= i)
			std::cout << "Error: index out of range" << std::endl;
	}
	std::cout << std::endl;

	// Display the contact
	m_contacts[index].display();
}