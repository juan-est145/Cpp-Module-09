/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:47:35 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/15 20:18:56 by juestrel         ###   ########.fr       */
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
		tStatus status = CORRECT;
		std::stringstream stream(line);
		std::string valueS, date;
		std::getline(stream, date, '|');
		std::getline(stream, valueS);
		if ((status = this->valDate(date)) != CORRECT || (status = this->valValue(valueS)) != CORRECT)
		{
			this->printMsg(status, date, std::atof(valueS.c_str()));
			continue;
		}
		if (this->_bitcoinPrices.find(date) == this->_bitcoinPrices.end())
			date = this->findClosestDate(date);
		this->printMsg(status, date, std::atof(valueS.c_str()));
	}
}

BitcoinExchange::tStatus BitcoinExchange::valDate(std::string &date)
{
	date.erase(0, date.find_first_not_of(' '));
	date.erase(date.find_last_not_of(' ') + 1);

	if (date.empty() || date[4] != '-' || date[7] != '-' || date.size() != 10)
		return (E_BAD_INPUT);
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (year <= 0 || month <= 0 || month > 12)
		return (E_BAD_INPUT);
	int maxDay = 31;
	if (month == 2)
	{
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		maxDay = isLeap ? 29 : 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		maxDay = 30;
	if (day <= 0 || day > maxDay)
		return (E_BAD_INPUT);
	return (CORRECT);
}

BitcoinExchange::tStatus BitcoinExchange::valValue(std::string &valueS)
{
	valueS.erase(0, valueS.find_first_not_of(' '));
	valueS.erase(valueS.find_last_not_of(' ') + 1);
	if (valueS.empty())
		return (E_BAD_INPUT);
	for (size_t i = 0; i < valueS.size(); i++)
	{
		if (!std::isdigit(valueS[i]) && valueS[i] != '.' && valueS[i] != '-' && valueS[i] != '+')
			return (E_BAD_INPUT);
	}
	double valueBtc = std::atof(valueS.c_str());
	if (valueBtc > 1000)
		return (E_LARGE);
	else if (valueBtc < 0)
		return (E_NEGATIVE);
	return (CORRECT);
}

std::string BitcoinExchange::findClosestDate(const std::string &date)
{
	std::string closest;
	for (std::map<std::string, float>::iterator it = this->_bitcoinPrices.begin(); it != this->_bitcoinPrices.end(); ++it)
	{
		if (it->first > date)
			break;
		closest = it->first;
	}
	return (closest);
}

void BitcoinExchange::printMsg(tStatus status, const std::string &date, float value)
{
	if (status == CORRECT)
	{
		std::cout << date << " => " << value << " = " << this->_bitcoinPrices[date] * value << std::endl;
		return;
	}
	std::cout << "Error: ";
	if (date.empty())
		std::cout << "no previous date found";
	else if (status == E_BAD_INPUT)
		std::cout << "bad input => " << date;
	else if (status == E_LARGE)
		std::cout << " too large a number => " << date;
	else if (status == E_NEGATIVE)
		std::cout << " not a positive number => " << date;
	std::cout << std::endl;
}

BitcoinExchange::~BitcoinExchange() {}