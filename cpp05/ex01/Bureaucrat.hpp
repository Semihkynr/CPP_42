/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:09:55 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/08 15:10:05 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Form; // İlerideki Form sınıfı için ön bildirim

class Bureaucrat {
    private:
        const std::string name;
        int               grade;
        Bureaucrat(); // Parametresiz kullanım yasak

    public:
        // Orthodox Canonical Form
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        // Getters
        const std::string getName() const;
        int               getGrade() const;

        // Yetki değişimleri
        void    promote();   // dereceyi yükseltir (sayı düşer)
        void    demote();    // dereceyi düşürür (sayı artar)
        void    signForm(Form& f);

        // Hata sınıfları
        class GradeTooHighException : public std::exception {
            public: virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public: virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif