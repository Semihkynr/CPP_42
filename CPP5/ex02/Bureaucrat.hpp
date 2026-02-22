/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:59:36 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/22 13:07:28 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <string>

class AForm;

class Bureaucrat {
    private:
        int grade;
        const std::string name;
        Bureaucrat();
    public:
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        const std::string getName() const;
        int getGrade() const;
        void promote();
        void demote();
        void signForm(AForm& f);
        void executeForm(AForm const & form);
        class GradeTooHighException : public std::exception {
            public: virtual const char* what() const throw();};
        class GradeTooLowException : public std::exception {
            public: virtual const char* what() const throw();};
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);
#endif