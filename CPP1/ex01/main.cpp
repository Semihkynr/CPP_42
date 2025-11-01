/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:35:13 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/01 18:07:33 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* Zomsu = zombieHorde(11,"Zomsu");
    
    for(int i = 0; i < 11; i++)
    {
        std::cout <<"Zombi "<< i+1<<std::endl;
        Zomsu[i].announce();
    }
    delete [] Zomsu;
}