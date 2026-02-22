/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:59:55 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/22 13:24:00 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) 
    : AForm("Shrubbery Creation", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    (void)other;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
    std::string filename = this->target + "_shrubbery";
    std::ofstream outfile(filename.c_str());

    if (!outfile.is_open()) {
        std::cerr << "Error: Could not open the file for writing!" << std::endl;
        return;}

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

    outfile.close();
    std::cout << "Shrubbery has been planted in " << filename << std::endl;
}