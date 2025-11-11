/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:35:57 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/11 22:57:08 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(int ac, char **av){
    if(ac == 2){
        ClapTrap Clap(av[1]);
        Clap.attack("Kaynar");
        std::cout << Clap.getEnergy() << std::endl;
        Clap.takeDamage(5);
        Clap.beRepaired(5);
        Clap.beRepaired(5);
        std::cout << Clap.getHit() << std::endl;
        Clap.takeDamage(5);
        Clap.takeDamage(5);
    }
    else
        std::cout << "\"./ClapTrap <name>\" Please!!!" << std::endl;
    return 0;
}