/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:31:27 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/15 20:52:56 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "Error, you need to provide at least a number as an argument" << std::endl;
		return (1);
	}
	PmergeMe merge(argc, argv);
	return (0);
}