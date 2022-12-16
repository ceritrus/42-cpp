#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Address:" << std::endl;
    std::cout << "String: \t" << &str << std::endl;
    std::cout << "Pointer: \t" << stringPTR << std::endl;
    std::cout << "Reference: \t" << &stringREF << std::endl;
    
    std::cout << std::endl;

    std::cout << "Value:" << std::endl;
    std::cout << "String: \t" << str << std::endl;
    std::cout << "Pointer: \t" << *stringPTR << std::endl;
    std::cout << "Reference: \t" << stringREF << std::endl;
}