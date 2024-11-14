/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:32:50 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/14 23:14:12 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char *argv[])
{
	if (argc != 2 || argv[1] == NULL)
		return std::cerr << "You must provide only one argument" << std::endl, 1;
	RPN rpn;
	std::cout << rpn.rpnCalculation(argv[1]) << std::endl;
	return (0);
}