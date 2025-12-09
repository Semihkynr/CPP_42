/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:13:38 by skaynar           #+#    #+#             */
/*   Updated: 2025/12/08 12:31:11 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {std::cout << "WrongAnimal constructor called" << std::endl;}
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {std::cout << "WrongAnimal copy constructor called" << std::endl;}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other)
        this->type = other.type;
    std::cout << "WrongAnimal copy assignment called" << std::endl;
    return *this;}

WrongAnimal::~WrongAnimal() {std::cout << "WrongAnimal destructor called" << std::endl;}
std::string WrongAnimal::getType() const {return this->type;}
void WrongAnimal::makeSound() const {std::cout << "WrongAnimalSound" << std::endl;}