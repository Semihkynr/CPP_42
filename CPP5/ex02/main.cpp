/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:59:41 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/22 13:15:20 by skaynar          ###   ########.fr       */
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

        bahcivan.signForm(f1);
        bahcivan.executeForm(f1);
        for (int i = 0; i < 5; i++) bahcivan.promote(); 
        std::cout << "Terfi sonrası: " << bahcivan << std::endl;
        bahcivan.executeForm(f1);
    }
    catch (std::exception &e) {
        std::cerr << "Beklenmedik hata: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 2: Robotomy (Robotlaştırma) =====" << std::endl;
    try {
        Bureaucrat tech("Teknisyen", 40);
        RobotomyRequestForm f2("Müşteri_1");

        std::cout << f2 << std::endl;
        tech.signForm(f2);
        tech.executeForm(f2);
        tech.executeForm(f2);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 3: Presidential Pardon (Af) =====" << std::endl;
    try {
        Bureaucrat boss("Cumhurbaşkanı", 4);
        PresidentialPardonForm f3("Suçlu Cemil");
        
        std::cout << f3 << std::endl;
        boss.executeForm(f3); 
        boss.signForm(f3);
        boss.executeForm(f3);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 4: Yetkisiz Bürokrat =====" << std::endl;
    try {
        Bureaucrat intern("Stajyer", 150);
        PresidentialPardonForm f4("Mahkum");
        
        std::cout << f4 << std::endl;
        intern.signForm(f4);
        intern.executeForm(f4);
    }
    catch (std::exception &e) {
        std::cerr << "Yakalanan Hata: " << e.what() << std::endl;
    }

    return 0;
}
