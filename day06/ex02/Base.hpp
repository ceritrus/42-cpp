#pragma once

#include <iostream>

class Base
{
public:
	virtual ~Base(){};
};

class A : public Base
{
public:
	A(){std::cerr << "Constructor: A" << std::endl;};
};

class B : public Base
{
public:
	B(){std::cerr << "Constructor: B" << std::endl;};
};

class C : public Base
{
public:
	C(){std::cerr << "Constructor: C" << std::endl;};
};