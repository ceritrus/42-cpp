#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	louis("Louis", 2);
		std::cout << louis << std::endl;
		louis.incGrade();
		std::cout << louis << std::endl;
        for (int i = 0; i < 149; i++)
		    louis.decGrade();
		std::cout << louis << std::endl;
		louis.decGrade();
        std::cout << "Exception should be thrown so no one should read this" << std::endl; 
	}
	catch (std::exception & ex)
	{
		std::cout << "Exception : " << ex.what() << std::endl;
	}
	return (0);
}