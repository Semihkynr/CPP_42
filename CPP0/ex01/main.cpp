/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:57:21 by skaynar           #+#    #+#             */
/*   Updated: 2025/10/26 16:45:23 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
    PhoneBook   myPhoneBook;
    std::string command;

    std::cout << "Welcome to your My Awesome PhoneBook!" << std::endl;

    while (true) {
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        
        if (!std::getline(std::cin, command)) {
            break;
        }

        if (command == "ADD") {myPhoneBook.addContact();} 
        else if (command == "SEARCH") {myPhoneBook.searchContacts();}
        else if (command == "EXIT") {
            std::cout << "CU L8ER" << std::endl;
            break;
        } else {std::cout << "Please use ADD, SEARCH, or EXIT." << std::endl;}}
    return 0;}