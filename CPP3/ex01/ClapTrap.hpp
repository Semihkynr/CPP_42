/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:35:52 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/11 23:01:58 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;
    std::string name;
    unsigned int maxHp;
public:
    ClapTrap(std::string nam);
    ClapTrap();
    ~ClapTrap();
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    std::string getName();
    int getDamage();
    int getEnergy();
    int getHit();
    void setEnergy(int energy);
    void setHit(int hit);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif