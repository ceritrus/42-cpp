#include "Span.hpp"
#include <iostream>

int main()
{
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        try
        {
            sp.addNumber(11);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << "# End of scope #" << std::endl;
    }

    {
        Span sp = Span(1);
        sp.addNumber(10);
        try
        {
            std::cout << sp.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            std::cout << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "# End of scope #" << std::endl;
    }

    {
        std::vector<int> test = std::vector<int>();
        for (int i = 0; i < 100; i++)
            test.push_back(i * 2);
        Span sp = Span(100);
        try
        {
            sp.addRange(test.begin(), test.end());
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            std::cout << sp.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            std::cout << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "# End of scope #" << std::endl;
    }

    {
        Span sp = Span(10000);
        sp.fillRandom();
        try
        {
            std::cout << sp.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            std::cout << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "# End of scope #" << std::endl;
    }
    return 0;
}