/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* main_refactored.cpp                              :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+         */
/* Created: 2025/12/08 11:49:24 by skaynar           #+#    #+#             */
/* Updated: 2025/12/08 11:52:13 by skaynar          ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void demonstrate_animal_array_polymorphism()
{
    std::cout << "\n---  Animal Dizisi Polimorfizm Testi ---" << std::endl;
    
    const int N = 6;
    // Orijinal değişken adı korunmuştur.
    Animal* animal[N]; 

    // Diziyi doldurma: İlk N/2 Dog, geri kalan Cat
    std::cout << "1. Nesneler Oluşturuluyor (3 Dog, 3 Cat)..." << std::endl;
    for (int i = 0; i < N; ++i) {
        if (i < N / 2) {
            std::cout << "  animal[" << i << "] -> Dog" << std::endl;
            animal[i] = new Dog();
        } else {
            std::cout << "  animal[" << i << "] -> Cat" << std::endl;
            animal[i] = new Cat();
        }
    }

    // Ses çıkarma testi
    std::cout << "\n2. Ses Çıkarma Testi (makeSound):" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << "  animal[" << i << "] Sesi: ";
        animal[i]->makeSound(); // Polimorfizm sayesinde doğru makeSound çağrılır
    }

    // Bellek temizleme
    std::cout << "\n3. Bellek Temizleme (delete):" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << "  animal[" << i << "] Siliniyor..." << std::endl;
        delete animal[i]; // Virtual destructor sayesinde doğru destructor çağrılır
    }
}

void demonstrate_deep_copy_test()
{
    std::cout << "\n--- Derin Kopyalama (Deep Copy) Testi ---" << std::endl;

    // Orijinal değişken adları korunmuştur.
    Dog* d1 = new Dog();
    
    // d1'e bir fikir atama
    d1->getBrain()->setIdea(0, "Chase the mailman"); 
    
    // Derin kopyalama konstrüktörü ile d2 oluşturma
    Dog* d2 = new Dog(*d1); 
    
    std::cout << "1. İlk Durum Kontrolü:" << std::endl;
    std::cout << "  d1 str[0]: " << d1->getBrain()->getIdea(0) << " (Adres: " << d1->getBrain() << ")" << std::endl;
    std::cout << "  d2 str[0]: " << d2->getBrain()->getIdea(0) << " (Adres: " << d2->getBrain() << ")" << std::endl;
    
    // d1'in fikrini değiştirme
    d1->getBrain()->setIdea(0, "Eat the bone"); 
    
    std::cout << "\n2. d1 Değiştirildikten Sonraki Durum Kontrolü:" << std::endl;
    std::cout << "  d1 str[0]: " << d1->getBrain()->getIdea(0) << std::endl;
    // Eğer Deep Copy doğru çalıştıysa, d2'nin içeriği değişmemelidir.
    std::cout << "  d2 str[0]: " << d2->getBrain()->getIdea(0) << " (Değişmediyse, Deep Copy başarılıdır)" << std::endl; 

    // Bellek Temizleme
    std::cout << "\n3. Bellek Temizleme (Dog Nesneleri):" << std::endl;
    delete d2;
    delete d1;
}

int main()
{
    // Animal dizisi ve polimorfizm testini çalıştır
    demonstrate_animal_array_polymorphism();
    
    // Derin kopyalama testini çalıştır
    demonstrate_deep_copy_test();
    
    return 0;
}