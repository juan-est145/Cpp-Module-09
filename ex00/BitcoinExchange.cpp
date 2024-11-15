/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:47:35 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/15 19:16:58 by juestrel         ###   ########.fr       */
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

void BitcoinExchange::getValues(const char *data)
{
	std::ifstream bcVal(data);
	std::string line;
	if (!bcVal.is_open())
	{
		std::cerr << "Error, could not open db file" << std::endl;
		exit(1);
	}
	std::getline(bcVal, line);
	while (std::getline(bcVal, line))
	{
		t_status status = CORRECT;
		std::stringstream stream(line);
		std::string valueS, date;
		std::getline(stream, date, '|');
		std::getline(stream, valueS);
		if ((status = this->valData(date)) != CORRECT || (status = this->valData(date, valueS)) != CORRECT)
		{
			//COUT SOMETHING
			continue;
		}
		if (this->_bitcoinPrices.find(date) == this->_bitcoinPrices.end())
		{
			//DO something
		}
		//Default case
	}
}

BitcoinExchange::t_status BitcoinExchange::valData(const std::string &date)
{
	
}

BitcoinExchange::t_status BitcoinExchange::valData(const std::string &date, const std::string &valueS)
{
	
}

BitcoinExchange::~BitcoinExchange() {}