#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>

class PmergeMe
{
private:
	std::vector<int> _vector;
	std::deque<int> _deque;

public:
	PmergeMe(void);
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &assign);
	~PmergeMe(void);
};

#endif