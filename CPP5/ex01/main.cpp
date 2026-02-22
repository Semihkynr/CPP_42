/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:08:19 by skaynar           #+#    #+#             */
/*   Updated: 2026/02/22 12:50:32 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "--- CREATING BUREAUCRATS ---" << std::endl;
    Bureaucrat boss("The Big Boss", 1);
    Bureaucrat intern("Sad Intern", 145);

    std::cout << boss << std::endl;
    std::cout << intern << std::endl;

    std::cout << "\n--- CREATING FORMS ---" << std::endl;
    Form a3("A3 Coffee Machine Request", 140, 150);
    Form topSecret("Nuclear Launch Codes", 1, 1);

    std::cout << a3 << std::endl;
    std::cout << topSecret << std::endl;

    std::cout << "\n--- SIGNING PROCESS ---" << std::endl;
    intern.signForm(a3);
    boss.signForm(topSecret);
    intern.signForm(topSecret);

    std::cout << "\n--- FINAL STATUS ---" << std::endl;
    std::cout << a3 << std::endl;
    std::cout << topSecret << std::endl;

    return 0;
}