#ifndef PRESIDENTIALPARDON_HPP
# define  PRESIDENTIALPARDON_HPP

# ifndef DEBUG
#  define DEBUG false
# endif

# include <iostream>
# include <fstream>

class PresidentialPardonForm;
# include "Form.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
private:
    std::string _target;
public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string const &target);
    PresidentialPardonForm(PresidentialPardonForm const &that);
    ~PresidentialPardonForm(void);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &that);

    std::string const getTarget(void) const;
    void execute(Bureaucrat const &executor) const;
    static std::string const name;
};

#endif