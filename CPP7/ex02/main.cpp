/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:01:33 by skaynar           #+#    #+#             */
/*   Updated: 2026/05/21 13:07:06 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(){

    try
    {
        Array<int> emptyArr;
        std::cout << "Empty array: " << emptyArr.size() << std::endl;

        Array<int> numbers(5);
        for (unsigned int i = 0; i < numbers.size(); i++)
            numbers[i] = i * 10;
        
        std::cout << "numbers array: ";
        for (unsigned int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;
        
        const Array<int>& constNumbers = numbers;
        std::cout << "constNumbers[2] = " << constNumbers[2] << std::endl;

        std::cout << numbers[10] << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
}
