#include "RPN.hpp"

RPN::RPN() : _op(""), _stack()
{
}

RPN::RPN(const std::string & str) : _op(str), _stack()
{
	if (str.empty() || str.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw std::runtime_error("Error: invalid expression");
}

RPN::~RPN()
{

}

RPN::RPN(const RPN & src) : _op(src._op), _stack(src._stack)
{

}

RPN & RPN::operator=(const RPN & src)
{
	if (this != &src)
	{
		this->_op = src._op;
		this->_stack = src._stack;
	}
	return *this;
}

void RPN::reset(const std::string & str)
{
	if (str.empty() || str.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw std::runtime_error("Error: invalid expression");
	this->_op = str;
	this->_stack = std::stack<float>();
}

float RPN::compute()
{
	for (size_t i = 0; i < this->_op.length(); i++)
	{
		if (this->_op[i] == ' ')
			continue;
		char token = this->_op[i];
		if (isOperator(token))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error: invalid expression");
			float a = _stack.top();
			_stack.pop();
			float b = this->_stack.top();
			_stack.pop();
			if (token == '+')
				_stack.push(b + a);
			else if (token == '-')
				_stack.push(b - a);
			else if (token == '*')
				_stack.push(b * a);
			else if (token == '/')
				_stack.push(b / a);
		}
		else if (isNumber(token))
		{
			_stack.push(token - '0');
		}
		else
		{
			throw std::runtime_error("Error: invalid character");
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error: invalid expression");
	return _stack.top();
}

bool RPN::isOperator(const char & c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::isNumber(const char & c)
{
	return (c >= '0' && c <= '9');
}