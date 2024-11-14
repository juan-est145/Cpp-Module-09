#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

int RPN::rpnCalculation(std::string &op)
{
	return (0);
}

RPN & RPN::operator=(const RPN &assign)
{
	if (this != &assign)
		this->_stack = assign._stack;
	return (*this);
}

RPN::~RPN() {}