#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
private:
	std::map<std::string, float> _bitcoinPrices;

public:
	BitcoinExchange(void);
	BitcoinExchange(std::string db);
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &assign);
	~BitcoinExchange(void);
};

#endif