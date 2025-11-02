/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 23:57:17 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/02 17:31:42 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac , char **av)
{
    if(ac == 2)
    {
        Harl harl;
        harl.complain(av[1]); 
    }
    else
        std::cout << "./harl <level> pls!!" << std::endl;
    return 0;
}