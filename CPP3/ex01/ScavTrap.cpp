/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:40:13 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/12 01:23:03 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string nam): ClapTrap(nam)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->maxHp = this->hitPoints;
    std::cout << "ScavTrap constructor called" << std::endl;
}
ScavTrap::ScavTrap(): ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->maxHp = this->hitPoints;
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other):ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = other;
}

ScavTrap &ScavTrap :: operator=(const ScavTrap &other)
{
    ClapTrap::operator=(other);
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (this->energyPoints <= 0 || this->hitPoints <= 0)
    { std::cout << "ScavTrap " << name << " has no energy to attack!"<< std::endl;
        return; }
    this->energyPoints--;
    std::cout << "ScavTrap " << name << " attack " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{ std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;}