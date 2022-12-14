#include "Contact.hpp"

Contact::Contact() 
	: m_assigned(0)
{
	m_name = std::string("Name");
	m_surname = std::string("Surname");
	m_nickname = std::string("Nickname");
	m_phone = std::string("Phone ##");
	m_secret = std::string("Secret");
}

Contact::~Contact()
{

}

void Contact::display()
{
	std::cout << "-- CONTACT INFOS --" << std::endl;
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Last Name: " << m_surname << std::endl;
	std::cout << "Nickame: " << m_nickname << std::endl;
	std::cout << "Phone Number: " << m_phone << std::endl;
	std::cout << "Darkest Secret: " << m_secret << std::endl;
	std::cout << std::endl;
}

void Contact::assign()
{
	m_assigned = 1;
	std::cout << "-- NEW CONTACT --" << std::endl;
	std::cout << "New contact's name: ";
	std::getline(std::cin, m_name);
	std::cout << "New contact's last name: ";
	std::getline(std::cin, m_surname);
	std::cout << "New contact's nickname: ";
	std::getline(std::cin, m_nickname);
	std::cout << "New contact's phone number: ";
	std::getline(std::cin, m_phone);
	std::cout << "New contact's darkest secret: ";
	std::getline(std::cin, m_secret);
	std::cout << std::endl;
}

bool Contact::isAssigned()
{
	return m_assigned;
}

void Contact::formatDisplay(int index)
{
	// Index
	std::cout << std::setfill(' ') << std::setw(10);
	if (index < 0)
		std::cout << "Index";
	else
		std::cout << index;
	std::cout << std::resetiosflags(std::ios::showbase) << "|";

	// Name
	std::cout << std::setfill(' ') << std::setw(10) << format(m_name);
	std::cout << std::resetiosflags(std::ios::showbase) << "|";

	// Last Name
	std::cout << std::setfill(' ') << std::setw(10) << format(m_surname);
	std::cout << std::resetiosflags(std::ios::showbase) << "|";

	// Nickname
	std::cout << std::setfill(' ') << std::setw(10) << format(m_nickname);
	std::cout << std::resetiosflags(std::ios::showbase) << std::endl;
}

std::string Contact::format(std::string str)
{
	std::string output;
	if (str.size() > 10)
	{
		output = str.substr(0, 9);
		output.append(".");
	}
	else
		output = str;
	return output;
}