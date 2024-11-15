#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <climits>

class PmergeMe
{
private:
	void insertSmallNums(std::vector <int> &result, int target);
public:
	PmergeMe(void);
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &assign);
	void mergeInsertSort(std::vector<int> &vector);
	void mergeInsertSort(std::deque<int> &deque);
	~PmergeMe(void);
};

#endif