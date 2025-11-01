/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:35:04 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/01 17:58:03 by skaynar          ###   ########.fr       */
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
        Zombie();
        std::string getName();
        void setName(std::string newName);
        void announce();
};
Zombie* zombieHorde( int N, std::string name );
Zombie* newZombie( std::string name );

#endif