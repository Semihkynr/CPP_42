/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:35:54 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/11 23:01:36 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string nam)
{   this->name = nam;
this->attackDamage = 0;
this->energyPoints = 10;
this->hitPoints = 10;  
std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(){
    this->attackDamage = 0;
    this->energyPoints = 10;
    this->hitPoints = 10; 
    this->name = "Nameless";
    std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{  std::cout << "Destructor called" << std::endl;}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

std::string ClapTrap::getName(){return name;}

int ClapTrap::getDamage(){return attackDamage;}

int ClapTrap::getEnergy(){return energyPoints;}

int ClapTrap::getHit(){return hitPoints;}

void ClapTrap::setEnergy(int energy){this->energyPoints = energy;};

void ClapTrap::setHit(int hit){this->hitPoints = hit;};

void ClapTrap::attack(const std::string& target){
    if(this->hitPoints > 0 && this->energyPoints > 0)
        {std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;}
    else
        {
            if(this->hitPoints <= 0)
            {   std::cout << "You need healt!"<< std::endl;}
            else{std::cout << "You are tired! You need EnergyPoints!" << std::endl; }
        }
};
void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints <= 0)
    {std::cout << this->name << " is already destroyed and cannot take " << amount << " points of further damage." << std::endl;
        return ;}
    int newHitPoints = this->hitPoints - (int)amount;
    if (newHitPoints < 0)
        newHitPoints = 0;

    setHit(newHitPoints);
    std::cout << this->name << " takes " << amount << " points of damage!" << " Hit Points remaining: " << this->hitPoints << "." << std::endl;
    if (this->hitPoints == 0)
    {std::cout << this->name << " has been destroyed!" << std::endl;}
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints <= 0)
    {std::cout << this->name << " is destroyed and cannot repair itself." << std::endl;
        return;}
    if (this->energyPoints <= 0)
    {std::cout << this->name << " is out of energy and cannot repair itself!" << std::endl;
        return;}
    this->hitPoints += amount;
    if(this->hitPoints > 10)
        this->hitPoints = 10;
    this->energyPoints--;
    std::cout << this->name << " repairs itself for " << amount << " points of health! " << "Hit Points: " << this->hitPoints << ", Energy remaining: " << this->energyPoints << "." << std::endl;
}