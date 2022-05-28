#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>

class Zombie
{
public:
	Zombie();
	Zombie(std::string newName);
	~Zombie();
	void announce();
	void setName(std::string newName);
private:
	std::string name;
};

#endif