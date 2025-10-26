/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:34:57 by skaynar           #+#    #+#             */
/*   Updated: 2025/10/26 16:30:07 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int     nextIndex;
    int     contactCount;

    void        printFormatted(std::string str);
    void        displayContacts();
    bool        isAllDigits(const std::string& str);
    std::string getNonEmptyInput(std::string prompt);


public:
    PhoneBook();
    void addContact();
    void searchContacts();
};

#endif