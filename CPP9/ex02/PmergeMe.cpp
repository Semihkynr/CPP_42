#include "PmergeMe.hpp"
#include <iostream>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <sys/time.h>

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &other){(void)other;}
PmergeMe &PmergeMe::operator=(const PmergeMe &other){
	(void)other;
	return (*this);}
PmergeMe::~PmergeMe(){}
static bool isAllDigits(const std::string &s){
	if (s.empty())
		return (false);
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return (false);
	}
	return (true);}
std::vector<int> PmergeMe::parseArgs(int argc, char **argv) const{
	std::vector<int> result;
	for (int i = 1; i < argc; ++i)
	{
		std::string token(argv[i]);
		if (!isAllDigits(token))
			throw std::runtime_error("Error");
		long value = std::atol(token.c_str());
		if (value < 0 || value > INT_MAX)
			throw std::runtime_error("Error");
		result.push_back(static_cast<int>(value));
	}
	if (result.empty())
		throw std::runtime_error("Error");
	return (result);}
static double nowMicroseconds(){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (static_cast<double>(tv.tv_sec) * 1000000.0 + static_cast<double>(tv.tv_usec));}
static void printSequence(const std::string &label, const std::vector<int> &seq){
	std::cout << label;
	for (size_t i = 0; i < seq.size(); ++i)
		std::cout << (i == 0 ? "" : " ") << seq[i];
	std::cout << std::endl;}
void PmergeMe::run(int argc, char **argv) const{
	std::vector<int> input = parseArgs(argc, argv);
	printSequence("Before: ", input);
	double startVector = nowMicroseconds();
	std::vector<int> sortedVector = mergeInsertionSort<std::vector<int> >(input);
	double endVector = nowMicroseconds();
	double startDeque = nowMicroseconds();
	std::deque<int> sortedDeque = mergeInsertionSort<std::deque<int> >(input);
	double endDeque = nowMicroseconds();
	(void)sortedDeque;
	printSequence("After: ", sortedVector);
	std::cout << "Time to process a range of " << input.size()
		<< " elements with std::vector : " << (endVector - startVector) << " us" << std::endl;
	std::cout << "Time to process a range of " << input.size()
		<< " elements with std::deque : " << (endDeque - startDeque) << " us" << std::endl;}