#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
private:
	Contact *m_contacts;
	int	m_index;
public:
	void add();
	void search();
};
#endif