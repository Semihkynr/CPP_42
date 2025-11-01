/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:29:57 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/01 20:46:07 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name){this->name=name;}
void Zombie::setName(std::string newName){name=newName;}
std::string Zombie::getName(){return name;}
void Zombie::announce( void ){std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl; }

