/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Home.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 12:24:18 by skaynar           #+#    #+#             */
/*   Updated: 2026/03/12 14:50:35 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Home.hpp"
#include <cstdlib>
#include <ctime>

Home * generate(void) {
    int r = std::rand() % 3;
    if (r == 0) {std::cout << "Gereçte üretilen: A" << std::endl;
        return new A;
    } else if (r == 1) {std::cout << "Gerçekte üretilen: B" << std::endl;
        return new B;
    } else {std::cout << "Gerçekte üretilen: C" << std::endl;
        return new C;}}
void identify(Home* p) {
    std::cout << "Pointer ile tespit: ";
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Bilinmeyen Tip" << std::endl;
}
void identify(Home& p) {
    std::cout << "Referans ile tespit: ";
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (const std::exception& e) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (const std::exception& e) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (const std::exception& e) {}
}