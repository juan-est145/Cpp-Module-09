/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:28:59 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/15 22:58:16 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &copy) 
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &assign) 
{
	(void)assign;
	return *this;
}

void PmergeMe::mergeInsertSort(std::vector<int> &vector)
{
	if (vector.size() <= 1)
		return;
	for (size_t i = 0; i < vector.size(); i+=2)
	{
		if (vector[i] > vector[i + 1])
			std::swap(vector[i], vector[i + 1]);
	}
    std::vector<int> largeNums;
	for (size_t i = 1; i < vector.size(); i += 2)
		largeNums.push_back(vector[i]);
	this->mergeInsertSort(largeNums);
	std::vector<int> result = largeNums;
	for (size_t i = 0; i < vector.size(); i +=2)
	{
		
	}
	vector = result;
}

PmergeMe::~PmergeMe(void) {}
