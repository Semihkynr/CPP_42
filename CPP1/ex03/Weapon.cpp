/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 20:49:22 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/01 22:29:07 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void Weapon::setType(std::string type){this->type = type;}
std::string Weapon::getType(){return type;}

Weapon::Weapon(){};
Weapon::Weapon(std::string type){this->type = type;}
