#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
public:
	Brain();
	Brain(const Brain &a);
	~Brain();
	Brain & operator = (const Brain &a);


private:
	std::string ideas[100];

public:
	void think(std::string idea);
	void remember();
};

#endif