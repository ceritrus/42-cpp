#ifndef SHRUBBERYCREATIONFORM_HPP
# define  SHRUBBERYCREATIONFORM_HPP

# ifndef DEBUG
#  define DEBUG false
# endif

# include <iostream>
# include <fstream>
# include <stdlib.h>

class ShrubberyCreationForm;
# include "Form.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
private:
    std::string _target;
public:
    class FileHandlingException : public std::runtime_error
    {
    public:
       FileHandlingException(std::string message) : std::runtime_error(message) {};
    };
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string const &target);
    ShrubberyCreationForm(ShrubberyCreationForm const &that);
    ~ShrubberyCreationForm(void);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &that);

    std::string const getTarget(void) const;
    void execute(Bureaucrat const &executor) const;
    static std::string const name;
    static std::string const trees[3];

    static Form *generate(std::string const &target);
};

#endif