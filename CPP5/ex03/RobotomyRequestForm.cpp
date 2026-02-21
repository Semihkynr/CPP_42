/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:59:50 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/18 17:08:00 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime> // Zaman bazlı rastgelelik için

RobotomyRequestForm::RobotomyRequestForm(const std::string target) 
    : AForm("Robotomy Request", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), target(other.target) {}

// name ve target const olduğu için operatör boş döner
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    (void)other;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const {
    std::cout << "* BZZZZZT! WHRRRRRRR! DRILLING NOISES *" << std::endl;

    // Basit bir %50 şans algoritması
    // Her çalıştığında farklı sonuç vermesi için main'de srand() çağırmayı unutma
    if (std::rand() % 2 == 0) {
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "The robotomy on " << this->target << " failed. System error!" << std::endl;
    }
}