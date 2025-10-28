/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:34:55 by skaynar           #+#    #+#             */
/*   Updated: 2025/10/26 20:48:05 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <sstream>

PhoneBook::PhoneBook() {
    nextIndex = 0;
    contactCount = 0;
}

void PhoneBook::printFormatted(std::string str) {
    if (str.length() > 10) {
        std::cout << std::setw(9) << str.substr(0, 9) << ".";
    } else {
        std::cout << std::setw(10) << str;
    }
}

bool PhoneBook::isAllDigits(const std::string& str) {
    if (str.empty()) {
        return false;
    }
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

std::string PhoneBook::getNonEmptyInput(std::string prompt) {
    std::string input = "";
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty()) {std::cout << "Field cannot be empty. Please try again." << std::endl;}
    } while (input.empty());
    return input;
}

void PhoneBook::addContact() {
    std::string input;

    input = getNonEmptyInput("Enter First Name: ");
    contacts[nextIndex].setFirstName(input);

    input = getNonEmptyInput("Enter Last Name: ");
    contacts[nextIndex].setLastName(input);

    input = getNonEmptyInput("Enter Nickname: ");
    contacts[nextIndex].setNickName(input);

    do {
        input = getNonEmptyInput("Enter Phone Number: ");
        if (!isAllDigits(input)) {
            std::cout << "Invalid input. Please use only digits." << std::endl;
        }
    } while (!isAllDigits(input));
    contacts[nextIndex].setPhoneNumber(input);

    input = getNonEmptyInput("Enter Darkest Secret: ");
    contacts[nextIndex].setSecret(input);

    std::cout << "Contact successfully added!" << std::endl;

    nextIndex = (nextIndex + 1) % 8;

    if (contactCount < 8) {
        contactCount++;
    }
}

void PhoneBook::displayContacts() {
    std::cout << "*******************************************" << std::endl;
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    std::cout << "*******************************************" << std::endl;

    for (int i = 0; i < contactCount; i++) {
        std::cout << std::setw(10) << (i + 1) << "|";
        printFormatted(contacts[i].getFirstName());
        std::cout << "|";
        printFormatted(contacts[i].getLastName());
        std::cout << "|";
        printFormatted(contacts[i].getNickName());
        std::cout << std::endl;
    }
    std::cout << "*******************************************" << std::endl;
}

void PhoneBook::searchContacts() {
    if (contactCount == 0) {
        std::cout << "Phonebook is empty. Please ADD a contact first." << std::endl;
        return;
    }
    displayContacts();
    std::string input;
    int index = 0;
    std::cout << "Enter the index of the contact to display (1 to " << contactCount << "): ";
    std::getline(std::cin, input);
    std::stringstream ss(input);
    char extra_char;
    if (!(ss >> index) || (ss >> extra_char)) {
        std::cout << "Invalid input. Please enter only a number." << std::endl;
    } 
    else if (index >= 1 && index <= contactCount) {
        std::cout << "--- Contact Details (Index " << index << ") ---" << std::endl;
        std::cout << "First Name:     " << contacts[index-1].getFirstName() << std::endl;
        std::cout << "Last Name:      " << contacts[index-1].getLastName() << std::endl;
        std::cout << "Nickname:       " << contacts[index-1].getNickName() << std::endl;
        std::cout << "Phone Number:   " << contacts[index-1].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contacts[index-1].getSecret() << std::endl;
    } 
    else {
        std::cout << "Invalid index. Please enter a number between 1 and " << contactCount << "." << std::endl;
    }}