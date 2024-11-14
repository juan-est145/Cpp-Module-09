#include "RPN.hpp"

// Constructors
RPN::RPN() {}

RPN::RPN(const RPN &copy)
{
	_stack = copy.getStack();
}

RPN::RPN(std::stack<int> stack)
{
	_stack = stack;
}


// Destructor
RPN::~RPN()
{
}


// Operators
RPN & RPN::operator=(const RPN &assign)
{
	_stack = assign.getStack();
	return *this;
}
