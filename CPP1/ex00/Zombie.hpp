/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:29:59 by skaynar           #+#    #+#             */
/*   Updated: 2025/10/28 16:16:12 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    private: 
        std::string name;
    public:
        Zombie(std::string name);
        std::string getName();
        void setName(std::string newName);
        void announce( void );
        Zombie* newZombie( std::string name );
        void randomChump( std::string name );
};

#endif