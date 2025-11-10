/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:53:00 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/10 12:40:06 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){std::cout << "Default Costructer Called" << std::endl;
	this->fixedPointValue = 0;}

Fixed::Fixed(const Fixed &cpy){std::cout << "Copy Costructer Called" << std::endl;
	*this = cpy;}

Fixed& Fixed::operator=(const Fixed& other)
{std::cout << "Copy Assigment Operator Called" << std::endl;
	this->fixedPointValue = other.getRawBits();
	return (*this);}

Fixed::~Fixed(){std::cout << "Destructor Called" << std::endl;}

void	Fixed::setRawBits(int raw){std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;}
	
int	Fixed::getRawBits() const{std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);}
