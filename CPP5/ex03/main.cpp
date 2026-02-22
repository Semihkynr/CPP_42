/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:59:41 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/22 13:22:54 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    Intern  someRandomIntern;
    Bureaucrat boss("Müdür", 1);
    AForm* rrf;

    std::cout << "--- TEST 1: Geçerli Form ---" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }
    std::cout << "\n--- TEST 2: Geçersiz Form ---" << std::endl;
    AForm* unknown;
    unknown = someRandomIntern.makeForm("kahve istegi", "Mutfak");
    if (unknown) {delete unknown;}
    return 0;
}