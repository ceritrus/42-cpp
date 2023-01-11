#include "PresidentialPardonForm.hpp"

std::string const PresidentialPardonForm::name = "Robotomy Request";

PresidentialPardonForm::PresidentialPardonForm(void)
    : Form(name, 25, 5), _target("default") 
{
    if (DEBUG)
        std::cerr << "Default Constructor: PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : Form(name, 25, 5), _target(target)
{
    if (DEBUG)
        std::cerr << "Constructor: PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &that)
    : Form(name, 25, 5), _target(that.getTarget()) 
{
    if (DEBUG)
        std::cerr << "Copy Constructor: PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    if (DEBUG)
        std::cerr << "Destructor: PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &that)
{
    if (DEBUG)
        std::cerr << "Copy Assignment Operator: PresidentialPardonForm" << std::endl;
    _target = that.getTarget();
    return *this;
}

std::string const PresidentialPardonForm::getTarget(void) const
{
    return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    Form::execute(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl; 
}