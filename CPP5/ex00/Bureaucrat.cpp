/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:37:30 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/22 11:11:09 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat Grade Too High Exception";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat Grade Too Low Exception";
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
        this->grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return name;}
int Bureaucrat::getGrade() const { return grade;}

void Bureaucrat::incrementGrade() {
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat  &b) {
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return o;
}