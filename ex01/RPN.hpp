#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
#include <stack>

class RPN
{
	public:
		// Constructors
		RPN();
		RPN(const RPN &copy);
		RPN(std::stack<int> stack);
		
		// Destructor
		~RPN();
		
		// Operators
		RPN & operator=(const RPN &assign);
		
		// Getters / Setters
		std::stack<int> getStack() const;
		
	private:
		std::stack<int> _stack;
		
};

#endif