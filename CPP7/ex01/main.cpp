/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:01:33 by skaynar           #+#    #+#             */
/*   Updated: 2026/05/21 14:17:21 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(const T& i){
    std::cout << i << " ";
}

template <typename T>
void square(T& i){
    i *= i;
}

int main(){
    int array[] = {1,2,3,4,5};

    iter(array,5,print<int>);
    std::cout << std::endl;
   
    iter(array,5,square<int>);
    iter(array,5,print<int>);
    std::cout << std::endl;

    std::string famous[] = {"monica","rach","joe","chandler","ross"};
    iter(famous,5,print<std::string>);
}