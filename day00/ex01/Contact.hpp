#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>
#include <iomanip>

class Contact
{
public:
	Contact();
	~Contact();
private:
	std::string m_name;
	std::string m_surname;
	std::string m_nickname;
	std::string m_phone;
	std::string m_secret;
	int	m_assigned;
public:
	void display();
	void assign();
	bool isAssigned();
	void formatDisplay(int index);
private:
	std::string format(std::string str);
};
#endif