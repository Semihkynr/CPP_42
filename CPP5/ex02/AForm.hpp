/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:47:45 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/13 17:03:37 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat; // Forward declaration

class AForm {
    private:
        const std::string name;
        bool              isSigned;
        const int         gradeToSign;
        const int         gradeToExec;
        AForm();

    public:
        AForm(const std::string name, int gradeToSign, int gradeToExec);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        const std::string getName() const;
        bool getIsSigned() const;
        int getGradeToExec() const;
        int getGradeToSign() const;
        void beSigned(const Bureaucrat& b);
        void execute(const Bureaucrat& executor) const;
        virtual void executeAction() const = 0;
        class GradeTooHighException : public std::exception {
            public: virtual const char* what() const throw();};
        class GradeTooLowException : public std::exception {
            public: virtual const char* what() const throw();};
        class FormNotSignedException : public std::exception {
            public: virtual const char* what() const throw();};
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif




