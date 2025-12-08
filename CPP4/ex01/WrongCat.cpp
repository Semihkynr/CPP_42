/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:49:31 by skaynar           #+#    #+#             */
/*   Updated: 2025/12/08 11:52:44 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {this->type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {this->type = other.type;
    std::cout << "WrongCat copy constructor called" << std::endl;}
WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other)
        WrongAnimal::operator=(other);
    std::cout << "WrongCat copy assignment called" << std::endl;
    return *this;}
WrongCat::~WrongCat() {std::cout << "WrongCat destructor called" << std::endl;}
void WrongCat::makeSound() const {std::cout << "WrongMIAW!" << std::endl;}