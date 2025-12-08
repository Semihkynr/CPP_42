/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:49:07 by skaynar           #+#    #+#             */
/*   Updated: 2025/12/08 11:49:09 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal"){std::cout << "Animal default constructor called" << std::endl;}
Animal::Animal(const Animal& other) : type(other.type) {std::cout << "Animal copy constructor called" << std::endl;}
Animal& Animal::operator=(const Animal& other) {
	if (this != &other)
		this->type = other.type;
	std::cout << "Animal copy assignment called" << std::endl;
	return *this;}
Animal::~Animal(){std::cout << "Animal destructor called" << std::endl;}
std::string Animal::getType() const{return this->type;}
void Animal::makeSound() const{std::cout << "AnimalSound" << std::endl;}