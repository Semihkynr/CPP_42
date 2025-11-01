/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:58:31 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/01 23:55:27 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>


int check_arg(char **av)
{
    std::ifstream file(av[1]);

    if(std::string(av[1]).empty() || std::string(av[3]).empty() || std::string(av[3]).empty())
    {
        std::cout << "Empty Arguments!!" << std::endl;
        return 0 ;
    }
    else if(std::string(av[2]).compare(av[3]) == 0)
        {
            std::cout << "Same Arguments!!" << std::endl;   
            return 0 ;
        }
    else if(!file.is_open())
        {std::cout << "Isn't openned!" << std::endl;
        return 0 ;}
    else
        return 1;
}

int main(int ac , char **av)
{
    if(ac != 4)
        {std::cout << "3 arguments pls!"<< std::endl;
        return 0;}
    if(check_arg(av) == 0)
        return 0 ;
    std::string file = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::string secondFile = file + ".replace";
    std::string fake;
    std::ifstream myFile(av[1]);
    std::ofstream copyFile(secondFile.c_str());
    
    if(!copyFile.is_open())
        {std::cout << "Isn't openned!" << std::endl; 
        return 0 ;}
        
    while (std::getline (myFile, fake)) {
        size_t i = fake.find(s1);
        while (i != std::string::npos) { fake.erase(i, s1.length());
            fake.insert(i, s2);
            i = fake.find(s1);}
        copyFile << fake << std::endl;
    }
    copyFile.close();
    myFile.close();
}