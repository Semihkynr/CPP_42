/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:33:13 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/21 13:33:26 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }
Intern::~Intern() {}

AForm* Intern::makeForm(std::string formName, std::string target) {
    // Geçerli form isimlerini bir dizide tutuyoruz
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    int i = 0;
    while (i < 3 && formNames[i] != formName)
        i++;
    AForm* result = NULL;
    switch (i) {
        case 0:
            result = new ShrubberyCreationForm(target);
            break;
        case 1:
            result = new RobotomyRequestForm(target);
            break;
        case 2:
            result = new PresidentialPardonForm(target);
            break;
        default:
            std::cout << "Error: Intern cannot create " << formName << " because it doesn't exist." << std::endl;
            return NULL;
    }
    
    std::cout << "Intern creates " << result->getName() << std::endl;
    return result;
}