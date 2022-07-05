#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade)
    : _name(name), _grade(grade)
{
    if (_grade > 150)
    {
        _grade = 150;
        throw GradeTooLowException("Grade too low!");
    }
    else if (_grade < 1)
    {
        _grade = 1;
        throw GradeTooHighException("Grade too high!");
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &that)
    : _name(that.getName()), _grade(that.getGrade()) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &that)
{
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
        throw GradeTooHighException("Grade too high!");
    else
        _grade -= 1;
}

void Bureaucrat::decGrade(void)
{
    if (_grade == 150)
        throw GradeTooHighException("Grade too low!");
    else
        _grade += 1;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &that)
{
    out << that.getName();
    out << ", bureaucrat grade " << that.getGrade();
    return out;
}