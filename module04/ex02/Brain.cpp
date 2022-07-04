#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Constructor: Brain" << std::endl;
}

Brain::Brain(const Brain &a)
{
	std::cout << "Copy Constructor: Brain" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = a.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Destructor: Brain" << std::endl;
}

Brain & Brain::operator = (const Brain &a)
{
	std::cout << "Copy Assignment Operator: Brain" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = a.ideas[i];
	return *this;
}

void Brain::think(std::string idea)
{
	int i = 0;
	while (i < 100 && !ideas[i].empty())
		i++;
	if (i < 100)
		ideas[i] = idea;	
}

void Brain::remember()
{
	for (int i = 0; i < 100; i++)
	{
		if (ideas[i].length() > 0)
		{
			std::cout << "\t" << i << ": " << ideas[i] << std::endl;
		}
	}
}
