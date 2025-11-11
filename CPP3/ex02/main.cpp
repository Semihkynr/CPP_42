/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:53:22 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/12 01:32:03 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(int ac, char **av)
{
    if(ac == 2){
        std::cout << "--- 1. FRAGTRAP OLUSTURMA VE BASLANGIC TESTI ---" << std::endl;
        FragTrap st(av[1]);
    
        std::cout << "\n--- 2. ATTACK VE ENERJI TESTI ---" << std::endl;
        st.attack("Bandit");
        st.attack("Bandit");
        st.attack("Bandit");
    
        std::cout << "\n--- 3. HASAR ALMA TESTI ---" << std::endl;
        st.takeDamage(10);
        st.takeDamage(50);
    
        std::cout << "\n--- 4. TAMIR VE ENERJI TESTI ---" << std::endl;
        std::cout << st.getHit() << std::endl;
        st.beRepaired(20);
        st.beRepaired(20);
        std::cout << st.getHit() << std::endl;
        
        std::cout << "\n--- 5. OZEL YETENEK TESTI ---" << std::endl;
        st.highFivesGuys();
    
        std::cout << "\n--- 6. KLASIK CLAPTRAP NESNESI ---" << std::endl;
        ClapTrap ct("CL4P-TRP");
        ct.attack("Target");
        
        std::cout << "\n--- 7. PROGRAM SONU VE YIKICILAR ---" << std::endl;    
    }
    else
        std::cout << "\"./FragTrap <name>\" Please!!!" << std::endl;
    return 0;
}