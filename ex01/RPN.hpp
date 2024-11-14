#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <cstring>

class RPN
{
private:
	std::stack<int> _stack;
	bool isCharValid(const char c) const;
	bool isOperand(const char c) const;

public:
	RPN(void);
	RPN(const RPN &copy);
	int rpnCalculation(char *op);
	RPN &operator=(const RPN &assign);
	~RPN();
};

#endif