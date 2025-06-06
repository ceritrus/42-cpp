#include "Harl.hpp"

Harl::Harl()
{
	#ifdef DEBUG
		std::cout << "[Harl] : initialized to default" << std::endl;
	#endif
}

Harl::~Harl()
{ 
	#ifdef DEBUG
		std::cout << "[Harl] : destroyed" << std::endl;
	#endif
}

void Harl::complain(std::string level)
{
	void (Harl::*funcs[])(void) = 
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};

	std::string levels[] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++)
		if (level == levels[i])
			(this->*funcs[i])();

}

void Harl::debug()
{
	std::cout << "Debug: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "Info: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "Warning: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "Error: This is unacceptable! I want to speak to the manager now." << std::endl;
}