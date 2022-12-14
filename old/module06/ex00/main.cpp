
#include <iostream>
#include <cstdlib>
#include <string>

#define T_CHAR 0
#define T_INT 1
#define T_FLOAT 2
#define T_DOUBLE 3
#define T_ERR 4

char cvalue = 0;
int ivalue = 0;
float fvalue = 0;
double dvalue = 0;

int identify(char *str)
{
    size_t *ptr;
    ivalue = std::stoi(str, ptr, 10);
    if (*ptr)
        return T_INT;
    dvalue = std::stod(str, ptr);
    if (ptr)
        return T_DOUBLE;
    fvalue = std::stof(str, ptr);
    if (ptr)
        return T_FLOAT;
    if (std::string(str).length() == 1)
    {
        cvalue = str[0];
        return T_CHAR;
    }
    return T_ERR;
}

void fromChar(char c)
{
    std::cout << "Char: " << c << std::endl;
    std::cout << "Int: " << static_cast<int>(c) << std::endl;
    std::cout << "Float: " << static_cast<float>(c) << std::endl;
    std::cout << "Double: " << static_cast<double>(c) << std::endl;
}

void fromInt(int i)
{
    char tempchar = static_cast<char>(i);
    if (i < 0)
        std::cout << "Char: Impossible" << std::endl;
    else
        std::cout << "Char: " << (std::isprint(tempchar)?&tempchar:"Non displayable") << std::endl;
    std::cout << "Int: " << i << std::endl;
    std::cout << "Float: " << static_cast<float>(i) << std::endl;
    std::cout << "Double: " << static_cast<double>(i) << std::endl;
}

void fromFloat(float f)
{
    char tempchar = static_cast<char>(f);
    if (f < 0)
        std::cout << "Char: Impossible" << std::endl;
    else
        std::cout << "Char: " << (std::isprint(tempchar)?&tempchar:"Non displayable") << std::endl;
    std::cout << "Int: " << static_cast<int>(f) << std::endl; // Needs checking
    std::cout << "Float: " << f << std::endl;
    std::cout << "Double: " << static_cast<double>(f) << std::endl;
}

void fromDouble(double d)
{
    char tempchar = static_cast<char>(d);
    if (d < 0)
        std::cout << "Char: Impossible" << std::endl;
    else
        std::cout << "Char: " << (std::isprint(tempchar)?&tempchar:"Non displayable") << std::endl;
    std::cout << "Int: " << static_cast<int>(d) << std::endl; // Needs checking
    std::cout << "Float: " << static_cast<float>(d) << std::endl;
    std::cout << "Double: " << d << std::endl;
}

int main(int argc, char **argv)
{
    int type = T_ERR;

    if (argc != 2)
    {
        std::cerr << "Error: Invalid argument(s)\n"
            << "Usage: ./convert value" << std::endl;
    }
    else
    {
        type = identify(argv[1]);
        switch (type)
        {
            case T_CHAR:
                std::cout << "Type: char" << std::endl;
                fromChar(cvalue);
                break;
            case T_INT:
                std::cout << "Type: int" << std::endl;
                fromInt(ivalue);
                break;
            case T_FLOAT:
                std::cout << "Type: float" << std::endl;
                fromFloat(fvalue);
                break;
            case T_DOUBLE:
                std::cout << "Type: double" << std::endl;
                fromDouble(dvalue);
                break;
            default:
                std::cout << "Unknown or Invalid type" << std::endl;
                return 1;
                break;
        }
    }
    return 0;
}


