/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:18:30 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/12 01:30:21 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(std::string Name);
        FragTrap();
        ~FragTrap();
        FragTrap(const FragTrap &copy);
        FragTrap &operator=(const FragTrap &copy);
        
        void attack(const std::string& target);
        void highFivesGuys();
};

#endif