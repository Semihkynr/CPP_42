/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:39:02 by skaynar           #+#    #+#             */
/*   Updated: 2026/06/10 00:00:00 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    // --- Subject'in ornegi: 2 ve 14 bekleniyor ---
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan:  " << sp.longestSpan()  << std::endl;

    // --- Dolu Span'e ekleme -> istisna ---
    try {
        sp.addNumber(99);
    } catch (const std::exception& e) {
        std::cout << "Yakalandı: " << e.what() << std::endl;
    }

    // --- addRange: 10.000 rastgele sayi ile buyuk olcekli test ---
    std::srand(static_cast<unsigned int>(std::time(0)));
    const unsigned int N = 10000;
    std::vector<int> big(N);
    for (unsigned int i = 0; i < N; ++i)
        big[i] = std::rand();

    Span big_sp(N);
    big_sp.addRange(big.begin(), big.end());
    std::cout << "10k shortestSpan: " << big_sp.shortestSpan() << std::endl;
    std::cout << "10k longestSpan:  " << big_sp.longestSpan()  << std::endl;

    return 0;
}
