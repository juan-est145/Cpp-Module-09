/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:47:35 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/15 18:28:26 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string db) 
{
	std::ifstream dbFile(db.c_str());
	std::string line;

	if (!dbFile.is_open())
	{
		std::cerr << "Error, could not open db file" << std::endl;
		exit(1);
	}

	std::getline(dbFile, line);
	while (std::getline(dbFile, line))
	{
		float price;
		std::string date;
		std::stringstream sLine(line);
		if (std::getline(sLine, date, ',') && sLine >> price)
		{
			this->_bitcoinPrices[date] = price;
		}
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	if (this != &assign)
		this->_bitcoinPrices = assign._bitcoinPrices;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}