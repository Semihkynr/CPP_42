
#include "RPN.hpp"
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <stdexcept>

RPN::RPN(){}
RPN::RPN(const RPN &other){(void)other;}
RPN &RPN::operator=(const RPN &other){
	(void)other;
	return (*this);}
RPN::~RPN(){}
bool RPN::isOperator(const std::string &token) const{return (token == "+" || token == "-" || token == "*" || token == "/");}
bool RPN::isNumber(const std::string &token) const{
	if (token.empty())
		return (false);
	for (size_t i = 0; i < token.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(token[i])))
			return (false);}
	return (true);}
int RPN::applyOperator(int a, int b, const std::string &op) const{
	if (op == "+")
		return (a + b);
	if (op == "-")
		return (a - b);
	if (op == "*")
		return (a * b);
	if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("division by zero.");
		return (a / b);}
	throw std::runtime_error("unknown operator.");}
int RPN::evaluate(const std::string &expression) const{
	std::stack<int>	values;
	std::istringstream	iss(expression);
	std::string			token;

	while (iss >> token)
	{
		if (isNumber(token))
		{
			if (token.size() > 1)
				throw std::runtime_error("invalid expression.");
			values.push(std::atoi(token.c_str()));
		}
		else if (isOperator(token))
		{
			if (values.size() < 2)
				throw std::runtime_error("invalid expression.");
			int b = values.top();
			values.pop();
			int a = values.top();
			values.pop();
			values.push(applyOperator(a, b, token));
		}
		else
			throw std::runtime_error("invalid expression.");}	
	if (values.size() != 1)
		throw std::runtime_error("invalid expression.");
	return (values.top());}