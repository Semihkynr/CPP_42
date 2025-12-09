/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:13:30 by skaynar           #+#    #+#             */
/*   Updated: 2025/12/08 12:35:57 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;}
Cat::Cat(const Cat& other) : Animal(other) {this->type = other.type;
	this->brain = new Brain(*other.brain);
	std::cout << "Cat copy constructor called" << std::endl;}
Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);}
	std::cout << "Cat copy assignment called" << std::endl;
	return *this;}
Cat::~Cat() {delete this->brain;
	std::cout << "Cat destructor called" << std::endl;}
void Cat::makeSound() const {
	std::cout << "MIAV!" << std::endl;}
Brain* Cat::getBrain() const {return this->brain;}
