/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:39:08 by skaynar           #+#    #+#             */
/*   Updated: 2026/06/17 10:48:01 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(42);
    vec.push_back(30);
    try {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "vector'da bulundu: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        easyfind(vec, 99);
    } catch (const std::exception& e) {
        std::cout << "Yakalandı: " << e.what() << std::endl;
    }
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    try {
        std::list<int>::iterator it = easyfind(lst, 2);
        std::cout << "list'te bulundu: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}