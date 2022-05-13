#include <iostream>

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
public:
	void displayContact();
};