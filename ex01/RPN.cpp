#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

int RPN::rpnCalculation(char *op)
{
	int result = 0;
	size_t length = strlen(op);
	while (this->_stack.size() != 0)
		this->_stack.pop();
	for (size_t i = 0; i < length; i++)
	{
		if (!this->isCharValid(op[i]))
			return (-1);
		if (isdigit(op[i]))
			this->_stack.push(atoi(&op[i]));
	}
	return (result);
}

bool RPN::isCharValid(const char c) const
{
	if (isOperand(c) || c == ' ')
		return (true);
	else if (c >= '0' && c <= '9')
		return (true);
	std::cerr << "Error, invalid operand" << std::endl;
	return (false);
}

bool RPN::isOperand(const char c) const
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

RPN &RPN::operator=(const RPN &assign)
{
	if (this != &assign)
		this->_stack = assign._stack;
	return (*this);
}

RPN::~RPN() {}