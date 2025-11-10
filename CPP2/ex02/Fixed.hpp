/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:53:22 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/10 14:11:51 by skaynar          ###   ########.fr       */
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
		Fixed ();
		Fixed (const Fixed& num);
		~Fixed ();
		Fixed& operator=(const Fixed& num);
		Fixed(float const value);
		Fixed(int const value);
		int		toInt(void) const;
		float	toFloat(void) const;
		bool	operator> (const Fixed& num) const;
		bool	operator< (const Fixed& num) const;
		bool	operator>=(const Fixed& num) const;
		bool	operator<=(const Fixed& num) const;
		bool	operator==(const Fixed& num) const;
		bool	operator!=(const Fixed& num) const;
		Fixed	operator+(const Fixed& num);
		Fixed	operator-(const Fixed& num);
		Fixed	operator*(const Fixed& num);
		Fixed	operator/(const Fixed& num);
		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
		static Fixed&	max(Fixed& a, Fixed& b);
		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	max(Fixed const& a, Fixed const& b);
		static const Fixed&	min(Fixed const& a, Fixed const& b);
		void	setRawBits(int raw);
		int		getRawBits() const;
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif