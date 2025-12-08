/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:46:33 by skaynar           #+#    #+#             */
/*   Updated: 2025/12/08 11:51:51 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const int N = 6;
	Animal* animal[N];
	for (int i = 0; i < N; ++i) {
		if (i < N / 2)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}

	std::cout << "\nsound" << std::endl;
	for (int i = 0; i < N; ++i)
		animal[i]->makeSound();

	std::cout << "\ndelete" << std::endl;
	for (int i = 0; i < N; ++i)
		delete animal[i];
	std::cout << "\ncopy test" << std::endl;
	Dog* d1 = new Dog();
	d1->getBrain()->setIdea(0, "Chase the mailman");
	Dog* d2 = new Dog(*d1);
	std::cout << "d1 str[0]: " << d1->getBrain()->getIdea(0) << std::endl;
	std::cout << "d2 str[0]: " << d2->getBrain()->getIdea(0) << std::endl;
	d1->getBrain()->setIdea(0, "Eat the bone");
	std::cout << "after changing d1" << std::endl;
	std::cout << "d1 str[0]: " << d1->getBrain()->getIdea(0) << std::endl;
	std::cout << "d2 str[0]: " << d2->getBrain()->getIdea(0) << std::endl;
	delete d2;
	delete d1;
	return 0;
}