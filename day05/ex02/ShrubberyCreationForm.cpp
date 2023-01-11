#include "ShrubberyCreationForm.hpp"

std::string const ShrubberyCreationForm::name = "Shrubbery Creation";

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : Form(name, 145, 137), _target("default") 
{
    if (DEBUG)
        std::cerr << "Default Constructor: ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : Form(name, 145, 137), _target(target)
{
    if (DEBUG)
        std::cerr << "Constructor: ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &that)
    : Form(name, 145, 137), _target(that.getTarget()) 
{
    if (DEBUG)
        std::cerr << "Copy Constructor: ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    if (DEBUG)
        std::cerr << "Destructor: ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &that)
{
    if (DEBUG)
        std::cerr << "Copy Assignment Operator: ShrubberyCreationForm" << std::endl;
    _target = that.getTarget(); 
    return *this;
}

std::string const ShrubberyCreationForm::getTarget(void) const
{
    return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    Form::execute(executor);
    std::string filename(_target + "_shrubbery");
    std::ofstream file;
    file.open(filename.c_str());
    if (!file.is_open() || file.bad())
        throw FileHandlingException("ShrubberyCreationForm: Failed to open target_shrubbery");
    file << trees[rand() % 3] << std::endl;
    if (file.bad())
    {
        file.close();
        throw FileHandlingException("ShrubberyCreationForm: Something went wrong while writing to target");
    }
    file.close();
}

std::string const ShrubberyCreationForm::trees[3] = {
"    ccee88oo\n" \
"  C8O8O8Q8PoOb o8oo\n" \
" dOB69QO8PdUOpugoO9bD\n" \
"CgggbU8OU qOp qOdoUOdcb\n" \
"    6OuU  /p u gcoUodpP\n" \
"      \\\\\\//  /douUP\n" \
"        \\\\\\////\n" \
"         |||/\\\n" \
"         |||\\/\n" \
"         |||||\n" \
"   .....//||||\\....",
"         *\n" \
"        /|\\\n" \
"       /*|O\\\n" \
"      /*/|\\*\\\n" \
"     /X/O|*\\X\\\n" \
"    /*/X/|\\X\\*\\\n" \
"   /O/*/X|*\\O\\X\\\n" \
"  /*/O/X/|\\X\\O\\*\\\n" \
" /X/O/*/X|O\\X\\*\\O\\\n" \
"/O/X/*/O/|\\X\\*\\O\\X\\\n" \
"        |X|\n" \
"        |X|",
"                                                .\n" \
"                                    .         ;\n" \
"        .              .              ;%     ;;\n" \
"        ,           ,                :;%  %;\n" \
"         :        ;                   :;%;'     .,\n" \
"   ,.     %;     %;            ;        %;'    ,;\n" \
"    ;       ;%;  %%;        ,     %;    ;%;    ,%'\n" \
"    %;       %;%;      ,  ;       %;  ;%;   ,%;' \n" \
"    ;%;      %;        ;%;        % ;%;  ,%;'\n" \
"    `%;.     ;%;     %;'         `;%%;.%;'\n" \
"        `:;%.    ;%%. %@;        %; ;@%;%'\n" \
"        `:%;.  :;bd%;          %;@%;'\n" \
"            `@%:.  :;%.         ;@@%;'\n" \
"            `@%.  `;@%.      ;@@%;\n" \
"                `@%%. `@%%    ;@@%;\n" \
"                ;@%. :@%%  %@@%;\n" \
"                    %@bd%%%bd%%:;\n" \
"                    #@%%%%%:;;\n" \
"                    %@@%%%::;\n" \
"                    %@@@%(o);  .'\n" \
"                    %@@@o%;:(.,'\n" \
"                `.. %@@@o%::;\n" \
"                    `)@@@o%::;\n" \
"                    %@@(o)::;\n" \
"                    .%@@@@%::;\n" \
"                    ;%@@@@%::;.\n" \
"                    ;%@@@@%%:;;;.\n" \
"                ...;%@@@@@%%:;;;;,.."
};
