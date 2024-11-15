/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:31:27 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/15 22:50:32 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void valArgs(int argc, char *argv[], std::vector<int> &vector, std::deque<int> &deque)
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
		vector.push_back(static_cast<int>(number));
		deque.push_back(static_cast<int>(number));
	}
}

	int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "Error, you need to provide at least a number as an argument" << std::endl;
		return (1);
	}
	std::vector<int> vector;
	std::deque<int> deque;
	PmergeMe merge;
	valArgs(argc, argv, vector, deque);
	merge.mergeInsertSort(vector);
	merge.mergeInsertSort(deque);
	return (0);
}