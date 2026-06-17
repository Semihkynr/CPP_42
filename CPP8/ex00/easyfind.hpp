/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:38:52 by skaynar           #+#    #+#             */
/*   Updated: 2026/06/17 13:45:46 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>

class ValueNotFoundException : public std::exception {
public:
    virtual const char* what() const throw() {return "Hata: Aranan deger container icinde bulunamadi!";}
};
template <typename T>
typename T::iterator easyfind(T& cont, int to_find) {
    typename T::iterator it = std::find(cont.begin(), cont.end(), to_find);
    if (it == cont.end())
        throw ValueNotFoundException();
    return it;}

template <typename T>
typename T::const_iterator easyfind(const T& cont, int to_find) {
    typename T::const_iterator it = std::find(cont.begin(), cont.end(), to_find);
    if (it == cont.end())
        throw ValueNotFoundException();
    return it;}
#endif