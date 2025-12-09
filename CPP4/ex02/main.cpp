/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:13:35 by skaynar           #+#    #+#             */
/*   Updated: 2025/12/08 12:13:36 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	
    Animal* animals[2];

    animals[0] = new Dog();
    animals[1] = new Cat();

    std::cout << std::endl;
    for (int i = 0; i < 2; i++) {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    std::cout << std::endl;
    for (int i = 0; i < 2; i++)
        delete animals[i];

    return 0;
}