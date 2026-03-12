/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:25:12 by skaynar           #+#    #+#             */
/*   Updated: 2026/03/06 15:31:09 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "PLEASE ./ex00 <literal>" << std::endl;
        return 1;
    }
    std::cout << "--- Scalar Conversion Test ---" << std::endl;
    std::cout << "Input: " << argv[1] << std::endl;
    std::cout << "------------------------------" << std::endl;
    ScalarConverter::convert(argv[1]);
    return 0;
}