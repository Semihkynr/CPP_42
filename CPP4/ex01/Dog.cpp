/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:49:20 by skaynar           #+#    #+#             */
/*   Updated: 2025/12/08 11:51:28 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : brain(new Brain()){this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;}
Dog::Dog(const Dog& other) : Animal(other) {this->type = other.type;
	this->brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called" << std::endl;}
Dog& Dog::operator=(const Dog& other){
	if (this != &other) {
		Animal::operator=(other);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);}
	std::cout << "Dog copy assignment called" << std::endl;
	return *this;}
Dog::~Dog() {delete this->brain;
	std::cout << "Dog destructor called" << std::endl;}
void Dog::makeSound() const{std::cout << "Woof!" << std::endl;}
Brain* Dog::getBrain() const {return this->brain;}