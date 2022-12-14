#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) 
    : _name("default"), _grade(150)
{
    if (DEBUG)
        std::cerr << "Default Constructor: Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade)
    : _name(name), _grade(grade)
{
    if (DEBUG)
        std::cerr << "Constructor: Bureaucrat" << std::endl;
    if (_grade > 150)
        throw GradeTooLowException("Bureaucrat: Grade set too low!");
    else if (_grade < 1)
        throw GradeTooHighException("Bureaucrat: Grade set too high!");
}

Bureaucrat::Bureaucrat(Bureaucrat const &that)
    : _name(that.getName()), _grade(that.getGrade())
{
    if (DEBUG)
        std::cerr << "Copy Constructor: Bureaucrat" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
    if (DEBUG)
        std::cerr << "Destructor: Bureaucrat" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &that)
{
    if (DEBUG)
        std::cerr << "Copy Assignment Operator: Bureaucrat" << std::endl;
    _grade = that.getGrade();
    return *this;
}

const std::string Bureaucrat::getName(void) const
{
    return _name;
}

int Bureaucrat::getGrade(void) const
{
    return _grade;
}

void Bureaucrat::incGrade(void)
{
    if (_grade == 1)
        throw GradeTooHighException("Bureaucrat: Grade too high to be incremented");
    else
        _grade -= 1;
}

void Bureaucrat::decGrade(void)
{
    if (_grade == 150)
        throw GradeTooLowException("Bureaucrat: Grade too low to be decremented");
    else
        _grade += 1;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &that)
{
    out << that.getName();
    out << ", bureaucrat grade " << that.getGrade();
    return out;
}