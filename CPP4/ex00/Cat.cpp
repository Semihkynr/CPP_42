/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:46:23 by skaynar           #+#    #+#             */
/*   Updated: 2025/12/08 11:53:23 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){this->type = "Cat";
	std::cout<<"Cat constructor called"<<std::endl;}
Cat::Cat(const Cat& other) : Animal(other) {
	this->type = other.type;
	std::cout << "Cat copy constructor called" << std::endl;}
Cat& Cat::operator=(const Cat& other) {
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Cat copy assignment called" << std::endl;
	return *this;}
void Cat::makeSound() const{std::cout << "MIAV!" << std::endl;}
Cat::~Cat(){std::cout << "Cat destructor called" << std::endl;}