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
	typedef enum e_status
	{
		CORRECT,
		E_BAD_INPUT,
		E_LARGE,
		E_NEGATIVE,
	} t_status;
	std::map<std::string, float> _bitcoinPrices;
	t_status valData(const std::string &date);
	t_status valData(const std::string &date, const std::string &valueS);

public:
	BitcoinExchange(void);
	BitcoinExchange(std::string db);
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &assign);
	void getValues(const char *data);
	~BitcoinExchange(void);
};

#endif