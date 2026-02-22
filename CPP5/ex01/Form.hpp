/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:07:58 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/22 11:34:08 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form {
    private:
        const std::string name;
        bool _signed;
        const int reqSign;
        const int reqExec;

    public:
        Form(const std::string name, int signRank, int execRank);
        Form(const Form& src);
        Form& operator=(const Form& rhs);
        ~Form();
        const std::string getName() const;
        bool get_signed() const;
        int getReqSign() const;
        int getReqExec() const;
        void be_signed(const Bureaucrat& b);
        
        class GradeTooHighException : public std::exception {
            public: virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public: virtual const char* what() const throw();
        };
};
std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif