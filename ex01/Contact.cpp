#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "Please input the new contact's name: ";
	std::getline(std::cin, m_name);
	std::cout << "Please input the new contact's last name: ";
	std::getline(std::cin, m_last_name);
	std::cout << "Please input the new contact's nickname: ";
	std::getline(std::cin, m_nickname);
	std::cout << "Please input the new contact's phone number: ";
	std::getline(std::cin, m_phone_number);
	std::cout << "Please input the new contact's darkest secret: ";
	std::getline(std::cin, m_darkest_secret);
}

Contact::~Contact()
{

}

void Contact::displayContact()
{
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Last Name: " << m_last_name << std::endl;
	std::cout << "Nickame: " << m_nickname << std::endl;
	std::cout << "Phone Number: " << m_phone_number << std::endl;
	std::cout << "Darkest Secret: " << m_darkest_secret << std::endl;
}