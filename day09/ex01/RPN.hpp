#include <iostream>
#include <string>
#include <stack>

class RPN
{
public:
	RPN();
	RPN(const std::string & str);
	~RPN();
	RPN(const RPN & src);
	RPN & operator=(const RPN & src);

	float compute();
	void reset(const std::string & str);

	bool isOperator(const char & c);
	bool isNumber(const char & c);

private:
	std::string _op;
	std::stack<float> _stack;
};