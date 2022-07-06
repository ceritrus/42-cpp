#ifndef FORM_HPP
# define FORM_HPP

# ifndef DEBUG
#  define DEBUG false
# endif

# include <iostream>

class Form;
# include "Bureaucrat.hpp"

class Form
{
private:
    std::string const _name;
    bool _isSigned;
    int const _signGrade;
    int const _execGrade;

public:
    class GradeTooHighException : public std::runtime_error
    {
    public:
        GradeTooHighException(std::string message) : std::runtime_error(message) {};
    };
    class GradeTooLowException : public std::runtime_error
    {
    public:
        GradeTooLowException(std::string message) : std::runtime_error(message) {};
    };
    class FormAlreadySignedException : public std::runtime_error
    {
    public:
        FormAlreadySignedException(std::string message) : std::runtime_error(message) {};
    };
    Form(void);
    Form(std::string const &name, int Sign, int Exec);
    Form(Form const &that);
    ~Form(void);
    Form &operator=(Form const &that);

    const std::string getName(void) const;
    bool isSigned(void) const;
    int getSignGrade(void) const;
    int getExecGrade(void) const;

    void beSigned(Bureaucrat const &that);
};

std::ostream &operator<<(std::ostream &out, Form const &that);

#endif