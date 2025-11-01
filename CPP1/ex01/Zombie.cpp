/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:34:55 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/01 18:03:06 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

Zombie::Zombie(std::string name){this->name=name;}
Zombie::Zombie(){name = "nameless";}
void Zombie::setName(std::string newName){name=newName;}
std::string Zombie::getName(){return name;}
void Zombie::announce(){std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl; }

