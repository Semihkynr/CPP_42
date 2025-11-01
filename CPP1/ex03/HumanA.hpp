/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 20:49:08 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/01 22:07:57 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        Weapon  &weapon;
        std::string name;
    public:
        HumanA(std::string name, Weapon &weapon);
        void setWeapon(Weapon &weapon);
        void setName(std::string name);
        std::string getName();
        void attack();
};

#endif
