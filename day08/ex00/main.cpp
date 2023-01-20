#include "easyfind.hpp"

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> vec;

    std::vector<int>::iterator it;

    for (int i = 1; i < 20; i++)
        vec.push_back(i);

    it = easyfind(vec, 12);
    std::cout << *it << std::endl;
    it = find(vec.begin(), vec.end(), 12);
    std::cout << *it << std::endl << std::endl;
    
    it = easyfind(vec, 5);
    std::cout << *it << std::endl;
    it = find(vec.begin(), vec.end(), 5);
    std::cout << *it << std::endl << std::endl;

    it = easyfind(vec, 133);
    std::cout << *it << std::endl;
    it = find(vec.begin(), vec.end(), 133);
    std::cout << *it << std::endl;
}