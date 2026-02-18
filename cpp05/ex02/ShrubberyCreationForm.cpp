/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:59:55 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/18 17:08:46 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) 
    : AForm("Shrubbery Creation", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    (void)other; // name ve target const olduğu için bir şey kopyalanamaz
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
    // Dosya adını hazırlıyoruz: hedef_shrubbery
    std::string filename = this->target + "_shrubbery";
    
    // std::ofstream ile dosyayı açıyoruz. 
    // .c_str() kullanıyoruz çünkü C++98'de open() fonksiyonu std::string kabul etmez.
    std::ofstream outfile(filename.c_str());

    if (!outfile.is_open()) {
        std::cerr << "Error: Could not open the file for writing!" << std::endl;
        return;
    }

    // Dosyanın içine o meşhur ağaçlarımızı çiziyoruz
    outfile << "              v .   ._, |_  .," << std::endl;
    outfile << "           `-._\\/  .  \\ /    |/_" << std::endl;
    outfile << "               \\  \\, y | \\//" << std::endl;
    outfile << "         _\\_.___\\, \\/ -. \\||" << std::endl;
    outfile << "           `7-,--.`._||  / / ," << std::endl;
    outfile << "           /'     `-. `./ / |/_." << std::endl;
    outfile << "                     |    |//" << std::endl;
    outfile << "                     |_    /" << std::endl;
    outfile << "                     |-   |" << std::endl;
    outfile << "                     |   =|" << std::endl;
    outfile << "                     |    |" << std::endl;
    outfile << "--------------------/ ,  . \\--------" << std::endl;

    outfile.close(); // Dosyayı kapatmayı unutmuyoruz
    std::cout << "Shrubbery has been planted in " << filename << std::endl;
}