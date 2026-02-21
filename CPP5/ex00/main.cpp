/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:39:45 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/07 14:45:50 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "--- Test 1: Standard Bureaucrat ---" << std::endl;
    try {
        Bureaucrat b1("Müdür", 2);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << "Terfi sonrası: " << b1 << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Hata: " << e.what() << std::endl;
    }
    std::cout << "\n--- Test 2: Grade Too High (Geçersiz Başlangıç) ---" << std::endl;
    try {
        Bureaucrat b2("Tanrı", 0);
        std::cout << b2 << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Hata yakalandı: " << e.what() << std::endl;
    }
    std::cout << "\n--- Test 3: Grade Too Low (Geçersiz Başlangıç) ---" << std::endl;
    try {
        Bureaucrat b3("Stajyer", 151);
    }
    catch (std::exception &e) {
        std::cerr << "Hata yakalandı: " << e.what() << std::endl;
    }
    std::cout << "\n--- Test 4: Incrementing Grade 1 ---" << std::endl;
    try {
        Bureaucrat b4("Zirvedeki Adam", 1);
        std::cout << b4 << std::endl;
        b4.incrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << "Hata yakalandı: " << e.what() << std::endl;
    }
    std::cout << "\n--- Test 5: Decrementing Grade 150 ---" << std::endl;
    try {
        Bureaucrat b5("Yolun Sonu", 150);
        std::cout << b5 << std::endl;
        b5.decrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << "Hata yakalandı: " << e.what() << std::endl;
    }
    return 0;
}