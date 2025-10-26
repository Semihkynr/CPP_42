/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:00:02 by skaynar           #+#    #+#             */
/*   Updated: 2025/10/11 13:11:45 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(std::string value){firstName = value;}
void Contact::setLastName(std::string value){lastName = value;}
void Contact::setNickName(std::string value){nickName = value;}
void Contact::setPhoneNumber(std::string value){phoneNumber = value;}
void Contact::setSecret(std::string value){secret = value;}

std::string Contact::getFirstName(){return firstName;}
std::string Contact::getLastName(){return lastName;}
std::string Contact::getNickName(){return nickName;}
std::string Contact::getPhoneNumber(){return phoneNumber;}
std::string Contact::getSecret(){return secret;} 