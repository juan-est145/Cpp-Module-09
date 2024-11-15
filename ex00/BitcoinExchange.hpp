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
	typedef enum eStatus
	{
		CORRECT,
		E_BAD_INPUT,
		E_LARGE,
		E_NEGATIVE,
	} tStatus;
	std::map<std::string, float> _bitcoinPrices;
	tStatus valDate(std::string &date);
	tStatus valValue(std::string &valueS);
	std::string findClosestDate(const std::string &date);
	void printMsg(tStatus status, const std::string &date, float value);

public:
	BitcoinExchange(void);
	BitcoinExchange(std::string db);
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &assign);
	void getValues(const char *data);
	~BitcoinExchange(void);
};

#endif