/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:59:50 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/22 13:23:29 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string target) 
    : AForm("Robotomy Request", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    (void)other;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const {std::cout << "* BZZZZZT! WHRRRRRRR! DRILLING NOISES *" << std::endl;
    if (std::rand() % 2 == 0) {std::cout << this->target << " has been robotomized successfully!" << std::endl;}
    else {std::cout << "The robotomy on " << this->target << " failed. System error!" << std::endl;}
}