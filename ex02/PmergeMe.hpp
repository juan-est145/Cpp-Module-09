#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <climits>
#include <sys/time.h>

class PmergeMe
{
private:
	PmergeMe(void);
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &assign);
	static void mergeInsertSort(std::vector<int> &vector);
	static void insertSmallNums(std::vector<int> &result, int target);
	static void mergeInsertSort(std::deque<int> &deque);
	static void insertSmallNums(std::deque<int> &result, int target);
	~PmergeMe(void);
	
	
public:
	static double sort(std::vector <int> &vector);
	static double sort(std::deque<int> &deque);
};

#endif