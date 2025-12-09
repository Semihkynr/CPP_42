/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:13:21 by skaynar           #+#    #+#             */
/*   Updated: 2025/12/08 12:34:29 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    for (int i = 0; i < 100; ++i)
        ideas[i] = "";
    std::cout << "Brain default constructor called" << std::endl;}
Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];
    std::cout << "Brain copy constructor called" << std::endl;}
Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];}
    std::cout << "Brain copy assignment called" << std::endl;
    return *this;}
Brain::~Brain() {std::cout << "Brain destructor called" << std::endl;}
void Brain::setIdea(int i, const std::string& str) {
    if (i >= 0 && i < 100)
        ideas[i] = str;}
std::string Brain::getIdea(int i) const {
    if (i >= 0 && i < 100)
        return ideas[i];
    return std::string();}
