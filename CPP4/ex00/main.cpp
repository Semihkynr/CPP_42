/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* main_revize.cpp                                    :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+         */
/* Created: 2025/12/08 11:46:40 by skaynar           #+#    #+#             */
/* Updated: 2025/12/08 11:48:06 by skaynar          ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void demonstrate_correct_polymorphism()
{
    std::cout << "\n--- ✅ Animal (Doğru Polimorfizm) Testi ---" << std::endl;
    
    // Değişken adları orijinal haliyle korunmuştur.
    const Animal* meta = new Animal(); 
    const Animal* i = new Cat();       
    const Animal* j = new Dog();       
    
    std::cout << "1. Tip Kontrolü:" << std::endl;
    std::cout << "  i (Cat) Tipi: " << i->getType() << std::endl;
    std::cout << "  j (Dog) Tipi: " << j->getType() << std::endl;
    
    std::cout << "\n2. Ses Çıkarma (makeSound):" << std::endl;
    std::cout << "  j (Dog) Sesi: ";
    j->makeSound(); // Dog::makeSound çağrılır (Virtual fonksiyon)
    
    std::cout << "  i (Cat) Sesi: ";
    i->makeSound(); // Cat::makeSound çağrılır (Virtual fonksiyon)
    
    std::cout << "  meta (Animal) Sesi: ";
    meta->makeSound(); // Animal::makeSound çağrılır
    
    std::cout << "\n3. Bellek Temizleme (Animal):" << std::endl;
    delete meta;
    delete i;
    delete j;
}

void demonstrate_wrong_polymorphism()
{
    std::cout << "\n--- ❌ WrongAnimal (Yanlış Polimorfizm) Testi ---" << std::endl;
    
    // Değişken adları orijinal haliyle korunmuştur.
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrong = new WrongCat();

    std::cout << "1. Tip Kontrolü:" << std::endl;
    // WrongCat, WrongAnimal'dan türetilmiştir. getType() sanal değildir (muhtemelen).
    std::cout << "  wrong (WrongCat) Tipi: " << wrong->getType() << std::endl; 
    
    std::cout << "\n2. Ses Çıkarma (makeSound):" << std::endl;
    // makeSound sanal olmadığı için, işaretçinin tipine (WrongAnimal*) göre fonksiyon çağrılır.
    std::cout << "  wrong (WrongCat) Sesi: ";
    wrong->makeSound(); // Her zaman WrongAnimal::makeSound çağrılır!
    
    std::cout << "  wrongMeta (WrongAnimal) Sesi: ";
    wrongMeta->makeSound();
    
    std::cout << "\n3. Bellek Temizleme (WrongAnimal):" << std::endl;
    delete wrong;
    delete wrongMeta;
}

int main()
{
    // Temel testleri fonksiyonlar halinde ayırarak ana akışı basitleştirme
    demonstrate_correct_polymorphism();
    
    demonstrate_wrong_polymorphism();

    return 0;
}