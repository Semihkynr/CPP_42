/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:09:55 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/22 11:33:09 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Form;
class Bureaucrat {
    private:
        const std::string name;
        int               grade;
        Bureaucrat();
    public:
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        const std::string getName() const;
        int getGrade() const;

        void promote();
        void demote();
        void signForm(Form& f);

        class GradeTooHighException : public std::exception {
            public: virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public: virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif