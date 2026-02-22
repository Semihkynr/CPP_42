/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:49:07 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/22 12:51:17 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw() { return "AForm: Grade too high!"; }
const char* AForm::GradeTooLowException::what() const throw() { return "AForm: Grade too low!"; }
const char* AForm::FormNotSignedException::what() const throw() { return "AForm: Form is not signed yet!"; }
AForm::AForm(const std::string name, int gradeToSign, int gradeToExec) 
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
    if (this->gradeToSign < 1 || this->gradeToExec < 1)
        throw AForm::GradeTooHighException();
    if (this->gradeToSign > 150 || this->gradeToExec > 150)
        throw AForm::GradeTooLowException();
}
AForm::AForm(const AForm& other) 
    : name(other.name), isSigned(other.isSigned), 
      gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec) {}
AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}
AForm::~AForm() {}
const std::string AForm::getName() const { return this->name; }
bool AForm::getIsSigned() const { return this->isSigned; }
int AForm::getGradeToSign() const { return this->gradeToSign; }
int AForm::getGradeToExec() const { return this->gradeToExec; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();
    this->isSigned = true;
}
void AForm::execute(const Bureaucrat& executor) const {
    if (!this->isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->gradeToExec)
        throw AForm::GradeTooLowException();
    this->executeAction();
}
std::ostream& operator<<(std::ostream& out, const AForm& obj) {
    out << "Form [" << obj.getName() << "] - Signed: " << (obj.getIsSigned() ? "Yes" : "No")
        << " (Req Sign: " << obj.getGradeToSign() << ", Req Exec: " << obj.getGradeToExec() << ")";
    return out;
}




