#include "RobotomyRequestForm.hpp"

std::string const RobotomyRequestForm::name = "Robotomy Request";

RobotomyRequestForm::RobotomyRequestForm(void)
    : Form(name, 72, 45), _target("default") 
{
    if (DEBUG)
        std::cerr << "Default Constructor: RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : Form(name, 72, 45), _target(target)
{
    if (DEBUG)
        std::cerr << "Constructor: RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &that)
    : Form(name, 72, 45), _target(that.getTarget()) 
{
    if (DEBUG)
        std::cerr << "Copy Constructor: RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    if (DEBUG)
        std::cerr << "Destructor: RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &that)
{
    if (DEBUG)
        std::cerr << "Copy Assignment Operator: RobotomyRequestForm" << std::endl;
    _target = that.getTarget();
    return *this;
}

std::string const RobotomyRequestForm::getTarget(void) const
{
    return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    Form::execute(executor);
    std::cout << "Brrrrrrrrrrrrrr..." << std::endl;
    if (rand() % 2)
        std::cout << _target << " was successfully robotomized!" << std::endl;
    else
        std::cout << "Failed to robotomize " << _target << "..." << std::endl;
}

Form *RobotomyRequestForm::generate(std::string const &target)
{
    return (new RobotomyRequestForm(target));
}