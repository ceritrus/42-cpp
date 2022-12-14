#ifndef INTERN_HPP
# define INTERN_HPP

# ifndef DEBUG
#  define DEBUG false
# endif

#include <iostream>
#include <string>
#include <algorithm>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

typedef struct FormInfo
{
    std::string name;
    Form *(*func)(std::string const &target);
}   FormInfo;

class Intern
{
private:
    static FormInfo const glossary[12];
    char why;
public:
    class InvalidFormNameException : public std::runtime_error
    {
    public:
        InvalidFormNameException(std::string message) : std::runtime_error(message) {};
    };
    Intern(void);
    Intern(Intern const &that);
    ~Intern(void);
    Intern &operator=(Intern const &that);

    Form *makeForm(std::string const &name, std::string const &target);
};

#endif