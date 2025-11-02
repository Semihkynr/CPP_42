/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 20:49:18 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/01 22:06:53 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon  *weapon;
    public:
        HumanB(std::string name);
        void setName(std::string name);
        const std::string& getName();
        void setWeapon(Weapon &weapon);
        void attack();
};

#endif