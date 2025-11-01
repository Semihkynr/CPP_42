/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 20:49:24 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/01 21:53:49 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon{
    private:
        std::string type;
    public:
        Weapon();
        Weapon(std::string type);
        std::string getType();
        void setType(std::string type);
};

#endif