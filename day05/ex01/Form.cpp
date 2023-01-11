#include "Form.hpp"

Form::Form(void) 
    : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150)
{
    if (DEBUG)
        std::cerr << "Default Constructor: Form" << std::endl;
}

Form::Form(std::string const &name, int Sign, int Exec)
    : _name(name), _isSigned(false), _signGrade(Sign), _execGrade(Exec)
{
    if (DEBUG)
        std::cerr << "Constructor: Form" << std::endl;
    if (_signGrade > 150)
        throw GradeTooLowException("Form: Signature grade requirement set too low!");
    else if (_signGrade < 1)
        throw GradeTooHighException("Form: Signature grade requirement set too high!");
    if (_execGrade > 150)
        throw GradeTooLowException("Form: Execution grade requirement set too low!");
    else if (_execGrade < 1)
        throw GradeTooHighException("Form: Execution grade requirement set too high!");
    
}

Form::Form(Form const &that)
    : _name(that.getName()), _isSigned(that.isSigned()),
        _signGrade(that.getSignGrade()), _execGrade(that.getSignGrade())
{
    if (DEBUG)
        std::cerr << "Copy Constructor: Form" << std::endl;
}

Form::~Form(void)
{
    if (DEBUG)
        std::cerr << "Destructor: Form" << std::endl;
}

Form &Form::operator=(Form const &that)
{
    if (DEBUG)
        std::cerr << "Copy Assignment Operator: Form" << std::endl;
    _isSigned = that._isSigned;
    return *this;
}

const std::string Form::getName(void) const
{
    return _name;
}

bool Form::isSigned(void) const
{
    return _isSigned;
}

int Form::getSignGrade(void) const
{
    return _signGrade;
}

int Form::getExecGrade(void) const
{
    return _execGrade;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (_isSigned == true)
        throw FormAlreadySignedException("Form: Already signed");
    if (bureaucrat.getGrade() <= _signGrade)
        _isSigned = true;
    else
        throw GradeTooLowException("Form: Grade requirement for signature not met");
}


std::ostream &operator<<(std::ostream &out, Form const &that)
{
    out << that.getName() << " ([" 
        << (that.isSigned()?"signed":"unsigned") << "]"
        << ", Sign[" << that.getSignGrade() << "]"
        << ", Exec[" << that.getExecGrade() << "])";
    return out;
}