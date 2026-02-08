/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:08:10 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/08 15:15:28 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw() { return "Form: Grade too high!"; }
const char* Form::GradeTooLowException::what() const throw() { return "Form: Grade too low!"; }

Form::Form(const std::string name, int signRank, int execRank) 
    : name(name), _signed(false), reqSign(signRank), reqExec(execRank) {
    if (reqSign < 1 || reqExec < 1) throw Form::GradeTooHighException();
    if (reqSign > 150 || reqExec > 150) throw Form::GradeTooLowException();
}

Form::Form(const Form& src) 
    : name(src.name), _signed(src._signed), reqSign(src.reqSign), reqExec(src.reqExec) {}

Form& Form::operator=(const Form& rhs) {
    if (this != &rhs)
        this->_signed = rhs._signed;
    return *this;
}

Form::~Form() {}

const std::string Form::getName() const { return name; }
bool Form::get_signed() const { return _signed; }
int Form::getReqSign() const { return reqSign; }
int Form::getReqExec() const { return reqExec; }

void Form::be_signed(const Bureaucrat& b) {
    if (b.getGrade() > reqSign)
        throw Form::GradeTooLowException();
    _signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& obj) {
    out << "Form [" << obj.getName() << "] - signed: " << (obj.get_signed() ? "Yes" : "No")
        << " (Required Grade to Sign: " << obj.getReqSign() << ")";
    return out;
}