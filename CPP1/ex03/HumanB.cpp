/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 20:49:10 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/01 22:29:24 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::setName(std::string name){this->name = name;}
const std::string& HumanB::getName(){return name;}
HumanB::HumanB(std::string name){this->name = name;}
void HumanB::setWeapon(Weapon &weapon){this->weapon = &weapon;}

void HumanB::attack(){
    if(weapon == NULL)
        std::cout << getName() << " don't have weapon " << std::endl;
    else
        std::cout << getName() << " attacks with their " << weapon->getType() << std::endl;}
        