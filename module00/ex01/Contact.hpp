#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
public:
	Contact();
	~Contact();
private:
	std::string m_name;
	std::string m_last_name;
	std::string m_nickname;
	std::string m_phone_number;
	std::string m_darkest_secret;
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