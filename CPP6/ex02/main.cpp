/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 12:22:56 by skaynar           #+#    #+#             */
/*   Updated: 2026/03/07 12:33:22 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Home.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Home * generate(void);
void identify(Home* p);
void identify(Home& p);

int main() {
    std::srand(std::time(0));

    std::cout << "--- Test 1 ---" << std::endl;
    Home* ptr1 = generate();
    identify(ptr1);
    identify(*ptr1);
    delete ptr1;

    std::cout << "\n--- Test 2 ---" << std::endl;
    Home* ptr2 = generate();
    identify(ptr2);
    identify(*ptr2);
    delete ptr2;

    std::cout << "\n--- Test 3 ---" << std::endl;
    Home* ptr3 = generate();
    identify(ptr3);
    identify(*ptr3);
    delete ptr3;
    return 0;
}