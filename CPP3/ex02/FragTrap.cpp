/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:20:37 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/12 01:33:07 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string nam): ClapTrap(nam)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    this->maxHp = this->hitPoints;
    std::cout << "FragTrap constructor called" << std::endl;
}
FragTrap::FragTrap(): ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    this->maxHp = this->hitPoints;
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap()
{std::cout << "FragTrap destructor called" << std::endl;}

FragTrap::FragTrap(const FragTrap &other):ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = other;
}

FragTrap &FragTrap :: operator=(const FragTrap &other)
{
    ClapTrap::operator=(other);
    return (*this);
}

void FragTrap::attack(const std::string& target)
{
    if (this->energyPoints <= 0 || this->hitPoints <= 0)
    { std::cout << "FragTrap " << name << " has no energy to attack!"<< std::endl;
        return; }
    this->energyPoints--;
    std::cout << "FragTrap " << name << " attack " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{std::cout << "!!!FragTrap gives a high five!!!" << std::endl;}
