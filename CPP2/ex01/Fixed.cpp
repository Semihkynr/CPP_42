/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:53:15 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/10 14:08:14 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){std::cout << "Default costructer called" << std::endl;
	this->fixedPointValue = 0;}

Fixed::Fixed(const Fixed &cpy){std::cout << "Copy costructer called" << std::endl;
	*this = cpy;}

Fixed::~Fixed(){std::cout << "Destructor called" << std::endl;}

Fixed& Fixed::operator=(const Fixed& other){std::cout << "Copy assigment operator called" << std::endl;
	this->fixedPointValue = other.fixedPointValue;
	return (*this);}


Fixed::Fixed(int const value){std::cout << "Int costructer called" << std::endl;
	this->fixedPointValue = value << this->fractionalBits;}

Fixed::Fixed(float const value)
{
	std::cout << "Float costructer called" << std::endl;
	this->fixedPointValue = roundf(value * (1 << this->fractionalBits));
}
void	Fixed::setRawBits(int raw)
{std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
}
float	Fixed::toFloat(void) const
{return ((float)this->fixedPointValue / (1 << this->fractionalBits));}

int	Fixed::toInt(void) const{return (this->fixedPointValue >> this->fractionalBits);}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{os << fixed.toFloat();
	return (os);}