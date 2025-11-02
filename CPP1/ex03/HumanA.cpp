/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 20:49:06 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/01 22:29:31 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{this->name = name;}
void HumanA::setName(std::string name){this->name = name;}
std::string HumanA::getName(){return name;}
void HumanA::setWeapon(Weapon &weapon) {this->weapon = weapon;}

void HumanA::attack(){
    std::cout << getName()<<" attacks with their " << weapon.getType() << std::endl;}

