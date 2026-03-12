/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:34:12 by skaynar           #+#    #+#             */
/*   Updated: 2026/03/12 14:42:10 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
    Data myData;
    myData.id = 55;
    myData.name = "Data gibimsi";
    std::cout << "Orijinal Pointer Adresi: " << &myData << std::endl;
    std::cout << "Veriler: ID = " << myData.id << ", Name = " << myData.name << std::endl;
    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized Deger (uintptr_t): " << raw << std::endl;

    Data* resultPtr = Serializer::deserialize(raw);
    std::cout << "Deserialized Pointer Adresi: " << resultPtr << std::endl;

    if (resultPtr == &myData) {
        std::cout << "BASARILI: Pointerlar eslesiyor!" << std::endl;
        std::cout << "Geri donen veriler: ID = " << resultPtr->id 
                  << ", Name = " << resultPtr->name << std::endl;
    } else {
        std::cout << "HATA: Pointerlar eslesmiyor!" << std::endl;
    }

    return 0;
}