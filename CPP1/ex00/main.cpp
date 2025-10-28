/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:29:50 by skaynar           #+#    #+#             */
/*   Updated: 2025/10/28 16:22:58 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie myZombie("semih");
    
    myZombie.randomChump("KAYNAR");
    Zombie* newZombie = myZombie.newZombie("kaynar");
    std::cout << newZombie->getName() << std::endl;
    std::cout << myZombie.getName() << std::endl;

    
    return 1;
}