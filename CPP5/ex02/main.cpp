/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:59:41 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/18 17:09:16 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>   // time() için
#include <cstdlib> // srand() için

int main() {
    // Rastgelelik tohumunu ekiyoruz (Robotomy için)
    std::srand(std::time(NULL));

    std::cout << "===== TEST 1: Shrubbery (Ağaç Dikme) =====" << std::endl;
    try {
        Bureaucrat bahcivan("Bahçivan", 140);
        ShrubberyCreationForm f1("ev");

        std::cout << bahcivan << std::endl;
        std::cout << f1 << std::endl;

        bahcivan.signForm(f1);      // 140 <= 145 (İmzalar)
        bahcivan.executeForm(f1);   // 140 > 137 (ÇALIŞTIRAMAZ - Hata vermeli)
        
        // Terfi ettirelim
        for (int i = 0; i < 5; i++) bahcivan.promote(); 
        std::cout << "Terfi sonrası: " << bahcivan << std::endl;
        bahcivan.executeForm(f1);   // 135 <= 137 (Artık çalıştırır)
    }
    catch (std::exception &e) {
        std::cerr << "Beklenmedik hata: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 2: Robotomy (Robotlaştırma) =====" << std::endl;
    try {
        Bureaucrat tech("Teknisyen", 40);
        RobotomyRequestForm f2("Müşteri_1");

        tech.signForm(f2);
        tech.executeForm(f2); // %50 şansla başarılı/başarısız
        tech.executeForm(f2); // Tekrar deneyelim
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 3: Presidential Pardon (Af) =====" << std::endl;
    try {
        Bureaucrat boss("Cumhurbaşkanı", 4);
        PresidentialPardonForm f3("Suçlu_Cemil");

        // İmzasız çalıştırmayı deneyelim
        boss.executeForm(f3); 
        
        boss.signForm(f3);
        boss.executeForm(f3); // Şimdi çalışmalı
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 4: Yetkisiz Bürokrat =====" << std::endl;
    try {
        Bureaucrat intern("Stajyer", 150);
        PresidentialPardonForm f4("Mahkum");

        intern.signForm(f4);    // 150 > 25 (İmzalayamaz)
        intern.executeForm(f4); // İmzasız olduğu için direkt "NotSigned" hatası verir
    }
    catch (std::exception &e) {
        std::cerr << "Yakalanan Hata: " << e.what() << std::endl;
    }

    return 0;
}
