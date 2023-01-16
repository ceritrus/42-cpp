#include "Base.hpp"
#include <iostream>
#include <random>
Base *generate(void)
{
	// Magic shenanigans to generate a random number
	std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float>dist(1.00f, 3.99f);
	switch (static_cast<int>(dist(mt)))
	{
		case 1:
			return new A();
			break;
		case 2:
			return new B();
			break;
		case 3:
			return new C();
			break;
		default:
			return new C();
			break;
	}
}

void identify(Base *p)
{
	A* aptr = dynamic_cast<A*>(p);
	B* bptr = dynamic_cast<B*>(p);
	C* cptr = dynamic_cast<C*>(p);
	std::cout << "Object pointed to is of class: ";
	if (aptr != NULL)
		std::cout << "A" << std::endl;
	else if (bptr != NULL)
		std::cout << "B" << std::endl;
	else if (cptr != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unidentified" << std::endl;
}

void identify(Base &p)
{
	std::cout << "Object referenced is of class: ";
	try
	{
		A& aptr = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)aptr;
	}
	catch (std::bad_cast)
	{
		try
		{
			B& bptr = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
			(void)bptr;
		}
		catch (std::bad_cast)
		{
			try
			{
				C& cptr = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
				(void)cptr;
				return;
			}
			catch (std::bad_cast)
			{
				std::cout << "Unidentified" << std::endl;
			}
		}
	}
}

int main(void)
{
	Base *random = generate();
	Base &ref = *random;
	identify(random);
	identify(ref);
}
