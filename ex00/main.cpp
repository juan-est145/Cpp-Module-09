/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:19:22 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/15 20:07:59 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2 || argv[1] == NULL)
	{
		std::cerr << "Error, you need to provide one argument" << std::endl;
		return (1);
	}
	BitcoinExchange bE("data.csv");
	bE.getValues(argv[1]);
	return (0);
}