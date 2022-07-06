#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# ifndef DEBUG
#  define DEBUG false
# endif

# include <iostream>

class Bureaucrat;
# include "Form.hpp"

class Bureaucrat
{
private:
    std::string const _name;
    int _grade;

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
    Bureaucrat(void);
    Bureaucrat(std::string const &name, int grade);
    Bureaucrat(Bureaucrat const &that);
    ~Bureaucrat(void);
    Bureaucrat &operator=(Bureaucrat const &that);

    const std::string getName(void) const;
    int getGrade(void) const;

    void incGrade(void);
    void decGrade(void);

    void signForm(Form &form) const;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &that);

#endif