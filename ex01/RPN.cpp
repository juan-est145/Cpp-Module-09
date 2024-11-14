#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

int RPN::rpnCalculation(char *op)
{
	size_t length = strlen(op);
	while (this->_stack.size() != 0)
		this->_stack.pop();
	for (size_t i = 0; i < length; i++)
	{
		if (!this->isCharValid(op[i]))
			return (-1);
		if (isdigit(op[i]))
			this->_stack.push(atoi(&op[i]));
		else if (this->isOperand(op[i]))
			this->processOp(op[i]);
	}
	if (this->_stack.size() != 1)
	{
		std::cerr << "Error, invalid sequence" << std::endl;
		exit(1);
	}
	return (this->_stack.top());
}

bool RPN::isCharValid(const char c) const
{
	if ((isOperand(c) && this->_stack.size() >= 2) || c == ' ')
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

void RPN::processOp(const char c)
{
	int num1 = this->_stack.top();
	this->_stack.pop();
	int num2 = this->_stack.top();
	this->_stack.pop();

	if (c == '+')
		this->_stack.push(num2 + num1);
	else if (c == '-')
		this->_stack.push(num2 - num1);
	else if (c == '*')
		this->_stack.push(num2 * num1);
	else if (c == '/' && num1 == 0)
	{
		std::cerr << "Error, cannot divide by cero" << std::endl;
		exit(1);
	}
	else
		this->_stack.push(num2 / num1);
}

RPN &RPN::operator=(const RPN &assign)
{
	if (this != &assign)
		this->_stack = assign._stack;
	return (*this);
}

RPN::~RPN() {}