/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:10:16 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/08 15:16:00 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat rank is way too high!";}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat rank is way too low!";}

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
    {this->grade = other.grade;}return *this;}
Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName() const {return this->name;}

int Bureaucrat::getGrade() const{return this->grade;}

void Bureaucrat::promote() {
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::demote() {
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

void Bureaucrat::signForm(Form& f) {
    try {
        f.be_signed(*this);
        std::cout << this->name << " signed " << f.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->name << " couldn't sign " << f.getName() 
                  << " because " << e.what() << std::endl;
    }
}
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return out;
}