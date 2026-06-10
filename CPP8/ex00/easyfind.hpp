/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:38:52 by skaynar           #+#    #+#             */
/*   Updated: 2026/06/10 00:00:00 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>  // std::find icin
# include <exception>  // std::exception icin

/*
** Ozel istisna: aranan deger container icinde bulunamazsa firlatilir.
** std::exception'dan miras alarak standart catch bloklariyla yakalanabilir.
*/
class ValueNotFoundException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Hata: Aranan deger container icinde bulunamadi!";
    }
};

/*
** easyfind (non-const surum):
**   std::find, container'in basından sonuna kadar ilk eslesmeyi arar.
**   end() donerse deger yoktur -> istisna firlatilir.
**   "typename T::iterator": T'nin bagimli turu oldugu icin typename zorunlu.
*/
template <typename T>
typename T::iterator easyfind(T& cont, int to_find) {
    typename T::iterator it = std::find(cont.begin(), cont.end(), to_find);
    if (it == cont.end())
        throw ValueNotFoundException();
    return it;
}

/*
** easyfind (const surum):
**   const bir container'a da uygulanabilmesi icin gerekli asiri yuklemedir.
**   const_iterator dondurur; bu sayede salt-okunur nesnelerde de calisir.
*/
template <typename T>
typename T::const_iterator easyfind(const T& cont, int to_find) {
    typename T::const_iterator it = std::find(cont.begin(), cont.end(), to_find);
    if (it == cont.end())
        throw ValueNotFoundException();
    return it;
}

#endif
