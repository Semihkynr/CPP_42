/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 13:06:55 by skaynar           #+#    #+#             */
/*   Updated: 2026/05/21 14:22:24 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T,typename F>
void iter(T* array,size_t lenght, F func){
    for (size_t i = 0; i < lenght; i++)
        func(array[i]);
}

#endif