/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:53:20 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/10 17:04:41 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){std::cout << "Default Costructer Called" << std::endl;
	this->fixedPointValue = 0;}

Fixed::Fixed(const Fixed &cpy){std::cout << "Copy Costructer Called" << std::endl;
	*this = cpy;}

Fixed::~Fixed(){std::cout << "Destructor Called" << std::endl;}

Fixed& Fixed::operator=(const Fixed& num){std::cout << "Copy Assigment Operator Called" << std::endl;
	this->fixedPointValue = num.fixedPointValue;
	return (*this);}

Fixed::Fixed(int const value){std::cout << "Int Costructer Called" << std::endl;
	this->fixedPointValue = value << this->fractionalBits;}

Fixed::Fixed(float const value){std::cout << "Float Costructer Called" << std::endl;
	this->fixedPointValue = roundf(value * (1 << this->fractionalBits));}

void	Fixed::setRawBits(int raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}
int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
}

float	Fixed::toFloat(void) const{return ((float)this->fixedPointValue / (1 << this->fractionalBits));}

int	Fixed::toInt(void) const{return (this->fixedPointValue >> this->fractionalBits);}

Fixed	Fixed::operator+(const Fixed& num){Fixed tmp;
	tmp.fixedPointValue = this->fixedPointValue + num.fixedPointValue;
	return tmp;}
	
Fixed	Fixed::operator-(const Fixed& num)
{
	Fixed tmp;
	tmp.fixedPointValue = this->fixedPointValue - num.fixedPointValue;
	return tmp;
}
std::ostream& operator<<(std::ostream& os, const Fixed& fixed){os << fixed.toFloat();
		return (os);}
		
Fixed	Fixed::operator/(const Fixed& num)
{
	Fixed tmp;
	tmp.fixedPointValue = (float)this->fixedPointValue / (float)num.fixedPointValue * (1 << this->fractionalBits);
	return tmp;
}
Fixed	Fixed::operator*(const Fixed& num)
{
	Fixed tmp;
	tmp.fixedPointValue = this->fixedPointValue * num.fixedPointValue / (1 << this->fractionalBits);
	return tmp;
}

bool	Fixed::operator>(const Fixed& num) const
{
	return (this->fixedPointValue > num.fixedPointValue);
}

bool	Fixed::operator<(const Fixed& num) const
{
	return (this->fixedPointValue < num.fixedPointValue);
}

bool	Fixed::operator>=(const Fixed& num) const
{
	return (this->fixedPointValue >= num.fixedPointValue);
}

bool	Fixed::operator<=(const Fixed& num) const
{
	return (this->fixedPointValue <= num.fixedPointValue);
}

bool	Fixed::operator==(const Fixed& num) const
{
	return (this->fixedPointValue == num.fixedPointValue);
}

bool	Fixed::operator!=(const Fixed& num) const
{
	return (this->fixedPointValue != num.fixedPointValue);
}


Fixed&	Fixed::operator++() 
{
	this->fixedPointValue++;
	return (*this);
}

Fixed	Fixed::operator++(int) 
{
	Fixed tmp(*this);
	this->fixedPointValue++;
	return (tmp);
}

Fixed&	Fixed::operator--() 
{
	this->fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator--(int) 
{
	Fixed tmp(*this);
	this->fixedPointValue--;
	return (tmp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if(a < b)
		return a;
	return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if(a > b)
		return a;
	return b;
}

const Fixed&	Fixed::min(Fixed const& a, Fixed const& b)
{
	if(a < b)
		return a;
	return b;
}

const Fixed&	Fixed::max(Fixed const& a, Fixed const& b)
{
	if(a > b)
		return a;
	return b;
}