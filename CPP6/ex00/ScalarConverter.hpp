/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:59:28 by skaynar           #+#    #+#             */
/*   Updated: 2026/03/01 14:59:33 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <cmath>
# include <iomanip>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter& rhs);
        ScalarConverter(const ScalarConverter& src);
        ~ScalarConverter();
    public:
        static void convert(const std::string& literal);
};
#endif