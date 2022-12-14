#ifndef ROBOTOMYREQUESTFORM_HPP
# define  ROBOTOMYREQUESTFORM_HPP

# ifndef DEBUG
#  define DEBUG false
# endif

# include <iostream>
# include <fstream>

class RobotomyRequestForm;
# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <stdlib.h>

class RobotomyRequestForm : public Form
{
private:
    std::string _target;
public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string const &target);
    RobotomyRequestForm(RobotomyRequestForm const &that);
    ~RobotomyRequestForm(void);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &that);

    std::string const getTarget(void) const;
    void execute(Bureaucrat const &executor) const;
    static std::string const name;

    static Form *generate(std::string const &target);
};

#endif