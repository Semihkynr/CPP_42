#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <map>
#include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &dbFile);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		void processInputFile(const std::string &inputFile) const;
	private:
		std::map<std::string, double>	_database;
		void	loadDatabase(const std::string &dbFile);
		bool	isValidDate(const std::string &date) const;
		bool	isLeapYear(int year) const;
		double	getRateForDate(const std::string &date) const;
};
#endif