/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:09:18 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/01 18:15:16 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

int	main()
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout   << "brain adress: " << &brain << std::endl << "stringPTR adress: " << stringPTR << std::endl << "stringREF adress: " << &stringREF << std::endl << std::endl
				<< "brain value: " << brain << std::endl << "stringPTR value: " << *stringPTR << std::endl << "stringREF value: " << stringREF << std::endl;
	return 0;
}