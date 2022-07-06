#include "Intern.hpp"

FormInfo const Intern::glossary[12] =
{
    {"shrubberycreation", ShrubberyCreationForm::generate},
    {"robotomyrequest", RobotomyRequestForm::generate},
    {"presidentialpardon", PresidentialPardonForm::generate},
    {"ShrubberyCreation", ShrubberyCreationForm::generate},
    {"RobotomyRequest", RobotomyRequestForm::generate},
    {"PresidentialPardon", PresidentialPardonForm::generate},
    {"shrubbery creation", ShrubberyCreationForm::generate},
    {"robotomyr equest", RobotomyRequestForm::generate},
    {"presidential pardon", PresidentialPardonForm::generate},
    {"Shrubbery Creation", ShrubberyCreationForm::generate},
    {"Robotomy Request", RobotomyRequestForm::generate},
    {"Presidential Pardon", PresidentialPardonForm::generate}
};

Intern::Intern(void)
    : why('x')
{
    if (DEBUG)
        std::cerr << "Default Constructor: Intern" << std::endl;
}

Intern::Intern(Intern const &that)
    : why(that.why)
{
    if (DEBUG)
        std::cerr << "Copy Constructor: Intern" << std::endl;
}

Intern::~Intern(void)
{
    if (DEBUG)
        std::cerr << "Destructor: Intern" << std::endl;
}

Intern &Intern::operator=(Intern const &that)
{
    if (DEBUG)
        std::cerr << "Copy Assignment Operator: Intern" << std::endl;
    return *this;
    why = that.why;
}

Form *Intern::makeForm(std::string const &name, std::string const &target)
{
    Form *form = NULL;
    for (int i = 0; i < 12; i++)
    {
        if (name == glossary[i].name)
        {
            try
            {
                form = glossary[i].func(target);
                std::cout << "Intern creates " << form->getName() << std::endl;
                return form;
            }
            catch(const std::exception& e)
            {
                std::cerr << "Intern failed to create form:" << std::endl;
                std::cerr << "Exception: " << e.what() << '\n';
            }
        }
    }
    std::cout << "Intern failed to create form because it doesn't exist" << std::endl;
    throw InvalidFormNameException("Intern: Form name doesn't exist");
    return NULL;
}