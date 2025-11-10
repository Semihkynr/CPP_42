/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:53:16 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/10 14:09:06 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int fixedPointValue;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();
		void setRawBits(int raw);
		int	 getRawBits() const;
		Fixed& operator=(const Fixed& other);
		Fixed(int const value);
		Fixed(float const value);
		int	toInt(void) const;
		float toFloat(void) const;
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif