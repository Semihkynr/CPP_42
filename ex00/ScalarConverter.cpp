/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:26:28 by skaynar           #+#    #+#             */
/*   Updated: 2026/03/07 12:36:33 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) { (void)rhs; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
    double value;
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
        value = static_cast<double>(literal[0]);
    } else {value = std::atof(literal.c_str());}
    
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127) {
        std::cout << "impossible" << std::endl;
    } else if (!std::isprint(static_cast<int>(value))) {
        std::cout << "Non displayable" << std::endl;
    } else {std::cout << "'" << static_cast<char>(value) << "'" << std::endl;}
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || value > INT_MAX || value < INT_MIN) {
        std::cout << "impossible" << std::endl;
    } else {std::cout << static_cast<int>(value) << std::endl;}
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}