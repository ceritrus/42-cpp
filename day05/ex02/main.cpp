#include <iostream>
#include <stdlib.h>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define BREAKLINE std::cout << "###" << std::endl;

int main(void)
{
	srand(time(NULL));

	Bureaucrat supervisor("Supervisor", 1);
	std::cout << supervisor << std::endl;
	Bureaucrat adam("Adam", 25);
	std::cout << adam << std::endl;

	Form *shrub = new ShrubberyCreationForm("home");
	std::cout << *shrub << std::endl;
	shrub->beSigned(supervisor);
	shrub->execute(adam);

	Form *pres = new PresidentialPardonForm("Adam");
	std::cout << *pres << std::endl;
	supervisor.signForm(*pres);
	pres->execute(supervisor);

	Form *marvin = new RobotomyRequestForm("Marvin");
	std::cout << *marvin << std::endl;
	marvin->beSigned(supervisor);
	marvin->execute(adam);
	adam.executeForm(*marvin);
	adam.executeForm(*marvin);
	BREAKLINE

	try
	{
		adam.executeForm(*pres);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	BREAKLINE

	try
	{
		RobotomyRequestForm marvin = RobotomyRequestForm("Marvin");
		std::cout << marvin << std::endl;
		marvin.execute(supervisor);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	BREAKLINE

	try
	{
		PresidentialPardonForm pres = PresidentialPardonForm("Adam");
		std::cout << pres << std::endl;
		supervisor.signForm(pres);
		pres.execute(adam);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	BREAKLINE

	try
	{
		PresidentialPardonForm pres = PresidentialPardonForm("Adam");
		std::cout << pres << std::endl;
		supervisor.signForm(pres);
		adam.executeForm(pres);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete shrub;
	delete pres;
	delete marvin;

	return (0);
}