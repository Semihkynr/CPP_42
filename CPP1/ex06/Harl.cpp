/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 23:57:15 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/02 17:36:38 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    std::cout << "Constraction" << std::endl;    
}

void Harl::debug( void ){
    std::cout << "[DEBUG]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;}
    
void Harl::info( void ){
    std::cout << "[INFO]" << std::endl << "I cannot believe adding extra bacon costs more money. You didnot put enough bacon in my burger! If you did, I would not be asking for more!" << std::endl;}

void Harl::warning( void ){
    std::cout << "[WARNING]" << std::endl << "I think I deserve to have some extra bacon for free. I have been coming for years, whereas you started working here just last month. " << std::endl;}

void Harl::error( void ){
    std::cout << "[ERROR]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;}
    
void Harl::complain(std::string level)
{
    static const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i = 0;
    
	for (i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			break;
	}
	switch (i)
	{
		case 0:
			(this->*functions[0])();
			std::cout << std::endl;
		case 1:
			(this->*functions[1])();
			std::cout << std::endl;
		case 2:
			(this->*functions[2])();
			std::cout << std::endl;
		case 3:
			(this->*functions[3])();
			std::cout << std::endl;
			break;
        default:
            std::cout << "Wrong Alarm!" << std::endl;
            break;
}}
