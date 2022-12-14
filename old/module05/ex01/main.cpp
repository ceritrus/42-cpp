#include "Bureaucrat.hpp"
#define BREAKLINE std::cout << "###" << std::endl;

int	main(void)
{
	Bureaucrat daniel("Daniel", 72);
	
	try
	{
		Form form("Unimportant taxes", 150, 150);
		daniel.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	BREAKLINE

	try 
	{
		Form form("Coffee-10", 10, 75);
		daniel.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	BREAKLINE

	try 
	{
		Form form("Paycheck", 80, 0);
		daniel.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	BREAKLINE

	try 
	{
		Form form("Mousecheese", 100, 1000);
		daniel.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	BREAKLINE

	try
	{
		Form form("Some paper", 620, 40);
		std::cout << form << form;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	BREAKLINE

	try
	{
		Form form("A very cool form", -50, 10);
		std::cout << form << form;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	BREAKLINE

	try
	{
		Form form("B12-c127", 100, 100);
		daniel.signForm(form);
		daniel.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	BREAKLINE

	return (0);
}