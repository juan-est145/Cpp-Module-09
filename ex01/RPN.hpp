#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN
{
private:
	std::stack<int> _stack;

public:
	RPN(void);
	RPN(const RPN &copy);
	int rpnCalculation(std::string &op); 
	RPN &operator=(const RPN &assign);
	~RPN();
};

#endif