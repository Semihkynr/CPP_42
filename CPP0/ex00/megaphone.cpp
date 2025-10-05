/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:22:13 by skaynar           #+#    #+#             */
/*   Updated: 2025/10/05 14:27:03 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for(int i = 1; i < ac; i++)
        for(int j = 0; av[i][j]; j++)
            std::cout << (char)toupper(av[i][j]);
    std::cout << std::endl;
}