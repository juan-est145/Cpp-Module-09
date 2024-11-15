#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <climits>

template <typename T>
class PmergeMe
{
private:
	T _container;

public:
	PmergeMe(void);
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &assign);
	void push_back(int number);
	void mergeInsertSort(void);
	~PmergeMe(void);
};

template <typename T>
PmergeMe<T>::PmergeMe(void) {}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe<T> &copy) 
{
	*this = copy;
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe<T> &assign) 
{
	if (this != &assign)
		this->_container = assign._container;
	return *this;
}

template <typename T>
void PmergeMe<T>::push_back(int number)
{
	this->_container.push_back(number);
}
template <typename T>
void PmergeMe<T>::mergeInsertSort(void)
{

}

template <typename T>
PmergeMe<T>::~PmergeMe(void) {}

#endif