/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:38:59 by skaynar           #+#    #+#             */
/*   Updated: 2026/06/10 00:00:00 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>  // std::stack - miras alinacak ata sinif
# include <deque>  // std::deque - varsayilan dahili container

/*
** MutantStack: std::stack'ten miras alan, ona iterator destegi ekleyen sinif.
**
** std::stack, dahili veriyi koruyucu (protected) bir "c" uye degiskeninde
** saklar. Miras sayesinde bu degiskene dogrudan erisilebilir; boylece
** c.begin() / c.end() cagrilarak stack iteratif hale getirilir.
**
** Tasarim avantajlari:
**   - std::stack'in tum fonksiyonlari (push, pop, top, size, empty) ucretsiz gelir
**   - Dahili yapiya dokunulmadan iterator eklenir
**   - std::stack<T> s(mstack) derlenir: ikisi de ayni Container (deque) kullanir
*/
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    // OCF: 4 zorunlu fonksiyon
    MutantStack() : std::stack<T, Container>() {}

    MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}

    MutantStack& operator=(const MutantStack& other) {
        if (this != &other)
            std::stack<T, Container>::operator=(other);
        return *this;
    }

    ~MutantStack() {}

    /*
    ** Iterator typedef'leri: MutantStack<int>::iterator gibi kullanim saglar.
    ** Container'in kendi iterator turleri dogrudan iletilir.
    ** "typename" zorunlu: Container bir sablon parametresi oldugu icin
    ** derleyici "iterator"'in bir tur mi yoksa statik uye mi oldugunu
    ** bilemez; typename bunu acikca belirtir.
    */
    typedef typename Container::iterator               iterator;
    typedef typename Container::const_iterator         const_iterator;
    typedef typename Container::reverse_iterator       reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    // Ileri yonlu iterator erisimi - "this->c" korunan ata uye degiskenidir
    iterator       begin()        { return this->c.begin(); }
    iterator       end()          { return this->c.end();   }
    const_iterator begin()  const { return this->c.begin(); }
    const_iterator end()    const { return this->c.end();   }

    // Ters yonlu iterator erisimi - sondan basa dogru dolasim saglar
    reverse_iterator       rbegin()       { return this->c.rbegin(); }
    reverse_iterator       rend()         { return this->c.rend();   }
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend()   const { return this->c.rend();   }
};

#endif
