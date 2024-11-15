/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:28:59 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/15 20:54:57 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char *argv[])
{
	for (size_t i = 1; i < (unsigned int)argc; i++)
	{
		for (size_t j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] == '+')
                j++;
            if (argv[i][0] == '0')
            {
                std::cout << "Error: 0 cannot be present as a number" << std::endl;
                exit(1);
            }
            else if (!isdigit(argv[i][j]))
            {
                std::cout << "Error, invalid character in sequence" << std::endl;
                exit(1);
            }
		}
		long number = atol(argv[i]);
		if (number > INT_MAX || number <= 0)
		{
			std::cout << "Error: number is either too big for int or a negative" << std::endl;
            exit(1);
		}
		this->_vector.push_back(static_cast<int>(number));
		this->_deque.push_back(static_cast<int>(number));
	}
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &assign)
{
	if (this != &assign)
	{
		this->_vector = assign._vector;
		this->_deque = assign._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}
