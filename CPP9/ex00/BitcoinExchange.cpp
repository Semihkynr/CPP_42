#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <climits>

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const std::string &dbFile){loadDatabase(dbFile);}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
	: _database(other._database){}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
	if (this != &other)
		_database = other._database;
	return (*this);}
BitcoinExchange::~BitcoinExchange(){}
static std::string trim(const std::string &s){
	size_t start = s.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return ("");
	size_t end = s.find_last_not_of(" \t\r\n");
	return (s.substr(start, end - start + 1));}
bool BitcoinExchange::isLeapYear(int year) const{return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));}
bool BitcoinExchange::isValidDate(const std::string &date) const{
	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < date.size(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return (false);
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int maxDay = daysInMonth[month - 1];
	if (month == 2 && isLeapYear(year))
		maxDay = 29;
	if (day < 1 || day > maxDay)
		return (false);
	return (true);}
void BitcoinExchange::loadDatabase(const std::string &dbFile){
	std::ifstream file(dbFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("could not open database file.");
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue;
		std::string date = trim(line.substr(0, comma));
		std::string rateStr = trim(line.substr(comma + 1));
		if (!isValidDate(date))
			continue;
		double rate = std::atof(rateStr.c_str());
		_database[date] = rate;
	}}
double BitcoinExchange::getRateForDate(const std::string &date) const{
	std::map<std::string, double>::const_iterator it = _database.lower_bound(date);
	if (it != _database.end() && it->first == date)
		return (it->second);
	if (it == _database.begin())
		throw std::runtime_error("no matching date in database.");
	--it;
	return (it->second);}

void BitcoinExchange::processInputFile(const std::string &inputFile) const{
	std::ifstream file(inputFile.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		size_t bar = line.find('|');
		if (bar == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = trim(line.substr(0, bar));
		std::string valueStr = trim(line.substr(bar + 1));
		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (valueStr.empty())
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		char *endptr;
		double value = std::strtod(valueStr.c_str(), &endptr);
		if (*endptr != '\0')
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		try
		{
			double rate = getRateForDate(date);
			std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Error: bad input => " << line << std::endl;
		}}}